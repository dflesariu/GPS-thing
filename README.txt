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

Wiring 

Display <-> ESP32

SCL <-> D18 / HSCLK / VSPI_CLK
SDA <-> D23 / HMOSI / VSPI_MOSI
RES <-> D21
DC <-> D19 / HMISO / VSPI_MISO
CS <-> D5 / HCS / VSPI_CS
BLK <-> D23 / LED Backlight
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