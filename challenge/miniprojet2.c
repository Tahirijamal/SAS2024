#include <stdio.h>
#include <string.h>

struct reservation {
    char nom[30];
    char prenom[30];
    char telephone[20];
    int age;
    char date[11];
    char reference[8];
      char statut[20];
};

struct reservation tab[200];
int count = 0;

void ajouter() {
    printf("entrez votre nom: ");
    scanf("%s", tab[count].nom);
    printf("entrez votre prenom: ");
    scanf("%s", tab[count].prenom);
    printf("entrez votre numero: ");
    scanf("%s", tab[count].telephone);
    printf("entrer votre statut : ");
    scanf("%s", tab[count].statut);
    printf("quel age avez-vous? : ");
    scanf("%d", &tab[count].age);
    printf("entrez votre date de reservation au format dd-mm-yyyy: ");
    scanf("%s", tab[count].date);
    printf("entrez votre reference (C.I.N): ");
    scanf("%s", tab[count].reference);

    printf("votre reservation a ete ajoute avec succes.\n");
    count++;
}

void afficher() {
    if (count == 0) {
        printf("Aucune reservation a afficher.\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("details de la reservation:\n");
            printf("le nom: %s\n", tab[i].nom);
            printf("le prenom: %s\n", tab[i].prenom);
            printf("le numero: %s\n", tab[i].telephone);
            printf("le statut: %s\n", tab[i].statut);
            printf("votre age: %d\n", tab[i].age);
            printf("la date de reservation: %s\n", tab[i].date);
            printf("reference: %s\n", tab[i].reference);
            printf("\n--------------------------------------\n\n");
        }
    }
}

void supprimer() {
    char reference[8];
    int found = 0;


    printf("entrez la reference (C.I.N) de la reservation a supprimer: ");
    scanf("%s", reference);

    for (int i = 0; i < count; i++) {
       if (strcmp(tab[i].reference, reference) == 0) {
            found = 1;
            for (int j = i; j < count - 1; j++) {
                tab[j] = tab[j + 1];
            }
            count--;
            printf("reservation supprimee avec succes.\n");
            break;
        }
    }
    if (!found) {
        printf("reservation non trouvee.\n");
    }
}
void trierparstatut() {
    struct reservation temp;
int option;
printf("entre le type du triage:(1- par statut.\n");
scanf("%d",&option);
if (option==1){
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(tab[i].statut, tab[j].statut) > 0) {
            temp = tab[j];
                tab[j] = tab[i];
                tab[i] = temp;
            }
        }
    }
 }

    printf("reservations triees par statut avec succes.\n");
}
int dixreservation() {
    char nom_dixreservation[10][20] = {"said", "ilyas", "hakimi", "hakim", "jamal", "fouad", "khadija", "zeneb", "malika", "imad"};
    char prenom_dixreservation[10][20] = {"sammouni", "tahiri", "ziyach", "khadraoui", "kioui", "saad", "taoussi", "chkib", "zmalkaoui", "madridi"};
    char telephon_dixreservation[10][14] = {"0123456789", "0624754321", "0678256789", "068725543", "0123456789", "0740954091", "0123456789", "9887438748", "0123456789", "98403484334"};
    int age_dixreservation[10] = {22, 30, 25, 35, 22, 48, 28, 30, 29, 45};
    char date_de_reservation_dixreservation[10][15] = {"01-01-2022", "02-01-2023", "03-01-2023", "04-01-2023", "05-01-2023", "06-01-2023", "07-01-2023", "08-01-2023", "09-01-2023", "10-01-2023"};
    char statut_dixreservation[10][30] = {"valide" , "annule","reporte" , "valide","reporte","annule","valide","valide","annule","valide"};
    for (int i = 0; i < 10; i++) {
        strcpy(tab[i].nom, nom_dixreservation[i]);
        strcpy(tab[i].prenom, prenom_dixreservation[i]);
        strcpy(tab[i].telephone, telephon_dixreservation[i]);
        strcpy(tab[i].statut, statut_dixreservation[i]);
        tab[i].age = age_dixreservation[i];
        strcpy(tab[i].date, date_de_reservation_dixreservation[i]);
        snprintf(tab[i].reference, sizeof(tab[i].reference), "CIN%d", i + 1);
    }
    count = 10;
}

int main() {
    dixreservation();
    int choix;
    while (1) {
        printf("\n----- main menu -----\n");
        printf("1. ajouter une reservation.\n");
        printf("2. afficher les reservations.\n");
        printf("3. modifier une reservation.\n");
        printf("4. supprimer une reservation.\n");
        printf("5. trier  une reservation.\n");
        printf("6. xite\n");
        printf("entre votre ou choix: ");
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

            case 5 :
                trierparstatut();
                break ;
                case 6:
                printf("merci pour votre visite.\n");
                return 0;
            default:
                printf("choix invalide, veuillez réessayer.\n");
        }
    }
    return 0;
}
