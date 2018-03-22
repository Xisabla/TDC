#include <stdio.h>
#include <stdlib.h>

int factorielle(int n)
{
	if (n == 1 || n == 0)
	{
		return 1;
	}

	return n * factorielle(n - 1);
}

int parmis(int k, int n)
{
	return factorielle(n) / (factorielle(k) * factorielle(n - k));
}

int main(int argc, char *argv[])
{
	int n;

	printf("Entrez n: ");
	scanf("%d", &n);

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%5d", parmis(j, i));
		}
		printf("\n");
	}

	/*for (int i = 0; i <= n; i++)
	{
		*(tab + n * i) = 1;
		*(tab + n * i + i) = 1;
		for (int j = 1; j < i; j++)
		{
			*(tab + n * i + j) = *(tab + n * (i - 1) + j) + *(tab + n * (i - 1) + (j - 1));
		}
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%5d ", *(tab + n * i + j));
		}
		printf("\n");
	}*/

	return 0;
}
