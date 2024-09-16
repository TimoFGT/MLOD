#include <stdio.h>
#include <stdbool.h>

// Types
typedef enum {
    janvier,
    février,
    mars,
    avril,
    mai,
    juin,
    juillet,
    aout,
    septembre,
    octobre,
    novembre,
    decembre,
} Mois;

typedef struct {
    int jour;
    Mois mois;
    int annee;
} Date;


// Fonctions

bool estBissextile(short annee);

bool estDateValide(Date* d);
short nombreDeJoursDansLeMois(Date *d);
bool isDateValide(Date *d);
char* libelleMois(Mois m);

void afficherDate(Date *d);
void initialiseDate(Date *d);
Date* newDate();


int main(void) {
    Date d;
    printf("Version 1: initialisation d'une date allouée statiquement\n");
    initialiseDate(&d);
    afficheDate(&d);

    printf("\nVersion 2: recopie d'une date alloué statiquement\n");
    d = creerDateParCopie();
    afficheDate(&d);

    printf("\nVersion 3: allocation dynamique de date\n");
    Date *pDate;
    pDate = newDate();
    afficherDate(pDate);
    free(pDate);
    pDate=NULL;

    printf("\nVersion 3.1: allocation dynamique d'un tableau de date\nCette dernière version sera celle à privilégier notamment dans les prochains TD sur les matrices ou les listes\n");
};

void initialiseDate(Date *d) {
    bool dValide = false;

    do {
        printf("jour: ");
        scanf("%hu",&(d->jour));
        printf("mois: ");
        scanf("%d",(int *)&d->mois);
        printf("annee: ");
        scanf("%hu",&d->annee);

        if(!(dValide=estDateValide(d))) {
            printf("\t date invalide !");
            afficherDate(d);
        }
    } while (!dValide);
}

// Retourne une date initialisé par copie
Date creerDateParCopie() {
    Date d;
    initialiseDate(&d);
    return d;
};

// Alloue dynamiquement une date, l'initialise et retourne son adresse
Date* newDate() {
    Date *d = (Date*)malloc(sizeof(Date));
    initialiseDate(d);
    return d;
}