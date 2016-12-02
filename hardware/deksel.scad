$fn = 90;



module mount() {
	translate( [ 0, 7, 0 ] ) 
	rotate( [ 90, 0, 0 ] )
	difference() {
		union() {
			translate( [ 0, 12, 0 ] ) cylinder( d = 10, h = 7 );
			translate( [ -5, 0, 0 ] ) cube( [ 10, 12, 7 ] );
		}
		translate( [ 0, 12, 0 ] ) cylinder( h = 7, d = 2 );
	} 	
}

module base() {
	difference() {
		cylinder( d = 100, h = 5 );
		translate( [ 0, 0, 2 ] ) cylinder( d = 90, h = 5 );
		cylinder( d = 12, h = 5 );
	}
}

difference() {
    union() {
        base();
        rotate( [ 0, 0, 0 ] ) translate( [ 0, -50, 0 ] ) mount();
        rotate( [ 0, 0, 120 ] ) translate( [ 0, -50, 0 ] ) mount();
        rotate( [ 0, 0, 240 ] ) translate( [ 0, -50, 0 ] ) mount();
    }
    difference() {
        cylinder( d = 110, h = 20 );
        cylinder( d = 100, h = 20 );
    }
    translate( [ 0, 0, 2 ] )
        difference() {
            cylinder( d = 110, h = 20 );
            cylinder( d = 96, h = 20 );
        }
}


