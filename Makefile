CC = avr-gcc

CFLAGS = -std=c11 -g -Os -mmcu=attiny85 -Ilib
CFLAGS += -Wall -Wpedantic -Wdouble-promotion -Wshadow -Wlogical-op
CFLAGS += -fno-strict-aliasing -fno-strict-overflow

build/main.hex: build/main.elf
	avr-objcopy -j .text -j .data -O ihex $< $@

build/main.elf:
	$(CC) -o $@ $(CFLAGS) src/main.c

clean:
	rm build/* || true

flash: build/main.hex
	sudo avrdude -v -c usbtiny -p attiny85 -U flash:w:build/main.hex

size: build/main.elf
	avr-size -Cx --mcu attiny85 build/main.elf
