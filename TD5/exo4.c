#include <stdio.h>
#include <stdlib.h>

void afficherMatrice(int *matrice, int n, int m)
{
	printf("[");
	for (int i = 0; i < n * m; i++)
	{
		if (i % n == 0 && i != 0)
		{
			printf("]\n[");
		}
		printf("%2d ", *(matrice + i));
	}
	printf("]");
}

void remplirRandom(int *matrice, int n, int m)
{
	srand(time(NULL));

	for (int i = 0; i < n * m; i++)
	{
		*(matrice + i) = rand() % 10;
	}
}

void sommeMatrices(int *matriceA, int *matriceB, int *matriceS, int n, int m)
{
	for (int i = 0; i < n * m; i++)
	{
		*(matriceS + i) = *(matriceA + i) + *(matriceB + i);
	}
}

int main(int argc, char *argv[])
{
	int n;
	int m;

	printf("Nombre de lignes: ");
	scanf("%d", &n);
	printf("Nomre de colonnes: ");
	scanf("%d", &m);

	int size = n * m;

	int *matriceA = NULL;
	int *matriceB = NULL;
	int *matriceS = NULL;

	matriceA = (int *)malloc(size * sizeof(int));
	if (matriceA == NULL)
	{
		printf("Erreur memoire");
		return -1;
	}

	matriceB = (int *)malloc(size * sizeof(int));
	if (matriceB == NULL)
	{
		printf("Erreur memoire");
		return -1;
	}

	matriceS = (int *)malloc(size * sizeof(int));
	if (matriceS == NULL)
	{
		printf("Erreur memoire");
		return -1;
	}

	remplirRandom(matriceA, n, m);
	system("sleep 1");
	remplirRandom(matriceB, n, m);
	sommeMatrices(matriceA, matriceB, matriceS, n, m);

	printf("Matrice A:\n");
	afficherMatrice(matriceA, n, m);
	printf("\nMatrice B:\n");
	afficherMatrice(matriceB, n, m);
	printf("\nMatrice A+B:\n");
	afficherMatrice(matriceS, n, m);

	return 0;
}