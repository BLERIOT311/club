#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

#include "ressource.h"

void enregistrer_don() {
    struct don don;
    srand(time(NULL));
    fgetc(stdin);
    printf("Entrez le nom du donateur : \n ");
   scanf("%s",don.nom_donneur);

    printf("Entrez le montant du don : \n");
    scanf("%d", &don.argent);
   
    printf("Entrez le statut du don [NB: Obligatoire] : \n");
    scanf("%s",don.statut);
   
    don.numero =rand() % 100 + 1;

    printf("Le numero de votre don est(à mémoriser) : %d \n\n\n ",don.numero);
    strcpy(don.date,__DATE__);

    FILE *fp = fopen("Ressourcedon.txt", "a+");
    if (fp == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }

    // Write the structure to the file (you can adjust the format as needed)
    fwrite(&don, sizeof(struct don), 1, fp);

    fclose(fp);
}


void statue_don() {
    int donID;
    printf("\nEntrez le numéro du don (si ce don a un statut) : ");
    scanf("%d", &donID);

    FILE *fp = fopen("Ressourcedon.txt", "r+");
    if (fp == NULL) {
        perror("\nErreur lors de l'ouverture du fichier.\n");
        return;
    }

    struct don don;
    int trouve = 0;

    while (fread(&don, sizeof(struct don), 1, fp)) {
        if (don.numero == donID) {
            printf("Entrez le nouveau statut du don : ");
            scanf("%s", don.statut);
            fseek(fp, sizeof(struct don), SEEK_CUR); // Move to the next record
            trouve = 1;
            break; // No need to continue searching
        }
    }

    fclose(fp);

    if (!trouve) {
        printf("Le don n'a jamais été statué.\n");
    }
}

void afficher_don() {
    FILE *fp = fopen("Ressourcedon.txt", "r");
    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    struct don don;
    int ID,trouve=0;
    printf("Entrer le numero du don : ");
    scanf("%d",&ID);
    while (fread(&don, sizeof(struct don), 1, fp)) {
      if(don.numero==ID){  
        printf("\nIDDON: %d", don.numero);
        printf("\nNOM ET PRENOM DU DONATAIRE :%s", don.nom_donneur);
        printf("\nMONTANT DU DON : %d\n", don.argent);
        printf("STATUT :%s\n", don.statut);
        printf("DATE :%s\n\n\n",don.date);
        trouve=1;
        break;
      }
    }
    

    fclose(fp);

     if(trouve==0)
          printf("L e don avec l'ID %d non trouvé.\n", ID);
}


void modifier_don() {
    int num, n;
    printf("Vous vous apprêtez à modifier les informations sur ce don !\n\n  1) Continuer\n  2) Quitter\n");
    scanf("%d", &n);

    switch (n) {
        case 1:
            FILE *fp = fopen("Ressourcedon.txt", "r+");
            if (fp == NULL) {
                perror("Erreur lors de l'ouverture du fichier");
                return;
            }
            printf("Entrez le numéro du don si ce don avait été statué : ");
            scanf("%d", &num);

            struct don don;
            int trouvé = 0;

            while (fread(&don, sizeof(struct don), 1, fp)) {
                if (don.numero == num) {
                    printf("Entrez le nom du donateur : ");
                    scanf("%s", don.nom_donneur);

                    printf("Entrez le montant du don : ");
                    scanf("%d", &don.argent);

                    printf("Entrez le statut du don : ");
                    scanf("%s", don.statut);
                    strcpy(don.date,__DATE__);
                    fseek(fp, -sizeof(struct don), SEEK_CUR); // Déplacez-vous vers l'enregistrement précédent
                    fwrite(&don, sizeof(struct don), 1, fp); // Écrivez la structure dans le fichier
                    trouvé = 1;
                    break; // Pas besoin de continuer la recherche
                }
            }

            fclose(fp);

            if (trouvé==0) {
                printf("Enregistrement avec l'ID %d non trouvé.\n", num);
            } else {
                printf("Le don a été modifié avec succès.\n");
            }
            break;

        case 2:
            return;

        default:
            break;
    }
}
void supprimer_don() {
    FILE *fp, *fpTemp;
    int num, trouvé = 0;

    fp = fopen("Ressourceequip.txt", "r");
    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    fpTemp = fopen("tempRessourceequip.txt", "w");
    if (fpTemp == NULL) {
        perror("Erreur lors de la création du fichier temporaire");
        fclose(fp);
        return;
    }

    printf("Entrez le numéro du don si ce a un statut : ");
    scanf("%d", &num);

    struct don don;

    while (fread(&don, sizeof(struct don), 1, fp)) {
        if (don.numero != num) {
            fwrite(&don, sizeof(struct don), 1, fpTemp);
        } else {
            trouvé = 1;
        }
    }

    fclose(fp);
    fclose(fpTemp);

    remove("Ressourcedon.txt");
    rename("tempRessourcedon.txt", "Ressourcedon.txt");

    if (trouvé==0) {
        printf("Enregistrement avec l'ID %d non trouvé.\n", num);
    } else {
        printf("Le don a été supprimé avec succès.\n");
    }
}




