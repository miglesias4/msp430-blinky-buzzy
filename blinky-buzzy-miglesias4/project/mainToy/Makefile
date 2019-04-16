#makefile config.

COMMON_OBJECTS	=
CPU				= msp430g2553
CFLAGS			= -mmcu=${CPU} -I../h
LDFLAGS			= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC				= msp430-elf-gcc
AS				= msp430-elf-as

all: main.elf

#additional rules for files
main.elf: ${COMMON_OBJECTS} p2_Interupt_Handle.o WD_Interupt.o buzzer.o led.o switches.o main.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: main.elf
	mspdebug rf2500 "prog main.elf"

clean:
	rm -f *.o *.elf *.~ *.c~ *.h~

# assy:
# 	msp430-elf-gcc -mmcu=msp430g2553 -L/opt/ti/msp430_gcc/include -S switches.c
