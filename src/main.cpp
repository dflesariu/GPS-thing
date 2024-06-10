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

int buttonK1State = 0;
int buttonK2State = 0;
int buttonK3State = 0;
int buttonK4State = 0;

//function declarations here:
int myFunction(int, int);
int mainMenu();
int GPSMenu();
int historyMenu();

void setup() {
  // put your setup code here, to run once:
  
  // initialize the button GPIO as an input:
  pinMode(25, INPUT); //button K1
  pinMode(26, INPUT); //button K2
  pinMode(32, INPUT); //button K3
  pinMode(33, INPUT); //button K4
  
  //initialise screen
  tft.init();
  //set screen BG color to black
  tft.fillScreen(TFT_BLACK);
  tft.drawRect(0, 0, tft.width(), tft.height(), TFT_RED);

  // Set "cursor" at top left corner of display (0,0) and select font
  // (1=8 pixel, 2=16 pixels, 4=26 pixels) / if you only put in one coord, it's the width
  tft.setCursor(0, 0, 2);

  // Set the font colour to be white with a black background
  tft.setTextColor(TFT_WHITE);

  // We can now plot text on screen using the "print" class
  tft.println(" Initialised \n");
  tft.println(" Panda");



  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
 
  mainMenu();

}


// put function definitions here:
int mainMenu() {
  // Set the font colour to be white with a black background or the other way around
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  
  //Draw a rectangle starting from point 0 0 to point, tft width tft height (all around the screen)
  tft.drawRect(0, 0, tft.width(), tft.height(), TFT_GREEN);

  // Set "cursor" at top left corner of display (0,0) and select font 
  tft.setCursor(12, 1, 1);
  // Print the name of the menu entry
  tft.println("main menu");
  // Draw a line 
  tft.drawLine(0, 10, tft.width(), 10, TFT_BLUE);

  //Live GPS button
  tft.setCursor(4, 20, 2);
  tft.println("Live GPS");
  tft.drawLine(0, 45, tft.width(), 45, TFT_BLUE);

  //Live GPS button
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

  //read the button state
  buttonK1State = digitalRead(buttonK1);
  // loop 
  delay(500);
  while (buttonK1State && buttonK2State && buttonK3State && buttonK4State == HIGH)
  {
    buttonK1State = digitalRead(buttonK1);
    buttonK2State = digitalRead(buttonK2);
    buttonK3State = digitalRead(buttonK3);
    buttonK4State = digitalRead(buttonK4);
    delay(500);
  };

  if (buttonK4State == HIGH)
  {
    GPSMenu();
  } 
  else if(buttonK3State == HIGH)
  {
    historyMenu();
  }

  return 0;
}

int GPSMenu() {
  
  //reset button state
  buttonK1State = 0;
  buttonK2State = 0;
  buttonK3State = 0;
  buttonK4State = 0;

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

  //
  tft.drawLine(0, 125, tft.width(), 125, TFT_BLUE);
  tft.setCursor(4, 137, 2);
  tft.println("Main Menu");

  // Read the button state with delay, the delay is necessary
  // in order to negate false button presses
  delay(100);
  buttonK1State = digitalRead(buttonK1);
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
  buttonK1State = 0;
  buttonK2State = 0;
  buttonK3State = 0;
  buttonK4State = 0;

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

  //
  tft.drawLine(0, 125, tft.width(), 125, TFT_BLUE);
  tft.setCursor(4, 137, 2);
  tft.println("Main Menu");

  // Read the button state with delay, the delay is necessary
  // in order to negate false button presses
  delay(100);
  buttonK1State = digitalRead(buttonK1);
  // loop to check for button presses
  while (buttonK1State || buttonK2State || buttonK3State || buttonK4State == HIGH)
  {
    tft.setCursor(4, 124, 1);
    tft.println("Waiting");
    buttonK1State = digitalRead(buttonK1);
    delay(50);
  };


  return 0;
}




// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}