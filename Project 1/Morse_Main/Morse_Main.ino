/**
Project 1 - Morse Code LED System Development
Patrick Sacchet, Robert Walsh
EN.605.715.81.FA23
Professor Doug Ferguson
10SEP23
*/

// This file will serve for executing 'main' looping functionality, i.e., taking input from user (via Serial_Handler.ino) 
  // to convert to morse code (via Morse_Converter.ino) and then finally displaying that morse code via our connected LED 

#include "Morse_Convert.h"
#include "Serial_Handler.h"

void setup ()
{
  Serial.begin(9600); // send and receive at 9600 baud
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{

  // Each time we loop take an input string from the user as an array; for each character in the array, send it to our morse code converter to get the 
    // light display array, then parse through the array to output the morse code message 

  // Should be array of arrays
  int morseArray[MAX_INPUT] ;

  String userInput = parseInput();
  convertToMorse(userInput, morseArray);

  // Now iterate through morseArray; for each entry send all values in the subarray as power intervals to our bulb and then make appropiate pauses between letters and spaces

  
}