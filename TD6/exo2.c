#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	FILE *input = NULL;
	FILE *output = NULL;

	int car = 0;

	input = fopen("text.txt", "r");
	output = fopen("out.txt", "w");

	if (input == NULL)
	{
		printf("Impossible de lire le fichier");
		return 1;
	}

	if (output == NULL)
	{
		printf("Impossible d'ecrire le fichier");
		return 1;
	}

	do
	{
		car = fgetc(input);
		if (car != EOF)
		{
			fputc(tolower(car), output);
			printf("%c", tolower(car));
		}
	} while (car != EOF);

	fclose(input);
	fclose(output);

	return 0;
}
