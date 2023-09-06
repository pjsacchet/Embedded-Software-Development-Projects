/**
Project 1 - Morse Code LED System Development
Patrick Sacchet, Robert Walsh
EN.605.715.81.FA23
Professor Doug Ferguson
10SEP23
*/

// This program will handle simple I/O with the user

/** Waits for input from the user; parses byte by byte and adds them to an array to return for parsing
 prarms: N/A
 returns: string of user input
*/
String parseInput()
{
  Serial.println("Enter morse code message:");

  //wait for data available
  while (Serial.available() == 0) {}

  //read until timeout
  
 // messageString.reserve(MAX_INPUT);
  String messageString = Serial.readString();

  Serial.println(messageString);

  //char messageChar = Serial.read();
  //Serial.print(messageChar);

  // remove any \r \n whitespace at the end of the String
  messageString.trim();
  
  // remove uppercase to simplify encoder
  messageString.toLowerCase();

  return messageString;
}