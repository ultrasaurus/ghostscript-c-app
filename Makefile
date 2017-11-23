CC = cc
GS_LIB = $(GS_HOME)/lib/libgs.dylib
GS_INC = $(GS_HOME)/include/ghostscript
CFLAGS = -I$(GS_INC)
OBJECTS = main.o $(GS_LIB)

$(info GS_HOME="$(GS_HOME)")
$(info GS_LIB="$(GS_LIB)")


all: app

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

app: $(OBJECTS)
	$(CC) $(OBJECTS) -o app

clean:
	rm -f *.o app
