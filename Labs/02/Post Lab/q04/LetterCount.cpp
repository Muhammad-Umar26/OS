#include <iostream>
#include <fstream>

#include "LetterCount.h"

int LetterCount::countLetters(string filename) {
    ifstream file(filename);

    if(!file) {
        cout << "Error: Could not open file." << endl;
        return -1;
    }

    int count = 0;
    char ch;
    while(file.get(ch)) {
        if(isalpha(ch)) ++count;
    }

    file.close();

    return count;
}