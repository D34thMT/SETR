DEFAULT_TARGET = test_runner

OBJECTS = sensor.o main.o
CFLAGS = -g -Wall -O3
CC = gcc

# Generate application
$(DEFAULT_TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(DEFAULT_TARGET) $(OBJECTS)

# Generate object files for C source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean run

all: clean run

clean:
	rm -f *.o $(DEFAULT_TARGET)

run: $(DEFAULT_TARGET)
	./$(DEFAULT_TARGET)