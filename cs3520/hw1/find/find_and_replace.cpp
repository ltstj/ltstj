#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib> 

using namespace std;

bool vowels(char v) {
    v = tolower(v);
    return v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u';
}

bool punctuation(char p) {
    string punc = "!.,;\"'?";
    return punc.find(p) != string::npos;
}

int main() {
    string paragraph;
    cout << "Enter a paragraph: ";
    getline(cin, paragraph);

    cout << "\nThe user inputted paragraph:\n" << paragraph << "\n";

    stringstream ss(paragraph);
    string word;
    vector<string> words;

    while (ss >> word) {
        words.push_back(word);
    }

    int total = words.size();
    int vCount = 0;
    int cCount = 0;
    int twoVWords = 0;
    int pWords = 0;

    for (const string &word : words) {
        int numVowels = 0, consonants = 0;
        bool punctuations = false;

        for (char c : word) {
            if (vowels(c)) {
                numVowels++;
            } else if (isalpha(c)) {
                consonants++;
            } else if (punctuation(c)) {
                punctuations = true;
            }
        }

        vCount += numVowels;
        cCount += consonants;
        if (numVowels == 2) {
            twoVWords++;
        }
        if (punctuation) {
            pWords++;
        }
    }

    cout << "Total number of words: " << total << endl;
    cout << "Number of vowels: " << vCount << endl;
    cout << "Number of consonants: " << cCount << endl;
    cout << "Number of words with exactly two vowels: " << twoVWords << endl;
    cout << "Number of words containing punctuation: " << pWords << endl;

    int length;
    cout << "Enter a number for word length: ";
    cin >> length;

    int smallerOrEqual = 0;
    for (const string &word : words) {
        int cLength = 0;
        for (char c : word) {
            if (isalpha(c)) {
                cLength++;
            }
        }
        if (cLength <= length) {
            smallerOrEqual++;
        }
    }

    cout << "The number of words with " << length << " letters or less is " << smallerOrEqual << endl;

    int randLength = rand() % 7 + 3;

    int smaller = 0;
    for (const string &word : words) {
        if (word.length() < randLength) {
            smaller++;
        }
    }

    cout << "The random number word length is: " << randLength << endl;
    cout << "The number of words with " << randLength << " letters or less is " << smaller << endl;
}