
#include "lm4f120h5qr.h"
#include "lcd_z.h"
#define MODE_WRITE_CMD 0x80
#define MODE_WRITE_CHAR 0xc0
#define MODE_CLEAR 0x00
#define D_TIME 1000

void delay(unsigned int delay)
{
  unsigned int time=0;
  unsigned int current_t=NVIC_ST_CURRENT_R;
  for(unsigned int time=(current_t-(unsigned int)NVIC_ST_CURRENT_R);time<=delay;time=(current_t-(unsigned int)NVIC_ST_CURRENT_R)) {}
  
}

void init_lcd()
{
  SYSCTL_RCGC2_R |= 0x00000003;
  GPIO_PORTB_DIR_R = 0xFF;       
  GPIO_PORTA_DIR_R |= 0xC0;
  GPIO_PORTB_DEN_R = 0xFF;       
  GPIO_PORTA_DEN_R |= 0xFF;
  GPIO_PORTA_DATA_R=0x00;
  lcd_clr();
  delay(D_TIME);  
  write_cmd(0x30);       
  delay(D_TIME); 
  delay(D_TIME); 
  write_cmd(0x38);         
  write_cmd(0x10);         
  write_cmd(0x0C);        
  write_cmd(0x06);  
  delay(D_TIME);
  
}

void write_cmd(uint8_t cmd)
{
  
  GPIO_PORTB_DATA_R=cmd;
  GPIO_PORTA_DATA_R=MODE_CLEAR;           
  delay(D_TIME);   
  GPIO_PORTA_DATA_R=MODE_WRITE_CMD;            
  delay(D_TIME); 
  GPIO_PORTA_DATA_R=MODE_CLEAR;         
  delay(D_TIME);
}

void write_data(uint8_t data)
{
  
GPIO_PORTB_DATA_R=data;
  GPIO_PORTA_DATA_R=MODE_CLEAR;           
  delay(D_TIME);   
  GPIO_PORTA_DATA_R=MODE_WRITE_CHAR;            
  delay(D_TIME); 
  GPIO_PORTA_DATA_R=MODE_CLEAR;         
  delay(D_TIME);
}

void write_string(char* string)
{
  //lcd_clr();
  int i=0;
  while(string[i])
  {
    write_data(string[i++]);
    delay(100000);
    
  }
}
void lcd_clr(void){
  write_cmd(0x01);          
  delay(D_TIME); 
  write_cmd(0x02);          
  delay(D_TIME); 
}

void set_cursor(int x, int y)
{
  //write_cmd(0x01);
  //delay(1000);
  //write_cmd(0x02);
  //delay(1000);
  if(y==1) write_cmd(0xc0);
  delay(1000);
  for(int i=0;i<x;i++){
    write_cmd(0x14);
    delay(1000);
  }
}
void latch()
{
  GPIO_PORTA_DATA_R=0x80;
  delay(D_TIME);
  GPIO_PORTA_DATA_R=0x00;
  delay(D_TIME);
  
}