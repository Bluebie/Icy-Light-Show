#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

// For the niceness
typedef unsigned char byte;
typedef unsigned char boolean;

// make bit & value, eg bit(5) #=> 0b00010000
#define bit(number) _BV(number)
#define pin(number) bit(number)

// booleans
#define    on 255
#define   off 0
#define  true 1
#define false 0
#define   yes true
#define    no false

// set a pin on DDRB to be an input or an output - i.e. becomeOutput(pin(3));
inline void inputs(byte pinmap) { DDRD &= ~pinmap; }
inline void outputs(byte pinmap) { DDRD |= pinmap; }

// turn a pin on or off
inline void lightOn(byte light) { PORTD |= light; }
inline void lightOff(byte light) { PORTD &= ~light; }

// the previous version of set
inline void set(byte pin, boolean state) {
  if (state) {
    lightOn(pin);
  } else {
    lightOff(pin);
  }
}

// delay in milliseconds
#define delay(ms) _delay_ms(ms);
