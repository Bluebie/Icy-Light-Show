#include "util.c"
#define microcontroller atmega328
#include "pixels.c"

/*byte pixels[] = {
  px________,
  px________,
  px________,
  px8_____8_,
  px8888888_,
  px8_____8_,
  px________,
  px_88888__,
  px8_____8_,
  px_8___8__,
  px________,
  px________,
  px____888_,
  px8888____,
  px____888_,
  px________,
  px________,
  px________,
  px________,
  px8888888_,
  px8_______,
  px8_______,
  px________,
  px888888__,
  px___8__8_,
  px888888__,
  px________,
  px8888888_,
  px8__8__8_,
  px_88_88__,
  px________,
  px_8__88__,
  px8__8__8_,
  px_88__8__,
  px________,
  px________,
  px________,
  px________,
  px________,
  px________,
  px________,
  px________,
  px________,
  px________
};*/

/*byte pixels[] = {
  px8_____8_,
  px8888888_,
  px8_____8_,
  px________,
  px________,
  px____88__,
  px__88__8_,
  px88___8__,
  px__88__8_,
  px____88__,
  px________,
  px________,
  px_888888_,
  px8_______,
  px8_______,
  px8888888_,
  px________,
  px________,
  px________,
  px________,
  px________,
  px________,
  px________,
  px________,
  px________,
  px________
};*/

byte pixels[] = {
//  px_______8,
//  px______8_,
  px_____8__,
  px____8___,
  px___8____,
  px__8_____,
  px_8______,
  px8_______,
  px_8______,
  px__8_____,
  px___8____,
  px____8___,
  px_____8__,
  px______8_
};

void outputPixels(byte lights) {
  lightOff(0xFF); // turn all lights off
  lightOn(lights & px8888888_); // pull these high
}

int main() {
  byte counter = 0;
  byte prev = 0;
  
  becomeOutput(0xFF);
  
  lightOff(pin(0) | pin(1) | pin(2) | pin(3) | pin(4) | pin(5) | pin(6) | pin(7));
  
  byte swappy = px_8_8_8_8; // we need to alternate pxels on, due to silly wiring
  unsigned int redraws; // counter to hold how many alternating redraws remain
  byte line; // stores the currently playing line
  while(true) {
    counter = (counter + 1) % sizeof(pixels);
    redraws = 1000;
    while(redraws > 0) {
      swappy = ~swappy;
      line = pixels[counter];
      outputPixels(line & swappy);
      redraws--;
    }
    
    lightOff(0xFF);
    delay(1); // 1ms blank section
  }
  
  return 0;
}
