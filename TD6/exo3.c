#include <stdio.h>
#include <stdlib.h>

int numbersToLetters(int n)
{
	if (n < 0 || n > 1000)
	{
		return 0;
	}

	if (n == 300)
	{
		printf("This is sparta !!!\n");
	}

	if (n == 42)
	{
		printf("La reponse a la vie, l'univers et tout ce qui existe...\n");
	}

	char *unitsToLetters[20] = {
		"", "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf",
		"dix", "onze", "douze", "treize", "quatorze", "quinze", "seize", "dix-sept", "dix-huit", "dix-neuf"};
	char *tensToLetters[10] = {
		"", "dix", "vingt", "trente", "quarante", "cinquante", "soixante", "", "quatre-vingt", ""};

	int units = n % 10;
	int tens = ((n - units) % 100) / 10;
	int hundreds = ((n - tens * 10 - units) % 1000) / 100;

	if (n == 0)
	{
		printf("zero");
		return 1;
	}

	if (n == 100)
	{
		printf("cents");
		return 1;
	}

	if (n == 1000)
	{
		printf("mille");
		return 1;
	}

	if (tens == 1 || tens == 0)
	{
		units += tens * 10;
		tens = 0;
	}

	if (tens == 7 || tens == 9)
	{
		tens--;
		units += 10;
	}

	char *outUnits = unitsToLetters[units];
	char *outTens = tensToLetters[tens];
	char *outHundreds = unitsToLetters[hundreds];

	printf("%s%s%s %s%s", (hundreds > 1) ? outHundreds : "", (hundreds == 0) ? "" : (tens + units == 0) ? " cents " : " cent ", outTens, (units == 1 && tens < 7 && tens > 1) ? "et " : "", outUnits);

	return 1;
}

int main(int argc, char *argv[])
{
	int n;

	do
	{
		printf("Entrez votre nombre (entre 0 et 1000): ");
		scanf("%d", &n);
	} while (n < 0 && n > 1000);

	numbersToLetters(n);

	return 0;
}
