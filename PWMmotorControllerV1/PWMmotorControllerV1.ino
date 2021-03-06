// Program generates a pwm output at P0 based on the value of the voltage at P2 on ATTiny85
// Based on some examples from Adafruit and Arduino
// Program is used to to drive a pwm motor controller on a portable motor tester module for FRC
// Mike Druiven, Feb 4, 2020

#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

// Which pin on the ATTiniy85 is connected to the NeoPixels?
#define PIN            1

// How many NeoPixels are attached to the ATTiny85?
#define NUMPIXELS      5

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 200; // delay for 0.2 seconds
int y=0; //Which of 5 NeoPixels are we addressing
void setup() {
pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
 for (int x=0; x<5; x++){
  pixels.setPixelColor(x, pixels.Color(0,150,0)); // Moderately bright green color.
}
int z = analogRead(1); // Voltage at P2 generated using potentiometer (0-5 volts becomes 0 - 1023)
int pwmz = map(z,0,1023,0,254); // pwm values go from 0 to 255, not 0 to 1024, so remap them
analogWrite(0,pwmz); // send signal to speed controller
if (z>819){  // use if to determine which LED is red
  y=4;
}
else if (z>614){
  y=3;
}
else if (z>410){
  y=2;
}
else if (z>200){
  y=1;
}
else {
  y=0;
}

pixels.setPixelColor(y, pixels.Color(150,0,0)); // set one of 5 LEDs to red depending on potentiometer setting
pixels.show(); // This sends the updated pixel color to the hardware.
delay(delayval);
}  // end loop
