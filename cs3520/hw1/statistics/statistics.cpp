#include <iostream>
#include <string>
using namespace std;

int main() {
    string paragraph;
    cout << "Enter a paragraph: ";
    getline(cin, paragraph);

    string searchStr;
    cout << "Enter the word or sentence that you want to look for: ";
    getline(cin, searchStr);

    int count = 0;
    int index = paragraph.find(searchStr, 0);
    while (index != -1) {
        cout << "Found at index: " << index << endl;
        count++;
        index = paragraph.find(searchStr, index + 1);
    }
    cout << "'" << searchStr << "'" << " was found " << count << " times." << endl;

    string replaceStr = searchStr;
    for (int i = 0; i < replaceStr.length() / 2; i++) {
        swap(replaceStr[i], replaceStr[replaceStr.length() - 1 - i]);
    }

    string newPara = paragraph;
    index = newPara.find(searchStr, 0);
    while (index != -1) {
        newPara.replace(index, searchStr.length(), replaceStr);
        index = newPara.find(searchStr, index + replaceStr.length());
    }

    cout << "\nOriginal paragraph:\n" << paragraph << endl;
    cout << "\nNew paragraph:\n" << newPara << endl;
}