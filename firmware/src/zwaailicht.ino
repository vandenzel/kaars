void zwaailicht( void ) {

    static char col = 0;
    static unsigned long now = 0;

    fadeall( 40 );
    if ( col < 7 ) {
	setcol( col, CRGB::Red );
    } else {
	setcol( col, CRGB::Blue );
    }

    if ( millis() > now + 50 ) {
	col++;
	col %= 14;
	now = millis();
    }

}

