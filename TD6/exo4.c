#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *input = NULL;

	char mot[50];
	char maxMot[50];
	int maxSize = 0;

	input = fopen("text.txt", "r");

	while (fscanf(input, "%s", mot) != EOF)
	{
		int size = 0;

		while (*(mot + size) != '\0')
		{
			size++;
		}

		if (size > maxSize)
		{
			maxSize = size;
			strcpy(maxMot, mot);
		}
	}

	printf("%s - %d lettres", maxMot, maxSize);

	fclose(input);

	return 0;
}
