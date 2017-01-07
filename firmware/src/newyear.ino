byte ny_pattern[][ 7 ] = {
    { 255, 255, 255, 255, 255, 255, 255 },	// header
    { 255, 255, 255, 255, 255, 255, 255 },
    { 255, 255, 255, 255, 255, 255, 255 },
    { 255, 255, 255, 255, 255, 255, 255 },
    { 255, 255, 255, 255, 255, 255, 255 },
    { 255, 255, 255, 255, 255, 255, 255 },
    { 255, 255, 255, 255, 255, 255, 255 },

{   17	,   38	,   253	,   255	,   255	,   94	,   65	},
{   17	,   0	,   55	,   255	,   255	,   215	,   3	},
{   17	,   177	,   7	,   82	,   255	,   173	,   0	},
{   17	,   185	,   224	,   1	,   0	,   0	,   54	},
{   51	,   196	,   255	,   224	,   59	,   57	,   227	},
{   255	,   255	,   255	,   255	,   255	,   255	,   255	},
{   255	,   130	,   13	,   0	,   13	,   134	,   252	},
{   47	,   0	,   26	,   32	,   27	,   1	,   85	},
{   2	,   228	,   255	,   255	,   255	,   203	,   0	},
{   11	,   141	,   228	,   232	,   228	,   121	,   17	},
{   132	,   0	,   0	,   0	,   0	,   0	,   150	},
{   255	,   246	,   123	,   87	,   123	,   244	,   255	},
{   252	,   254	,   255	,   255	,   255	,   251	,   252	},
{   11	,   214	,   255	,   255	,   255	,   91	,   90	},
{   17	,   156	,   185	,   185	,   185	,   111	,   38	},
{   17	,   0	,   0	,   0	,   0	,   0	,   34	},
{   17	,   213	,   253	,   253	,   253	,   253	,   253	},
{   12	,   214	,   255	,   255	,   255	,   255	,   255	},
{   255	,   255	,   255	,   255	,   255	,   255	,   255	},
{   255	,   255	,   255	,   255	,   255	,   147	,   35	},
{   20	,   49	,   245	,   255	,   255	,   144	,   30	},
{   113	,   0	,   0	,   27	,   207	,   150	,   30	},
{   255	,   244	,   157	,   0	,   0	,   9	,   33	},
{   255	,   255	,   255	,   251	,   190	,   17	,   34	},

    { 255, 255, 255, 255, 255, 255, 255 },	// footer
    { 255, 255, 255, 255, 255, 255, 255 },
    { 255, 255, 255, 255, 255, 255, 255 },
    { 255, 255, 255, 255, 255, 255, 255 },
    { 255, 255, 255, 255, 255, 255, 255 },
    { 255, 255, 255, 255, 255, 255, 255 },	
    { 255, 255, 255, 255, 255, 255, 255 }	
};

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

   