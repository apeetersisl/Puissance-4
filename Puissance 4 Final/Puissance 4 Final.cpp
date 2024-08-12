#include <stdio.h>
/*Malheureusement ma fonction Print grille m'empèche de mettre mes fonctions dans des fichiers séparés*/
#define NbCol 7
#define NbLine 6
int GrilleP4[NbLine][NbCol] = { 0 };
int IxCol;
int IxLine;
int WON = 0;

/* Test de case libre dans la colone demandée du tableau + Vérification colonne pleine / valide */
int Emptycase(int GrilleP4[NbLine][NbCol], int IxCol)
{
	if (IxCol<0 || IxCol>NbCol - 1)
	{
		printf("Ceci n'est pas une colonne valide, veuillez en entrer une nouvelle.");
		IxLine = -2;
		return IxLine;
	}
	if (GrilleP4[NbLine - 1][IxCol] == 0)
	{
		IxLine = NbLine - 1;
		return IxLine;
	}
	for (IxLine = (NbLine - 1); (GrilleP4[IxLine][IxCol] != 0) && (IxLine >= 0); IxLine--)
	{
		if (IxLine == 0)
		{
			printf("La colonne choisie est pleine, veuillez en choisir une autre.");
			IxLine = -1;
			return IxLine;
		}
	}
	return IxLine;
}
/* Test si un joueur gagne ou non */
int WinTest(int GrilleP4[NbLine][NbCol], int IxLine, int IxCol)
{
	/* Test Diagonal */
	if ((IxCol < 4) && (IxLine < 3))
	{
		if (GrilleP4[IxLine][IxCol] == GrilleP4[IxLine + 1][IxCol + 1] == GrilleP4[IxLine + 2][IxCol + 2] == GrilleP4[IxLine + 3][IxCol + 3] == 1)
		{
			WON = 1;
			return WON;
		}
		if (GrilleP4[IxLine][IxCol] == GrilleP4[IxLine + 1][IxCol + 1] == GrilleP4[IxLine + 2][IxCol + 2] == GrilleP4[IxLine + 3][IxCol + 3] == 2)
		{
			WON = 2;
			return WON;
		}
	}
	if ((IxCol > 2) && (IxLine > 2))
	{
		if (GrilleP4[IxLine][IxCol] == GrilleP4[IxLine - 1][IxCol - 1] == GrilleP4[IxLine - 2][IxCol - 2] == GrilleP4[IxLine - 3][IxCol - 3] == 1)
		{
			WON = 1;
			return WON;
		}
		if (GrilleP4[IxLine][IxCol] == GrilleP4[IxLine - 1][IxCol - 1] == GrilleP4[IxLine - 2][IxCol - 2] == GrilleP4[IxLine - 3][IxCol - 3] == 2)
		{
			WON = 2;
			return WON;
		}
	}
	if ((IxCol > 2) && (IxLine < 3))
	{
		if (GrilleP4[IxLine][IxCol] == GrilleP4[IxLine + 1][IxCol - 1] == GrilleP4[IxLine + 2][IxCol - 2] == GrilleP4[IxLine + 3][IxCol - 3] == 1)
		{
			WON = 1;
			return WON;
		}
		if (GrilleP4[IxLine][IxCol] == GrilleP4[IxLine + 1][IxCol - 1] == GrilleP4[IxLine + 2][IxCol - 2] == GrilleP4[IxLine + 3][IxCol - 3] == 2)
		{
			WON = 2;
			return WON;
		}
	}
	if ((IxLine > 2) && (IxCol < 4))
	{
		if (GrilleP4[IxLine][IxCol] == GrilleP4[IxLine - 1][IxCol + 1] == GrilleP4[IxLine - 2][IxCol + 2] == GrilleP4[IxLine - 3][IxCol + 3] == 1)
		{
			WON = 1;
			return WON;
		}
		if (GrilleP4[IxLine][IxCol] == GrilleP4[IxLine - 1][IxCol + 1] == GrilleP4[IxLine - 2][IxCol + 2] == GrilleP4[IxLine - 3][IxCol + 3] == 2)
		{
			WON = 2;
			return WON;
		}
	}
	/* Test Horizontal */
	if (GrilleP4[IxLine][IxCol] == 1 && GrilleP4[IxLine][IxCol + 1] == 1 && GrilleP4[IxLine][IxCol + 2] == 1 && GrilleP4[IxLine][IxCol + 3] == 1)
	{
		WON = 1;
		return WON;
	}
	if (GrilleP4[IxLine][IxCol] == 2 && GrilleP4[IxLine][IxCol + 1] == 2 && GrilleP4[IxLine][IxCol + 2] == 2 && GrilleP4[IxLine][IxCol + 3] == 2)
	{
		WON = 2;
		return WON;
	}
	if (GrilleP4[IxLine][IxCol] == 1 && GrilleP4[IxLine][IxCol - 1] == 1 && GrilleP4[IxLine][IxCol - 2] == 1 && GrilleP4[IxLine][IxCol - 3] == 1)
	{
		WON = 1;
		return WON;
	}
	if (GrilleP4[IxLine][IxCol] == 2 && GrilleP4[IxLine][IxCol - 1] == 2 && GrilleP4[IxLine][IxCol - 2] == 2 && GrilleP4[IxLine][IxCol - 3] == 2)
	{
		WON = 2;
		return WON;
	}
	/* Test Vertical */
	if (GrilleP4[IxLine][IxCol] == 1 && GrilleP4[IxLine + 1][IxCol] == 1 && GrilleP4[IxLine + 2][IxCol] == 1 && GrilleP4[IxLine + 3][IxCol] == 1)
	{
		WON = 1;
		return WON;
	}
	if (GrilleP4[IxLine][IxCol] == 2 && GrilleP4[IxLine + 1][IxCol] == 2 && GrilleP4[IxLine + 2][IxCol] == 2 && GrilleP4[IxLine + 3][IxCol] == 2)
	{
		WON = 2;
		return WON;
	}
	/* Si aucun test concluant*/
	WON = 0;
	return WON;
}

