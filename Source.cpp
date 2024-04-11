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
            // If whitespace is encountered and we are in a word, it means the word has ended
            if (inWord) {
                count++;
                inWord = false;
            }
        }
        else {
            // If a non-whitespace character is encountered, we are in a word
            inWord = true;
        }
    }

    // Check if the last word didn't end with whitespace
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