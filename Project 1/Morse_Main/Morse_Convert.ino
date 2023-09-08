/**
Project 1 - Morse Code LED System Development
Patrick Sacchet, Robert Walsh
EN.605.715.81.FA23
Professor Doug Ferguson
10SEP23
*/

// This program will convert ascii characters passeed to it into its morse code equivalent

/** Parses through passed string and inputs corresponding morse code values into the output array for display
params: input - user provided input string
        morseArray - array for storing morse value arrays (should be an array of arrays)
returns: size of the resulting array
*/
int convertToMorse(String input, int**& morseArray)
{
  // Parse through each letter of our input string
  unsigned int index = 0; // where we are in our user provided string 
  while(index < input.length())
  {
    int morseIndex = 0; // where we are in our morse dictionary 

    // Get our first letter
    char currentLetter = morseChars[morseIndex];
    char currentChar = input[index];

    morseArray[index] = (int*)malloc( sizeof(int) *MORSE_MAX);

    // Go through all our morse code values until we find the right letter
    while(currentChar != currentLetter)
    {
      morseIndex++;
      currentLetter = morseChars[morseIndex];
    }

    if (morseIndex > MORSE_VALUES)
    {
      Serial.println("Beyond the limit of our array! ");
    }

    int i;

    // This is going to spit out six everytime because I had to initialize the morseValues array as a double array with a specified size value for columns 
    int arrayLength = sizeof(morseValues[morseIndex])/sizeof(int);
    bool letterSpace = false;   // Flag used to properly add a letter space to our array

    for(i=0; i<arrayLength; i++)
    {
      if((morseValues[morseIndex][i] == 0) && (letterSpace == false))
      {
        letterSpace = true;   // Flag that we've reached the letter space at the FIRST zero in the array
        morseArray[index][i] = LETTER_SPACE;
      }
      else
      {
        // We'll add all values of our array including zeros...
        morseArray[index][i] = morseValues[morseIndex][i];
        if(morseValues[morseIndex][i] == WORD_SPACE)
        {
          letterSpace = true; // added to make sure we dont add extra delays after a word space
        }
      }  
    }

    // Next user letter
    index++;
  }
  
  return input.length();
}