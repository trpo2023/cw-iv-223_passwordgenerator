CC = gcc
CFLAGS = -o

TARGET = pwgen
SRCS = pwgen.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)