#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LONGUEUR_MAX_MOT 256

// Structure pour stocker le mot et sa frequence
typedef struct {
    char *mot;
    int frequence;
} FrequenceMot;

// Variables globales
FrequenceMot *dictionnaire = NULL;
int nombreMots = 0;
int capaciteDictionnaire = 0;

void initialiserDictionnaire();
void redimensionnerDictionnaire();
void libererDictionnaire();
void convertirEnMinuscules(char *mot);
void ajouterMotAuDictionnaire(char *mot);
void ecrireFichierTexte();
void analyserFichier(const char *nomFichier);
int comparerFrequences(const void *a, const void *b);
void afficherMotsFrequents(int n);
void rechercherFrequenceMot(const char *mot);
void sauvegarderStatistiques(const char *nomFichier);