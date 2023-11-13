/**
Project 8 - Transmit Pitch Roll & Yaw data
Patrick Sacchet, Robert Walsh
EN.605.715.81.FA23
Professor Doug Ferguson
19NOV23
*/

#include <Arduino_FreeRTOS.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

/* This driver uses the Adafruit unified sensor library (Adafruit_Sensor),
   which provides a common 'type' for sensor data and some helper functions.

   To use this driver you will also need to download the Adafruit_Sensor
   library and include it in your libraries folder.

   You should also assign a unique ID to this sensor for use with
   the Adafruit Sensor API so that you can identify this particular
   sensor in any data logs, etc.  To assign a unique ID, simply
   provide an appropriate value in the constructor below (12345
   is used by default in this example).

   Connections
   ===========
   Connect SCL to SCL pin (analog 5 on Arduino UNO)
   Connect SDA to SDA pin (analog 4 on Arduino UNO)
   Connect VDD to 3-5V DC (depending on your board's logic level)
   Connect GROUND to common ground

   History
   =======
   2015/MAR/03  - First release (KTOWN)
   2015/AUG/27  - Added calibration and system status helpers
*/

/* Set the delay between fresh samples */
#define BNO055_SAMPLERATE_DELAY_MS (100)

// Check I2C device address and correct line below (by default address is 0x29 or 0x28)
//                                   id, address
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28, &Wire);

// Our RTOS tasks we'll be using
void TaskReadData (void *pvParamters);

void TaskDisplaySensorStatus(void *pvParameters);

/**************************************************************************/
/*
    Display some basic info about the sensor status
*/
/**************************************************************************/
void displaySensorStatus(void)
{
  /* Get the system status values (mostly for debugging purposes) */
  uint8_t system_status, self_test_results, system_error;
  system_status = self_test_results = system_error = 0;
  bno.getSystemStatus(&system_status, &self_test_results, &system_error);

  /* Display the results in the Serial Monitor */
  Serial.println("");
  Serial.print("System Status: 0x");
  Serial.println(system_status, HEX);
  Serial.print("Self Test:     0x");
  Serial.println(self_test_results, HEX);
  Serial.print("System Error:  0x");
  Serial.println(system_error, HEX);
  Serial.println("");
  delay(500);
}

/**************************************************************************/
/*
    Arduino setup function (automatically called at startup)
*/
/**************************************************************************/
void setup(void)
{
  // Define our RTOS tasks (highest priority)
  xTaskCreate(TaskReadData, "ReadData", 256, NULL, 3, NULL);

  xTaskCreate(TaskReadSensorStatus, "ReadSensor", 256, NULL, -1, NULL);

}

/**************************************************************************/
/*
    Arduino loop function, called once 'setup' is complete (your own code
    should go here)
*/
/**************************************************************************/

// Do not need this loop since we have events now 
void loop(void)
{

}

void TaskReadSensorStatus(void *pvParameters)
{
  for (;;)
  {
    displaySensorStatus();
  }
}

// Our RTOS function; will never return or exit
void TaskReadData(void* pvParameters)
{
  Serial.begin(115200);

  while (!Serial) delay(10);  // wait for serial port to open!

  // Initialize sensor
  if(!bno.begin())
  {
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }

  delay(1000);

  bno.setExtCrystalUse(true);

  // Print our roll, pitch and yaw data then pause before polling for new data 
  for(;;)
  {
    sensors_event_t event;
    bno.getEvent(&event);

  
    Serial.print("X: ");
    Serial.print(event.orientation.x, 4);
    Serial.print("\tY: ");
    Serial.print(event.orientation.y, 4);
    Serial.print("\tZ: ");
    Serial.print(event.orientation.z, 4);

    /// New line for next sample
    Serial.println("");

    // Wait for delay time before polling for new data 
    delay(BNO055_SAMPLERATE_DELAY_MS);
  }
}
