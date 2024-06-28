#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <NMEAGPS.h>
#include "NMEA.h"
#include "Menu.h"

//custom libraries here:


//constants and variables declarations here:


//function declarations here:
int myFunction(int, int);


void setup() {
  //initial GPS setup
  //nmeasetup();


  // initialize the button's corresponding GPIO pin as an input:
  pinMode(25, INPUT); //button K1
  pinMode(26, INPUT); //button K2
  pinMode(32, INPUT); //button K3
  pinMode(33, INPUT); //button K4
  
  // initialise screen
  tft.init();
  // set screen BG color to black
  tft.fillScreen(TFT_BLACK);
  // draw a red rectangle around the edges
  tft.drawRect(0, 0, tft.width(), tft.height(), TFT_RED);

  // Set "cursor" at top left corner of display (0,0) and select font
  // (1=8 pixel, 2=16 pixels, 4=26 pixels) / if you only put in one coord, it's the width
  tft.setCursor(0, 0, 2);

  // Set the font colour to be white
  tft.setTextColor(TFT_WHITE);

  // We can now plot text on screen using the "print" class
  tft.println(" Initialised \n");
  tft.println(" Panda");
 

  delay(1000);
}

void loop() {
  //keeping mainMenu() here so it behaves like a homescreen
  //starting the nmea loop
  //nmealoop();
  mainMenu();
}



// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}