void enregistrer_equipement() {
     
    struct equipement equipement;
    srand(time(NULL));

    fgetc(stdin);
    printf("Entrez le nom du donateur : ");
    scanf("%s",equipement.nom_donneur);
    
    printf("Entrez le nom de l'équipement : ");
    scanf("%s",equipement.nom_equipement);

    printf("Entrez le statut de l'équipement [NB: Obligatoire] : ");
     scanf("%s",equipement.statut);
    strcpy(equipement.date,__DATE__);

    
    equipement.numero =rand() % 100 + 1;
    printf("Le numero de votre equipement est(à memoriser) : %d \n\n\n ",equipement.numero);

    FILE *fp = fopen("Ressourceequip.txt", "a+");
    if (fp == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        return;
    }

    fwrite(&equipement, sizeof(struct equipement), 1, fp);

    fclose(fp);
}

void statue_equipement() {
    int eqID;

    printf("\nEntrez le numéro de l'équipement (si ce don a un statut ): ");
    scanf("%d", &eqID);

    FILE *fp = fopen("Ressourceequip.txt", "r+");
    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    struct equipement equipement;
    int trouve = 0;

    while (fread(&equipement, sizeof(struct equipement), 1, fp)) {
        if (equipement.numero == eqID) {
            printf("Entrez le nouveau statut de l'équipement : ");
            scanf("%s", equipement.statut);
            fseek(fp, -sizeof(struct equipement), SEEK_CUR); // Revenir à l'enregistrement précédent
            fwrite(&equipement, sizeof(struct equipement), 1, fp); // Écrire la structure dans le fichier
            trouve = 1;
            break; // Pas besoin de continuer la recherche
        }
    }

    fclose(fp);

    if (trouve==0) {
        printf("L'équipement n'a jamais été statué.\n");
    }
}

void afficher_equipement() {
    FILE *fp = fopen("Ressourceequip.txt", "r");
    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    struct equipement equipement;
    int ID;
    int trouve=0;
    printf("Entrer le numero de l'equipement : ");
    scanf("%d",&ID);
    while (fread(&equipement, sizeof(struct equipement), 1, fp)) {
      if(equipement.numero==ID){  
        printf("\nID :%d\n", equipement.numero);
        printf(" NOM ET PRENOM :%s\n", equipement.nom_donneur); 
        printf("NOM DE L'EQUIPEMENT :%s\n", equipement.nom_equipement);
        printf("STATUT :%s\n", equipement.statut);
        printf("DATE: %s\n", equipement.date);
        trouve=1;
        break;

      }
    }
            
    fclose(fp);

    if(trouve==0)
          printf("L'equipement avec l'ID %d non trouvé.\n", ID);
}


