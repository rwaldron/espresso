PROJECT = espresso
MCU = atmega2560
CPU_SPEED = 16000000UL
TARGET = $(PROJECT).hex

CC = avr-gcc
CXX = avr-g++

INCLUDE = -Iarduino -Ijs
CFLAGS = $(INCLUDE) -mmcu=$(MCU) -DF_CPU=$(CPU_SPEED) -Os -w -Wl,--gc-sections \
	-ffunction-sections -fdata-sections
LIBS = -Larduino -Ljs -larduino -ljs -lm

OBJECTS = main.o bytecode.o b_digital.o b_analog.o b_serial.o

default: all

all: libarduino.a libjs.a $(TARGET)

libarduino.a:
	cd arduino; $(MAKE) all

libjs.a:
	cd js; $(MAKE) all

$(TARGET): $(PROJECT).elf
	avr-objcopy -O ihex $< $@

$(PROJECT).elf: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

%.o: %.c
	$(CC) $< $(CFLAGS) -c -o $@

clean:
	cd arduino; $(MAKE) $@
	cd js; $(MAKE) $@
	rm *.o *.elf *.hex

.PHONY: all clean
