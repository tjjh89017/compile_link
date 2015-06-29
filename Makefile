PROG = hello
CC = gcc
CPP = gcc -E
CC1 = gcc -S
LD = gcc
AS = as
DEBUG = 

INC = 

CFLAGS = -O0 $(INC)
#CFLAGS += -m32

LDFLAGS = 
LIBS = 
#LDFLAGS = -m32

OBJS = hello.o
PRE_CODE = $(patsubst %.o, %.i, $(OBJS))
ASM_CODE = $(patsubst %.o, %.s, $(OBJS))

.PHONY: all clean preprocess assembly object

.c.o:
	$(CC) $(CFLAGS) -c $*.c

%.i: %.c
	$(CPP) $(CFLAGS) $*.c -o $*.i

%.s: %.c
	$(CC1) $(CFLAGS) $*.c

all: $(PROG)

$(PROG): $(OBJS)
	$(LD) $(LDFLAGS) $(LIBS) $(OBJS) -o $(PROG)

preprocess: $(PRE_CODE)

assembly: $(ASM_CODE)

object: $(OBJS)

clean:
	-rm -rf $(PRE_CODE) $(ASM_CODE) $(OBJS) $(PROG)
