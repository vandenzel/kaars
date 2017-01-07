
#define matrix(x,y) (leds[ (x) + ((y) * 7) ])

void testpattern() {

    static byte state = 0;
    static unsigned long now = 0;

    if ( state > 13 ) state = 0;

    for( byte i = 0; i < NUM_LEDS; i++ ) {
	leds[ i ] = CRGB::Black;
    }

    if ( state < 7 ) {
	for ( byte i = 0; i < 7; i++ ) {
	    matrix( state, i ) = CRGB::White;
	}
    } else {
	for ( byte i = 0; i < 7; i++ ) {
	    matrix( i, state - 7 ) = CRGB::White;
	}
    }

    if ( millis() > now ) {
	now = millis() + 100;
	state++;
    }

}
