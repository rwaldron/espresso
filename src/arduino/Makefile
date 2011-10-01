MCU = atmega2560
CPU_SPEED = 16000000UL
TARGET = libarduino.a

CC = avr-gcc
CXX = avr-g++

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(CPU_SPEED) -Os -w

OBJECTS = wiring_serial.o

default: all

all: $(TARGET)

$(TARGET): $(OBJECTS)
	avr-ar rcs $(TARGET) $^

%.o: %.c
	$(CC) $< $(CFLAGS) -c -o $@

clean:
	rm $(TARGET)
	rm *.o

.PHONY: all clean
