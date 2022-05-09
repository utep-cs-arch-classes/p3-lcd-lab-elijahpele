#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"
#include "switches.h"
#include "buzzer.h"

// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!! 
u_int backgroundColor = COLOR_PINK;
 
void main(void)
{
  configureClocks();
  lcd_init();
  switch_init();
  buzzer_init();
  clearScreen(backgroundColor);
  init_circle();
  init_unique_shape();
  draw_triangle();
  drawRectOutline(0,0,127,159,COLOR_PURPLE);
  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);	              /**< GIE (enable interrupts) */
  

}
// while (1) {	  		/* forever */
//  if (redrawScreen) {
//    redrawScreen = 0;
//    draw_moving_circle();
//     }
  
      // green_on = 0;   	/* led off */
      // led_changed = 1;
      // led_update();
      // or_sr(0x10);	/**< CPU OFF */
    //green_on = 1;	/* led on */
    //led_changed = 1;
    //led_update();
// }
//}

   