void PrintGrille(int GrilleP4[NbLine][NbCol])
{
	for (IxLine = 0; IxLine < NbLine; IxLine++)
	{
		for (IxCol = 0; IxCol < NbCol; IxCol++)
		{
			if (IxCol < (NbCol - 1))
			{
				printf("( %d )", GrilleP4[IxLine][IxCol]);
			}
			else
			{
				printf("( %d ) \n", GrilleP4[IxLine][IxCol]);
			}
		}
	}
	return;
}


int main()
{

	int Turn = 1;
	int Player = Turn % 2;
	int ColChosen;
	printf("Joueur 1, vous jouez avec les 1. \nJoueur 2, vous jouez avec les 2. \nJoueur 1, commencez par indiquer la colonne ou vous voulez placer votre pion.\n");
	while (Turn != (NbCol * NbLine) || WON == 1 || WON == 2)
	{

		Player = Turn % 2;
		PrintGrille(GrilleP4);
		scanf_s("%d", &ColChosen);
		IxCol = ColChosen - 1;
		IxLine = Emptycase(GrilleP4, IxCol);
		while (IxLine == -1 || IxLine == -2)
		{
			scanf_s("%d", &ColChosen);
			IxCol = ColChosen - 1;
			IxLine = Emptycase(GrilleP4, IxCol);
			while ((getchar()) != '\n');
		}
		if (Player != 0)
		{
			GrilleP4[IxLine][IxCol] = 1;
			WON = WinTest(GrilleP4, IxLine, IxCol);
			if (WON == 1)
			{
				PrintGrille(GrilleP4);
				printf("Bravo joueur 1, vous avez gagne! \n");
				printf("Merci d'avoir joue !");
				return 0;
			}
			printf("Joueur 2, a vous de jouer \n");
		}
		else
		{
			GrilleP4[IxLine][IxCol] = 2;
			WON = WinTest(GrilleP4, IxLine, IxCol);
			if (WON == 2)
			{
				PrintGrille(GrilleP4);
				printf("Bravo joueur 2, vous avez gagne! \n");
				printf("Merci d'avoir joue !");
				return 0;
			}
			printf("Joueur 1, a vous de jouer \n");
		}
		Turn = Turn++;
	}

	printf("Pas de gagnant cette fois ci...Merci d'avoir joue !");

}

