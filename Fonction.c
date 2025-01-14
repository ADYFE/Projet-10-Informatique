#include "Fonction.h"

// Fonction pour analyser le fichier texte
void analyserFichier(const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "r");
    if(fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier!\n");
        return;
    }

    char mot[LONGUEUR_MAX_MOT];
    int lignes = 1, caracteres = 0, mots = 0;
    int ch;
    int dernierCaractere = '\n';  // Initialiser à un saut de ligne pour gérer les fichiers vides

    while((ch = fgetc(fichier)) != EOF) {
        caracteres++;

        if(ch == '\n') {
            lignes++;
        }

        if(isspace(ch)) {
            if(strlen(mot) > 0) {
                ajouterMotAuDictionnaire(mot);
                mots++;
                mot[0] = '\0';
            }
        } else {
            int len = strlen(mot);
            if(len < LONGUEUR_MAX_MOT - 1) {
                mot[len] = ch;
                mot[len + 1] = '\0';
            }
        }

        dernierCaractere = ch;
    }

    // Traiter le dernier mot s'il existe
    if(strlen(mot) > 0) {
        ajouterMotAuDictionnaire(mot);
        mots++;
    }

    // Ajuster le comptage des lignes pour les fichiers sans saut de ligne final
    if(dernierCaractere != '\n' && caracteres > 0) {
        lignes++;
    }

    printf("\nStatistiques du fichier:\n");
    printf("Nombre de lignes: %d\n", lignes-1);
    printf("Nombre de mots: %d\n", mots);
    printf("Nombre de caracteres: %d\n", caracteres);

    fclose(fichier);
}