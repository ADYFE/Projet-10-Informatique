#include "Fonction.h"

// Nouvelle fonction pour écrire un fichier texte
void ecrireFichierTexte() {
    char nomFichier[256];
    char buffer[1024];
    FILE *fichier;

    printf("\nEntrez le nom du fichier a creer (avec l'extension .txt): ");
    scanf("%255s", nomFichier); // L'utilisateur devra entrer un nom a un mot car avec scanf le programme compte uniquement un mot. Avec fgets ou gets le programme ne marche pas.

    fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        printf("Erreur lors de la creation du fichier!\n");
        return;
    }

    printf("Entrez le texte (tapez 'FIN' sur une nouvelle ligne pour terminer):\n");
    getchar(); // Pour consommer le newline precedent

    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        
        if (strcmp(buffer, "FIN\n") == 0) {
            break;
        }
        
        fputs(buffer, fichier);
    }

    fclose(fichier);
    printf("Le fichier %s a ete cree avec succes!\n", nomFichier);
}

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

// Fonction de comparaison pour le tri des frequences
int comparerFrequences(const void *a, const void *b) {
    return ((FrequenceMot *)b)->frequence - ((FrequenceMot *)a)->frequence;
}

// Fonction pour afficher les mots les plus frequents
void afficherMotsFrequents(int n) {
    qsort(dictionnaire, nombreMots, sizeof(FrequenceMot), comparerFrequences);

    printf("\nMots les plus frequents:\n");
    for(int i = 0; i < n && i < nombreMots; i++) {
        printf("%s: %d fois\n", dictionnaire[i].mot, dictionnaire[i].frequence);
    }
}

// Fonction pour rechercher la frequence d'un mot
void rechercherFrequenceMot(const char *mot) {
    char motRecherche[LONGUEUR_MAX_MOT];
    strcpy(motRecherche, mot);
    convertirEnMinuscules(motRecherche);

    for(int i = 0; i < nombreMots; i++) {
        if(strcmp(dictionnaire[i].mot, motRecherche) == 0) {
            printf("\nLe mot '%s' apparait %d fois\n", mot, dictionnaire[i].frequence);
            return;
        }
    }
    printf("\nLe mot '%s' n'a pas ete trouve dans le texte\n", mot);
}

// Fonction pour sauvegarder les statistiques dans un fichier
void sauvegarderStatistiques(const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "w");
    if(fichier == NULL) {
        printf("Erreur lors de la creation du fichier de sortie!\n");
        return;
    }

    fprintf(fichier, "Statistiques de frequence des mots:\n\n");
    for(int i = 0; i < nombreMots; i++) {
        fprintf(fichier, "%s: %d\n", dictionnaire[i].mot, dictionnaire[i].frequence);
    }

    fclose(fichier);
    printf("\nStatistiques sauvegardees dans %s\n", nomFichier);
}