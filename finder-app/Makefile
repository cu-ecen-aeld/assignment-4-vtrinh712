# initialize cross-compiler & flags
CC = gcc
CFLAGS = -Wall -Werror

# check to see if cross-compiler is specified; otherwise, set to native/default build platform
ifeq ($(CROSS_COMPILE),)
TARGET = writer
else
TARGET = writer-arm
endif

.PHONY: all clean

all: $(TARGET)

# set up use cases
writer: writer.o
	$(CC) $(CFLAGS) $< -o $@

writer-arm: writer.o
	$(CC) $(CFLAGS) $< -o $@ -static

writer.o: writer.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) writer.o writer-arm
