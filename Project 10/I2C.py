import smbus2
import time

# Purpose of this program is to send messages and request IMU data via I2C from the Arduino slave

# Created by Addison Sears-Collins
# April 17, 2019
# Open a new file to log the IMU data

f = open("imu_data.txt", "w")
# for RPI version 1, use bus = smbus.SMBus(0)
bus = smbus2.SMBus(1)
# This is the address we setup in the Arduino Program
#SLAVE_ADDRESS = 0x04
SLAVE_ADDRESS = 0x28

def request_reading():
    try:
        # Read a block of 12 bytes starting at SLAVE_ADDRESS, offset 0
        reading = bus.read_i2c_block_data(SLAVE_ADDRESS, 0, 12)

        # Extract the IMU reading data
        if reading[0] < 1:
            roll_sign = "+"
        else:
            roll_sign = "-"
        roll_1 = reading[1]
        roll_2 = reading[2]
        roll_3 = reading[3]
        if reading[4] < 1:
            pitch_sign = "+"
        else:
            pitch_sign = "-"
        pitch_1 = reading[5]
        pitch_2 = reading[6]
        pitch_3 = reading[7]
        if reading[8] < 1:
            yaw_sign = "+"
        else:
            yaw_sign = "-"
        yaw_1 = reading[9]
        yaw_2 = reading[10]
        yaw_3 = reading[11]
        # Print the IMU data to the console
        print("Roll: " + roll_sign + str(roll_1) + str(roll_2) + str(roll_3) +
        " Pitch: " + pitch_sign + str(pitch_1) + str(pitch_2) + str(pitch_3) +
        " Yaw: " + yaw_sign + str(yaw_1) + str(yaw_2) + str(yaw_3))
        try:
            f.write("Roll: " + roll_sign + str(roll_1) + str(roll_2) + str(roll_3) +
            " Pitch: " + pitch_sign + str(pitch_1) + str(pitch_2) + str(pitch_3) +
            " Yaw: " + yaw_sign + str(yaw_1) + str(yaw_2) + str(yaw_3) + "\n")
        except(KeyboardInterrupt, SystemExit):
            f.close()

    except Exception as e:
        pass

# Request IMU data every 5 seconds from the Arduino
while True:
    # Used for testing:
        # command = raw_input("Enter command: l - toggle LED, r - read IMU ")
        # if command == 'l' :
        # bus.write_byte(SLAVE_ADDRESS, ord('l'))
        # elif command == 'r' :
    request_reading()
    time.sleep(5)
