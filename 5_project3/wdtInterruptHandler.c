#include <msp430.h>
#include "libTimer.h"
#include "draw_shapes.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "switches.h"
#include "buzzer.h"
#include "stateMachine.h"

// function that handles interrupts
// from the periodic timer
// The timer fires an event 250 times/sec
extern u_int circle_color;
void
__interrupt_vec(WDT_VECTOR) WDT()
{
  const  u_int second_limit = 250;
  static u_int second_count = 0;
  static u_int button_counter = 0;
  static u_int slow_counter = 0;
  // drawRectOutline(0, 0, 127, 159, COLOR_RED);
  second_count++;

  if(switch4_down){button_counter++;}
  
  if (button_counter == 0) {
    char c = 'E';
    drawChar5x7(110, 140,c, COLOR_BLACK, COLOR_PINK); 
  }
  
  if (button_counter == 1) {
    char c = 'P';
      drawChar5x7(110, 140,c, COLOR_BLACK, COLOR_PINK); 
  }
  if(button_counter == 2){button_counter=0;}
 
  if (second_count >= second_limit) {
	second_count = 0;
	draw_moving_circle();
	draw_moving_thing();
	slow_counter++;
	//buzzer_set_period(100);
  }
  
  switch(slow_counter){
  case(10):
    runS1();
    break;
  
  case(11):
    slow_counter = 0;
    break; 
    
  default:
    runS2();
  }
}
