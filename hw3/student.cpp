#include "student.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int experienceLevelToInt(const string &level) {
    if (level == "Beginner") return 1;
    if (level == "Intermediate") return 2;
    if (level == "Advanced") return 3;
    throw invalid_argument("Invalid experience level: " + level);
}

void readCSV(const string &filename, unordered_map<string, Student> &students) {
    ifstream file(filename);
    string line, word;
    getline(file, line); // Skip the header line
    while (getline(file, line)) {
        stringstream ss(line);
        Student student;
        getline(ss, student.username, ',');
        try {
            getline(ss, word, ','); student.programming = experienceLevelToInt(word);
            getline(ss, word, ','); student.debugging = experienceLevelToInt(word);
            getline(ss, word, ','); student.design = experienceLevelToInt(word);
        } catch (const invalid_argument &e) {
            cerr << "Invalid data in CSV file: " << e.what() << " in line: " << line << endl;
            continue; // Skip this line and move to the next
        }
        getline(ss, word, ','); 
        stringstream ss2(word);
        while (getline(ss2, word, ';')) student.do_not_work_with.push_back(word);
        getline(ss, word, ','); 
        stringstream ss3(word);
        while (getline(ss3, word, ';')) student.want_to_work_with.push_back(word);
        students[student.username] = student;
    }
}

vector<vector<string>> formTeams(const unordered_map<string, Student> &students, int teamSize, bool prioritizePreferences) {
    vector<vector<string>> teams;
    set<string> assigned;

    for (const auto &entry : students) {
        const Student &student = entry.second;
        if (assigned.find(student.username) != assigned.end()) continue;

        vector<string> team;
        team.push_back(student.username);
        assigned.insert(student.username);

        if (prioritizePreferences) {
            for (const string &preferred : student.want_to_work_with) {
                if (team.size() >= teamSize) break;
                if (students.find(preferred) != students.end() && assigned.find(preferred) == assigned.end()) {
                    team.push_back(preferred);
                    assigned.insert(preferred);
                }
            }
        }

        for (const auto &entry2 : students) {
            if (team.size() >= teamSize) break;
            const Student &s = entry2.second;
            if (assigned.find(s.username) == assigned.end() && 
                find(student.do_not_work_with.begin(), student.do_not_work_with.end(), s.username) == student.do_not_work_with.end()) {
                team.push_back(s.username);
                assigned.insert(s.username);
            }
        }

        teams.push_back(team);
    }

    return teams;
}

void calculateTeamScores(const unordered_map<string, Student> &students, const vector<vector<string>> &teams) {
    for (size_t i = 0; i < teams.size(); ++i) {
        int programmingScore = 0, debuggingScore = 0, designScore = 0;
        for (const string &username : teams[i]) {
            programmingScore += students.at(username).programming;
            debuggingScore += students.at(username).debugging;
            designScore += students.at(username).design;
        }
        cout << "Team " << i + 1 << ": Programming = " << programmingScore
             << ", Debugging = " << debuggingScore << ", Design = " << designScore << endl;
    }
}

void printTeams(const vector<vector<string>> &teams) {
    for (size_t i = 0; i < teams.size(); ++i) {
        cout << "Team " << i + 1 << ": ";
        for (const string &username : teams[i]) {
            cout << username << " ";
        }
        cout << endl;
    }
}