import os
import dbus
import dbus.service
import dbus.mainloop.glib
from gi.repository import GLib
import subprocess


class Profile(dbus.service.Object):
    fd = -1

    @dbus.service.method('org.bluez.Profile1',
                         in_signature='',
                         out_signature='')
    def Release(self):
        print('Release')

    @dbus.service.method('org.bluez.Profile1',
                         in_signature='oha{sv}',
                         out_signature='')
    def NewConnection(self, path, fd, properties):
        self.fd = fd.take()
        print('NewConnection(%s, %d)' % (path, self.fd))
        for key in properties.keys():
            if key == 'Version' or key == 'Features':
                print('  %s = 0x%04x' % (key, properties[key]))
            else:
                print('  %s = %s' % (key, properties[key]))
        io_id = GLib.io_add_watch(self.fd,
                                  GLib.PRIORITY_DEFAULT,
                                  GLib.IO_IN | GLib.IO_PRI,
                                  self.io_cb)

    # Where we print to screen...
    def io_cb(self, fd, conditions):
        data = os.read(fd, 1024)
        print('Callback Data: {0}'.format(data.decode('ascii')))
        #command = data.decode('ascii')
        command = data.decode('ascii').rstrip()
        #if (file!= '' and len(file) != 0 and file != '\r'):
        os.system(command)
            # technically works but wont work unless program terminates
            #os.write(fd, bytes(subprocess.check_output(['python', file])) + b'\n')
        '''
        popen = subprocess.Popen(["python", file], stdout=subprocess.PIPE, universal_newlines=True)
        for stdout_line in iter(popen.stdout.readline, ""):
            os.write(fd, bytes(stdout_line) + b'\n')
            yield stdout_line
        popen.stdout.close()
        return_code = popen.wait()
        '''




        #os.write(fd, bytes(output.rstrip()) + b'\n')
        # dont write back to our listener... write our output!
        #os.write(fd, bytes(list(reversed(data.rstrip()))) + b'\n')
        return True

    @dbus.service.method('org.bluez.Profile1',
                         in_signature='o',
                         out_signature='')
    def RequestDisconnection(self, path):
        print('RequestDisconnection(%s)' % (path))

        if self.fd > 0:
            os.close(self.fd)
            self.fd = -1


def main():
    dbus.mainloop.glib.DBusGMainLoop(set_as_default=True)

    bus = dbus.SystemBus()

    manager = dbus.Interface(bus.get_object('org.bluez',
                                            '/org/bluez'),
                             'org.bluez.ProfileManager1')

    mainloop = GLib.MainLoop()

    adapter = dbus.Interface(bus.get_object('org.bluez',
                                            '/org/bluez/hci0'),
                            dbus.PROPERTIES_IFACE)
    discoverable = adapter.Get('org.bluez.Adapter1', 'Discoverable')
    if not discoverable:
        print('Making discoverable...')
        adapter.Set('org.bluez.Adapter1', 'Discoverable', True)

    profile_path = '/foo/baz/profile'
    server_uuid = '00001101-0000-1000-8000-00805f9b34fb'
    opts = {
        'Version': dbus.UInt16(0x0102),
        'AutoConnect': dbus.Boolean(True),
        'Role': 'server',
        'Name': 'SerialPort',
        'Service': '00001101-0000-1000-8000-00805f9b34fb',
        'RequireAuthentication': dbus.Boolean(False),
        'RequireAuthorization': dbus.Boolean(False),
        'Channel': dbus.UInt16(1),
    }

    print('Starting Serial Port Profile...')

    profile = Profile(bus, profile_path)

    manager.RegisterProfile(profile_path, server_uuid, opts)

    try:
        mainloop.run()
    except KeyboardInterrupt:
        mainloop.quit()


if __name__ == '__main__':
    main()
