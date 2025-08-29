CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2
TARGET = student
SRC = src/student.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o
