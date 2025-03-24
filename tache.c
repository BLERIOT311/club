
#include<stdio.h>
#include<stdlib.h>
#include"tache.h"
#include<time.h>
#include <string.h>


void cree_tache(char *nom_respo) {
    tache t;

    srand(time(NULL));

    for (int i = 0; i < 5; i++)
        t.libelle[i] = 'a' + rand() % 26;
    t.libelle[5] = '\0'; // Null-terminate the string

    t.numero_tache = rand() % 1000;
    strcpy(t.nom_respo, nom_respo);

    int i = 1;
    while (i != 0) {
        int n;

        printf("Choisissez votre profession :\n1) Informaticiens\n2) Analyste de donn�es\n3) Techniciens\n4) Sans certificat de profession\nChoix : ");
        scanf("%d", &n);
        switch (n) {
            case 1:
                strcpy(t.nom, "equipe_de_medias_sociaux");
                t.budget = 5000;
                i = 0;
                    printf("VOICI VOTRE NUM�RO DE Tache 'equipe_de_medias_sociaux' M�MORIS� : %d\n", t.numero_tache);

                break;
            case 2:
                strcpy(t.nom, "equipe_d_analystes");
                t.budget = 4500;
                i = 0;
                    printf("VOICI VOTRE NUM�RO DE T�CHE 'equipe_d_analyste' M�MORIS� : %d\n", t.numero_tache);

                break;
            case 3:
                strcpy(t.nom, "equipe_technique");
                t.budget = 6000;
                i = 0;
                    printf("VOICI VOTRE NUM�RO DE T�CHE 'equipe technique' M�MORIS� : %d\n", t.numero_tache);

                break;
            case 4:
                strcpy(t.nom, "agents_d_entretiens");
                t.budget = 2000;
                i = 0;
                    printf("VOICI VOTRE NUM�RO DE T�CHE 'agent_d_entretient' M�MORIS� : %d\n", t.numero_tache);

                break;
            default:
                printf("\nErreur, r�essayez.\n");
                break;
        }
    }

    FILE *f;
    time_t tt = time(NULL);
    struct tm *tm = localtime(&tt);
    char str[30];
    strftime(str, sizeof(str), "le_%d/%m/%Y__a__%Hh:%Mmin", tm);
    strcpy(t.heure_cree, str);
    strcpy(t.heure_fin, str);

    f = fopen("tache.txt", "a");
    if (f == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        exit(EXIT_FAILURE);
    }
    fwrite(&t, sizeof(tache), 1, f);
    fclose(f);
}

int rechercher_tache(char nom[30]){
    FILE *f;
    tache neww;
    f=fopen("tache.txt","r");
if(f==NULL){
    perror("Erreur lors de l'ouverture du fichier");
    return 0;
}
    while(fscanf(f, "\n\n\t%s", neww.nom) ==1){
            if(strcmp(neww.nom,nom)==0) {
                fclose(f);
                return 1;
               }
    }
    fclose(f);
    return 0;
}


void supprimer_tache(char nom[30]){
    if(rechercher_tache(nom)==1){
          FILE *f, *temp;
        tache neww;
        char header[200];
        int num;
        printf("entrer le numero du membre a supprimer\n");
        scanf("%d",&num);

        f=fopen("tache.txt","r");
        if (f == NULL) {
            printf("Erreur lors de l'ouverture du fichier membre.txt\n");
            return;
        }

        temp=fopen("temp.txt","w");
        if (temp == NULL) {
            printf("Erreur lors de l'ouverture du fichier temp.txt\n");
            fclose(f);
            return;
        }

        // Copier l'en-t�te


        while(fread(&neww,sizeof(tache),1,f)){
                if(neww.numero_tache != num){
                fwrite(&neww,sizeof(tache),1,f);
            }
        }

        fclose(f);
        fclose(temp);

        if(remove("tache.txt") == 0) {
            if(rename("temp.txt","tache.txt") == 0) {
                    printf("!erreur survenue\n");
                return ;
            } else {
                return ;
            }
        } else {
            return  ;
        }
    }else{
            return ;
    }
}


void modifier_tache(){
    printf("entrer le nom de la tache a modifier:\n");
    char nom[30];
    scanf("%s",nom);
    tache temp;
    FILE *f;
    f = fopen("tache.txt", "r+");
    if(f == NULL){
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }
        if(rechercher_tache(nom)==1){
            supprimer_tache(nom);
            cree_tache(nom);
        }

    fclose(f);
}

void afficher_tache(){
    printf("entrer le nom de la tache\n");

        char nom[30];
        scanf("%s",nom);

    tache neww;
    FILE *f;

    f = fopen("tache.txt", "r");
    if(f == NULL){
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }


    while(fread(&neww,sizeof(tache),1,f)){

            if(strcmp(nom,neww.nom)==0){
                printf("NOM_responsable:%s  NOM_tache:%s  Libelle:%s  Budget:%f ID_TACHE:%d HEURE_DE_DEBUT:%s  HEURE DE FIN:%s \n\n",neww.nom_respo,neww.nom,neww.libelle,neww.budget,neww.numero_tache,neww.heure_cree,neww.heure_fin);
                break;
            }

    }
        fclose(f);

        while (getchar() != '\n');

    printf("Appuyez sur Entr�e pour continuer...\n");
    getchar();
}

