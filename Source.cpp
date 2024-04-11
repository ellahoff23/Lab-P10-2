#include <iostream>
#include <string>

using namespace std;

int count_letters(const string& str) {
    int count = 0;

    for (char c : str) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            count++;
        }
    }

    return count;
}

int count_words(const string& str) {
    int count = 0;
    bool inWord = false;

    for (char c : str) {
        if (c == ' ' || c == '\t' || c == '\n') {
    
            if (inWord) {
                count++;
                inWord = false;
            }
        }
        else {
            inWord = true;
        }
    }

    if (inWord) {
        count++;
    }

    return count;
}

int main() {
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    int letterCount = count_letters(input);
    int wordCount = count_words(input);

    cout << "Number of letters: " << letterCount << endl;
    cout << "Number of words: " << wordCount << endl;

    return 0;
}