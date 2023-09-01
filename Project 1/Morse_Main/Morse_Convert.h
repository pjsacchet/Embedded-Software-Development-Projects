const int DOT = 1000; // one second
const int DASH = 3000; // three seconds
const int SAME_LETTER_SPACE = 1000; // one second rest while in same letter
const int LETTER_SPACE = 3000; // three seconds between letters
const int WORD_SPACE = 7000; // seven seconds between words

const unsigned int MORSE_VALUES = 36; // 26 letters + 10 numbers 

// Key values for different letters; we will parse this in order to grab the appropiate array of display times for each character
typedef struct 
{
  char letter;
  int values[];
}morseLetter;

// Mapping of letters and numbers to their morse values
morseLetter morseValues[] = {
                             {'a', {DOT, DASH}},
                             {'b', {DASH, DOT, DOT, DOT}},
                             {'c', {DASH, DOT, DASH, DOT}},
                             {'d', {DASH, DOT, DOT}},
                             {'e', {DOT}},
                             {'f', {DOT, DOT, DASH, DOT}},
                             {'g', {DASH, DASH, DOT}},
                             {'h', {DOT, DOT, DOT, DOT}},
                             {'i', {DOT, DOT}},
                             {'j', {DOT, DASH, DASH, DASH}},
                             {'k', {DASH, DOT, DASH}},
                             {'l', {DOT, DASH, DOT, DOT}},
                             {'m', {DASH, DASH}},
                             {'n', {DASH, DOT}},
                             {'o', {DASH, DASH, DASH}},
                             {'p', {DOT, DASH, DASH, DOT}},
                             {'q', {DASH, DASH, DOT, DASH}},
                             {'r', {DOT, DASH, DOT}},
                             {'s', {DOT, DOT, DOT}},
                             {'t', {DASH}},
                             {'u', {DOT, DOT, DASH}},
                             {'v', {DOT, DOT, DOT, DASH}},
                             {'w', {DOT, DASH, DASH}},
                             {'x', {DASH, DOT, DOT, DASH}},
                             {'y', {DASH, DOT, DASH, DASH}},
                             {'z', {DASH, DASH, DOT, DOT}},
                             {'1', {DOT, DASH, DASH, DASH, DASH}},
                             {'2', {DOT, DOT, DASH, DASH, DASH}},
                             {'3', {DOT, DOT, DOT, DASH, DASH}},
                             {'4', {DOT, DOT, DOT, DOT, DASH}},
                             {'5', {DOT, DOT, DOT, DOT, DOT}},
                             {'6', {DASH, DOT, DOT, DOT, DOT}},
                             {'7', {DASH, DASH, DOT, DOT, DOT}},
                             {'8', {DASH, DASH, DASH, DOT, DOT}},
                             {'9', {DASH, DASH, DASH, DASH, DOT}},
                             {'0', {DASH, DASH, DASH, DASH, DASH}}
                             };

void convertToMorse(String input, int* morseArray);
