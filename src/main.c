#define F_CPU 1000000UL


#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>
#include <util/delay.h>


int main(void) {
  DDRB = (1 << PB2) | (1 << PB1) | (1 << PB0);

  PORTB = (1 << PB2) | (1 << PB1) | (1 << PB0);

  bool input_state = false;
  uint8_t health = 3;

  while(1) {
    if(PINB & (1 << PB4)) {
      if(input_state == false) {
        input_state = true;
        health--;

        if(health < 3) {
          PORTB &= ~(1 << PB2);
        }

        if(health < 2) {
          PORTB &= ~(1 << PB1);
        }

        if(health < 1) {
          PORTB &= ~(1 << PB0);
        }

        _delay_ms(500);
      }
    } else {
      input_state = false;
    }

    if(health < 1) {
      PORTB = (1 << PB2) | (1 << PB1) | (1 << PB0);
      _delay_ms(250);
      PORTB = 0;
      _delay_ms(250);

      PORTB = (1 << PB2) | (1 << PB1) | (1 << PB0);
      _delay_ms(250);
      PORTB = 0;
      _delay_ms(250);

      PORTB = (1 << PB2) | (1 << PB1) | (1 << PB0);
      _delay_ms(250);
      PORTB = 0;
      _delay_ms(250);

      PORTB = (1 << PB2) | (1 << PB1) | (1 << PB0);
      _delay_ms(250);
      PORTB = 0;
      _delay_ms(250);

      PORTB = (1 << PB2) | (1 << PB1) | (1 << PB0);
      health = 3;
    }
  }

  return 0;
}