void afficher_tout_tache(){

    tache neww;
    FILE *f=fopen("tache.txt","r");
    printf("\nNOM_responsable\t\tNOM_tache\t\t\tLibelle\t\t\tBudget\t\t\tID_TACHE\t\t\tHEURE_DE_DEBUT\t\t\tHEURE DE FIN\n\n");

    while(fread(&neww,sizeof(tache),1,f)){
        printf("\n%s\t\t%s\t\t%s\t\t%f\t\t%d\t\t%s\t\t%s\n\n",neww.nom_respo,neww.nom,neww.libelle,neww.budget,neww.numero_tache,neww.heure_cree,neww.heure_fin);
    }
        fclose(f);

        while (getchar() != '\n');

    printf("Appuyez sur Entr�e pour continuer...\n");
    getchar();
}

float budget_total_tache(){

    tache neww;
    float sum=0;

    FILE *f=fopen("tache.txt","r");


    while(fread(&neww,sizeof(tache),1,f)){
        sum+=neww.budget;
    }

    fclose(f);
    return sum;

}

void effectuer_tache(char nom[30],int num){
    char heure[100];
    FILE *f=fopen("tache.txt","r");
    tache neww;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);


    strftime(heure,sizeof(heure), "le_%d/%m/%Y__a__%Hh:%Mmin", tm);


    while(fread(&neww,sizeof(tache),1,f)){
        if(neww.numero_tache==num)
        strcpy(neww.heure_fin,heure);
            fclose(f);
           return;
        }

        printf("\ntache effectuer avec succes\n\n");
        while (getchar() != '\n');


    printf("Appuyez sur Entr�e pour continuer...\n");
    getchar();
    }


void afficher_infor(){
    FILE *f=fopen("tache.txt","r");
    tache neww;

    printf("\nNOM_responsable\t\tNOM_tache\t\tLibelle\t\tBudget\t\tID_TACHE\t\tHEURE_DE_DEBUT\t\tHEURE DE FIN\n\n");

    while(fread(&neww,sizeof(tache),1,f)){
        if(strcmp(neww.nom,"equipe de medias sociaux")==0)
           printf("\n%s\t\t%s\t\t%s\t\t%f\t\t%d\t\t%s\t\t%s\n\n",neww.nom_respo,neww.nom,neww.libelle,neww.budget,neww.numero_tache,neww.heure_cree,neww.heure_fin);

    }
    while (getchar() != '\n');

    printf("Appuyez sur Entr�e pour continuer...\n");
    getchar();
}

void afficher_analyste(){
    FILE *f=fopen("tache.txt","r");

    tache neww;

    printf("\nNOM_responsable\t\tNOM_tache\t\tLibelle\t\tBudget\t\tID_TACHE\t\tHEURE_DE_DEBUT\t\tHEURE DE FIN\n\n");

    while(fread(&neww,sizeof(tache),1,f)){
        if(strcmp(neww.nom,"equipe d'analytes")==0)
           printf("\n%s\t\t%s\t\t%s\t\t%f\t\t%d\t\t%s\t\t%s\n\n",neww.nom_respo,neww.nom,neww.libelle,neww.budget,neww.numero_tache,neww.heure_cree,neww.heure_fin);

    }

    while (getchar() != '\n');

    printf("Appuyez sur Entr�e pour continuer...\n");
    getchar();
}

void afficher_techniciens(){
    FILE *f=fopen("tache.txt","r");
    tache neww;

    printf("\nNOM_responsable\t\tNOM_tache\t\tLibelle\t\tBudget\t\tID_TACHE\t\tHEURE_DE_DEBUT\t\tHEURE DE FIN\n\n");

    while(fread(&neww,sizeof(tache),1,f)){
        if(strcmp(neww.nom,"equipe technique")==0)
           printf("\n%s\t\t%s\t\t%s\t\t%f\t\t%d\t\t%s\t\t%s\n\n",neww.nom_respo,neww.nom,neww.libelle,neww.budget,neww.numero_tache,neww.heure_cree,neww.heure_fin);

    }
    while (getchar() != '\n');

    printf("Appuyez sur Entr�e pour continuer...\n");
    getchar();
}

void afficher_agent(){
    FILE *f=fopen("tache.txt","r");
    tache neww;

    printf("\nNOM_responsable\t\tNOM_tache\t\tLibelle\t\t\tBudget\t\t\tID_TACHE\t\t\tHEURE_DE_DEBUT\t\t\tHEURE DE FIN\n\n");

    while(fread(&neww,sizeof(tache),1,f)){
        if(strcmp(neww.nom,"agents d'entretiens")==0)
           printf("\n%s\t\t%s\t\t%s\t\t%f\t\t%d\t\t%s\t\t%s\n\n",neww.nom_respo,neww.nom,neww.libelle,neww.budget,neww.numero_tache,neww.heure_cree,neww.heure_fin);

    }
    while (getchar() != '\n');

    printf("Appuyez sur Entr�e pour continuer...\n");
    getchar();
}


