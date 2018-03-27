list: list.c list.h
	gcc -c list.c

build: list exo$(EXERCICE).c
	gcc exo$(EXERCICE).c -o exo$(EXERCICE) list.o -lm

clean:
	find . -type f ! -name "*.*" ! -path "./Makefile" -delete
	find . -type f -name "*out*" -delete

run: build
	./exo$(EXERCICE)
	$(MAKE) clean