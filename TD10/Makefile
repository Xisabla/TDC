list: list.c list.h
	gcc -c list.c

basketteur:
	gcc -c basketteur.c

build: list basketteur exo$(EXERCICE).c
	gcc exo$(EXERCICE).c -o exo$(EXERCICE) list.o basketteur.o -lm

clean:
	find . -type f ! -name "*.*" ! -path "./Makefile" -delete
	find . -type f -name "*out*" -delete
	rm *.o

run: build
	./exo$(EXERCICE)
	$(MAKE) clean