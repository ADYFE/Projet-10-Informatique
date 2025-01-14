#include "Fonction.c"

int main() {
    char nomFichier[256];
    char choix;
    char motRecherche[LONGUEUR_MAX_MOT];

    // Initialiser le dictionnaire
    initialiserDictionnaire();

    while(1) {
        printf("\n========== Menu de l'Analyseur de Texte ==========\n");
        printf("1. Creer un nouveau fichier texte\n");
        printf("2. Analyser un fichier texte existant\n");
        printf("3. Afficher les mots les plus frequents (top 10)\n");
        printf("4. Recherhcer la frequence d'un mot\n");
        printf("5. Sauvegarder les statistiques dans un fichier\n");
        printf("6. Quitter\n");
        printf("Entrez votre choix: ");
        scanf(" %c", &choix);

        switch(choix) {
            case '1':
                ecrireFichierTexte();
                break;
            case '2':
                // Libérer la memoire precedente si necessaire
                if(nombreMots > 0) {
                    libererDictionnaire();
                    initialiserDictionnaire();
                }
                printf("Entrez le nom du fichier a analyser: ");
                scanf("%s", nomFichier);
                analyserFichier(nomFichier);
                break;

            case '3':
                afficherMotsFrequents(10);
                break;

            case '4':
                printf("Entrez le mot a rechercher: ");
                scanf("%s", motRecherche);
                rechercherFrequenceMot(motRecherche);
                break;

            case '5':
                printf("Entrez le nom du fichier de sortie: ");
                scanf("%s", nomFichier);
                sauvegarderStatistiques(nomFichier);
                break;

            case '6':
                libererDictionnaire();
                printf("Au revoir!\n");
                return 0;

            default:
                printf("Choix invalide! Veuillez reessayer.\n");
        }
    }

    return 0;
}