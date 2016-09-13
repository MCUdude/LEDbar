#ifndef LEDbar_h
#define LEDbar_h

#include "Arduino.h"

class LEDbar
{

  public:
    // Constructor with dim pin
    LEDbar(uint8_t clk, uint8_t data, uint8_t dim);
    // Constructor without dim pin
    LEDbar(uint8_t clk, uint8_t data);

    // Pass the number of LEDs
    void begin(uint8_t numberOfLEDs);
    
    // Clear the LED bar
    void clear();
    
    // Turn on all LEDs
    void all();

    // Adjust the brightness (0 - 255)
    void brightness(uint8_t level);

    // Set n dots from position x 
    void setDots(uint8_t position, uint8_t dots);

    // Turn on n leds from start position. Use negative numbers to start from the other end
    void setLevel(int8_t level);

    // Set a repeating pattern, 8 bit standard
    void setPattern(uint64_t pattern, uint8_t length = 8);

    
  private:
    // Latch bit
    void strobe(bool dataIn);

    /* Provate variables */
    uint8_t _clk;
    uint8_t _data;
    int8_t _dim = -1;
    uint8_t _brightness = 255;
    
    uint8_t _numberOfLEDs;
};

#endif
