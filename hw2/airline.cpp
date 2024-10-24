//Tejadatta Kalapatapu
//CS3520 Summer 1

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;
 
const string SEATS = "ABDEFH";
const int COLUMNS = 6;
const int ROWS = 12;
const string USERNAME = "test";
const string PASSWORD = "pwd";

struct Passenger {
    string n;
    string s;
};

vector<vector<string>> seatingChart(ROWS, vector<string>(COLUMNS, "Empty"));
vector<Passenger> manifest;

void SeatingChart() {
    cout << "Seating Chart:\n";
    cout << "      A      B      D      E      F      H\n";
    for (int i = 0; i < ROWS; ++i) {
        cout << setw(2) << i + 1 << " ";
        for (int j = 0; j < COLUMNS; ++j) {
            cout << setw(6) << seatingChart[i][j] << " ";
        }
        cout << "\n";
    }
}

bool availableSeats(const string& s) {
    int r = s[1] - '1';
    int c = SEATS.find(s[0]);
    return seatingChart[r][c] == "Empty";
}

void assignment(const string& name, const string& s) {
    int r = s[1] - '1';
    int c = SEATS.find(s[0]);
    seatingChart[r][c] = name;
    manifest.push_back({name, s});
}

void manualSelection(const string& n) {
    string s;
    while (true) {
        cout << "Enter seat # (Example: C3): ";
        cin >> s;
        if (availableSeats(s)) {
            assignment(n, s);
            break;
        } else {
            cout << "Seat is already occupied. Please pick another: ";
        }
    }
}

void automaticSelection(const string& n, char classType) {
    int start, end;
    switch (classType) {
        case 'F':
            start = 0;
            end = 0;
            break;
        case 'B':
            start = 1;
            end = 3;
            break;
        default:
            start = 4;
            end = 11;
            break;
    }
    while (true) {
        int r = start + rand() % (end - start + 1);
        int c = rand() % COLUMNS;
        string s = SEATS[c] + to_string(r + 1);
        if (availableSeats(s)) {
            assignment(n, s);
            break;
        }
    }
}

void changeOrCancel(const string& n, const string& s) {
    for (auto i = manifest.begin(); i != manifest.end(); ++i) {
        if (i->n == n && i->s == s) {
            seatingChart[s[1] - '1'][SEATS.find(s[0])] = "Empty";
            manifest.erase(i);
            return;
        }
    }
    cout << "The information you have provided is invalid/incorrect.\n";
}

void printBoardingPass(const string& s) {
    for (const auto& passenger : manifest) {
        if (passenger.s == s) {
            string classType = (s[1] == '1') ? "First Class" :
                               (s[1] >= '2' && s[1] <= '4') ? "Business Class" : "Economy Class";
            cout << "Name: " << passenger.n << "\n"
                 << "Seat: " << passenger.s << "\n"
                 << "Class: " << classType << "\n";
            return;
        }
    }
    cout << "The information you have provided is invalid/incorrect.\n";
}

void saveManifest() {
    ofstream outFile("Manifest.txt");
    for (const auto& passenger : manifest) {
        outFile << passenger.n << " " << passenger.s << "\n";
    }
}

void loadOldManifest() {
    ifstream inFile("Manifest.txt");
    string n, s;
    while (inFile >> n >> s) {
        assignment(n, s);
    }
}

void printPassengerManifest() {
    cout << "Passenger Manifest:\n";
    cout << "Name       | Seat\n";
    cout << "------------------\n";
    for (const auto& passenger : manifest) {
        cout << setw(10) << passenger.n << " | " << passenger.s << "\n";
    }
}

bool login() {
    string user, pwd;
    cout << "Enter username: ";
    cin >> user;
    cout << "Enter password: ";
    cin >> pwd;
    return (user == USERNAME && pwd == PASSWORD);
}

int main() {
    loadOldManifest();
    char userType;
    cout << "Do you want to view the Passenger or Employee menu (type P or E): ";
    cin >> userType;

    if (tolower(userType) == 'e') {
        if (!login()) {
            cout << "The credentials you entered are either invalid or incorrect.\n";
            return 1;
        }
    }

    while (true) {
        if (tolower(userType) == 'p') {
            cout << "\nPassenger Menu:\n"
                 << "1. Display the seating chart\n"
                 << "2. Automated seat selection\n"
                 << "3. Manual seat selection\n"
                 << "4. Change or cancel your seat\n"
                 << "5. Print your boarding pass\n"
                 << "6. Quit\n";
            int option;
            cin >> option;
            switch (option) {
                case 1:
                    SeatingChart();
                    break;
                case 2: {
                    string n;
                    char classType;
                    cout << "Enter your name: ";
                    getline(cin, n);
                    cout << "Enter class (F/B/E): ";
                    cin >> classType;
                    automaticSelection(n, toupper(classType));
                    break;
                }
                case 3: {
                    string n;
                    cout << "Enter your name: ";
                    getline(cin, n);
                    manualSelection(n);
                    break;
                }
                case 4: {
                    string n, s;
                    cout << "Enter your name: ";
                    getline(cin, n);
                    cout << "Enter seat: ";
                    cin >> s;
                    changeOrCancel(n, s);
                    break;
                }
                case 5: {
                    string s;
                    cout << "Enter seat: ";
                    cin >> s;
                    printBoardingPass(s);
                    break;
                }
                case 6:
                    saveManifest();
                    return 0;
                default:
                    cout << "Invalid! Please try again.\n";
            }
        } else if (toupper(userType) == 'E') {
            cout << "\nEmployee Menu:\n"
                 << "1. Display the seating chart\n"
                 << "2. Print the passenger manifest\n"
                 << "3. Load the previous manifest\n"
                 << "4. Save the current manifest\n"
                 << "5. Change or cancel seat\n"
                 << "6. Quit\n";
            int option;
            cin >> option;
            switch (option) {
                case 1:
                    SeatingChart();
                    break;
                case 2:
                    printPassengerManifest();
                    break;
                case 3:
                    loadOldManifest();
                    break;
                case 4:
                    saveManifest();
                    break;
                case 5: {
                    string n, s;
                    cout << "Enter passenger name: ";
                    cin >> n;
                    cout << "Enter seat: ";
                    cin >> s;
                    changeOrCancel(n, s);
                    break;
                }
                case 6:
                    saveManifest();
                    return 0;
                default:
                    cout << "Invalid! Please try again.\n";
            }
        }
    }
}
