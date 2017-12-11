byte ny_pattern[][ 7 ] = 
#include "2018.h"
;

#define pattern_length (sizeof(ny_pattern)/sizeof(*ny_pattern))

void newyear( void ) {

    static byte start_kleur = 0;
    static byte start_line = 0;
    static unsigned long now = 0;

    fadeall( 100 );
    byte kleur = start_kleur;
    for ( byte col = 0; col < 7; col++ ) {
	for ( byte row = 0; row < 7; row++ ) {
	    byte i = ( 6 - col ) + ( row * 7 );
	    leds[ i ] = ColorFromPalette( RainbowColors_p, kleur, 255, LINEARBLEND );
	    leds[ i ].nscale8( 255 - ny_pattern[ col + start_line ][ row ] );
	    kleur += 1;
	}
    }
    start_kleur++;

    if ( millis() > now ) {
	start_line++;
	if ( start_line > pattern_length - 7 ) start_line = 0;
	now = millis() + 100;
    }
}

   
