#include "constante.h"
#include<stdio.h>
#include <time.h>

int HauteurGrille(){

	int haut;

	scanf("%d", &haut);

	return haut;
}
void CreationGrille(char grille[][M] ,int n ,int m){

     int i, j, k;
     for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){

			grille[i][j] = ' '; /// On initialise la matrice   vide
		}
	 }
	 for(j = 2; j < m-2; j++){
		grille[n/2][j]='z';
	 }
	i = 0;
	while(i<=n/2){
		for(j=0;j<m/3;j++){
			grille[i][i+j] = 'z';
        }
        for(j=(m/2)+2;j<m;j++){
            grille[i][j-i] = 'z';
        }
        i++;
	}
    k = 0;
	i = (n/2)+1;
	while(i<n){
		for(j = (m/2)+1; j < m-1; j++){
			grille[i][j+k] = 'z';
		}
		for(j = 1; j <=m/3; j++){
			grille[i][j-k] = 'z';
		}
		i++;
		k++;
	}
}
void AfficheGrille(char grille[][M] , int n, int m){

    int i,j, k;
    printf("   ");
    for(j =0; j<m;j++){
        printf(" %X  ",j);
    }
    printf("  ");
    printf("\n");
    for(i=0;i<n;i++){
    	printf("  ");
        for(k = 0; k < m; k++){
            printf("+---");
        }
		printf("\n");
        printf("%X",i);
        for(j=0;j<m;j++){
            printf(" | \x1b[32m%c\x1b[0m",grille[i][j]);
        }
        printf(" |");
        printf("\n");
    }
    printf("  ");
    for(i = 0; i < m; i++){
        printf("+---");
    }
}
int NombreDeCasesJouables(char grille[][M], int n , int m){

     int k;
     int i, j;
     k = 0;
     for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(grille[i][j] == 'z'){
                k ++;
            }
        }
    }
    return k;
}

void NombreDeCasesAdjacentes(char grille[][M], int n, int m){

        int i, j;
      // Nombre de mines dans les cases adjascentes
        for (i = 0; i < n; i++){
            for (j = 0; j < m; j++) {
                if(grille[i][j]!=' '){
                // Si la case actuelle n'est pas une mine
                    if (grille[i][j] != 'M') {
                        int minesAdjacentes = 0;
                        // V rification les cases adjacentes
                        for (int dx = -1; dx <= 1; dx++) {
                            for (int dy = -1; dy <= 1; dy++) {
                                int ni = i + dx;
                                int nj = j + dy;
                                // V rification si la case adjacente est dans la grille
                                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                                    // Si la case adjacente est une mine
                                    if (grille[ni][nj] == 'M') {
                                        minesAdjacentes++;
                                    }
                                }
                            }
                        }
                        // affichage de nombre de mines adjacentes dans la case
                        grille[i][j] = minesAdjacentes + '0';
                      }
                }
                else{
                    grille[i][j]=' ';
                }
            }
        }
}

