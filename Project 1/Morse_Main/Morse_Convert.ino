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
void convertToMorse(String input, int*** morseArray)
{
  // Parse through each letter of our input string
  unsigned int index = 0; // where we are in our user provided string 
  while(index < input.length())
  {
    unsigned int morseIndex = 0; // where we are in our morse dictionary 

    // Get our first letter
    char currentLetter = morseChars[morseIndex];
    char currentChar = input[index];

    Serial.println(MORSE_VALUES); 

    // Go through all our morse code values until we find the right letter
    while((strcmp(&currentChar, &currentLetter) != 0) && morseIndex < MORSE_VALUES)
    {
      morseIndex++;
      currentLetter = morseChars[morseIndex];
    }

    // For each entry in the morse array add it to our own array
    int i;
    int arrayLength = sizeof(&morseValues[morseIndex])/sizeof(int);
    for(i=0; i<arrayLength; i++)
    {
      *morseArray[index][i] = morseValues[morseIndex][i];
    }

    // Add same letter space only if the next letter is not an empty space
    if (strcmp(&input[index+1], &morseChars[MORSE_VALUES-1]) != 0)
    {
      *morseArray[index][i+1] = SAME_LETTER_SPACE;
    }

    // Next user letter
    index++;
  }
}