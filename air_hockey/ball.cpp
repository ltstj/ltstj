/* ball.cpp --- 
 * 
 * Filename: ball.cpp
 * Description: 
 * Author: Adeel Bhutta 
 * Maintainer: 
 * Created: Wed May 15 2024
 * Last-Updated: 
 *           By: 
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

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstdbool>
#include <ncurses.h>
#include "key.hpp"
#include "ball.hpp"

// Move the ball based on its speed
void moveBall(ball_t* b, zone_t* z, const slider_t* top_slider, const slider_t* bottom_slider){
    undraw_ball(b);

    int new_x = b->upper_left_x + b->speed_x * b->speed;
    int new_y = b->upper_left_y + b->speed_y * b->speed;

    // Check for collisions
    if (checkCollisionWithZone(b, z)) {
        // Handle collision with zone
    }
    if (checkCollisionSlider((slider_t*)top_slider, b) || checkCollisionSlider((slider_t*)bottom_slider, b)) {
        // Handle collision with sliders
    }

    // Update ball position
    b->upper_left_x = new_x;
    b->upper_left_y = new_y;

    draw_ball(b);
}


// Check if the ball collides with the slider.
// Change Y direction of the ball if it collides
bool checkCollisionSlider(slider_t *s, ball_t *b){
    if ((b->upper_left_y == s->upper_left_y && b->upper_left_x >= s->upper_left_x && b->upper_left_x <= s->upper_left_x + s->size) ||
        (b->upper_left_y == s->upper_left_y + s->size && b->upper_left_x >= s->upper_left_x && b->upper_left_x <= s->upper_left_x + s->size)) {
        b->speed_y = -b->speed_y;  // Reverse y direction
        return true;
    }
    return false;
}

// Check if the ball collides with the left walls of the zone.
// Change X direction of the ball if it collides
bool checkCollisionWithZone(ball_t *b, zone_t *z){
   bool collision = false;
    if (b->upper_left_x <= z->upper_left_x || b->upper_left_x >= z->lower_right_x) {
        b->speed_x = -b->speed_x;  
        collision = true;
    }
    if (b->upper_left_y <= z->upper_left_y || b->upper_left_y >= z->lower_right_y) {
        b->speed_y = -b->speed_y; 
        collision = true;
    }
    return collision;
}


// Inititialize ball with its position and speed in the X & Y directions
ball_t *init_ball(int upper_left_x, int upper_left_y, int speed_x, int speed_y, char color[3]) {
    ball_t *b;
    b = (ball_t *) malloc(sizeof(ball_t));
    b->draw_char = 'O';
    b->upper_left_x = upper_left_x;
    b->upper_left_y = upper_left_y;
    b->color[0] = 0;
    b->color[1] = 0;
    b->color[2] = 0;
    b->speed_x = 1;
    b->speed_y = 1;
    memcpy(b->color, color, sizeof(char) * 3);
    b->speed = 1;  
    return (b);
}



// Renders the ball on the screen
void draw_ball(ball_t *b){
    if (b->color[0] == 'r') {
        attron(COLOR_PAIR(1)); // Assuming 1 is red
    } else if (b->color[0] == 'g') {
        attron(COLOR_PAIR(2)); // Assuming 2 is green
    } else if (b->color[0] == 'b') {
        attron(COLOR_PAIR(3)); // Assuming 3 is blue
    }
    mvprintw(b->upper_left_y, b->upper_left_x, "%c", b->draw_char);
    attroff(COLOR_PAIR(1));
}

// Replaces the ball with blank space
void undraw_ball(ball_t *b){
    mvprintw(b->upper_left_y, b->upper_left_x," ",b->draw_char);
}
