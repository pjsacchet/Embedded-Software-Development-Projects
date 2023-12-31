'''
Project 9 - Transmit Pitch Roll & Yaw data via Bluetooth
Patrick Sacchet, Robert Walsh
EN.605.715.81.FA23
Professor Doug Ferguson
19NOV23
'''

# This file serves to bridge functionality easily between having our Arduino run on our Pi and reading serial outuput data with ease
import serial
import os


def readCom(fd):
    # May need to change which interface we're reading on depending on what the Pi chooses
    ser = serial.Serial('/dev/ttyACM0', 115200, timeout=1)
    ser.reset_input_buffer()

    #with open ("test.txt", "w+") as outputfile:
    while True:
        if ser.in_waiting > 0:
            try:
                line = ser.readline().decode('utf-8').rstrip()
                os.write(fd, bytes(line, 'utf-8') + b'\n')
                #outputfile.write(line)
                #print(line)
            except Exception as e:
                continue


def main():
    # May need to change which interface we're reading on depending on what the Pi chooses
    ser = serial.Serial('/dev/ttyACM0', 115200, timeout=1)
    ser.reset_input_buffer()

    #with open ("test.txt", "w+") as outputfile:
    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').rstrip()
            #os.write(line)
            #outputfile.write(line)

            print(line)

if __name__ == '__main__':
    main()
