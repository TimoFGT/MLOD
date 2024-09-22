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
	char ligneCourante[1024];
	int nbWinner=0;
	char filename[] = "turingWinners.csv";

	f = fopen(filename,"r");
	while (fgets(ligneCourante,1024,f) != NULL) {
		nbWinner+=1;
	}
	rewind(f);

	return nbWinner;
}

Vainqueur* readWinners(int nbWinner, FILE* f) {
    Vainqueur* winners = calloc(nbWinner, sizeof(Vainqueur));
    for (int i = 0; i < nbWinner; i++) {
        char ligneCourante[1024];
        if (fgets(ligneCourante, sizeof(ligneCourante), f) != NULL) {
            char* champAnnee = strtok(ligneCourante, ";");
            char* champNom = strtok(NULL, ";");
            char* champSujet = strtok(NULL, ";");

            if (champAnnee != NULL && champNom != NULL && champSujet != NULL) {
                winners[i].annee = atoi(champAnnee);
                winners[i].nom = strdup(champNom);
                winners[i].sujet = strdup(champSujet);
            }
        }
    }
    return winners;
}

void printWinners(Vainqueur* winners, int nbWinners, FILE* out) {
    for (int i = 0; i < nbWinners; i++) {
        fprintf(out, "%u;%s;%s\n", winners[i].annee, winners[i].nom, winners[i].sujet);
    }
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

	if (f == NULL) {
        fprintf(stderr, "Erreur : impossible d'ouvrir le fichier %s\n", filename);
        return EXIT_FAILURE;
    }
	if (out == NULL) {
        fprintf(stderr, "Erreur : impossible d'ouvrir le fichier %s\n", outputFilename);
        return EXIT_FAILURE;
    }

	int nbWinner = numberOfWinners(f);
	rewind(f);

	Vainqueur* winners = readWinners(nbWinner, f);
	rewind(f);

	/*
	int c;
	while ((c= fgetc(f)) != EOF) {
		putc(c, out);
	};
	*/

	printWinners(winners, nbWinner, out);


   for (int i = 0; i < nbWinner; i++) {
        free(winners[i].nom);
        free(winners[i].sujet);
    }
    free(winners);

	fclose(f);
	fclose(out);

	return EXIT_SUCCESS;
}



