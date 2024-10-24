/* air_hockey.cpp --- 
 * 
 * Filename: air_hockey.cpp
 * Description: 
 * Author: Adeel Bhutta 
 * Maintainer: 
 * Created: Wed May 15 2024
 * Last-Updated: Tue May 28 2024
 *           By: Tejadatta Kalapatapu
 *     Update #: 0
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Copyright (c) 2016 Adeel Bhutta
 * 
 * All rights reserved. 
 * 
 * Additional copyrights may follow 
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ncurses.h>
#include "air_hockey.hpp"
#include "slider.hpp"
#include "ball.hpp"
#include "zone.hpp"
#include "key.hpp"

// Constants
#define MAX_SCORE_ENTRIES 10

// Function to save the best scores to a file
void save_best_scores(const std::vector<int>& scores) {
    std::ofstream file("./saves/save_best_10.game");
    for (const auto& score : scores) {
        file << score << std::endl;
    }
    file.close();
}

// Function to load the best scores from a file
std::vector<int> load_best_scores() {
    std::vector<int> scores;
    std::ifstream file("./saves/save_best_10.game");
    int score;
    while (file >> score) {
        scores.push_back(score);
    }
    file.close();
    return scores;
}

// Function to update the best scores
void update_best_scores(std::vector<int>& scores, int new_score) {
    scores.push_back(new_score);
    std::sort(scores.rbegin(), scores.rend());
    if (scores.size() > MAX_SCORE_ENTRIES) {
        scores.resize(MAX_SCORE_ENTRIES);
    }
    save_best_scores(scores);
}

// Function to set up the goal area
void setup_goal_area(zone_t* zone) {
    int goal_width;
    std::cout << "Enter the width of the goal area (less than the width of the zone): ";
    std::cin >> goal_width;
    // Set the goal areas at the top and bottom of the zone
    zone->goal_top_width = goal_width;
    zone->goal_bottom_width = goal_width;
}

// Function to handle difficulty levels, obstacles, and speeds
void setup_difficulty_levels(zone_t* zone, ball_t* ball) {
    int level;
    std::cout << "Enter the difficulty level (1 to 3): ";
    std::cin >> level;
    switch (level) {
        case 1:
            ball->speed = 1; // Low speed
            break;
        case 2:
            ball->speed = 2; // Medium speed
            // Add obstacles
            zone->obstacles.push_back({10, 10});
            zone->obstacles.push_back({20, 20});
            break;
        case 3:
            ball->speed = 3; // High speed
            // Add more obstacles
            zone->obstacles.push_back({10, 10});
            zone->obstacles.push_back({20, 20});
            zone->obstacles.push_back({30, 30});
            break;
        default:
            ball->speed = 1;
    }
}

int air_hockey_main() {
    initscr();
    start_color();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    timeout(100);

    int rounds;
    std::cout << "Enter the number of rounds: ";
    std::cin >> rounds;

    zone_t* zone = init_zone(15, 15, 15, 15);
    char ball_color[3] = {'r', 'g', 'b'};
    ball_t* ball = init_ball(zone->width / 2, zone->height / 2, 1, 1, ball_color);
    slider_t* top_slider = init_slider(zone->width / 2, 1, 'T', 4, ball_color);
    slider_t* bottom_slider = init_slider(zone->width / 2, zone->height - 2, 'B', 4, ball_color);

    setup_goal_area(zone);
    setup_difficulty_levels(zone, ball);

    int top_score = 0;
    int bottom_score = 0;

    for (int i = 0; i < rounds; ++i) {
        while (true) {
            int ch = getch();
            if (ch == 'q' || ch == 'Q') {
                endwin();
                return 0;
            }

            // Handle slider input
            handle_slider_input(top_slider, ch, zone->height / 2);
            handle_slider_input(bottom_slider, ch, zone->height / 2);

            // Move the ball and check for collisions
            moveBall(ball, zone, top_slider, bottom_slider);

            // Check for goals and update scores
            if (ball->speed_y<= 0) {
                bottom_score++;
                break;
            } else if (ball->speed_y >= zone->height - 1) {
                top_score++;
                break;
            }

            // Draw everything
            draw_zone(zone);
            draw_slider(top_slider);
            draw_slider(bottom_slider);
            draw_ball(ball);

            refresh();
        }
    }

    endwin();

    std::vector<int> scores = load_best_scores();
    update_best_scores(scores, top_score);
    update_best_scores(scores, bottom_score);

    return 0;
}
