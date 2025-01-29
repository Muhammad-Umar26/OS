#include <iostream>
#include <fstream>
#include <exception>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Error: No file name provided." << endl;
        return 1;
    }

    string fileName = argv[1];

    ifstream file(fileName);
    if (file) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Error: Could not open the file." << endl;
    }

    return 0;
}
