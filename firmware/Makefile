MCU := attiny84
F_CPU := 8000000UL
TARGET := quiet-orbit-qo-r1
SOURCES := main.c led_pwm.c
OBJECTS := $(SOURCES:.c=.o)

CC := avr-gcc
OBJCOPY := avr-objcopy
SIZE := avr-size
CFLAGS := -mmcu=$(MCU) -DF_CPU=$(F_CPU) -std=c11 -Os -Wall -Wextra -Werror -ffunction-sections -fdata-sections
LDFLAGS := -mmcu=$(MCU) -Wl,--gc-sections

.PHONY: all clean size

all: $(TARGET).hex size

$(TARGET).elf: $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

%.o: %.c pins.h led_pwm.h
	$(CC) $(CFLAGS) -c $< -o $@

size: $(TARGET).elf
	$(SIZE) --mcu=$(MCU) --format=avr $<

clean:
	rm -f $(OBJECTS) $(TARGET).elf $(TARGET).hex
