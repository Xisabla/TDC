event: event.c event.h
	gcc -c event.c

build: event exo2.c
	gcc exo2.c -o exo2 event.o -lm

debug: event exo2.c
	gcc exo2.c -o exo2 event.o -lm -g
	ddd

clean:
	find . -type f ! -name "*.*" ! -path "./Makefile" -delete
	find . -type f -name "*out*" -delete
	rm events.txt
	rm *.o