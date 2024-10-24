/* zone.cpp --- 
 * 
 * Filename: zone.cpp
 * Description: 
 * Author: Adeel Bhutta 
 * Maintainer: 
 * Created: Wed May 15 2024
 * Last-Updated: Tejadatta Kalapatapu
 *           By: Tue May 28 2024
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
#include "zone.hpp"
#include <vector>
#include <ncurses.h>
#include <cstdio>
#include <ctime>
#include <cstdlib>

// Initializes zone position and dimensions
zone_t *init_zone(int upper_left_x, int upper_left_y, int width, int height) {
  zone_t *z;
  z = (zone_t *) malloc(sizeof(zone_t));
  z->upper_left_x = upper_left_x + 10;    // added 10 to create some space on the left side of the zone to display messages
  z->upper_left_y = upper_left_y;
  z->lower_right_x = COLS - 1;
  z->lower_right_y = LINES - 1;
  z->width = width-10;
  z->height = height;
  z->draw_char = '#';
  z->color[0] = 0;
  z->color[1] = 0;
  z->color[2] = 0;
  z->goal_top_width = COLS; 
  z->goal_bottom_width = COLS; 
  return (z);
}


// Renders zone on the screen
void draw_zone(zone_t *z) {
  for (int x = z->upper_left_x; x <= z->lower_right_x; ++x) {
        mvprintw(z->upper_left_y, x, "-");
        mvprintw(z->lower_right_y, x, "-");
  }
  for (int y = z->upper_left_y; y <= z->lower_right_y; ++y) {
        mvprintw(y, z->upper_left_x, "|");
        mvprintw(y, z->lower_right_x, "|");
  }
  for (const auto& obstacle : z->obstacles) {
        mvprintw(obstacle.second, obstacle.first, "X");
  }
}

// Replaces the zone boundary with blank spaces
void undraw_zone(zone_t *z) {
  for (int x = z->upper_left_x; x <= z->lower_right_x; ++x) {
        mvprintw(z->upper_left_y, x, " ");
        mvprintw(z->lower_right_y, x, " ");
  }
  for (int y = z->upper_left_y; y <= z->lower_right_y; ++y) {
        mvprintw(y, z->upper_left_x, " ");
        mvprintw(y, z->lower_right_x, " ");
  }
  for (const auto& obstacle : z->obstacles) {
        mvprintw(obstacle.second, obstacle.first, " ");
  }
}
