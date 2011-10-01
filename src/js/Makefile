MCU = atmega2560
CPU_SPEED = 16000000UL
TARGET = libjs.a

CC = avr-gcc

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(CPU_SPEED) -Os -w -Wl,--gc-sections \
	-ffunction-sections -fdata-sections

OBJECTS = bc.o heap.o object.o debug.o vm.o vmswt0.o alloc.o utils.o mrgsort.o \
		b_array.o b_bool.o b_func.o b_core.o b_number.o b_object.o \
		b_string.o b_math.o

default: all

all: $(TARGET)

$(TARGET): $(OBJECTS)
	avr-ar rcs $(TARGET) $^

%.o: %.c
	$(CC) $< $(CFLAGS) -c -o $@

clean:
	rm *.o *.a

.PHONY: all clean
