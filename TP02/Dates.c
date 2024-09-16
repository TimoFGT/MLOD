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
    enum mois ceMois;
    int annee;
};