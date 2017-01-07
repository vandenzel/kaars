void setup( void ) {

    Serial.begin( 115200 );

    pinMode( A0, INPUT );
    pinMode( A1, INPUT );

}

void loop( void ) {

    static word v0;
    static word v1;

    word a0 = analogRead( A0 );
    word a1 = analogRead( A1 );

    if ( v0 * 32 > a0 + 8 ) v0 = a0 / 32;
    if ( v0 * 32 < a0 - 8 ) v0 = a0 / 32;

    if ( v1 * 128 > a1 + 8 ) v1 = a1 / 128;
    if ( v1 * 128 < a1 - 8 ) v1 = a1 / 128;

    
    Serial.print( a0 );
    Serial.print( "\t" );
    Serial.print( v0 );
    Serial.print( "\t" );
    Serial.print( a1 );
    Serial.print( "\t" );
    Serial.print( v1 );
    Serial.println();

    delay( 1000 / 50 );

}


