#include "lcd_z.h"

int main()
{
  NVIC_ST_CTRL_R=0;
  NVIC_ST_RELOAD_R=0x04c4b400;
  NVIC_ST_CURRENT_R=0;
  NVIC_ST_CTRL_R=0x00000005;
  init_lcd();
  while(1)
  {
    lcd_clr();
    delay(0x04c4b400);
    set_cursor(1,0);
    write_string("RUMY TECHNOLOGY");
    for(int i=0;i<4;i++) delay(0x04c4b400);
    lcd_clr();
    delay(0x04c4b400);
    set_cursor(5,0);
    write_string("--RUMY--");
    for(int i=0;i<2;i++) delay(0x04c4b400);
    set_cursor(3,1);
    write_string("TECHNOLOGY");
    for(int i=0;i<4;i++) delay(0x04c4b400);
    
  }
  return 0;
}
