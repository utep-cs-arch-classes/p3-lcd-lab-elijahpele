#ifndef _DRAW_SHAPES_H_
#define _DRAW_SHAPES_H_

#include <lcdutils.h>

extern short redrawScreen;

typedef struct rect_st {
  int rect_row;
  int rect_col;
  int old_rect_row;
  int old_rect_col;
  u_char height;
  u_char width;
} rectangle;

typedef struct cir_st {
  int cir_x;
  int cir_y;
  int old_cir_x;
  int old_cir_y;
  int r;
} circle;

typedef struct thing_st{
  int x;
  int y;
  int old_x;
  int old_y;
} thing;

extern u_int background_color;
u_int circle_color;
/* initializes shape positions */
void init_shapes(void);

void moving_thing(void);
void draw_moving_thing(void);

void init_unique_shape(void);

/*initialized circle position*/
void init_circle(void);

/* handles erasing and updating all the shapes */
void draw_moving_shapes(void);

/*handles erasing and updating the circle shape */
void draw_moving_circle(void);

/* handles a single rectangle, updates its 
   position and draws it at its new location */
void moving_rectangle(rectangle* to_draw);

/* handles a single circle, updates its 
   position and draws it at its new location */
void moving_circle(void);

/* draws a rectangle */
void draw_rectangle(void);

/*draws a thing */
void draw_thing(void);

/* draws a triangle */
void draw_triangle(void);

/* draws a circle with the given parameters */
void draw_circle(int x, int y, int r, u_int color);

#endif // _DRAW_SHAPES_H_
