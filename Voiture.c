#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VEHICULES 100

// Structure pour représenter un véhicule
typedef struct {
    char marque[50];
    char modele[50];
    int annee;
    char couleur[50];
} Vehicule;

Vehicule vehicules[MAX_VEHICULES];
int nbVehicules = 0;

// Fonction pour vider le buffer du clavier
void viderBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Fonction pour ajouter un véhicule
void ajouterVehicule() {
    printf("=== AJOUTER UN VEHICULE ===\n");

    if (nbVehicules == MAX_VEHICULES) {
        printf("Le nombre maximal de véhicules a été atteint. Impossible d'ajouter un nouveau véhicule.\n");
        return;
    }

    Vehicule vehicule;

    printf("Marque : ");
    fgets(vehicule.marque, sizeof(vehicule.marque), stdin);
    vehicule.marque[strcspn(vehicule.marque, "\n")] = '\0';

    printf("Modèle : ");
    fgets(vehicule.modele, sizeof(vehicule.modele), stdin);
    vehicule.modele[strcspn(vehicule.modele, "\n")] = '\0';

    printf("Année : ");
    scanf("%d", &vehicule.annee);
    viderBuffer();

    printf("Couleur : ");
    fgets(vehicule.couleur, sizeof(vehicule.couleur), stdin);
    vehicule.couleur[strcspn(vehicule.couleur, "\n")] = '\0';

    vehicules[nbVehicules] = vehicule;
    nbVehicules++;

    printf("Le véhicule a été ajouté avec succès.\n");
}

// Fonction pour modifier un véhicule
void modifierVehicule() {
    printf("=== MODIFIER UN VEHICULE ===\n");

    if (nbVehicules == 0) {
        printf("Aucun véhicule enregistré. Impossible de modifier.\n");
        return;
    }

    printf("Marque du véhicule à modifier : ");
    char marque[50];
    fgets(marque, sizeof(marque), stdin);
    marque[strcspn(marque, "\n")] = '\0';

    bool vehiculeTrouve = false;
    for (int i = 0; i < nbVehicules; i++) {
        if (strcmp(vehicules[i].marque, marque) == 0) {
            vehiculeTrouve = true;

            printf("Nouvelle marque : ");
            fgets(vehicules[i].marque, sizeof(vehicules[i].marque), stdin);
            vehicules[i].marque[strcspn(vehicules[i].marque, "\n")] = '\0';

            printf("Nouveau modèle : ");
            fgets(vehicules[i].modele, sizeof(vehicules[i].modele), stdin);
            vehicules[i].modele[strcspn(vehicules[i].modele, "\n")] = '\0';

            printf("Nouvelle année : ");
            scanf("%d", &vehicules[i].annee);
            viderBuffer();

            printf("Nouvelle couleur : ");
            fgets(vehicules[i].couleur, sizeof(vehicules[i].couleur), stdin);
            vehicules[i].couleur[strcspn(vehicules[i].couleur, "\n")] = '\0';

            printf("Le véhicule a été modifié avec succès.\n");
            break;
        }
    }

    if (!vehiculeTrouve) {
        printf("Aucun véhicule avec cette marque n'a été trouvé.\n");
    }
}

// Fonction pour supprimer un véhicule
void supprimerVehicule() {
    printf("=== SUPPRIMER UN VEHICULE ===\n");

    if (nbVehicules == 0) {
        printf("Aucun véhicule enregistré. Impossible de supprimer.\n");
        return;
    }

    printf("Marque du véhicule à supprimer : ");
    char marque[50];
    fgets(marque, sizeof(marque), stdin);
    marque[strcspn(marque, "\n")] = '\0';

    bool vehiculeTrouve = false;
    for (int i = 0; i < nbVehicules; i++) {
        if (strcmp(vehicules[i].marque, marque) == 0) {
            vehiculeTrouve = true;

            for (int j = i; j < nbVehicules - 1; j++) {
                vehicules[j] = vehicules[j + 1];
            }

            nbVehicules--;

            printf("Le véhicule a été supprimé avec succès.\n");
            break;
        }
    }

    if (!vehiculeTrouve) {
        printf("Aucun véhicule avec cette marque n'a été trouvé.\n");
    }
}

// Fonction pour afficher les statistiques
void afficherStatistiques() {
    printf("=== STATISTIQUES ===\n");

    if (nbVehicules == 0) {
        printf("Aucun véhicule enregistré.\n");
        return;
    }

    int nbVoituresRouges = 0;
    int nbMotos = 0;
    // Ajoutez d'autres statistiques selon vos besoins

    for (int i = 0; i < nbVehicules; i++) {
        if (strcmp(vehicules[i].couleur, "rouge") == 0) {
            nbVoituresRouges++;
        }

        // Exemple de comptage de motos
        // Vous pouvez ajouter des conditions pour d'autres types de véhicules
        if (strstr(vehicules[i].modele, "moto") != NULL) {
            nbMotos++;
        }
    }

    printf("Nombre de voitures rouges : %d\n", nbVoituresRouges);
    printf("Nombre de motos : %d\n", nbMotos);
    // Affichez d'autres statistiques ici
}

// Fonction pour afficher la liste des véhicules
void afficherListeVehicules() {
    printf("=== LISTE DES VEHICULES ===\n");

    if (nbVehicules == 0) {
        printf("Aucun véhicule enregistré.\n");
        return;
    }

    for (int i = 0; i < nbVehicules; i++) {
        printf("Véhicule %d :\n", i + 1);
        printf("Marque : %s\n", vehicules[i].marque);
        printf("Modèle : %s\n", vehicules[i].modele);
        printf("Année : %d\n", vehicules[i].annee);
        printf("Couleur : %s\n", vehicules[i].couleur);
        printf("--------------------\n");
    }
}

int main() {
    int choix;

    do {
        printf("\n===== GESTION DES VEHICULES =====\n");
        printf("1. Ajouter un véhicule\n");
        printf("2. Modifier un véhicule\n");
        printf("3. Supprimer un véhicule\n");
        printf("4. Afficher les statistiques\n");
        printf("5. Afficher la liste des véhicules\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        viderBuffer();

        switch (choix) {
            case 1:
                ajouterVehicule();
                break;
            case 2:
                modifierVehicule();
                break;
            case 3:
                supprimerVehicule();
                break;
            case 4:
                afficherStatistiques();
                break;
            case 5:
                afficherListeVehicules();
                break;
            case 0:
                printf("Merci d'avoir utilisé l'application. Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 0);

    return 0;
}
