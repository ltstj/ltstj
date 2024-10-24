// Properties of the slider
typedef struct slider {
  char type_str[7];
  char piece[1][4];             
  int upper_left_x;
  int upper_left_y;
  int size;
  char draw_char;
  char color[3];
} slider_t;


slider_t *init_slider(int initial_x, int initial_y, char type, int size, char color[3]);
void draw_slider(slider_t *s);
void undraw_slider(slider_t *s);
void moveSlider(slider_t *s, int x, int y);
void handle_slider_input(slider_t *slider, int ch, int centerline); 
