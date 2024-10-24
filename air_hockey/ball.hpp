#include "zone.hpp"
#include "slider.hpp"

// ball_t holds all properties of the ball
typedef struct ball {
  int upper_left_x;
  int upper_left_y;
  int speed_x;
  int speed_y;
  int speed;
  char draw_char;
  char color[3];
} ball_t;

ball_t *init_ball(int upper_left_x, int upper_left_y, int speed_x, int speed_y, char color[3]);
void draw_ball(const ball_t *b);
void undraw_ball(const ball_t *b);
bool checkCollisionWithZone(ball_t *b, zone_t *z);
bool checkCollisionSlider(slider_t *s, ball_t *b);
void moveBall(ball_t* b, zone_t* z, const slider_t* top_slider, const slider_t* bottom_slider);
