// Program generates a pwm output at P0 based on the value of the voltage at P2 on ATTiny85
// Based on some examples from Adafruit and Arduino
// Program is used to drive a pwm motor controller on a portable motor tester module for FRC
// Mike Druiven, Feb 4, 2020

#include <Adafruit_NeoPixel.h> // A 5 Neopixel strip is used to visually indicate direction and speed.
#include <avr/power.h>

// Which pin on the ATTiniy85 is connected to the NeoPixels?
#define PIN            1

// How many NeoPixels are attached to the ATTiny85?
#define NUMPIXELS      5

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 200; // delay for 0.2 seconds
int y=0; // Which of 5 NeoPixels are we addressing
void setup() {
pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
 for (int x=0; x<5; x++){
  pixels.setPixelColor(x, pixels.Color(0,150,0)); // Moderately bright green color.
}
int z = analogRead(1); // Voltage at P2 generated using potentiometer (0-5 volts becomes 0 - 1023)
int pwmz = map(z,0,1023,128,254); // pwm values go from 128 to 255, not 0 to 1024, so remap them
analogWrite(0,pwmz); // send pwm signal to speed controller
if (pwmz>230){  // use if to determine which LED is red
  y=4;
}
else if (pwmz>204){
  y=3;
}
else if (pwmz>179){
  y=2;
}
else if (pwmz>153){
  y=1;
}
else {
  y=0;
}

pixels.setPixelColor(y, pixels.Color(150,0,0)); // set one of 5 LEDs to red depending on potentiometer setting
pixels.show(); // This sends the updated pixel color to the hardware.
delay(delayval);
}  // end loop
