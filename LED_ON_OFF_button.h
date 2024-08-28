#include <avr/io.h>      // Include AVR I/O definitions
#include <util/delay.h>  // Include delay functions

// Define the CPU frequency if it's not already defined
#ifndef F_CPU
#define F_CPU 16000000UL // Set the frequency to 16 MHz
#endif

int main(void) {
    // Set all pins of PORTD as outputs
    DDRD = 0xFF;
    
    // Set all pins of PORTB as inputs
    DDRB = 0x00;
    
    // Initialize PORTD with all LEDs off
    PORTD = 0x00;

    while(1) {  // Infinite loop
        // Check if the first pin of PORTB (PB0) is HIGH
        if(PINB & (1<<0)) {
            // If PB0 is HIGH, turn on the first 4 LEDs of PORTD
            PORTD = 0x0F;  // Binary: 00001111
        }
        else {
            // If PB0 is LOW, turn on the last 4 LEDs of PORTD
            PORTD = 0xF0;  // Binary: 11110000
        }
    }
}
