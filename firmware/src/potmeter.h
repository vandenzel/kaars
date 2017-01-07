class Potmeter {

private:
    byte pin;
    word factor;
    word value;
    word current;
    word result;

public:

    Potmeter( byte _pin, word _scale ) {
	pin = _pin;
	factor = 1024 / _scale;
    }

    void poll() {
	value = analogRead( pin );
	if ( value > ( current * factor ) + 8 ) current = value / factor;
	if ( value < ( current * factor ) - 8 ) current = value / factor;
    }

    bool changed( void ) {
	poll();
	if ( current != result ) return true;
	return false;
    }

    word read( void ) {
	result = current;
	return result;
    }

};


