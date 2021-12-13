#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        3 

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 54 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

uint32_t redColor = pixels.Color(255, 0, 0);
uint32_t greenColor = pixels.Color(0, 255, 0);
uint32_t blueColor = pixels.Color(0, 0, 255);
uint32_t whiteColor = pixels.Color(255, 255, 255);
uint32_t orangeColor = pixels.Color(252, 53, 3);
void loop() {

  verticalTripleFlag(blueColor, whiteColor, redColor);  // France
  delay(5000);
  verticalTripleFlag(greenColor, whiteColor, orangeColor);  //irleandFlag();
  delay(5000);
  doubleHorizontalFlag(whiteColor, redColor); //polandFlag();
  delay(5000);  
  czechFlag();
  delay(5000);
  verticalTripleFlag(greenColor, whiteColor, redColor);  //italyFlag();
  delay(5000);
//  pixels.clear(); // Set all pixel colors to 'off'  
  }

void doubleHorizontalFlag(uint32_t Color1, uint32_t Color2){
    for(int i=0; i<27; i++) { 
        pixels.setPixelColor(i, Color1);
        pixels.show();   // Send the updated pixel colors to the hardware.
    }

    for(int i=27; i<55; i++){
        pixels.setPixelColor(i, Color2);
        pixels.show();
    }
}


void czechFlag(){
    for(int i=0; i<27; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(100, 100, 100));
    
    pixels.show();   // Send the updated pixel colors to the hardware.
}

for(int i=27; i<55; i++){
    pixels.setPixelColor(i, pixels.Color(252, 0, 0));
    pixels.show();
}


    for(int i=0; i<7; i++) { 
    pixels.setPixelColor(i*9, pixels.Color(0, 0, 250));
    pixels.setPixelColor(i*9+1, pixels.Color(0, 0, 250));
    pixels.show();   
}

    pixels.setPixelColor(11, pixels.Color(0, 0, 250));  
    pixels.setPixelColor(20, pixels.Color(0, 0, 250)); 
    pixels.setPixelColor(21, pixels.Color(0, 0, 250));  
    pixels.setPixelColor(29, pixels.Color(0, 0, 250));  
    pixels.setPixelColor(30, pixels.Color(0, 0, 250));  
    pixels.setPixelColor(38, pixels.Color(0, 0, 250));
    pixels.show();
}



void verticalTripleFlag(uint32_t Color1, uint32_t Color2, uint32_t Color3){
    for(int i=0; i<7; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i*9, Color1);
    pixels.setPixelColor(i*9+1, Color1);
    pixels.setPixelColor(i*9+2, Color1);
    
    pixels.setPixelColor(i*9+3, Color2);
    pixels.setPixelColor(i*9+4, Color2);
    pixels.setPixelColor(i*9+5, Color2);

    pixels.setPixelColor(i*9+6, Color3);
    pixels.setPixelColor(i*9+7, Color3);
    pixels.setPixelColor(i*9+8, Color3);
    
    pixels.show();   // Send the updated pixel colors to the hardware.
}}


void italyFlag(){
    for(int i=0; i<7; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i*9, pixels.Color(0, 204, 0));
    pixels.setPixelColor(i*9+1, pixels.Color(0, 204, 0));
    pixels.setPixelColor(i*9+2, pixels.Color(0, 204, 0));
    
    pixels.setPixelColor(i*9+3, pixels.Color(100, 100, 100));
    pixels.setPixelColor(i*9+4, pixels.Color(100, 100, 100));
    pixels.setPixelColor(i*9+5, pixels.Color(100, 100, 100));

    pixels.setPixelColor(i*9+6, pixels.Color(250, 0, 0));
    pixels.setPixelColor(i*9+7, pixels.Color(250, 0, 0));
    pixels.setPixelColor(i*9+8, pixels.Color(250, 0, 0));
    
    pixels.show();   // Send the updated pixel colors to the hardware.
}}
