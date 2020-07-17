CC=gcc
CFLAGS= -Wall -Werror -O2 -g
OBJS= cpu.o

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) main.c

cpu.o: cpu.c
	$(CC) $(CFLAGS) -c cpu.c

clean:
	rm *.out *.o
