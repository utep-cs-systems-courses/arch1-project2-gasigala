#include <msp430.h>
#include "buzzer.h"
#include "led.h"
#include "switches.h"
#include "buzzer_notes.h"
#include "state_machines.h"




// SWITCH 1
void play_song_1()
{
  static char curr_note = 0;
  static int  ledBool =0;
  // All notes of song, 0s are for break in between notes
  int notes[47] = {D5, A4, D5, A4, D5, A4, D5, B4_FLAT, D5, B4_FLAT, D5, B4_FLAT, D5, B4_FLAT,A4, A3, D4, C4_SHARP, D4, E4, F4_SHARP, D4, D4, C4_SHARP, C4_SHARP, B3, D4, D4, D4, E4, D4, D4, D4, 0, 0, G4, G4, F4_SHARP, D4, D4, D4, A3, D4, C4_SHARP, D4, E4, F4_SHARP };
  int n = 47;

  if (curr_note < n){
      buzzer_set_period(notes[curr_note]);
      curr_note++;
      if(ledBool){
	swap_leds(ledBool);
	ledBool =0;
      }
      else{
	swap_leds(ledBool);
	ledBool =1;
      }
	
  }
  else {
    curr_note = 0;
  }
  
}
