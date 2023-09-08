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
#include "Blink_Handler.h"

int** morseArray;

void setup ()
{
  Serial.begin(9600); // send and receive at 9600 baud
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  morseArray = (int**) malloc(sizeof(int*)*MAX_INPUT);
}

void loop()
{
  int sizeOfInputMessage = 0;
  // Take input from user
  String userInput = parseInput();
  // Convert input into 2D array, each element containing the corresponding letter's morse values
  sizeOfInputMessage = convertToMorse(userInput, morseArray);
  // Convert our morse values to blink output 
  blinkLed(sizeOfInputMessage,morseArray);
}