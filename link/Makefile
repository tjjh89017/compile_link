PROG = link
CC = gcc
CPP = gcc -E
CC1 = gcc -S
LD = gcc
AS = as
DEBUG = 
OBJDUMP = 

INC = -I./ 

CFLAGS = -O0 $(INC)
CC1FLAGS = 

LDFLAGS = 
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

OBJS = main.o \
	   foo.o

PRE_CODE = $(patsubst %.o, %.i, $(OBJS))
ASM_CODE = $(patsubst %.o, %.s, $(OBJS))

.PHONY: all clean preprocess assembly object

.c.o:
	$(CC) $(CFLAGS) -c $*.c

%.i: %.c
	$(CPP) $(CFLAGS) $*.c -o $*.i

%.s: %.c
	$(CC1) $(CFLAGS) $(CC1FLAGS) $*.c

all: $(PROG)

$(PROG): $(OBJS)
	$(LD) $(LDFLAGS) $(LIBS) $(OBJS) -o $(PROG)

preprocess: $(PRE_CODE)

assembly: $(ASM_CODE)

object: $(OBJS)

clean:
	-rm -rf $(PRE_CODE) $(ASM_CODE) $(OBJS) $(PROG)
