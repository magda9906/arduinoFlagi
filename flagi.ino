#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 3

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 54 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup()
{
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
uint32_t yellowColor = pixels.Color(255, 255, 0);

void loop()
{
  verticalTripleFlag(blueColor, whiteColor, redColor); // France
  delay(5000);
  verticalTripleFlag(greenColor, whiteColor, orangeColor); //irleandFlag();
  delay(5000);
  doubleHorizontalFlag(whiteColor, redColor); //polandFlag();
  delay(5000);
  czechFlag();
  delay(5000);
  verticalTripleFlag(greenColor, whiteColor, redColor); //italyFlag();
  delay(5000);
  tripleHorizontalFlag(redColor, whiteColor, greenColor); //hungaryFlag();
  delay(5000);
  doubleHorizontalFlag(blueColor, yellowColor); //ukraineFlag();
  swedenFlag(); //Sweden flag
  delay(5000);
  verticalTripleFlag(blueColor, yellowColor, redColor); //romaniaFlag();
  delay(5000);
  tripleHorizontalFlag(whiteColor, blueColor, redColor); //russiaFlag();
  delay(5000);
  doubleHorizontalFlag(redColor, whiteColor); //monacoFlag();
  delay(5000);
  tripleHorizontalFlag(yellowColor, greenColor, redColor); //lithuaniaFlag();
  delay(5000);
  tripleHorizontalFlag(redColor, whiteColor, blueColor); //luxembourgFlag();
  delay(5000);
  denmarkFlag(); // Denmark flag
  delay(5000);
  //Latvia flag
  lightAll(204, 0, 0);
  int latv[] = {0, 0, 1, 1, 0, 0};
  lightHorizontalStripes(latv, 255, 255, 255);
  delay(5000);
  tripleHorizontalFlag(redColor, whiteColor, redColor);
  delay(5000);
//  pixels.clear(); // Set all pixel colors to 'off'  
  }

// Dwa poziome pasy
void doubleHorizontalFlag(uint32_t Color1, uint32_t Color2)
{
  for (int i = 0; i < 27; i++)
  {
    pixels.setPixelColor(i, Color1);
    pixels.show(); // Send the updated pixel colors to the hardware.
  }

  for (int i = 27; i < 55; i++)
  {
    pixels.setPixelColor(i, Color2);
    pixels.show();
  }
}

// Trzy poziome pasy
void tripleHorizontalFlag(uint32_t Color1, uint32_t Color2, uint32_t Color3)
{
  for (int i = 0; i < 18; i++)
  {
    pixels.setPixelColor(i, Color1);
    pixels.show(); // Send the updated pixel colors to the hardware.
  }

  for (int i = 18; i < 36; i++)
  {
    pixels.setPixelColor(i, Color2);
    pixels.show();
  }

  for (int i = 36; i < 54; i++)
  {
    pixels.setPixelColor(i, Color3);
    pixels.show();
  }
}

// Trzy pionowe pasy
void verticalTripleFlag(uint32_t Color1, uint32_t Color2, uint32_t Color3)
{
  for (int i = 0; i < 7; i++)
  { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i * 9, Color1);
    pixels.setPixelColor(i * 9 + 1, Color1);
    pixels.setPixelColor(i * 9 + 2, Color1);

    pixels.setPixelColor(i * 9 + 3, Color2);
    pixels.setPixelColor(i * 9 + 4, Color2);
    pixels.setPixelColor(i * 9 + 5, Color2);

    pixels.setPixelColor(i * 9 + 6, Color3);
    pixels.setPixelColor(i * 9 + 7, Color3);
    pixels.setPixelColor(i * 9 + 8, Color3);

    pixels.show(); // Send the updated pixel colors to the hardware.
  }
}

