// This structure holds the properties of the zone such as position and dimesions
#include <vector>
typedef struct zone {
  int upper_left_x;
  int upper_left_y;
  int lower_right_x, lower_right_y;
  int width;
  int height;
  char draw_char;
  char color[3];
  int goal_top_width;
  int goal_bottom_width;
  std::vector<std::pair<int, int>> obstacles;
} zone_t;


void undraw_zone(zone_t *z);
void draw_zone(zone_t *z);
zone_t *init_zone(int upper_left_x, int upper_left_y, int width, int height);