CC=gcc
CFLAGS=-lWarn -pedantic
temp: temp.o 
	$(CC) temp.o -L. -lcurl -lwiringPi -o temp

temp.o: temp.c
	$(CC) $(CFLAGS) -c -ansi -std=gnu99 w1.c -o w1 $<

clean:
	rm temp *.o
