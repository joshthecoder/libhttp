CC?=gcc
CFLAGS=-ansi -DPLATFORM_POSIX

session.o: http.h session.c
	$(CC) $(CFLAGS) -c session.c -o $@

clean:
	rm *.o

