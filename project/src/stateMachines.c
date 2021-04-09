#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

char toggle_red()		/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

//turn on red turn off green
void turnOnRed()
{
  red_on = 1;
  green_on = 0;
  led_update();
}

//turn on green turn off red 
void turnOnGreen()
{
  green_on = 1;
  red_on = 0;
  led_update();
}

//turn off led and buzzer
void turnOffAll()
{
  buzzer_set_period(0);
  red_on = 0;
  green_on = 0;
  led_update();
}
char toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}

void toggle_leds()
{
  buzzer_set_period(1000);
  static char state = 0;
  switch(state){
  }
}

void buzzer_noise(){
 
}
  
void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;  

  static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }

  led_changed = changed;
  led_update();
}



