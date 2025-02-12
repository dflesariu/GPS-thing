#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
//#include <NMEAGPS.h>
//#include "NMEA.h"
#include "Menu.h"

void setup() {
  //tft_init();
}

void loop() {
 
  //keeping mainMenu() here so it behaves like a homescreen
  tft_init();
  mainMenu();
}