#define F_CPU 1000000UL


#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>
#include <util/delay.h>


void buzzer_on(void) {
  TCCR1 = (1 << 2) | (1 << 1);
  GTCCR = (1 << 6) | (1 << 5);
  OCR1B = 60;
  OCR1C = 120;
}


void buzzer_off(void) {
  GTCCR = 0;
}


int main(void) {
  DDRB = (1 << PB4) | (1 << PB2) | (1 << PB1) | (1 << PB0);

  PORTB = (1 << PB2) | (1 << PB1) | (1 << PB0);

  bool input_state = false;
  uint8_t health = 3;

  buzzer_off();

  while(1) {
    if(PINB & (1 << PB3)) {
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

        buzzer_on();
        _delay_ms(100);
        buzzer_off();
        _delay_ms(400);
      }
    } else {
      input_state = false;
    }

    if(health < 1) {
      buzzer_on();

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

      buzzer_off();
    }
  }

  return 0;
}
