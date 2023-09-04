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

int outputPin = 13; // pin number for LED

void setup ()
{
  Serial.begin(9600); // send and receive at 9600 baud
  pinMode(outputPin, OUTPUT); 
}

void loop()
{
  // Each time we loop take an input string from the user as an array; for each character in the array, send it to our morse code converter to get the 
    // light display array, then parse through the array to output the morse code message 

  // Create an array of pointers to arrays and allocate accordingly 
  int** morseArray = new int*[MAX_INPUT];
  // should prob allocate in morse_convert so we dont have empty space in our arrays...
    // just get length of the corresponding character array and allocate that as needed 
  for (int i=0; i<MAX_INPUT; i++)
  {
    morseArray[i] = new int[MORSE_MAX];
  }

  String userInput = parseInput();
  userInput.toLowerCase();
  convertToMorse(userInput, &morseArray);

  // Now iterate through morseArray; for each entry send all values in the subarray as power intervals to our bulb and then make appropiate pauses between letters and spaces


  // Call cleanup at some point to free the memory we allocated 
  
}