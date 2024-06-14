#define USER_SETUP_ID 505

#define ST7735_DRIVER
#define TFT_WIDTH  80
#define TFT_HEIGHT 160
#define ST7735_GREENTAB160x80  // For 160 x 80 display (BGR, inverted, 26 offset)

//PIN NUMBERS - ESP32 Dev board

#define TFT_MOSI 23     // In some display driver board, it might be written as "SDA" and so on.
#define TFT_SCLK 18 
#define TFT_CS   5      // Chip select control pin
#define TFT_DC   19     // Data Command control pin
#define TFT_RST  21     // Reset pin (could connect to Arduino RESET pin)
#define TFT_BL   22     // LED back-light

#define SMOOTH_FONT


// Define the SPI clock frequency, this affects the graphics rendering speed. Too
// fast and the TFT driver will not keep up and display corruption appears.
// With an ILI9341 display 40MHz works OK, 80MHz sometimes fails
// With a ST7735 display more than 27MHz may not work (spurious pixels and lines)
// With an ILI9163 display 27 MHz works OK.


#define SPI_FREQUENCY  27000000
#define SPI_READ_FREQUENCY  20000000
//
#define SPI_TOUCH_FREQUENCY  2500000 // the display has no touch, so attempt to remove
//

//maybe add the fonts too?
