#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define N 30
#define M 30


typedef struct Case{
        int hauteur;
        char grille[N][M];
}CASE;

int HauteurGrille();
void CreationGrille(char grille[][M] ,int ,int );
void AfficheGrille(char grille[][M] , int , int );
int Probabilite(int );
int NombreDeCasesJouables(char grille[][M], int , int );
void NombreDeCasesAdjacentes(char grille[][M], int , int );
void JeuDemineur(char grille[][M], int , int );
void AjoutMines(int nombresDeMines, char grille[][M], int , int );

