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
  
  // Take user string, split it into bytes, place bytes in buffer and return 
  while (Serial.available()== 0) {} // this syntax is wack?
  
    String input = Serial.readString();
     
     // Check the user didn't go over our max value (and any other string sanitation we want here)


    
    
  

  return input;
}