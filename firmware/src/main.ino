// vim: set sw=4 sts=4 si:

#include <FastLED.h>
#include "potmeter.h"

#define TOTAL_LEDS 50
#define NUM_LEDS 49
#define STATUS_LED 49
#define DATA_PIN 11
#define FRAMES_PER_SECOND 50
#define BRIGHTNESS 100
#define gReverseDirection false

CRGB leds[ (byte) TOTAL_LEDS ];
CRGB status[] = {
    CRGB::Brown,	// 0 bruin
    CRGB::Red,		// 1 rood
    CRGB::Orange,	// 2 orange
    CRGB::Yellow,	// 3 geel
    CRGB::Green,	// 4 groen 
    CRGB::Blue,		// 5 blauw
    CRGB::Violet,   	// 6 paars
    CRGB::White		// 7 wit
};

void setup( void ) {
    //Serial.begin( 115200 );
    delay( 3000 );
    FastLED.addLeds< WS2811, DATA_PIN, RGB >( leds, TOTAL_LEDS );
    FastLED.setBrightness( BRIGHTNESS ); 
}

byte current_led = 0;
byte pattern     = 0;
byte brightness  = 0;

void loop( void ) {

    static unsigned long status_timer = 0;

    Potmeter pot0( A0, 32 );
    Potmeter pot1( A1, 8  );

    if ( pot0.changed() ) {
	brightness = pot0.read();
	FastLED.setBrightness( brightness * 8 );
	leds[ STATUS_LED ] = status[ pattern ];
	status_timer = millis() + 5000;
    }

    if ( pot1.changed() ) {
	pattern = pot1.read();
	leds[ STATUS_LED ] = status[ pattern ];
	status_timer = millis() + 5000;
    }

    if ( millis() > status_timer ) {
	leds[ STATUS_LED ] = CRGB::Black;
    }

    switch (pattern) {
	case 0:
	    fire2012();
	    break;
	case 1:
	    zwaailicht();
	    break; 
	case 2:
	    newyear();
	    break;
	case 3:
	    break;
	case 4:
	    break;
	case 5:
	    break;
	case 6:
	    break;
	case 7:
	    testpattern();
	    break;
    }

    FastLED.show();
    delay( 1000 / FRAMES_PER_SECOND );
}

void setcol( char col, CRGB colour ) {
    col = col % 7;
    for( byte row = 0; row < 7; row++ )
	leds[ 7 * row + (byte)col ] = colour;
}
void fadeall( byte scale ) {
    for ( byte led = 0; led < 49; led++ )
	leds[ led ].fadeToBlackBy( scale );
}
void fadecol( char col, byte scale ) {
    col = col % 7;
    for( byte row = 0; row < 7; row++ ) 
	leds[ 7 * row + (byte)col ].fadeToBlackBy( scale );
}

void uit( void ) {
    for ( byte i = 0; i < NUM_LEDS; i++ ) {
	leds[ i ] = CRGB::Black;
    }
}
