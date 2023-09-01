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
        morseArray - array for storing morse value arrays 
returns: N/A (we store the appropiate morse code values in the provided array)
*/
void convertToMorse(String input, int* morseArray)
{
  // Parse through each letter of our input string
  unsigned int index = 0;
  while(index < input.length())
  {
    unsigned int morseIndex = 0;

    // Get our first letter
    morseLetter* currentLetter = &morseValues[morseIndex];
    char currentChar = input[index];

    // Go through all our morse code values until we find the right letter
    while((strcmp(&currentChar, &currentLetter->letter) != 0) && morseIndex <= MORSE_VALUES)
    {
      morseIndex++;
      //currentLetter = &morseValues[morseIndex];
    }

    // Either we found our value or read through all of our characters and didnt find anything...
      // We need to have an array of arrays... iterate through each entry
     Serial.println(currentLetter->letter);
    // Set our index to the array of morse code values
    //morseArray[index] = currentLetter->values;
    index++;
  }
}