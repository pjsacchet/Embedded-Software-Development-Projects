/**
Project 2 - Serial Transmit of Temperature
Patrick Sacchet, Robert Walsh
EN.605.715.81.FA23
Professor Doug Ferguson
24SEP23
*/

// This file will serve for executing 'main' looping functionality, i.e., initializing the sensor, reading temparatures from the sensor, and outputtin them via serial
  // PLEASE NOTE: funcitonality relies on the 'DHT sensor library' by Adafruit being installed on the running system prior to initialization
  // REQUIRES the following Arduino libraries:
  // - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
  // - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#define DHTPIN 2     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Note the following calculations were taken to get the correct timing
// sytemclock = 16 MHz
// prescalarTimer1 = 256
// speedTimer1 = 16MHz / 256 = 62.5KHz
// pulseTime = 1/62.5KHz = 16us
// OCR register = 1s / 16us = 62500
unsigned int reload = 0xF424;     // max count for clock reg with 1 second percision (62500)
volatile byte count;

// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);

// Timer 1 ISR
ISR(TIMER1_COMPA_vect)
{
  // increment count every second
  count++;
  Serial.print("Count is: ");
  Serial.println(count);
}

void setup() {
  Serial.begin(9600);
  
  //initialize the temp sensor
  dht.begin();

  // initialize timer one for 1s percision
  cli();
  TCCR1A = 0;
  TCCR1B = 0; 
  OCR1A = reload;
  TCCR1B = (1<<WGM12) | (1<<CS12); 
  TIMSK1 = (1<<OCIE1A); 
  sei(); 
  Serial.println("TIMER1 Setup Finished.");
}

void loop() {

  float f = 0;

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    // check if it has been 10 seconds
  if(count == 10)
  {
    f = dht.readTemperature(true);
    // Check if any reads failed and exit early (to try again).
    if (isnan(f)) 
    {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
    }

    Serial.print("Temperature = ");
    Serial.print(f);
    Serial.println("°F");
    count = 0;
  }
}