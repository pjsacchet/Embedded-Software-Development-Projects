/**
Project 1 - Morse Code LED System Development
Patrick Sacchet, Robert Walsh
EN.605.715.81.FA23
Professor Doug Ferguson
10SEP23
*/

// This program will generate a blink sequene via the onboardLED

/** Generates the corresponding blink outputs to our Arduino
 prarms: size - size of the array
         morseArray - already constructed morse code 2D array
 returns: string of user input
*/
void blinkLed(int size, int**& morseArray)
{
  int index = 0;
  Serial.println("The size of input message was:");
  Serial.println(size);

  while(index < size) // go through each 'letter' == get each array
  {
    // NOTE: We expect after every letter will end with a LETTER SPACE. Thus, in the event
    // that there is a space between words, we spimply add 4 more seconds of delay to get
    // the full 7 seconds of LED low

    int i = 0;
    while(i < MORSE_MAX)
    {
      int currentValue = morseArray[index][i]; // get each element in each array

      if (currentValue != 0) // only blink for our actual values since we needed to allocate six spots per array
      {
        switch(currentValue)
        {
          case DOT:
            digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
            delay(DOT);
            //check to see if next blink is apart of the same word
            if(*morseArray[index+1] != LETTER_SPACE)
            {
              digitalWrite(LED_BUILTIN, LOW);  // turn the LED on (HIGH is the voltage level)
              delay(DOT);
            }

            Serial.println("DOT");
            break;

          case DASH:
            digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
            delay(DASH);
            //check to see if next blink is apart of the same word
            if(*morseArray[index+1] != LETTER_SPACE)
            {
              digitalWrite(LED_BUILTIN, LOW);  // turn the LED on (HIGH is the voltage level)
              delay(DOT);
            }
            Serial.println("DASH");
            break;

          case LETTER_SPACE:
            digitalWrite(LED_BUILTIN, LOW);  // turn the LED on (HIGH is the voltage level)
            delay(LETTER_SPACE);
            Serial.println("LETTER SPACE");
            break;

          case WORD_SPACE:
            digitalWrite(LED_BUILTIN, LOW);  // turn the LED on (HIGH is the voltage level)
            // Note we assume every letter ends with letter space so we need to account for that delay below
            delay(WORD_SPACE - LETTER_SPACE);
            Serial.println("WORD SPACE");
            break;
            
          default:
            Serial.println("Ahhhh error. Something wen't wrong and we shouldn't be here!");
            break;
        }
      }
      i++; // get next entry in the array
    }

    index++;
  }
}