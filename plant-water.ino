// included for LED light library
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixels(1, PIN_NEOPIXEL);

void setup() {
  pinMode(A0, OUTPUT); // pump control signal
  pixels.begin();  //initializes the pixel

}
int sensorValue = 0;  // Mosture sensor reading

void loop() {
  
    sensorValue = analogRead(A1); // Read mosture sensor 
    // if plant is dry 
   if (sensorValue > 600){ 
    pixels.setPixelColor(0, pixels.Color(100,0,0));  //red
    pixels.show(); // turns LED on
    digitalWrite(A0, HIGH);  // turns on pump
    // else if plant does not need water
    }else {
      // pump is off
      digitalWrite(A0, LOW);
      pixels.setPixelColor(0, pixels.Color(0,100,0));  //green
      pixels.show(); // turns LED on
    }
    
  }
