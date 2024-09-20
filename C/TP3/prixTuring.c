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

struct prixTuring {
	unsigned short annee;
	char* nom;
	char* sujet;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// FONCTIONS
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


int numberOfWinners(FILE* farg) {
	char c="";
	int numeroChamp=1;
	bool champNon = false;
	FILE* fichier;
	int nbLignes=0;
	while (c != EOF) {
		c=fgetc(fichier);
		if (c == "\n") {
			//On est sur une nouvelle ligne
			while(c != "\n") {
				
			}

		}
	};
	return nbLignes;
}

readWinners(FILE* ) {

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

	char c="";
	while (c != EOF) {
		c = fgetc(f);
		putc(c, out);
	};


    // TODO


	fclose(f);

	return EXIT_SUCCESS;
}



