/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring

 Tests
 diff out.csv turingWinners.csv

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include <stdbool.h>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// VARIABLES
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

typedef struct {
	unsigned short annee;
	char* nom;
	char* sujet;
} Vainqueur;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// FONCTIONS
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*

int numberOfWinners(FILE*) {
	FILE* fichier;
	char* ligneCourante;
	char* champNom;
	int longueurChampNon;
	int nbWinner=0;
	char c;

	while (fgets(ligneCourante,1024,fichier) != NULL) {
		//fgets(ligneCourante,1024,fichier);
		champNom = strtok(ligneCourante,";")[1];
		longueurChampNon=sizeof(champNom)/sizeof(champNom[0]);
		for (int i=0;i<longueurChampNon;i++) {
			if (champNom[i]==",") {
				nbWinner+=1;
			}
			if (strstr(champNom," et ") != NULL) {
				nbWinner+=1;
			}
		}
	}
	return nbWinner;
}

*/

int numberOfWinners(FILE* f) {
	char* ligneCourante;
	int nbWinner=0;
	char filename[] = "turingWinners.csv";

	f = fopen(filename,"r");
	while (fgets(ligneCourante,1024,f) != NULL) {
		nbWinner+=1;
	}
	rewind(f);
	return nbWinner;
}


readWinners(FILE* f) {
	char* ligneCourante;
	char filename[] = "turingWinners.csv";
	f = fopen(filename,"r");
	char* champAnnee;
	char* champNom;
	char* champSujet;

	while (fgets(ligneCourante,1024,f) != NULL) {
		Vainqueur vainqueur;
		vainqueur.annee = strtok(ligneCourante,";")[0];
		vainqueur.nom = strtok(ligneCourante,";")[1];
		vainqueur.sujet = strtok(ligneCourante,";")[2];
	}
}

Vainqueur* readWinners(int nbWinner, FILE* f) {
	Vainqueur* winners = calloc(nbWinner,sizeof(Vainqueur));
	for (int i=0;i<nbWinner;i++) {
		readWinner(&winners[i],f);
	}
	return winners;
}

void readWinner(Vainqueur* winner, FILE* f) {

}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char** argv)
{
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";
	FILE* f;
	FILE* out;

	f = fopen(filename,"r");
	out = fopen(outputFilename,"a");

	int nbWinner = numberOfTuringWinner(f);
	rewind(f);

	//Vainqueur* vainqueur


	char c="";
	while (c != EOF) {
		c = fgetc(f);
		putc(c, out);
	};


    // TODO


	fclose(f);

	return EXIT_SUCCESS;
}



