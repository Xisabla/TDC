liste: liste.c liste.h
	gcc -c liste.c

lieu: lieu.c lieu.h
	gcc -c lieu.c

trajet: lieu liste trajet.c trajet.h
	gcc -c trajet.c

build: trajet exo1.c
	gcc exo1.c -o exo1 trajet.o liste.o lieu.o -lm

clean:
	find . -type f ! -name "*.*" ! -path "./Makefile" -delete
	find . -type f -name "*out*" -delete
	rm *.o