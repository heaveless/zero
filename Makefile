CC=clang
CFLAGS=-Wall -O3 -g -std=gnu11 -fno-strict-aliasing -Isrc
LDFLAGS=-lSDL2 -lm

APP=zero
SOURCES:=$(shell find . -type f -name "*.c")
EXECUTABLE=$(APP)

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE) $(LDFLAGS)

clean:
	rm -f $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

.PHONY: all clean run
