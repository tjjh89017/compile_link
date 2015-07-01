PROG = main
CC = gcc
CPP = gcc -E
CC1 = gcc -S
LD = gcc
AS = as
DEBUG = 
OBJDUMP = 

INC = 

CFLAGS = -O0 $(INC)
CC1FLAGS = 

LDFLAGS = -static
LIBS = 

ifeq ($(shell uname -s), Darwin)
CC1FLAGS += -mllvm --x86-asm-syntax=intel
DEBUG = lldb
OBJDUMP = gobjdump
else ifeq ($(shell uname -s), Linux)
DEBUG = gdb
OBJDUMP = objdump
CC1FLAGS += -masm=intel
endif

ifeq ($(M), 32)
CFLAGS += -m32
LDFLAGS += -m32
endif

OBJS = main.o
PRE_CODE = $(patsubst %.o, %.i, $(OBJS))
ASM_CODE = $(patsubst %.o, %.s, $(OBJS))
DUMP = $(patsubst %.o, %.o.dump, $(OBJS))

.PHONY: all clean preprocess assembly object objdump build
.DEFAULT_GOAL := all

.c.o:
	$(CC) $(CFLAGS) -c $*.c

%.i: %.c
	$(CPP) $(CFLAGS) $*.c -o $*.i

%.s: %.c
	$(CC1) $(CFLAGS) $(CC1FLAGS) $*.c

%.o.dump: %.o
	$(OBJDUMP) -d -M intel $*.o > $*.o.dump

$(PROG): $(OBJS)
	$(LD) $(LDFLAGS) $(LIBS) $(OBJS) -o $(PROG)

all: preprocess assembly object objdump build

preprocess: $(PRE_CODE)

assembly: $(ASM_CODE)

object: $(OBJS)

objdump: $(DUMP)

build: $(PROG)

clean:
	-rm -rf $(PRE_CODE) $(ASM_CODE) $(OBJS) $(DUMP) $(PROG)
