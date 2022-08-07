CFLAGS   = -Wall -Wextra -mtune=native -g
LDFLAGS  = -lSDL2


srcdir=src/

all: tdemo

tdemo: main.o map.o
	$(CC) main.o map.o -o tdemo $(LDFLAGS)

main.o: $(srcdir)main.c
	$(CC) $(srcdir)main.c -c -o main.o $(CFLAGS)


map.o: $(srcdir)map.c
	$(CC) $(srcdir)map.c -c -o map.o $(CFLAGS)

clean:
	rm *.o tdemo

