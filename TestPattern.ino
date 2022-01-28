#include <Gamebuino-Meta.h>

#include "PatternDefs.h"

#define DUR 8 // DURation unit set to 8 screen frames

const uint16_t u16_pattern_1[] = { // fundamental
  PATTERN_NOTE( DO, DUR*1 ),
  PATTERN_NOTE( DO, DUR*1 ),
  PATTERN_NOTE( DO, DUR*1 ),
  PATTERN_NOTE( RE, DUR*1 ),
  PATTERN_NOTE( MI, DUR*2 ),
  PATTERN_NOTE( RE, DUR*2 ),

  PATTERN_NOTE( DO, DUR*1 ),
  PATTERN_NOTE( MI, DUR*1 ),
  PATTERN_NOTE( RE, DUR*1 ),
  PATTERN_NOTE( RE, DUR*1 ),
  PATTERN_NOTE( DO, DUR*4 )
};

const uint16_t u16_pattern_3[] = {  // third : +5 half tones
  PATTERN_NOTE( DO+5, DUR*1 ),
  PATTERN_NOTE( DO+5, DUR*1 ),
  PATTERN_NOTE( DO+5, DUR*1 ),
  PATTERN_NOTE( RE+5, DUR*1 ),
  PATTERN_NOTE( MI+5, DUR*2 ),
  PATTERN_NOTE( RE+5, DUR*2 ),

  PATTERN_NOTE( DO+5, DUR*1 ),
  PATTERN_NOTE( MI+5, DUR*1 ),
  PATTERN_NOTE( RE+5, DUR*1 ),
  PATTERN_NOTE( RE+5, DUR*1 ),
  PATTERN_NOTE( DO+5, DUR*4 )
};

const uint16_t u16_pattern_5[] = {  // fifth : +7 halt tones
  PATTERN_NOTE( DO+7, DUR*1 ),
  PATTERN_NOTE( DO+7, DUR*1 ),
  PATTERN_NOTE( DO+7, DUR*1 ),
  PATTERN_NOTE( RE+7, DUR*1 ),
  PATTERN_NOTE( MI+7, DUR*2 ),
  PATTERN_NOTE( RE+7, DUR*2 ),

  PATTERN_NOTE( DO+7, DUR*1 ),
  PATTERN_NOTE( MI+7, DUR*1 ),
  PATTERN_NOTE( RE+7, DUR*1 ),
  PATTERN_NOTE( RE+7, DUR*1 ),
  PATTERN_NOTE( DO+7, DUR*4 )
};

const uint16_t u16_pattern_12[] = { // octave : + 12 half tones
  PATTERN_NOTE( DO+12, DUR*1 ),
  PATTERN_NOTE( DO+12, DUR*1 ),
  PATTERN_NOTE( DO+12, DUR*1 ),
  PATTERN_NOTE( RE+12, DUR*1 ),
  PATTERN_NOTE( MI+12, DUR*2 ),
  PATTERN_NOTE( RE+12, DUR*2 ),

  PATTERN_NOTE( DO+12, DUR*1 ),
  PATTERN_NOTE( MI+12, DUR*1 ),
  PATTERN_NOTE( RE+12, DUR*1 ),
  PATTERN_NOTE( RE+12, DUR*1 ),
  PATTERN_NOTE( DO+12, DUR*4 )
};

void setup() {
  // put your setup code here, to run once:
  gb.begin();
}

const char* pcLegend[] = { "Fundamental", "Third      ", "Fifth      ", "Octave     " };
const char* pcONOFF[] = { "dis", "ENA" };
uint8_t u8_config[] = {1, 0, 0, 0};
uint8_t u8_cursor = 0;


void loop() {
    // configuration use PAD to enable/disable
  if (gb.buttons.pressed(BUTTON_UP))    u8_cursor+=3;
  if (gb.buttons.pressed(BUTTON_DOWN))  u8_cursor++;
  u8_cursor %=4;

  if (gb.buttons.pressed(BUTTON_B))
    for ( uint8_t i = 0 ; i < 4 ; i++ )
      gb.sound.stop(i); // stop all channels
      
    // change on/off fro tracks
  if (gb.buttons.pressed(BUTTON_RIGHT))  u8_config[u8_cursor] = 1;
  if (gb.buttons.pressed(BUTTON_LEFT))  u8_config[u8_cursor] = 0;
    // sound play
  if (gb.buttons.pressed(BUTTON_A))
  {
    if ( u8_config[0] ) gb.sound.play( u16_pattern_1 ); // fundamental
    if ( u8_config[1] ) gb.sound.play( u16_pattern_3 ); // third
    if ( u8_config[2] ) gb.sound.play( u16_pattern_5 ); // quinte
    if ( u8_config[3] ) gb.sound.play( u16_pattern_12 ); // octave
  }
    // display
  gb.display.clear();
  for ( uint8_t i = 0 ; i < 4 ; i++ )
    gb.display.printf( "%c %s %s\n", u8_cursor==i?16:' ', pcLegend[i], pcONOFF[u8_config[i]] );

    gb.display.print( "\nA : PLAY | B : STOP\n" );
    for ( uint8_t i = 0 ; i < 4 ; i++ )
      gb.display.printf( "ch%d is %s\n", i, gb.sound.isPlaying(i)?"Playing":"Idle"  );

  while(!gb.update());
}


