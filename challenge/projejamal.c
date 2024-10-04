#include <stdio.h>
#include <string.h>

struct reservation {
    char nom[40];
    char prenom[40];
    char telephone[20];
    int age;
    char date[10];
    char reference[8];
};

struct reservation tab[200];
int count = 0;

void ajouter() {
    printf("Entrez votre nom: ");
    scanf("%s", tab[count].nom);
    printf("Entrez votre prenom: ");
    scanf("%s", tab[count].prenom);
    printf("Entrez votre numero: ");
    scanf("%s", tab[count].telephone);
    printf("Quel age avez-vous? : ");
    scanf("%i", &tab[count].age);
    printf("Entrez votre date de reservation au format dd-mm-yyyy: ");
    scanf("%s", tab[count].date);
    printf("Entrez votre reference (C.I.N): ");
    scanf("%s", tab[count].reference);

    printf("Votre reservation a ete ajoute avec succes.\n");
    count++;
}

void afficher() {
    if (count == 0) {
        printf("Aucune reservation a afficher.\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("Details de la reservation:\n");
            printf("Le nom: %s\n", tab[i].nom);
            printf("Le prenom: %s\n", tab[i].prenom);
            printf("Le numero: %s\n", tab[i].telephone);
            printf("Votre age: %d\n", tab[i].age);
            printf("La date de reservation: %s\n", tab[i].date);
            printf("Reference: %s\n", tab[i].reference);
            printf("\n--------------------------------------\n\n");
        }
    }
}

void supprimer() {
    char nom[30];
    char reference[8];
    int found = 0;

    printf("Entrez le nom de la reservation a supprimer: ");
    scanf("%s", nom);
    printf("Entrez la reference (C.I.N) de la reservation a supprimer: ");
    scanf("%s", reference);

    for (int i = 0; i < count; i++) {
        if (strcmp(tab[i].nom, nom) == 0 && strcmp(tab[i].reference, reference) == 0) {
            found = 1;
            for (int j = i; j < count - 1; j++) {
                tab[j] = tab[j + 1];
            }
            count--;
            printf("Reservation supprimee avec succes.\n");
            break;
        }
    }
    if (!found) {
        printf("Reservation non trouvee.\n");
    }
}

int main() {
    
    int choix;
    while (1) {
        printf("\n----- Menu -----\n");
        printf("1. Ajouter une reservation.\n");
        printf("2. Afficher les reservations.\n");
        printf("3. Modifier une reservation.\n");
        printf("4. Supprimer une reservation.\n");
        printf("5. Quitter\n");
        printf("ENTREZ VOTRE CHOIX: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter();
                break;
            case 2:
                afficher();
                break;
            case 4:
                supprimer();
                break;
            case 5:
                printf("À bientôt.\n");
                return 0;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
    }
    return 0;
}

