CROSS_COMPILE ?=
CC = $(CROSS-COMPILE)gcc
CFLAGS = -Wall -Wextra -g

TARGET = writer
SRC = writer.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)
