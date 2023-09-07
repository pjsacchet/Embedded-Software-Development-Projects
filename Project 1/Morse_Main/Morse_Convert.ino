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
returns: N/A (we store the appropiate morse code values in the provided array)
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

    //Serial.println(currentChar);

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

    for(i=0; i<arrayLength; i++)
    {
      // We'll add all values of our array including zeros...
      morseArray[index][i] = morseValues[morseIndex][i];
      //Serial.println(morseArray[index][i]);
      
    }

    /**
    // Add same letter space only if the next letter is not an empty space
    if (strcmp(&input[index+1], &morseChars[MORSE_VALUES-1]) != 0)
    {
      *morseArray[index][i+1] = SAME_LETTER_SPACE;
    }
    */
    //Serial.println("GOT ONE");

    // Next user letter
    index++;
  }
  
  return input.length();
}