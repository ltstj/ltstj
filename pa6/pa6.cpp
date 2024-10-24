//Tejadatta Kalapatapu
//CS 3520 Summer 1

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct tv_series {
    char* series_name;
    int first_release_year;
    int first_release_month;
    
    struct tv_episode {
        char episode_name[30];
        int episode_number;
        string episode_release_date;
        double episode_rating;
    };
    
    struct {
        int season_number;
        tv_episode episodes[7];
    } seasons[3], *seasons_ptr;
} some_tv_series, *ptr_some_tv_series = &some_tv_series;

struct tv_series_dynamic {
    char* series_name;
    int first_release_year;
    int first_release_month;
    
    struct tv_episode {
        char episode_name[30];
        int episode_number;
        string episode_release_date;
        double episode_rating;
    };
    
    struct tv_season {
        int season_number;
        tv_episode* episodes;
    };
    
    tv_season* seasons;
} *dyn_tv_series;

void create_static() {
    some_tv_series.series_name = (char*)"A Normal Show";
    some_tv_series.first_release_year = 2020;
    some_tv_series.first_release_month = 1;

    for (int i = 0; i < 3; ++i) {
        some_tv_series.seasons[i].season_number = i + 1;
        for (int j = 0; j < 7; ++j) {
            strcpy(some_tv_series.seasons[i].episodes[j].episode_name, ("Episode " + to_string(j + 1)).c_str());
            some_tv_series.seasons[i].episodes[j].episode_number = j + 1;
            some_tv_series.seasons[i].episodes[j].episode_release_date = "2020-0" + to_string(i + 1) + "-" + to_string(10 + j);
            some_tv_series.seasons[i].episodes[j].episode_rating = 8.0 + (j * 0.1);
        }
    }
}

void display_static() {
    cout << "Static Allocation:\n" << endl;
    cout << "Show Name: " << some_tv_series.series_name << endl;
    cout << "Release Year: " << some_tv_series.first_release_year << endl;
    cout << "Release Month: " << some_tv_series.first_release_month << endl;

    for (int i = 0; i < 3; ++i) {
        cout << "Season " << some_tv_series.seasons[i].season_number << endl;
        for (int j = 0; j < 7; ++j) {
            cout << "  Episode " << some_tv_series.seasons[i].episodes[j].episode_number << ": ";
            cout << some_tv_series.seasons[i].episodes[j].episode_name << " ";
            cout << some_tv_series.seasons[i].episodes[j].episode_release_date << " ";
            cout << some_tv_series.seasons[i].episodes[j].episode_rating << endl;
        }
    }
}

void create_dynamic() {
    dyn_tv_series = new tv_series_dynamic;
    dyn_tv_series->series_name = (char*)"A Not Normal Show";
    dyn_tv_series->first_release_year = 2020;
    dyn_tv_series->first_release_month = 1;
    
    dyn_tv_series->seasons = new tv_series_dynamic::tv_season[3];
    for (int i = 0; i < 3; ++i) {
        dyn_tv_series->seasons[i].season_number = i + 1;
        dyn_tv_series->seasons[i].episodes = new tv_series_dynamic::tv_episode[7];
        for (int j = 0; j < 7; ++j) {
            strcpy(dyn_tv_series->seasons[i].episodes[j].episode_name, ("Episode " + to_string(j + 1)).c_str());
            dyn_tv_series->seasons[i].episodes[j].episode_number = j + 1;
            dyn_tv_series->seasons[i].episodes[j].episode_release_date = "2020-0" + to_string(i + 1) + "-" + to_string(10 + j);
            dyn_tv_series->seasons[i].episodes[j].episode_rating = 8.0 + (j * 0.1);
        }
    }
}

void display_dynamic() {
    cout << "Dynamic Allocation:\n" << endl;
    cout << "Show Name: " << dyn_tv_series->series_name << endl;
    cout << "Release Year: " << dyn_tv_series->first_release_year << endl;
    cout << "Release Month: " << dyn_tv_series->first_release_month << endl;

    for (int i = 0; i < 3; ++i) {
        cout << "Season " << dyn_tv_series->seasons[i].season_number << endl;
        for (int j = 0; j < 7; ++j) {
            cout << "  Episode " << dyn_tv_series->seasons[i].episodes[j].episode_number << ": ";
            cout << dyn_tv_series->seasons[i].episodes[j].episode_name << " ";
            cout << dyn_tv_series->seasons[i].episodes[j].episode_release_date << " ";
            cout << dyn_tv_series->seasons[i].episodes[j].episode_rating << endl;
        }
    }
}

int main() {
    //part b
    create_static();
    display_static();
    cout << " " << endl;
    //part c
    create_dynamic();
    display_dynamic();
}
