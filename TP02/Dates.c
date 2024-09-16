enum mois {
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
};

struct Date {
    int jour;
    enum mois Mois;
    int annee;
};

void main(void) {
    struct Date d;
    initialiseDate(&d);
    afficheDate(&d);
    d = creerDateParCopie();
};

void initialiseDate(struct Date *d) {
    int CeJour;
    enum mois CeMois;
    int CetteAnnee;
    scanf("%d %s %d", CeJour, CeMois, CetteAnnee);
}

struct Date *afficheDate(struct Date *d) {
    return (&d);
}

