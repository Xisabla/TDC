#include <stdio.h>
#include <stdlib.h>

typedef struct pion_
{
	int color; // 0 = Blanc, 1 = Noir
	int type;  // 1 = Pion, 2 = Tour, 3 = Chevalier, 4 = Fou, 5 = Roi, 6 = Reine
} pion;

pion *initGrille()
{
	pion *grille = NULL;
	grille = (pion *)malloc(8 * 8 * sizeof(pion));

	if (grille == NULL)
	{
		return NULL;
	}

	pion TorBlancA;
	pion TorBlancB;
	pion ChvBlancA;
	pion ChvBlancB;
	pion FouBlancA;
	pion FouBlancB;
	pion RoiBlanc;
	pion ReiBlanc;
	pion PioBlancA;
	pion PioBlancB;
	pion PioBlancC;
	pion PioBlancD;
	pion PioBlancE;
	pion PioBlancF;
	pion PioBlancG;
	pion PioBlancH;

	pion TorNoirA;
	pion TorNoirB;
	pion ChvNoirA;
	pion ChvNoirB;
	pion FouNoirA;
	pion FouNoirB;
	pion RoiNoir;
	pion ReiNoir;
	pion PioNoirA;
	pion PioNoirB;
	pion PioNoirC;
	pion PioNoirD;
	pion PioNoirE;
	pion PioNoirF;
	pion PioNoirG;
	pion PioNoirH;

	PioBlancA.color = 0;
	PioBlancB.color = 0;
	PioBlancC.color = 0;
	PioBlancD.color = 0;
	PioBlancE.color = 0;
	PioBlancF.color = 0;
	PioBlancG.color = 0;
	PioBlancH.color = 0;
	TorBlancA.color = 0;
	TorBlancB.color = 0;
	ChvBlancA.color = 0;
	ChvBlancB.color = 0;
	FouBlancA.color = 0;
	FouBlancB.color = 0;
	RoiBlanc.color = 0;
	ReiBlanc.color = 0;

	PioBlancA.type = 1;
	PioBlancB.type = 1;
	PioBlancC.type = 1;
	PioBlancD.type = 1;
	PioBlancE.type = 1;
	PioBlancF.type = 1;
	PioBlancG.type = 1;
	PioBlancH.type = 1;
	TorBlancA.type = 2;
	TorBlancB.type = 2;
	ChvBlancA.type = 3;
	ChvBlancB.type = 3;
	FouBlancA.type = 4;
	FouBlancB.type = 4;
	RoiBlanc.type = 5;
	ReiBlanc.type = 6;

	PioNoirA.color = 1;
	PioNoirB.color = 1;
	PioNoirC.color = 1;
	PioNoirD.color = 1;
	PioNoirE.color = 1;
	PioNoirF.color = 1;
	PioNoirG.color = 1;
	PioNoirH.color = 1;
	TorNoirA.color = 1;
	TorNoirB.color = 1;
	ChvNoirA.color = 1;
	ChvNoirB.color = 1;
	FouNoirA.color = 1;
	FouNoirB.color = 1;
	RoiNoir.color = 1;
	ReiNoir.color = 1;

	PioNoirA.type = 1;
	PioNoirB.type = 1;
	PioNoirC.type = 1;
	PioNoirD.type = 1;
	PioNoirE.type = 1;
	PioNoirF.type = 1;
	PioNoirG.type = 1;
	PioNoirH.type = 1;
	TorNoirA.type = 2;
	TorNoirB.type = 2;
	ChvNoirA.type = 3;
	ChvNoirB.type = 3;
	FouNoirA.type = 4;
	FouNoirB.type = 4;
	RoiNoir.type = 5;
	ReiNoir.type = 6;

	*(grille) = TorNoirA;
	*(grille + 1) = ChvNoirA;
	*(grille + 2) = FouNoirA;
	*(grille + 3) = ReiNoir;
	*(grille + 4) = RoiNoir;
	*(grille + 5) = FouNoirA;
	*(grille + 6) = ChvNoirA;
	*(grille + 7) = TorNoirA;
	*(grille + 8) = PioNoirA;
	*(grille + 9) = PioNoirB;
	*(grille + 10) = PioNoirC;
	*(grille + 11) = PioNoirD;
	*(grille + 12) = PioNoirE;
	*(grille + 13) = PioNoirF;
	*(grille + 14) = PioNoirG;
	*(grille + 15) = PioNoirH;

	*(grille + 56) = TorBlancA;
	*(grille + 57) = ChvBlancA;
	*(grille + 58) = FouBlancA;
	*(grille + 59) = RoiBlanc;
	*(grille + 60) = ReiBlanc;
	*(grille + 61) = FouBlancA;
	*(grille + 62) = ChvBlancA;
	*(grille + 63) = TorBlancA;
	*(grille + 48) = PioBlancA;
	*(grille + 49) = PioBlancB;
	*(grille + 50) = PioBlancC;
	*(grille + 51) = PioBlancD;
	*(grille + 52) = PioBlancE;
	*(grille + 53) = PioBlancF;
	*(grille + 54) = PioBlancG;
	*(grille + 55) = PioBlancH;

	return grille;
}

int deplacer(pion *grille, int fromX, int fromY, int toX, int toY)
{
	pion current = *(grille + fromX * 8 + fromY);
	pion destination = *(grille + toX * 8 + toY);

	if (current.type == 1) // Pion
	{
		if (fromX == 1 && current.color == 1) // Pion a deplacement de 2 cases possible (côté noir)
		{
			if (toX == 3 && fromY == toY)
			{
				pion empty;
				empty.color = 0;
				empty.type = 0;
				*(grille + toX * 8 + toY) = current;
				*(grille + fromX * 8 + fromY) = empty;
			}
		}
		if (fromX == 6 && current.color == 0) // Pion a deplacement de 2 cases possible (côté blanc)
		{
			if (toX == 4 && fromY == toY)
			{
				pion empty;
				empty.color = 0;
				empty.type = 0;
				*(grille + toX * 8 + toY) = current;
				*(grille + fromX * 8 + fromY) = empty;
			}
		}

		// Il semblerait que suite à 50 lignes de conditions qui ne fonctionnaient pas, j'ai pété un cable, je vous pris de bien vouloir m'en excuser, basiquement ça devait marcher :)
	}
}

void afficherGrille(pion *grille)
{
	printf("     A  B  C  D  E  F  G  H\n");
	printf("  +--------------------------+\n");
	for (int i = 0; i < 8; i++)
	{
		printf("%d | ", 8 - i);
		for (int j = 0; j < 8; j++)
		{
			pion current = *(grille + i * 8 + j);
			printf(" %d ", current.type);
		}
		printf(" |\n");
	}
	printf("  +--------------------------+\n");
}

int main(int argc, char *argv[])
{
	pion *grille = initGrille();
	afficherGrille(grille);
	deplacer(grille, 1, 0, 3, 0);
	deplacer(grille, 6, 1, 4, 1);
	deplacer(grille, 3, 0, 4, 1);

	afficherGrille(grille);

	free(grille);

	return 0;
}
