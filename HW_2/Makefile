CC = gcc
CFLAGS = -Wall -fPIC
LDFLAGS = -shared

LIB = libyu.so
TARGET = app

OBJS = funcs.o

all: $(LIB) $(TARGET)

$(LIB): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(TARGET): main.o $(LIB)
	$(CC) -o $@ main.o -L. -lyu

main.o: main.c yu.h
	$(CC) $(CFLAGS) -c main.c

funcs.o: funcs.c yu.h
	$(CC) $(CFLAGS) -c funcs.c

clean:
	rm -f *.o *.so $(TARGET)
