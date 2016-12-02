// vim: set sw=4 sts=4 si:

#include <FastLED.h>

#define NUM_LEDS 50
#define DATA_PIN 11
#define FRAMES_PER_SECOND 60
#define BRIGHTNESS 100
bool gReverseDirection = false;

CRGB leds[ NUM_LEDS ];

void setup( void ) {
    delay( 3000 );
    FastLED.addLeds< WS2811, DATA_PIN, RGB >( leds, NUM_LEDS );
    FastLED.setBrightness( BRIGHTNESS ); 
}

byte current_led = 0;
byte pattern     = 0;

void loop( void ) {

    fire2012();

    FastLED.show();
    delay( 1000 / FRAMES_PER_SECOND );
}

void setcol( char col, CRGB colour ) {
    col = col % 7;
    for( char row = 0; row < 7; row++ )
	leds[ 7 * row + col ] = colour;
}
void fadeall( byte scale ) {
    for ( char led = 0; led < 49; led++ )
	leds[ led ].fadeToBlackBy( scale );
}
void fadecol( char col, byte scale ) {
    col = col % 7;
    for( char row = 0; row < 7; row++ ) 
	leds[ 7 * row + col ].fadeToBlackBy( scale );
}

void zwaailicht( void ) {

    static char col = 0;

    fadeall( 150 );
    if ( col < 7 ) {
	setcol( col, CRGB::Red );
    } else {
	setcol( col, CRGB::Blue );
    }

    col++;
    col %= 14;

}

#define COOLING  55
#define SPARKING 120

void fire2012() {
// Array of temperature readings at each simulation cell
  static byte heat[NUM_LEDS];

  // Step 1.  Cool down every cell a little
    for( int i = 0; i < NUM_LEDS; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / NUM_LEDS) + 2));
    }
  
    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
    for( int k= NUM_LEDS - 1; k >= 2; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    
    // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
    if( random8() < SPARKING ) {
      int y = random8(7);
      heat[y] = qadd8( heat[y], random8(160,255) );
    }

    // Step 4.  Map from heat cells to LED colors
    for( int j = 0; j < NUM_LEDS; j++) {
      CRGB color = HeatColor( heat[j]);
      int pixelnumber;
      if( gReverseDirection ) {
        pixelnumber = (NUM_LEDS-1) - j;
      } else {
        pixelnumber = j;
      }
      leds[pixelnumber] = color;
    }
}
