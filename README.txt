Prototyping a portable device that shows your current GPS coordinates.

Part list:
- 0.96 inch TFT SPI display (80x160) with 4 buttons
    - Documentation of similar display: https://thesolaruniverse.wordpress.com/2022/01/02/quite-a-hard-nut-to-crack-the-0-96-inch-80160-spi-7735s-tft-display-driven-by-an-esp8266-or-esp32-microcontroller/
- ESP32 WROOM devkit
    - Documentation: https://docs.espressif.com/projects/esp-idf/en/latest/esp32/hw-reference/esp32/get-started-devkitc.html
    - More info on pins: https://randomnerdtutorials.com/esp32-pinout-reference-gpios/
- ESP32 devkit breakout board
    - Info: https://www.otronic.nl/en/breakout-board-for-esp32-devkit-v1-with-screwdrive.html

- Neo 6M GPS module
    - Documentation: 
        -https://www.u-blox.com/en/product/neo-6-series
        -https://circuitdigest.com/microcontroller-projects/interfacing-neo6m-gps-module-with-esp32

Libraries:
- TFT_eSPI: https://github.com/Bodmer/TFT_eSPI
- NeoGPS: https://github.com/SlashDevin/NeoGPS

Wiring and config for "User_Setup.h"

Display <-> ESP32

SCL <-> 18 / HSCLK / VSPI_CLK / TFT_SCLK
SDA <-> 23 / HMOSI / VSPI_MOSI / TFT_MOSI
RES <-> 21 / reset  / TFT_RST
DC <-> 19 / HMISO / VSPI_MISO / TFT_MISO or TFT_DC
CS <-> 5 HCS / VSPI_CS / TFT_CS (you may also use pin 15)
BLK <-> 22 / LED Backlight (currently not defined )
K1 <-> D25
K2 <-> D26
K3 <-> D32
K4 <-> D33
VCC <-> VCC
GND <-> GND

Neo 6M <-> ESP32

VCC <-> VCC
GND <-> GND
TX <-> RX2 / 16
RX <-> TX2 / 17