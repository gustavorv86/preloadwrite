
CC = "/usr/bin/gcc"

TARGET = preloadwrite.so

all: $(TARGET)

$(TARGET): src/preloadwrite.c
	$(CC) -shared -fPIC -ldl -o $(TARGET) src/preloadwrite.c

clean:
	rm -f $(TARGET)

