// potmeterhouder.scad

$fn = 90;

union() {
    linear_extrude( height = 2 ) {
        intersection() {
            translate( [ -35, 0 ] ) square( [ 70, 35 ] );
            difference() {
                circle( r = 35 );
                circle( r = 15 );
                rotate( [ 0, 0, 45 ] ) {
                    translate( [ 0, 25 ] ) circle( d = 2 );
                    translate( [ 0, 25 - 8 ] ) circle( d = 2 );
                }
                rotate( [ 0, 0, -45 ] ) {
                    translate( [ 0, 25 ] ) circle( d = 2 );
                    translate( [ 0, 25 - 8 ] ) circle( d = 2 );
                }

                rotate( [ 0, 0, -80 ] ) 
                    translate( [ 0, 25 ] ) circle( d = 2 );
                rotate( [ 0, 0, 0 ] ) 
                    translate( [ 0, 25 ] ) circle( d = 2 );
                rotate( [ 0, 0, 80 ] ) 
                    translate( [ 0, 25 ] ) circle( d = 2 );

            }
        }
    }

    linear_extrude( height = 9 ) {
        intersection() {
            translate( [ -35, 0 ] ) square( [ 70, 35 ] );
            difference() {
                circle( r = 35 );
                circle( r = 15 );
                rotate( [ 0, 0, 45 ] ) translate( [ 0, 25 ] ) { 
                    translate( [ -10, -15 ] ) square( [ 20, 30 ] );
                }
                rotate( [ 0, 0, -45 ] ) translate( [ 0, 25 ] ) {
                    translate( [ -10, -15 ] ) square( [ 20, 30 ] );
                }

                rotate( [ 0, 0, -80 ] ) translate( [ 0, 25 ] ) circle( d = 2 );
                rotate( [ 0, 0, 0 ] ) translate( [ 0, 25 ] ) circle( d = 2 );
                rotate( [ 0, 0, 80 ] ) translate( [ 0, 25 ] ) circle( d = 2 );

            }
        }
    }
}
