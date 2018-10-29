CC=gcc
CFLAGS=-lWarn -pedantic

alarm: alarm.o 
	$(CC) alarm.o -L. -lcurl -lwiringPi -o alarm

alarm.o: alarm.c
	$(CC) $(CFLAGS) -c -ansi $<

clean:
	rm alarm *.o
