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

int numberOfWinners(FILE* f) {
	int nbWinner=0;
	char ch;
	while ((ch = fgetc(f)) != EOF) {
		if (ch == '\n') {
			nbWinner = nbWinner+1;
		}
	}
	return nbWinner;
}
//Réponse du debuggeur: nbWinner = 57


/*

void readWinner(FILE* f, Vainqueur* winners, int count) {
	char line[1024];
	int i=0;
	while (fgets(line,sizeof(line),f) && i < count) {
		char* token = strtok(line,";");
		winners[i].annee=atoi(token);
		token=strtok(NULL,";");
		winners[i].nom = malloc(strlen(token)+1);
		strcpy(winners[i].nom,token);
	}
}

*/

Vainqueur* readWinners(int nbWinner, FILE* f) {
    Vainqueur* winners = malloc(nbWinner * sizeof(Vainqueur));
	char ligneCourante[1024];
    for (int i = 0; i < nbWinner; i++) {
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
		printf("%u;%s;%s\n", winners[i].annee, winners[i].nom, winners[i].sujet);
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
	out = fopen(outputFilename,"w");

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

	printWinners(winners, nbWinner, out);

	/*
	int c;
	while ((c= fgetc(f)) != EOF) {
		putc(c, out);
	};
	*/

   for (int i = 0; i < nbWinner; i++) {
        free(winners[i].nom);
        free(winners[i].sujet);
    }
    free(winners);

	fclose(f);
	fclose(out);

	return EXIT_SUCCESS;
}



