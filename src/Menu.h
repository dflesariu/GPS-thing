#include <string>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <NMEAGPS.h>
#include "NMEA.h"
 


//constants and variables declarations here:
int mainMenu();
int GPSMenu();
int historyMenu();
int button_reset();
int button_read();
void tft_init();



TFT_eSPI tft = TFT_eSPI();  // Invoke custom library

//constants and variables declarations here:
const int buttonK1 = 25;
const int buttonK2 = 26;
const int buttonK3 = 32;
const int buttonK4 = 33;

std::string nmea_sentence = "test";
int buttonK1State = 1;
int buttonK2State = 1;
int buttonK3State = 1;
int buttonK4State = 1;

void tft_init() {
  // initialize the button's corresponding GPIO pin as an input:
  pinMode(buttonK1, INPUT); //button K1
  pinMode(buttonK2, INPUT); //button K2
  pinMode(buttonK3, INPUT); //button K3
  pinMode(buttonK4, INPUT); //button K4
  
  // initialise screen
  tft.init();
}

int mainMenu() {
  
  //reset button state
  button_reset();
  // Set the font colour to be white with a black background
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  
  //Draw a rectangle starting from point (0,0) to point (tft.width,tft.height)
  tft.drawRect(0, 0, tft.width(), tft.height(), TFT_GREEN);

  //Live GPS button
  // Set "cursor" at a specific place on the display (x,y) and select font
  // the cursor position is calculated as a % of the screen size
  tft.setCursor((tft.height()*5/100), (tft.height()*10/100), 2);
  // Print the name of the menu entry
  tft.println("Live GPS");
   // Draw a line 
  tft.drawLine(0, (tft.height()*25/100), tft.width(), (tft.height()*25/100), TFT_GREEN);

  //History button
  tft.setCursor((tft.height()*5/100), (tft.height()*35/100), 2);
  tft.println("History");
  tft.drawLine(0, (tft.height()*50/100), tft.width(), (tft.height()*50/100), TFT_GREEN);

  //Settings button
  tft.setCursor((tft.height()*5/100), (tft.height()*60/100), 2);
  tft.println("Settings");
  tft.drawLine(0, (tft.height()*75/100), tft.width(), (tft.height()*75/100), TFT_GREEN);

  //?? button
  tft.setCursor((tft.height()*5/100), (tft.height()*85/100), 2);
  tft.println("??");

  // Read the button state with delay, necessary
  // in order to negate false button presses
  delay(100);

  //button read loop
  while (buttonK1State && buttonK2State && buttonK3State && buttonK4State == HIGH)
  {
    button_read();
    //50ms is unnoticeable for the user
    delay(50);
  };

  if (buttonK4State == LOW)
  {
    GPSMenu();
  } 
  else if(buttonK3State == LOW)
  {
    historyMenu();
  }
  /*
  else if(buttonK2State == LOW)
  {
    settingMenu();
  }
  else if(buttonK1State == LOW)
  {
    questionMenu();
  }
  */
  return 0;
}

int GPSMenu() {
  
  //reset button state
  button_reset();

  // Set the font colour to be white with a black background or the other way around
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  
  //Draw a rectangle starting from point 0 0 to point, tft width tft height
  tft.drawRect(0, 0, tft.width(), tft.height(), TFT_BLUE);

  // Set "cursor" at top left corner of display (0,0) and select font
  tft.setCursor((tft.height()*5/100), (tft.height()*10/100), 2);
  // Print the name of the menu entry
  tft.println("Live GPS");
  // Draw a line 
  tft.drawLine(0, (tft.height()*25/100), tft.width(), (tft.height()*25/100), TFT_BLUE);

  //Back to main menu
  tft.drawLine(0, (tft.height()*75/100), tft.width(), (tft.height()*75/100), TFT_BLUE);
  tft.setCursor((tft.height()*5/100), (tft.height()*85/100), 2);
  tft.println("Main Menu");

  // Read the button state with delay, necessary
  // in order to negate false button presses
 
  delay(100);
  nmeasetup();
  // loop to check for button presses
  delay(100);
  while (buttonK1State && buttonK2State && buttonK3State && buttonK4State == HIGH)
  {
    button_read();
    nmealoop();
    //printf("%s\n", nmea_sentence.c_str());
    delay(50);
  };

  //stopping the gpsPort Serial connection when it's not needed otherwise the SPI connection to the screen fails.
  gpsPort.flush();

  return 0;
}


int historyMenu() {
  
  //reset button state
  button_reset();

  // Set the font colour to be white with a black background or the other way around
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  
  //Draw a rectangle starting from point (0,0) to point (tft.width,tft.height)
  tft.drawRect(0, 0, tft.width(), tft.height(), TFT_BLUE);

  // Set "cursor" at top left corner of display (0,0) and select font
  tft.setCursor((tft.height()*5/100), (tft.height()*10/100), 2);
  // Print the name of the menu entry
  tft.println("History");
  // Draw a line 
  tft.drawLine(0, (tft.height()*25/100), tft.width(), (tft.height()*25/100), TFT_BLUE);

  //Back to main Menu
  tft.drawLine(0, (tft.height()*75/100), tft.width(), (tft.height()*75/100), TFT_BLUE);
  tft.setCursor((tft.height()*5/100), (tft.height()*85/100), 2);
  tft.println("Main Menu");

  // Read the button state with delay, necessary
  // in order to negate false button presses
  delay(100);

  // loop to check for button presses
  while (buttonK1State && buttonK2State && buttonK3State && buttonK4State == HIGH)
  {
  
    button_read();
    delay(50);
  };

  return 0;
}

int button_reset()
{
  //reset button state
  return (buttonK1State=1, buttonK2State=1, buttonK3State=1, buttonK4State=1);
}


int button_read()
{
  //check for button presses
  buttonK1State = digitalRead(buttonK1);
  buttonK2State = digitalRead(buttonK2);
  buttonK3State = digitalRead(buttonK3);
  buttonK4State = digitalRead(buttonK4);
  return (buttonK4State,buttonK2State, buttonK3State, buttonK4State);
}

