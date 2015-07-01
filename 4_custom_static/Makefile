PROG = main
CC = gcc
CPP = gcc -E
CC1 = gcc -S
LD = gcc
AS = as
DEBUG = 
OBJDUMP = 
AR = ar

INC = -I./

CFLAGS = -O0 $(INC)
CC1FLAGS = 

LDFLAGS = 
LIBS = -ltest -L./

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
LIB_OBJS = foo.o \
		   bar.o
LIBRARY = libtest.a

PRE_CODE = $(patsubst %.o, %.i, $(OBJS) $(LIB_OBJS))
ASM_CODE = $(patsubst %.o, %.s, $(OBJS) $(LIB_OBJS))
DUMP = $(patsubst %.o, %.o.dump, $(OBJS) $(LIB_OBJS))

.PHONY: all clean preprocess assembly object objdump build lib
.DEFAULT_GOAL := all

.c.o:
	$(CC) $(CFLAGS) -c $*.c

%.i: %.c
	$(CPP) $(CFLAGS) $*.c -o $*.i

%.s: %.c
	$(CC1) $(CFLAGS) $(CC1FLAGS) $*.c

%.o.dump: %.o
	$(OBJDUMP) -d -M intel $*.o > $*.o.dump

$(PROG): $(OBJS) $(LIBRARY)
	$(LD) $(LDFLAGS) $(LIBS) $(OBJS) $(LIBRARY) -o $(PROG)

$(LIBRARY): $(LIB_OBJS)
	$(AR) rcs $(LIBRARY) $(LIB_OBJS)

all: preprocess assembly object objdump lib build

preprocess: $(PRE_CODE)

assembly: $(ASM_CODE)

object: $(OBJS)

objdump: $(DUMP)

build: $(PROG)

lib: $(LIBRARY)

clean:
	-rm -rf $(PRE_CODE) $(ASM_CODE) $(OBJS) $(DUMP) $(LIB_OBJS) $(LIBRARY) $(PROG)
