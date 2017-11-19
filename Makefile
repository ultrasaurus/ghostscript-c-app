CC = cc
OBJECTS = main.o

all: app

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

app: $(OBJECTS)
	$(CC) $(OBJECTS) -o app

clean:
	rm -f *.o app
