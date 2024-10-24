/* slider.cpp --- 
 * 
 * Filename: slider.cpp
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
#include "slider.hpp"
#include <ncurses.h>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>

// This intializes the properties of the slider
const slider_t slider_types[2] = {
    {
        "top",
        {{1,1,1,1}}, 
        0,
        0,
        4,
        '%',
        {0,0,0}
    },
    {
        "bottom",
        {{1,1,1,1}}, 
        0,
        0,
        4,
        '+',
        {0,0,0}
    },
};

// Changes the location of the slider
void moveSlider(slider_t *s, int x, int y) {
    undraw_slider(s);
    s->upper_left_x = x;
    s->upper_left_y = y;
    draw_slider(s);
}

// Intializes the slider
slider_t *init_slider (int initial_x, int initial_y, char type, int size, char color[3]) {
  slider_t *s = (slider *) malloc(sizeof(slider_t));
  if (type == 'T'){
      memcpy(s, &slider_types[0], sizeof(slider_t));
  }
  else
  {
      memcpy(s, &slider_types[1], sizeof(slider_t));
  }
  
  s->size = size;
  s->upper_left_x = initial_x;
  s->upper_left_y = initial_y;
  return(s);
}


// Renders the slider on the screen
void draw_slider(slider_t *s){
  int color_pair = atoi(s->color); 
  attron(COLOR_PAIR(color_pair));
    for (int i = 0; i < s->size; i++) {
        mvprintw(s->upper_left_y + i, s->upper_left_x, "%c", s->draw_char);
    }
    attroff(COLOR_PAIR(color_pair));
}

// Replaces the slider with blank spaces
void undraw_slider(slider_t *s){
  for (int i = 0; i < s->size; i++) {
        mvprintw(s->upper_left_y + i, s->upper_left_x, " ");
  }
}

void handle_slider_input(slider_t *slider, int ch, int centerline) {
    switch(ch) {
        case KEY_UP:
            if (slider->upper_left_y > 1 && slider->upper_left_y + slider->size / 2 < centerline) {
                moveSlider(slider, slider->upper_left_x, slider->upper_left_y - 1);
            }
            break;
        case KEY_DOWN:
            if (slider->upper_left_y + slider->size < LINES - 1 && slider->upper_left_y + slider->size / 2 < centerline) {
                moveSlider(slider, slider->upper_left_x, slider->upper_left_y + 1);
            }
            break;
        case KEY_LEFT:
            if (slider->upper_left_x > 1) {
                moveSlider(slider, slider->upper_left_x - 1, slider->upper_left_y);
            }
            break;
        case KEY_RIGHT:
            if (slider->upper_left_x < COLS - 2) {
                moveSlider(slider, slider->upper_left_x + 1, slider->upper_left_y);
            }
            break;
        case 'w':
        case 'W':
            if (slider->upper_left_y > centerline && slider->upper_left_y + slider->size / 2 < LINES - 1) {
                moveSlider(slider, slider->upper_left_x, slider->upper_left_y - 1);
            }
            break;
        case 's':
        case 'S':
            if (slider->upper_left_y + slider->size < LINES - 1 && slider->upper_left_y > centerline) {
                moveSlider(slider, slider->upper_left_x, slider->upper_left_y + 1);
            }
            break;
        case 'a':
        case 'A':
            if (slider->upper_left_x > 1) {
                moveSlider(slider, slider->upper_left_x - 1, slider->upper_left_y);
            }
            break;
        case 'd':
        case 'D':
            if (slider->upper_left_x < COLS - 2) {
                moveSlider(slider, slider->upper_left_x + 1, slider->upper_left_y);
            }
            break;
        default:
            break;
    }
}