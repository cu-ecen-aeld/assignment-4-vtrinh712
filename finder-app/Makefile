# initialize cross-compiler & flags
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Werror

.PHONY: all clean

all: writer

# set up use cases
writer: writer.o
	$(CC) $(CFLAGS) $< -o writer writer.c

writer-arm: writer.o
	$(CC) $(CFLAGS) $< -o $@ -static

writer.o: writer.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f writer writer.o writer-arm
