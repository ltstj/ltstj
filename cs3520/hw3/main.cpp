#include "student.hpp"
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    unordered_map<string, Student> students;
    string filename;
    int teamSize;
    bool prioritizePreferences;

    cout << "Enter the CSV file name: ";
    cin >> filename;
    cout << "Enter team size (3 or 4): ";
    cin >> teamSize;
    cout << "Prioritize student preferences over skill balance? (1 for yes, 0 for no): ";
    cin >> prioritizePreferences;

    readCSV(filename, students);
    vector<vector<string>> teams = formTeams(students, teamSize, prioritizePreferences);

    cout << "Formed Teams:" << endl;
    printTeams(teams);

    cout << "Team Scores:" << endl;
    calculateTeamScores(students, teams);

    return 0;
}