void modifier_equipement() {
    int num, n;
    printf("Vous vous apprêtez à modifier les informations sur cet équipement !\n\n");
    printf("1) Continuer\n2) Quitter\n");
    scanf("%d", &n);

    switch (n) {
        case 1:
            FILE *fp = fopen("Ressourceequip.txt", "r+");
            if (fp == NULL) {
                perror("Erreur lors de l'ouverture du fichier");
                return;
            }
            printf("Entrez le numéro de l'équipement si ce don avait été statué : ");
            scanf("%d", &num);

            struct equipement equipement;
            int trouvé = 0;

            while (fread(&equipement, sizeof(struct equipement), 1, fp)) {
                if (equipement.numero == num) {
                    fgetc(stdin);
                    printf("Entrez le nom du donateur : ");
                    fgets(equipement.nom_donneur,100,stdin);

                    printf("Entrez le nom de l'équipement : ");
                    scanf("%s", equipement.nom_equipement);

                    printf("Entrez le statut de l'équipement : ");
                    scanf("%s", equipement.statut);
                    strcpy(equipement.date,__DATE__);
                    
                    fseek(fp, -sizeof(struct equipement), SEEK_CUR);
                    fwrite(&equipement, sizeof(struct equipement), 1, fp);
                    trouvé = 1;
                    break;
                }
            }

            fclose(fp);

            if (trouvé==0) {
                printf("Enregistrement avec l'ID %d non trouvé.\n", num);
            } else {
                printf("L'équipement a été modifié avec succès.\n");
            }
            break;

        case 2:
            return;

        default:
            break;
    }
}

void supprimer_equipement() {
    FILE *fp, *fpTemp;
    int num, trouvé = 0;

    fp = fopen("Ressourceequip.txt", "r");
    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    fpTemp = fopen("tempRessourceequip.txt", "w");
    if (fpTemp == NULL) {
        perror("Erreur lors de la création du fichier temporaire");
        fclose(fp);
        return;
    }

    printf("Entrez le numéro de l'équipement si cet équipement a un statut : ");
    scanf("%d", &num);

    struct equipement equipement;

    while (fread(&equipement, sizeof(struct equipement), 1, fp)) {
        if (equipement.numero != num) {
            fwrite(&equipement, sizeof(struct equipement), 1, fpTemp);
        } else {
            trouvé = 1;
        }
    }

    fclose(fp);
    fclose(fpTemp);

    remove("Ressourceequip.txt");
    rename("tempRessourceequip.txt", "Ressourceequip.txt");

    if (trouvé==0) {
        printf("Enregistrement avec l'ID %d non trouvé.\n", num);
    } else {
        printf("L'équipement a été supprimé avec succès.\n");
    }
}



void enregistrer_fourniture() {
    struct fournitures fournitures;
     srand(time(NULL));
     fgetc(stdin);
    printf("\nEntrez le nom du donateur : ");
    scanf("%s",fournitures.nom_donneur);

    printf("\nEntrez le nom de la fourniture : ");
    scanf("%s",fournitures.nom_fourniture);

    printf("\nEntrez le statut de la fourniture [NB: Obligatoire] : ");
    scanf("%s", fournitures.statut);
   
    fournitures.numero =rand() % 100 + 1;

    printf("Le numero de votre founiture est(à memoriser)  : %d \n\n ",fournitures.numero);
     strcpy(fournitures.date,__DATE__); 

            FILE *fp = fopen("Ressourcefourn.txt", "a+");
            if (fp == NULL) {
                perror("Erreur lors de l'ouverture du fichier");
                return;
            }

            fwrite(&fournitures, sizeof(struct fournitures), 1, fp);
            printf("\nSuccessfully saved.\n\n\n");
            fclose(fp);
    
}

void statue_fourniture(){ 
    int fID;

    printf("Entrez le numéro de la fourniture (si cette fourniture a un statut ): ");
    scanf("%d", &fID);

    FILE *fp = fopen("Ressourcefourn.txt", "r+");
    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    struct fournitures fournitures;
    int trouve = 0;
    char nstfourn[30];

    while (fread(&fournitures, sizeof(struct fournitures), 1, fp)) {
        if (fournitures.numero == fID) {
            printf("Entrez le nouveau statut de la fourniture : ");
            scanf("%s", nstfourn);
            strcpy(fournitures.statut, nstfourn);
            fseek(fp, -sizeof(struct fournitures), SEEK_CUR);
            fwrite(&fournitures, sizeof(struct fournitures), 1, fp);
            trouve = 1;
            break;
        }
    }

    fclose(fp);

    if (trouve==0) {
        printf("La fourniture n'a jamais été statuée.\n");
    }
}