void JeuDemineur(char grille[][M], int n, int m){

    clock_t startTime, endTime;
    double gameTimeInSeconds;
    endTime = clock();
    startTime = clock();
    gameTimeInSeconds = ((double)(endTime-startTime)) / CLOCKS_PER_SEC;
    FILE*f1, *f2;
    int i,j, k;
    //  affichage de la grille mise  a jour
    printf("   ");
    for(j =0; j<m;j++){
        printf(" %X  ",j);
    }
    printf("  ");
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("  ");
        for(k = 0; k < m; k++){
            printf("+---");
        }
        printf("\n");
        printf("%X",i);
        for (j = 0; j < m; j++) {
            printf(" | \x1b[31m%c\x1b[0m", grille[i][j]);
        }
        printf(" |");
        printf("\n");
    }
    printf("  ");
    for(i = 0; i < m; i++){
        printf("+---");
    }
    printf("\n\n\n");
    printf("\n\n\n");
    char etatCache[N][M]; //avec N et M les dimensions maximales de notre matrices
    // Initialisation de la matrice d' tat cach  avec des caract res cach s (par exemple, '*')
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if(grille[i][j]!=' '){
                etatCache[i][j] = '*';
            }
            else{
                etatCache[i][j] = ' ';
            }
        }
    }
    // Affichage de la grille cachée
    printf("Grille cachee pour commencer le jeu:\n");
    printf("   ");
    for(j =0; j<m;j++){
        printf(" %X  ",j);
    }
    printf("  ");
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("  ");
        for(k = 0; k < m; k++){
            printf("+---");
        }
        printf("\n");
        printf("%X",i);
        for (j = 0; j < m; j++) {
            if (grille[i][j] == ' ') {
                printf(" |  ");  // Ne pas afficher les espaces
            }
            else {
                printf(" | \x1b[91m%c\x1b[0m", etatCache[i][j]);
            }
        }
        printf(" |");
        printf("\n");
    }
    printf("  ");
    for(i = 0; i < m; i++){
        printf("+---");
    }
    printf("\n");
    printf("\n\n\n");
    int x, y;
    // Enregistrement du temps de début
    startTime = clock();
    // Utilisation une boucle pour permettre   l'utilisateur de continuer   donner des coordonn es
    while (1) {
        int choice;
        int nombreDeMines=Probabilite(n);
        printf("Choisissez une action (1: Reveler, 2: Marquer drapeau,3:Enlever le marquage) : ");
        scanf("%d", &choice);
        // Demande a l'utilisateur de donner les coordonn es
        printf("Entrez la coordonnee x : ");
        scanf("%d", &x);
        printf("Entrez la coordonnee y : ");
        scanf("%d", &y);
        if(grille[x][y]!=' '){
            if (choice == 1) {
                // Verification si les coordonnees sont valides
                // Affichage des cases autour de la coordonnee fournie par l'utilisateur et cach les autres
                printf("  ");
                for(j =0; j<m;j++){
                    printf(" %X  ",j);
                }
                printf("  ");
                printf("\n");
                for (int i = 0; i < n; i++){
                    printf("  ");
                    for(k = 0; k < m; k++){
                        printf("+---");
                    }
                    printf("\n");
                    printf("%X",i);
                    for(int j = 0; j < m; j++) {
                        if ( grille[i][j] == 'M') {
                            printf(" | \x1b[91m*\x1b[0m");  // Cacher les mines
                        }
                        else if (i >= x - 1 && i <= x + 1 && j >= y - 1 && j <= y + 1) {
                            if(grille[i][j]!=' '){ 
                                printf(" | \x1b[95m%c\x1b[0m", grille[i][j]);  // Afficher les cases autour
                                etatCache[i][j] = grille[i][j];  //Mise a jour de la grille cachee
                            } 
                        }
                        else{ 
                            printf(" | \x1b[94m%c\x1b[0m", etatCache[i][j]);  // Cacher les autres cases
                        }
                    }
                    printf(" |");
                    printf("\n");
                }
                printf("  ");
                for(i = 0; i < m; i++){
                    printf("+---");
                }
                printf("\n\n\n");
                printf("\n\n\n");
                // Affichage de la grille complète
                printf("Grille mise a jour Affichage des cases adjascentes et des cases marquees:\n");
                printf("  ");
                for(j =0; j<m;j++){
                    printf(" %X  ",j);
                }
                printf("  ");
                printf("\n");
                for (int i = 0; i < n; i++){
                    printf("  ");
                    for(k = 0; k < m; k++){
                        printf("+---");
                    }
                    printf("\n");
                    printf("%X",i);
                    if(etatCache[i][j] != ' '){
                        for (int j = 0; j < m; j++) { 
                            printf(" | \x1b[93m%c\x1b[0m", etatCache[i][j]);// Afficher les cases avec les drapeaux et les cases révélées 
                        }
                    }
                    printf(" |");
                    printf("\n");
                }
                printf("  ");
                for(i = 0; i < m; i++){
                    printf("+---");
                }
                printf("\n\n\n");
                printf("\n\n\n");
                // Verification si la case choisie contient une mine
                endTime = clock();
                startTime = clock();
                gameTimeInSeconds = ((double)(endTime-startTime)) / CLOCKS_PER_SEC;
                if (grille[x][y] == 'M') {
                    f1 = fopen("DISQUE1.txt","w");
                    printf("Boom! Vous avez touche une mine!\n");
                    fprintf(f1, " Hauteur = %d\n", n);
                    fprintf(f1, "Nombre de mines = %d\n", nombreDeMines);
                    fprintf(f1,"Temps de jeu = %.2f\n", -gameTimeInSeconds);
                    exit(1); // Sortie de la boucle car le jeu est termin
                } 
            }
            else if (choice == 2){
                /*printf("Donner les coordonees x et y de la case a marquer:");
                scanf("%d %d", &x, &y);
                // Marquage avec un drapeau*/
                etatCache[x][y] = 'F';
                // Affichage de la grille complète
                printf("Grille mise a jour Affichage des cases adjascentes et des cases marquees:\n");
                printf("  ");
                for(j =0; j<m;j++){
                    printf(" %X  ",j);
                }
                printf("  ");
                printf("\n");
                for (int i = 0; i < n; i++){
                    printf("  ");
                    for(k = 0; k < m; k++){
                        printf("+---");
                    }
                    printf("\n");
                    printf("%X",i);
                    for (int j = 0; j < m; j++) {     
                        printf(" | \x1b[92m%c\x1b[0m", etatCache[i][j]);// Afficher les cases avec les drapeaux et les cases révélées
                    }
                    printf(" |");
                    printf("\n");
                }
                printf("  ");
                for(i = 0; i < m; i++){
                    printf("+---");
                }
                printf("\n\n\n");
                printf("\n\n\n");
            }
            else 
            if (choice==3){
                /*printf("Donner les coordonée x et y de la case a enlever");
                scanf("%d %d", &x, &y);*/
                //Enlever le marquage
                etatCache[x][y] = '*';
                // Affichage de la grille complète
                printf("Grille mise a jour Affichage des cases adjascentes et des cases marquees:\n");
                printf("  ");
                for(j =0; j<m;j++){
                    printf(" %X  ",j);
                }
                printf("  ");
                printf("\n");
                for (int i = 0; i < n; i++){
                    printf("  ");
                    for(k = 0; k < m; k++){
                        printf("+---");
                    }
                    printf("\n");
                    printf("%X",i);
                    for (int j = 0; j < m; j++) {
                        if(etatCache[i][j] == '1'){
                            printf(" |  \x1b[32m%c\x1b[0m  ", etatCache[i][j]);
                        }
                        else if(etatCache[i][j] == '0'){
                            printf(" |  \x1b[31m%c\x1b[0m  ", etatCache[i][j]);
                        }
                        else if(etatCache[i][j] == '2'){
                            printf(" |  \x1b[36m%c\x1b[0m  ", etatCache[i][j]);
                        }
                        else if(etatCache[i][j] == '*'){
                            printf(" |  \x1b[34m%c\x1b[0m  ", etatCache[i][j]);// Afficher les cases avec les drapeaux et les cases révélées
                        }
                    }
                    printf(" |");
                    printf("\n");
                }
                printf("  ");
                for(i = 0; i < m; i++){
                    printf("+---");
                }
                printf("\n\n\n");
                printf("\n\n\n");
            }
            int TotalCasesReveleesAndMarquees = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (etatCache[i][j] == 'F' || etatCache[i][j] != '*'||etatCache[i][j]==' '||etatCache[i][j] == '1' || etatCache[i][j] == '2' || etatCache[i][j] =='0' ) {
                        TotalCasesReveleesAndMarquees++;
                    }
                }
            }
            if (TotalCasesReveleesAndMarquees== n * m){
                // Enregistrement du temps de fin
                f2 = fopen("DISQUE2.txt","w");
                printf("Felicitations ! Toutes les cases sont marquees et revelees. Vous avez gagne !\n");
                printf("Temps de jeu : %.2f secondes\n", -gameTimeInSeconds);
                fprintf(f2, " Hauteur = %d\n", n);
                fprintf(f2, "Nombre de mines = %d\n", nombreDeMines);
                fprintf(f2,"Temps de jeu = %.2f\n", -gameTimeInSeconds);
                exit(1);
            }
        }
        else{
            printf("Erreur ! . Veillez rejouer dans la bonne zone.\n");
        }
    }
    fclose(f1);
    fclose(f2);
}

int Probabilite(int n){
    int h1;
    h1 = 2*(n-1)*n*0.1;
    return h1;
}

int NombreDeCasJouable(int n){

    return n*(2*(n-1));
}


// Ajouter des mines de mani re al atoire de la grille
void AjoutMines(int nombresDeMines, char grille[][M], int n, int m){
    srand(time(NULL));
    int k;
    for(k = 0; k < nombresDeMines; k++){
        int ligne = rand() % n;
        int colonne = rand() % m;
        while(grille[ligne][colonne] == 'M' || grille[ligne][colonne] == ' '){
            ligne = rand() % n;
            colonne = rand() % m;
        }
        grille[ligne][colonne] = 'M';
    }
}
