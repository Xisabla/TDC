#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include "conio.c"

int main(int argc, char *argv[])
{
	int car = 0;
	char filename[64];
	FILE *output = NULL;

	printf("Entrez le nom du fichier a modifier:\n");
	scanf("%s", filename);

	output = fopen(filename, "w");

	if (output == NULL)
	{
		printf("Impossible d'ecrire le fichier");
		return 1;
	}

	printf("\n--                      Mode edition                     --\n");
	printf("-- On peut pas effacer, et appuyez sur \"F2\" pour quitter --\n\n");

	while (car != 27)
	{
		car = getch();
		if (car != 27)
		{
			printf("%c", car);
			fputc(car, output);
		}
	}

	fclose(output);

	return 0;
}
