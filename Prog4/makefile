.SUFFIXES: .c .o

CC = gcc

CFLAGS = -g

.c.o:
	$(CC) $(CFLAGS) -c $<

organizer: main.o filenameUtil.o dirBuilder.o
	gcc main.o filenameUtil.o dirBuilder.o -o organizer

main.o: main.c filenameUtil.h
	gcc -c main.c

filenameUtil.o: filenameUtil.c filenameUtil.h
	gcc -c filenameUtil.c

dirBuilder.o: dirBuilder.c dirBuilder.h
	gcc -c dirBuilder.c

clean:
	rm -f *.o core
