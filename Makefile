OBJS=perfect6581.o netlist_sim.o
#CFLAGS=-Werror -Wall -Wextra -pedantic -O3
#CC=clang
CFLAGS+=-std=c99
CPPFLAGS=-DNDEBUG

all: clean sid

sid: $(OBJS) sid.o
	$(CC) -o sid $(OBJS) sid.o

test: $(OBJS) test.o
	$(CC) -o test $(OBJS) test.o

clean:
	rm -f $(OBJS) sid test