//Poziome paski
void lightHorizontalStripes(int tab[], int red_value, int green_value, int blue_value)
{

  int led_numbers[6] = {0, 9, 18, 27, 36, 45};

  for (int i = 0; i < 6; i++)
  {
    if (tab[i] == 1)
    {
      int n = led_numbers[i];
      pixels.setPixelColor(n, pixels.Color(red_value, green_value, blue_value));
      pixels.setPixelColor(n + 1, pixels.Color(red_value, green_value, blue_value));
      pixels.setPixelColor(n + 2, pixels.Color(red_value, green_value, blue_value));
      pixels.setPixelColor(n + 3, pixels.Color(red_value, green_value, blue_value));
      pixels.setPixelColor(n + 4, pixels.Color(red_value, green_value, blue_value));
      pixels.setPixelColor(n + 5, pixels.Color(red_value, green_value, blue_value));
      pixels.setPixelColor(n + 6, pixels.Color(red_value, green_value, blue_value));
      pixels.setPixelColor(n + 7, pixels.Color(red_value, green_value, blue_value));
      pixels.setPixelColor(n + 8, pixels.Color(red_value, green_value, blue_value));

      pixels.show();
    }
  }
}

//Pionowe paski
void lightVerticalStripes(int tab[], int red_value, int green_value, int blue_value)
{

  for (int i = 0; i < 9; i++)
  {
    if (tab[i] == 1)
    {
      pixels.setPixelColor(i, pixels.Color(red_value, green_value, blue_value));
      pixels.setPixelColor(i + 9, pixels.Color(red_value, green_value, blue_value));
      pixels.setPixelColor(i + 18, pixels.Color(red_value, green_value, blue_value));
      pixels.setPixelColor(i + 27, pixels.Color(red_value, green_value, blue_value));
      pixels.setPixelColor(i + 36, pixels.Color(red_value, green_value, blue_value));
      pixels.setPixelColor(i + 45, pixels.Color(red_value, green_value, blue_value));

      pixels.show();
    }
  }
}

void lightAll(int red_value, int green_value, int blue_value)
{

  for (int i = 0; i < 54; i++)
  {
    pixels.setPixelColor(i, pixels.Color(red_value, green_value, blue_value));

    pixels.show();
  }
}

void czechFlag()
{
  for (int i = 0; i < 27; i++)
  { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(100, 100, 100));

    pixels.show(); // Send the updated pixel colors to the hardware.
  }

  for (int i = 27; i < 55; i++)
  {
    pixels.setPixelColor(i, pixels.Color(252, 0, 0));
    pixels.show();
  }

  for (int i = 0; i < 7; i++)
  {
    pixels.setPixelColor(i * 9, pixels.Color(0, 0, 250));
    pixels.setPixelColor(i * 9 + 1, pixels.Color(0, 0, 250));
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

void italyFlag()
{
  for (int i = 0; i < 7; i++)
  { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i * 9, pixels.Color(0, 204, 0));
    pixels.setPixelColor(i * 9 + 1, pixels.Color(0, 204, 0));
    pixels.setPixelColor(i * 9 + 2, pixels.Color(0, 204, 0));

    pixels.setPixelColor(i * 9 + 3, pixels.Color(100, 100, 100));
    pixels.setPixelColor(i * 9 + 4, pixels.Color(100, 100, 100));
    pixels.setPixelColor(i * 9 + 5, pixels.Color(100, 100, 100));

    pixels.setPixelColor(i * 9 + 6, pixels.Color(250, 0, 0));
    pixels.setPixelColor(i * 9 + 7, pixels.Color(250, 0, 0));
    pixels.setPixelColor(i * 9 + 8, pixels.Color(250, 0, 0));

    pixels.show(); // Send the updated pixel colors to the hardware.
  }
}

void swedenFlag ()
{
  lightAll(0, 0, 255);
  int swed1[] = {0, 0, 0, 1, 0, 0};
  int swed2[] = {0, 0, 0, 1, 0, 0, 0, 0, 0};
  lightHorizontalStripes(swed1, 255, 255, 0);
  lightVerticalStripes(swed2, 255, 255, 0);
  delay(5000);
}

void denmarkFlag()
{
  lightAll(255, 0, 0);
  int den1[] = {0, 0, 0, 1, 0, 0};
  lightHorizontalStripes(den1, 255, 255, 255);
  int den2[] = {0, 0, 0, 1, 0, 0, 0, 0, 0};
  lightVerticalStripes(2, 255, 255, 255);
  delay(500);
}