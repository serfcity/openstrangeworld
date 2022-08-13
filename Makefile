CFLAGS   = -Wall -Wextra -mtune=native -g
LDFLAGS  = -lSDL2


srcdir=src/

all: openstrangeworld

openstrangeworld: main.o map.o event.o list.o window.o
	$(CC) main.o map.o event.o list.o window.o -o openstrangeworld $(LDFLAGS)

main.o: $(srcdir)main.c
	$(CC) $(srcdir)main.c -c -o main.o $(CFLAGS)


map.o: $(srcdir)map.c
	$(CC) $(srcdir)map.c -c -o map.o $(CFLAGS)

event.o: $(srcdir)event.c
	$(CC) $(srcdir)event.c -c -o event.o $(CFLAGS)

list.o: $(srcdir)list.c
	$(CC) $(srcdir)list.c -c -o list.o $(CFLAGS)

window.o: $(srcdir)window.c
	$(CC) $(srcdir)window.c -c -o window.o $(CFLAGS)

clean:
	rm *.o openstrangeworld

