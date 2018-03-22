build: exo$(EXERCICE).c
	gcc exo$(EXERCICE).c -o exo$(EXERCICE) -lm

clean:
	find . -type f ! -name "*.*" ! -path "./Makefile" -delete
	find . -type f -name "*out*" -delete

run: build
	./exo$(EXERCICE)
	$(MAKE) clean