CC=gcc
CFLAGS=-lWarn -pedantic

alarm: temp.o 
	$(CC) temp.o -L. -lcurl -lwiringPi -o temp

temp.o: temp.c
	$(CC) $(CFLAGS) -c -ansi $<

clean:
	rm temp *.o