void afficher_fourniture() {
    FILE *fp = fopen("Ressourcefourn.txt", "r");
    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    struct fournitures fournitures;
    int ID;
    printf("Enter le numero de la fourniture que vous voulez afficher :");
    scanf("%d",&ID);
    int trouve=0;
    while (fread(&fournitures, sizeof(struct fournitures), 1, fp)) {
      if(fournitures.numero==ID){
        printf("La fourniture numéro : %d\n", fournitures.numero);
        printf("NOM du donateur : %s\n", fournitures.nom_donneur);
        printf("NOM de la fourniture : %s\n", fournitures.nom_fourniture);
        printf("STATUT : %s\n", fournitures.statut);
         printf("DATE : %s", fournitures.date);
        trouve=1;
        break;
      }

    }
    if(trouve==0)
          printf("La fourniture avec l'ID %d non trouvé.\n", ID);
            
         fclose(fp);
    }

void modifier_fourniture() {
     struct fournitures fournitures;
    int num, n;
    printf("Vous vous apprêtez à modifier les informations sur cette fourniture !\n\n");
    printf("1) Continuer\n2) Quitter\n");
    scanf("%d", &n);

    switch (n) {
        case 1:
            FILE *fp = fopen("Ressourcefourn.txt", "r+");
            if (fp == NULL) {
                perror("Erreur lors de l'ouverture du fichier");
                return;
            }
            printf("Entrez le numéro de la fourniture si cette fourniture avait été statuée : ");
            scanf("%d", &num);

           
            int trouvé = 0;
            srand(time(NULL));
            
            while (fread(&fournitures, sizeof(struct fournitures), 1, fp)) {
                if (fournitures.numero == num) {
                      
            
            printf("\nEntrez le nom du donateur : ");
           
	    scanf("%s",fournitures.nom_donneur);
            fgetc(stdin);
            printf("\nEntrez le nom de la fourniture : ");
            
	    scanf("%s",fournitures.nom_fourniture);
            
            printf("\nEntrez le statut de la fourniture [NB: Obligatoire] : ");
            scanf("%s", fournitures.statut);
           strcpy(fournitures.date,__DATE__);

                    fseek(fp, -sizeof(struct fournitures), SEEK_CUR);
                    fwrite(&fournitures, sizeof(struct fournitures), 1, fp);
                    trouvé = 1;
                    break;
                }
            }

            fclose(fp);

            if (trouvé==0) {
                printf("Enregistrement avec l'ID %d non trouvé.\n", num);
            } else {
                printf("La fourniture a été modifiée avec succès.\n");
            }
            break;

        case 2:
            return;

        default:
            break;
    }
}


void supprimer_fourniture() {
    FILE *fp, *fpTemp;
    int num, trouvé = 0;

    fp = fopen("Ressourcefourn.txt", "r");
    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    fpTemp = fopen("tempRessourcefourn.txt", "w");
    if (fpTemp == NULL) {
        perror("Erreur lors de la création du fichier temporaire");
        fclose(fp);
        return;
    }

    printf("Entrez le numéro de la fourniture si cette fourniture a un statut : ");
    scanf("%d", &num);

    struct fournitures fourniture;

    while (fread(&fourniture, sizeof(struct fournitures), 1, fp)) {
        if (fourniture.numero != num) {
            fwrite(&fourniture, sizeof(struct fournitures), 1, fpTemp);
        } else {
            trouvé = 1;
        }
    }

    fclose(fp);
    fclose(fpTemp);

    remove("Ressourcefourn.txt");
    rename("tempRessourcefourn.txt", "Ressourcefourn.txt");

    if (trouvé==0) {
        printf("Enregistrement avec l'ID %d non trouvé.\n", num);
    } else{
         printf("la fourniture  a été supprimé avec succès.\n");
    }
}

