# DC-motor-test-unit
A simple stand-alone DC motor controller to test individual DC motors on FRC robots.
An ATTiny85 Arduino reads 0-5 volts from a potentiometer and maps the reading to a pwm output.
The ATTiny85 pwm output drives a standard pwm based DC speed controller.
A second ATTiny output drives a 5 element neopixel strip that gives an inidication of speed/direction.
The ATTiny can be replaced with any 5V Arduino. Just change up the i/o pin numbers.
