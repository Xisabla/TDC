#include <stdio.h>
#include <stdlib.h>

int isPrime(int n)
{
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main(int argc, char *argv[])
{
	FILE *input = NULL;
	FILE *output = NULL;

	int car = 0;

	input = fopen("liste.txt", "r");
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

	int n = 0;

	do
	{
		car = fgetc(input);
		if (car == '\n')
		{
			if (isPrime(n) == 1)
			{
				fprintf(output, "%d\n", n);
			}
			n = 0;
		}
		else
		{
			n = n * 10 + car - 48;
		}
	} while (car != EOF);

	fclose(input);
	fclose(output);

	return 0;
}
