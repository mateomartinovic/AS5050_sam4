CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
CFLAGS = -mcpu=cortex-m4 -mthumb -Wall -Wextra -O0 -g \
         -Iinc \
         -Iinc/component -Iinc/instance -Iinc/pio \
         -ICMSIS_6/CMSIS/Core/Include \
         -ffreestanding -nostdlib

LDFLAGS = -T linker.ld

OBJS = src/startup_sam4e16e.o src/system_sam4e.o src/main.o

all: main.bin

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

main.elf: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS)

main.bin: main.elf
	$(OBJCOPY) -O binary $< $@

clean:
	rm -f src/*.o *.elf *.bin
