const int DOT = 1000; // one second
const int DASH = 3000; // three seconds
const int SAME_LETTER_SPACE = 1000; // one second rest while in same letter
const int LETTER_SPACE = 3001; // three seconds between letters *** note this cannot be the same value as dash so add a milisecond and we can subtract one when we blink if we care enough to do so 
const int WORD_SPACE = 7000; // seven seconds between words

const int MORSE_VALUES = 37; // 26 letters + 10 numbers + 1 for empty space between words
const int MORSE_MAX = 6; // 6 with letter space 

// 'Mapping' of letters and numbers to their morse values
char morseChars[MORSE_VALUES] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', ' '};

int morseValues[MORSE_VALUES] [MORSE_MAX] = {
                    {DOT, DASH},
                    {DASH, DOT, DOT, DOT},
                    {DASH, DOT, DASH, DOT},
                    {DASH, DOT, DOT},
                    {DOT},
                    {DOT, DOT, DASH, DOT},
                    {DASH, DASH, DOT},
                    {DOT, DOT, DOT, DOT},
                    {DOT, DOT},
                    {DOT, DASH, DASH, DASH}, 
                    {DASH, DOT, DASH},
                    {DOT, DASH, DOT, DOT},
                    {DASH, DASH},
                    {DASH, DOT},
                    {DASH, DASH, DASH},
                    {DOT, DASH, DASH, DOT},
                    {DASH, DASH, DOT, DASH},
                    {DOT, DASH, DOT},
                    {DOT, DOT, DOT},
                    {DASH},
                    {DOT, DOT, DASH},
                    {DOT, DOT, DOT, DASH},
                    {DOT, DASH, DASH},
                    {DASH, DOT, DOT, DASH},
                    {DASH, DOT, DASH, DASH},
                    {DASH, DASH, DOT, DOT},
                    {DOT, DASH, DASH, DASH, DASH},
                    {DOT, DOT, DASH, DASH, DASH},
                    {DOT, DOT, DOT, DASH, DASH},
                    {DOT, DOT, DOT, DOT, DASH},
                    {DOT, DOT, DOT, DOT, DOT},
                    {DASH, DOT, DOT, DOT, DOT},
                    {DASH, DASH, DOT, DOT, DOT},
                    {DASH, DASH, DASH, DOT, DOT},
                    {DASH, DASH, DASH, DASH, DOT},
                    {DASH, DASH, DASH, DASH, DASH},
                    {WORD_SPACE}
                    };

int convertToMorse(String input, int**& morseArray);
