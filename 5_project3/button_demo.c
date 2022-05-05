#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"
#include "switches.h"
#include "buzzer.h"

// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!! 
u_int backgroundColor = COLOR_WHITE;
 
/*void
update_text(void)
{
  const u_char text_row = 20;
  const u_char text_col = 40;
  const u_char char_width = 12;
  static u_char blue = 31, green = 16, red = 31;
  u_int on_color  =                (green << 5) | red;
  u_int off_color = (blue << 11)                | red;
  
  if (switch1_state == down) {
    drawChar5x7(text_col, text_row, '1',on_color, backgroundColor);
  } else {
    drawChar5x7(text_col, text_row, '-',off_color, backgroundColor);
  }
  if (switch2_state == down) {
    drawChar5x7(text_col + char_width, text_row, '2',on_color, backgroundColor);
  } else {
    drawChar5x7(text_col + char_width, text_row, '-',off_color, backgroundColor);
  }

}*/

void main(void)
{
  configureClocks();
  lcd_init();
  switch_init();
  buzzer_init();
  clearScreen(backgroundColor);
  init_circle();
  draw_triangle();
  drawRectOutline(0,0,127,159,COLOR_RED);
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

   