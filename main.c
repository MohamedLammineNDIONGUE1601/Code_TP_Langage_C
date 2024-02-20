#include "constante.h"
#include<time.h>


int main(int argc, char const *argv[]){

	int i,j;
	int n;
	int k;
	int m; /* n : repr sente le nombre de lignes de la matrice
	            m : repr sente le nombre de colonnes de la matrice */
	CASE c;
    // Déclaration des variables pour mesurer le temps

	do{
		printf("Donner la hauteur de la matrice:  ");
		n = HauteurGrille();

		/*printf("Donner le nombre de colonnes de la matrice: ");
		scanf("%d",&m);*/
	}while((n<2||n>N)&&(m<2||m>M));
	m = 3*n - 3;
	CreationGrille(c.grille,n,m);
    AfficheGrille(c.grille,n,m);
	printf("\n\n");

    printf("Nombre total de cases jouables = %d\n", NombreDeCasesJouables(c.grille,n,m));

    int nombresDeMines = Probabilite(n);
    AjoutMines(nombresDeMines,c.grille,n,m);
    printf("Nombre total de mine dans la grille : %d\n", Probabilite(n));

    printf("\n\n\n");
    NombreDeCasesAdjacentes(c.grille,n,m);
    JeuDemineur(c.grille,n,m);
        return 0;
}
