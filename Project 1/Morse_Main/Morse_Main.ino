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
  //morseArray = (int**) alloca(sizeof(int*)*MAX_INPUT);

  // should prob allocate in morse_convert so we dont have empty space in our arrays...
    // just get length of the corresponding character array and allocate that as needed 
  //for (int i=0; i<MAX_INPUT; i++)
  //{
    //morseArray[i] = new int[MORSE_MAX];
  //  morseArray[i] = (int*)malloc( sizeof(int) *MORSE_MAX);
    //morseArray[i] = (int*)alloca( sizeof(int) *MORSE_MAX);
  //}
}

void loop()
{
  // Each time we loop take an input string from the user as an array; for each character in the array, send it to our morse code converter to get the 
    // light display array, then parse through the array to output the morse code message 

  // Create an array of pointers to arrays and allocate accordingly 
  //int** morseArray = new int*[MAX_INPUT];
  //int** morseArray = (int**) malloc(sizeof(int*)*MAX_INPUT);

  // should prob allocate in morse_convert so we dont have empty space in our arrays...
    // just get length of the corresponding character array and allocate that as needed 
  //for (int i=0; i<MAX_INPUT; i++)
  //{
    //morseArray[i] = new int[MORSE_MAX];
   // morseArray[i] = malloc( sizeof(int) *MORSE_MAX);
  //}

  String userInput = parseInput();

  convertToMorse(userInput, morseArray);

  blinkLed(morseArray);

  // Call cleanup at some point to free the memory we allocated 
  
}