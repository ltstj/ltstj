#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

struct Student {
    std::string username;
    int programming;
    int debugging;
    int design;
    std::vector<std::string> do_not_work_with;
    std::vector<std::string> want_to_work_with;
};

// Function prototypes
void readCSV(const string &filename, unordered_map<string, Student> &students);
vector<vector<string>> formTeams(const unordered_map<string, Student> &students, int teamSize, bool prioritizePreferences);
void calculateTeamScores(const unordered_map<string, Student> &students, const vector<vector<string>> &teams);
void printTeams(const vector<vector<string>> &teams);
int experienceLevelToInt(const string &level);