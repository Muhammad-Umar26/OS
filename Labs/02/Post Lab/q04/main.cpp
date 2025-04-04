#include <iostream>
#include "LetterCount.h"
#include "WordCount.h"
#include "LineCount.h"

int main() {
    string filename = "input.txt";

    LetterCount letterCounter;
    WordCount wordCounter;
    LineCount lineCounter;

    int letterCount = letterCounter.countLetters(filename);
    int wordCount = wordCounter.countWords(filename);
    int lineCount = lineCounter.countLines(filename);

    if(letterCount == -1 || wordCount == -1 || lineCount == -1) {
        cout << "Error: Could not open file!" << endl;
        return 1;
    }

    cout << "Letters: " << letterCount << endl;
    cout << "Words: " << wordCount << endl;
    cout << "Lines: " << lineCount << endl;

    return 0;
}