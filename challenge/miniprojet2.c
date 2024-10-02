#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char nom[60];
    char phone[90];
    char email[40];
}contact;


contact contacts[200];
  int totalcounte=0;
   void ajoutecontact() {
    printf("Entrez le nom:");


    scanf("%s",contacts[totalcounte].nom);
    printf("Entrez phone:");
    scanf("%s",contacts[totalcounte].phone);
    printf("Entrez email: ");
    scanf("%s",contacts[totalcounte].email);
   totalcounte++;
    printf("contact ajoute");


    };

void   afficherlescontact() {
    if (totalcounte == 0) {
        printf("raine contact à afficher.\n");

    }
    printf(" Liste des contacts:\n");
    for (int i = 0; i < totalcounte; i++) {
        printf("Nom: %s, Téléphone: %s, email: %s\n",
 contacts[i].nom, contacts[i].phone, contacts[i].email);
    }
}
void rechercheruncontact() {
    char nom[60];
    printf("Entrez le nom du contact à rechercher: ");
    scanf("%s", nom);
    for (int i = 0; i < totalcounte; i++) {
        if (strcmp(contacts[i].nom, nom) == 0) {
            printf("Contact trouvé: Nom: %s, phone: %s, email: %s\n",
            contacts[i].nom, contacts[i].phone, contacts[i].email);

        }
    }
    printf("Contact non trouvé.\n");
}

void suppremecontact() {
    char nom[60];
    printf("Entrez le nom du contact à supprime: ");
    scanf("%s", nom);
    for (int i = 0; i < totalcounte; i++) {
        if (strcmp(contacts[i].nom, nom) == 0) {
            for (int j = i; j < totalcounte - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
           totalcounte--;
            printf("Contact supprimé avec succès.\n");


  }
  }

void modefy(){
char nom[60];
printf("entre le nom modefie");
scanf("%s",nom);
for(int i=0;i<=totalcounte;i++){
 if (strcmp(contacts[i].nom, nom) == 0) {

printf("modifie le nomero de telephone");
scanf("%s",contacts[i].phone);
printf("modifie le email");
scanf("%s",contacts [i].email);
printf("Contact modifie  réussite!");

}
}
printf("contact no trouve");

}
int main(){
int choix;
do{



    printf("1. ajouter  contact\n");
    printf("2. afficher les contacts\n");
    printf("3. rechercher  contact\n");
    printf("4. modifie un contact\n");
    printf("5. supprimer un contact\n");
    printf("6. exite\n");
     printf("entrez votre choix \n");
     scanf("%d",&choix);


        switch(choix){

           case 1:
                ajoutecontact();
            break;
            case 2:
                afficherlescontact();
                break;
            case 3:
                  rechercheruncontact();
                break;
            case 4:
                modefy();
            break;
          case 5:
               suppremecontact();
                break;
            case 6:
                printf("MERCI BOUR VISIT");
                break;

            default:printf("Choix invalide. Veuillez ressayer.\n");

        };
    }while(choix!=6);

    return 0;
}
