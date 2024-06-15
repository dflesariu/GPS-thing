#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>  // Hardware-specific library

//custom libraries here:
TFT_eSPI tft = TFT_eSPI();  // Invoke custom library

//constants and variables declarations here:
const int buttonK1 = 25;
const int buttonK2 = 26;
const int buttonK3 = 32;
const int buttonK4 = 33;
const int i=0;

int buttonK1State = 1;
int buttonK2State = 1;
int buttonK3State = 1;
int buttonK4State = 1;

//function declarations here:
int myFunction(int, int);
int mainMenu();
int GPSMenu();
int historyMenu();

void setup() {
  
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
  // keeping mainMenu() here so it behaves like a homescreen
  mainMenu();

}

int mainMenu() {
  int buttonK1State = 1;
  int buttonK2State = 1;
  int buttonK3State = 1;
  int buttonK4State = 1;
  // Set the font colour to be white with a black background
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  
  //Draw a rectangle starting from point (0,0) to point (tft.w,tft.h)
  tft.drawRect(0, 0, tft.width(), tft.height(), TFT_GREEN);

  // Set "cursor" at a specific place on the display (x,y) and select font
  tft.setCursor(12, 1, 1);
  // Print the name of the menu entry
  tft.println("main menu");
  // Draw a line 
  tft.drawLine(0, 10, tft.width(), 10, TFT_BLUE);

  //Live GPS button
  tft.setCursor(4, 20, 2);
  tft.println("Live GPS");
  tft.drawLine(0, 45, tft.width(), 45, TFT_BLUE);

  //History button
  tft.setCursor(4, 57, 2);
  tft.println("History");
  tft.drawLine(0, 85, tft.width(), 85, TFT_BLUE);

  //Settings button
  tft.setCursor(4, 97, 2);
  tft.println("Settings");
  tft.drawLine(0, 125, tft.width(), 125, TFT_BLUE);

  //?? button
  tft.setCursor(4, 137, 2);
  tft.println("??");

  // Read the button state with delay, necessary
  // in order to negate false button presses
  delay(100);

  //button read loop
  while (buttonK1State && buttonK2State && buttonK3State && buttonK4State == HIGH)
  {
    buttonK1State = digitalRead(buttonK1);
    buttonK2State = digitalRead(buttonK2);
    buttonK3State = digitalRead(buttonK3);
    buttonK4State = digitalRead(buttonK4);
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
  buttonK1State = 1;
  buttonK2State = 1;
  buttonK3State = 1;
  buttonK4State = 1;

  // Set the font colour to be white with a black background or the other way around
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  
  //Draw a rectangle starting from point 0 0 to point, tft width tft height
  tft.drawRect(0, 0, tft.width(), tft.height(), TFT_BLUE);

  // Set "cursor" at top left corner of display (0,0) and select font
  tft.setCursor(10, 10, 2);
  // Print the name of the menu entry
  tft.println("Live GPS");
  // Draw a line 
  tft.drawLine(0, 30, tft.width(), 30, TFT_BLUE);

  //Back to main menu
  tft.drawLine(0, 125, tft.width(), 125, TFT_BLUE);
  tft.setCursor(4, 137, 2);
  tft.println("Main Menu");

  // Read the button state with delay, necessary
  // in order to negate false button presses
  delay(100);

  // loop to check for button presses
  while (buttonK1State && buttonK2State && buttonK3State && buttonK4State == HIGH)
  {
  
    buttonK1State = digitalRead(buttonK1);
    buttonK2State = digitalRead(buttonK2);
    buttonK3State = digitalRead(buttonK3);
    buttonK4State = digitalRead(buttonK4);
    delay(50);
  };

  
  return 0;
}


int historyMenu() {
  
  //reset button state
  buttonK1State = 1;
  buttonK2State = 1;
  buttonK3State = 1;
  buttonK4State = 1;

  // Set the font colour to be white with a black background or the other way around
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  
  //Draw a rectangle starting from point (0,0) to point (tft.width,tft.height)
  tft.drawRect(0, 0, tft.width(), tft.height(), TFT_BLUE);

  // Set "cursor" at top left corner of display (0,0) and select font
  tft.setCursor(10, 10, 2);
  // Print the name of the menu entry
  tft.println("History");
  // Draw a line 
  tft.drawLine(0, 30, tft.width(), 30, TFT_BLUE);

  //Back to main Menu
  tft.drawLine(0, 125, tft.width(), 125, TFT_BLUE);
  tft.setCursor(4, 137, 2);
  tft.println("Main Menu");

  // Read the button state with delay, necessary
  // in order to negate false button presses
  delay(100);

  // loop to check for button presses
  while (buttonK1State && buttonK2State && buttonK3State && buttonK4State == HIGH)
  {
  
    buttonK1State = digitalRead(buttonK1);
    buttonK2State = digitalRead(buttonK2);
    buttonK3State = digitalRead(buttonK3);
    buttonK4State = digitalRead(buttonK4);
    delay(50);
  };

  return 0;
}


// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}