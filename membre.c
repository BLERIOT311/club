
#include<stdio.h>
#include"membre.h"
#include<string.h>
#include<time.h>
#include"tache.h"
#include<stdlib.h>
#include<unistd.h>

void enregistrer() {
    membre *neww = malloc(sizeof(membre));
    FILE *f;

    printf("Entrez votre nom : ");
    scanf("%s", neww->nom);

    printf("Entrez votre prénom : ");
    scanf("%s", neww->prenom);

    srand(time(NULL));
    neww->numero = rand() % 100000;

    printf("Entrez votre adresse : ");
    scanf("%s", neww->adresse);

    printf("Entrez votre âge : ");
    scanf("%d", &neww->age);
    system("clear");
            sleep(0.1);
    cree_tache(neww->nom);

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char str[30];
    strftime(str, sizeof(str), "le_%d/%m/%Y__a__%Hh:%Mmin", tm);
    strcpy(neww->horaire, str);
        system("clear");
            sleep(0.1);
    printf("Entrez votre profession :\n1) INFORMATICIEN\n2) TECHNICIEN ELECTRO\n3) ANALYSTE\n4) SANS DIPLOME\nChoix : ");
    int choix;
    scanf("%d", &choix);
    switch (choix) {
        case 1:
            strcpy(neww->tache, "equipe medias");
            break;
        case 2:
            strcpy(neww->tache, "equipe de maintenance");
            break;
        case 3:
            strcpy(neww->tache, "equipe d'analyse");
            break;
        case 4:
            strcpy(neww->tache, "agent d'entretient");
            break;
        default:
            printf("Profession invalide.\n");
            return;
    }

    int n = 1;
    printf("CHOISISSEZ :\n1) Payer la 1ère tranche (1000f)\n2) Payer la 1ère et la 2ème tranche (3000f)\n3) Payer les trois tranches (5000f)\n4) Je n'ai pas assez de fonds pour m'inscrire, j'abandonne\nChoix : ");
    scanf("%d", &n);
    while (n != 0) {
        switch (n) {
            case 1:
                neww->pre_tranche=1000;
                n = 0;
                break;
            case 2:
                neww->pre_tranche=1000; neww->deu_tranche=2000;
                n = 0;
                break;
            case 3:
               neww->pre_tranche=1000;neww->deu_tranche=2000; neww->troi_tranche=2000;
                n = 0;
                break;
            default:
                printf("Vous ne pouvez accéder sans payer. Appuyez sur un chiffre pour continuer.\n");
                int j;
                scanf("%d", &j);
                break;
        }
    }

        printf("Felicitations, vous etes maintenant membre du club !\n\nVOICI VOTRE ID %d A MEMORISER.\n\n", neww->numero);

    f = fopen("membre.txt", "a");
    if (f == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        exit(EXIT_FAILURE);
    }
    fwrite(neww, sizeof(membre), 1, f);
    fclose(f);

    free(neww); // N'oubliez pas de libérer la mémoire allouée pour neww

    while (getchar() != '\n');

    printf("Appuyez sur Entrée pour continuer...\n");
    getchar();
}

membre rechercher_membre(int num){

    FILE *f;
    f=fopen("membre.txt","r");
    membre m;


   while(fread(&m,sizeof(membre),1,f)){
       if(m.numero==num) {
            fclose(f);
            return m;
        }

    }
    fclose(f);
    
}

void afficher_membre(char nom[30],int num){

    FILE *f;
    f=fopen("membre.txt","r");
    membre m;

   while(fread(&m,sizeof(membre),1,f)){

       if(strcmp(m.nom,nom)==0 && m.numero==num) {
            printf("\n\nNOM:%s\nPRENOM:%s\nAGE:%d\nID:%d\nADRESSE:%s\n1ER_TRCH:%d\n2E_TRCH:%d\n3E_TRCH:%d\nCOTISATION:%.2f\nTACHE:%s\nDATE:%s\n\n",m.nom,m.prenom,m.age,m.numero,m.adresse,m.pre_tranche,m.deu_tranche,m.troi_tranche,m.cotisation,m.tache,m.horaire );
            break;

        }

        }
    fclose(f);
    while (getchar() != '\n');

    printf("Appuyez sur Entrée pour continuer...\n");
    getchar();

}




void afficher_tout(){
    FILE *f;
    membre m;
    f=fopen("membre.txt","r");
    if(f==NULL)return;
    printf("NOM\tPRENOM\tAGE\tID\tADRESSE\t1E_TRCH\t2E_TRCH\t3E_TRCH\tCOTISATION\tTACHE\t\t\tDATE\n\n");
    while(fread(&m,sizeof(membre),1,f)){
        printf("%s\t%s\t%d\t%d\t%s\t%d\t%d\t%d\t%.f\t%s\t%s\n",m.nom,m.prenom,m.age,m.numero,m.adresse,m.pre_tranche,m.deu_tranche,m.troi_tranche,m.cotisation,m.tache,m.horaire );
    }
    while (getchar() != '\n');

    printf("Appuyez sur Entrée pour continuer...\n");
    getchar(); // attendre que l'utilisateur appuie sur 'Entrer'

    fclose(f);
}





void supprimer_membre(int num) {

    FILE *f, *temp;
    f=fopen("membre.txt","r");
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
    membre m;

    // Variable pour stocker le numéro lu depuis la ligne
    while (fread(&m,sizeof(membre),1,f)){
        if (  num!=m.numero) {
            fwrite(&m,sizeof(membre),1,temp);
        }
    }

    fclose(f);
    fclose(temp);

    if(remove("membre.txt") == 0) {
        if(rename("temp.txt","membre.txt") == 0) {
           ;
        } else {
            printf("Erreur lors du renommage du fichier\n");
        }
    } else {
        printf("Erreur lors de la suppression du fichier\n");
    }
}

void cotiser(int num, float cotisation) {

     membre m=rechercher_membre(num);
    supprimer_membre(num);
    FILE *f = fopen("membre.txt", "a");

    if (f == NULL)return;

    m.cotisation=cotisation;
    fwrite(&m,sizeof(membre),1,f);
    fclose(f);
    printf("\n\ncotisation ajouter avec succes\n\n");
    while (getchar() != '\n');

    printf("Appuyez sur Entrée pour continuer...\n");
    getchar(); // Close the file
}

void payer_tranche(int num){

    membre m=rechercher_membre(num);
    supprimer_membre(num);
    FILE *f=fopen("membre.txt","a");

           int n=1;
         while(n!=0){
            if(m.deu_tranche==0){
                 printf("1)payer la 2eme tranche(2000f)\n\n2)payer la 2eme et la troisiemme tranche ((2000f)*2)\n3)retour\n:");

            switch(n){
                case 1:

                    m.deu_tranche=2000;
                    m.troi_tranche=0;
                    n= 0;
                    while (getchar() != '\n');
                    printf("\t!tranche payer avec succes\n\n");
                    printf("Appuyez sur Entrée pour continuer...\n");
                    getchar();
                    break;
                case 2:
                    m.deu_tranche=2000;
                    m.troi_tranche=2000;
                    n= 0;
                    while (getchar() != '\n');
                    printf("\t!tranche payer avec succes\n\n");
                    printf("Appuyez sur Entrée pour continuer...\n");
                    getchar();
                        break;
                case 3:
                    n= 0;
                    break;
                default:
                    printf("!mauvaise saisie\n");
                    break;

            }
        }else if(m.troi_tranche==0){

            printf("payer la 3eme tranche \n 1)oui\n2)non\n choix:");
            int k;
            scanf("%d",&k);
            switch(k){
                case 1:
                    m.troi_tranche=2000;n=0;
                    while (getchar() != '\n');
                    printf("\t!tranche payer avec succes\n\n");
                    printf("Appuyez sur Entrée pour continuer...\n");
                    getchar();
                    break;

                case 2:
                    m.troi_tranche=0;n=0;break;

                }
        }else{
             printf("tranche deja payer!\n");
             n=0;
        }


    }

    fwrite(&m,sizeof(membre),1,f);
    fclose(f);
}

float tranche_total(){
    float sum=0;
    FILE *f=fopen("membre.txt","r");
    membre m;
    while(fread(&m,sizeof(membre),1,f)){

        sum+= m.pre_tranche+m.deu_tranche+m.troi_tranche;
    }
    return sum;
    fclose(f);
}


float cotisation_total(){
    FILE *f=fopen("membre.txt","r");
    float sum=0;
    membre m;
    while(fread(&m,sizeof(membre),1,f)){
           sum+=m.cotisation;
    }
    return sum;
    fclose(f);
    }

int verifier_membre(int num,char nom[30]){

    membre m;
    FILE *f = fopen("membre.txt", "r");
    while (fread(&m,sizeof(membre),1,f)) {
        if (strcmp(m.nom,nom)==0 && num==m.numero) {
            fclose(f);
            return 1;
        }
    }

    return 0;
}

int verifier_DG(int num, char nom[30]) {
    FILE *f = fopen("DG.txt", "r");
    char line[200];
    char numStr[12]; // Assuming int will not exceed 11 characters + null terminator
    sprintf(numStr, "%d", num); // Convert int to string
    while (fgets(line, 200, f) != NULL) {
        if (strstr(line, numStr) && strstr(line, nom)) {
            fclose(f);
            return 1;
        }
    }
    while (getchar() != '\n');

    printf("Appuyez sur Entrée pour continuer...\n");
    getchar();
    fclose(f);
    return 0;
}

int verifier_PDG(int num, char nom[30]) {
    FILE *f = fopen("PDG.txt", "r");
    char line[200];
    char numStr[12]; // Assuming int will not exceed 11 characters + null terminator
    sprintf(numStr, "%d", num); // Convert int to string
    while (fgets(line, 200, f) != NULL) {
        if (strstr(line, numStr) && strstr(line, nom)) {
            fclose(f);
            return 1;
        }
    }
    while (getchar() != '\n');

    printf("Appuyez sur Entrée pour continuer...\n");
    getchar();
    fclose(f);
    return 0;
}

int verifier_SECRET(int num, char nom[30]) {
    FILE *f = fopen("secretaire.txt", "r");
    char line[200];
    char numStr[12]; // Assuming int will not exceed 11 characters + null terminator
    sprintf(numStr, "%d", num); // Convert int to string
    while (fgets(line, 200, f) != NULL) {
        if (strstr(line, numStr) && strstr(line, nom)) {
            fclose(f);
            return 1;
        }
    }
    while (getchar() != '\n');

    printf("Appuyez sur Entrée pour continuer...\n");
    getchar();
    fclose(f);
    return 0;
}

int verifier_TRESOR(int num, char nom[30]) {
    FILE *f = fopen("tresorier.txt", "r");
    char line[200];
    char numStr[12]; // Assuming int will not exceed 11 characters + null terminator
    sprintf(numStr, "%d", num); // Convert int to string
    while (fgets(line, 200, f) != NULL) {
        if (strstr(line, numStr) && strstr(line, nom)) {
            fclose(f);
            return 1;
        }
    }
    while (getchar() != '\n');

    printf("Appuyez sur Entr�e pour continuer...\n");
    getchar();
    fclose(f);
    return 0;
}
int verifier_GT(int num, char nom[30]) {
    FILE *f = fopen("GT.txt", "r");
    char line[200];
    char numStr[12]; // Assuming int will not exceed 11 characters + null terminator
    sprintf(numStr, "%d", num); // Convert int to string
    while (fgets(line, 200, f) != NULL) {
        if (strstr(line, numStr) && strstr(line, nom)) {
            fclose(f);
            return 1;
        }
    }
    while (getchar() != '\n');

    printf("Appuyez sur Entrée pour continuer...\n");
    getchar();
    fclose(f);
    return 0;
}

int verifier_GR(int num, char nom[30]) {
    FILE *f = fopen("GR.txt", "r");
    char line[200];
    char numStr[12]; // Assuming int will not exceed 11 characters + null terminator
    sprintf(numStr, "%d", num); // Convert int to string
    while (fgets(line, 200, f) != NULL) {
        if (strstr(line, numStr) && strstr(line, nom)) {
            fclose(f);
            return 1;
        }
    }
    while (getchar() != '\n');

    printf("Appuyez sur Entrée pour continuer...\n");
    getchar();
    fclose(f);
    return 0;
}
int verifier_chef_technique(int num, char nom[30]) {
    FILE *f = fopen("membre_vip.txt", "r");
    char line[200];
    char numStr[12]; // Assuming int will not exceed 11 characters + null terminator
    sprintf(numStr, "%d", num); // Convert int to string
    while (fgets(line, 200, f) != NULL) {
        if (strstr(line, numStr) && strstr(line, nom)) {
            fclose(f);
            return 1;
        }
    }
    while (getchar() != '\n');

    printf("Appuyez sur Entrée pour continuer...\n");
    getchar();
    fclose(f);
    return 0;
}

int verifier_chef_analyste(int num, char nom[30]) {
    FILE *f = fopen("membre_vip.txt", "r");
    char line[200];
    char numStr[12]; // Assuming int will not exceed 11 characters + null terminator
    sprintf(numStr, "%d", num); // Convert int to string
    while (fgets(line, 200, f) != NULL) {
        if (strstr(line, numStr) && strstr(line, nom)) {
            fclose(f);
            return 1;
        }
    }
    while (getchar() != '\n');

    printf("Appuyez sur Entrée pour continuer...\n");
    getchar();
    fclose(f);
    return 0;
}

int verifier_chef_medias(int num, char nom[30]) {
    FILE *f = fopen("membre_vip.txt", "r");
    char line[200];
    char numStr[12]; // Assuming int will not exceed 11 characters + null terminator
    sprintf(numStr, "%d", num); // Convert int to string
    while (fgets(line, 200, f) != NULL) {
        if (strstr(line, numStr) && strstr(line, nom)) {
            fclose(f);
            return 1;
        }
    }
    while (getchar() != '\n');

    printf("Appuyez sur Entrée pour continuer...\n");
    getchar();
    fclose(f);
    return 0;
}

int verifier_chef_entretiens(int num, char nom[30]) {
    FILE *f = fopen("membre_vip.txt", "r");
    char line[200];
    char numStr[12]; // Assuming int will not exceed 11 characters + null terminator
    sprintf(numStr, "%d", num); // Convert int to string
    while (fgets(line, 200, f) != NULL) {
        if (strstr(line, numStr) && strstr(line, nom)) {
            fclose(f);
            return 1;
        }
    }
    while (getchar() != '\n');

    printf("Appuyez sur Entrée pour continuer...\n");
    getchar();
    fclose(f);
    return 0;
}

void modifier_membre(int num,char nom[30]) {
    membre m = rechercher_membre(num);
    supprimer_membre(num); // Assuming rechercher_membre returns a string
    FILE *f = fopen("membre.txt", "a"); // Use "w" mode to overwrite existing content
    int choice;


    do {
        printf("1) Changer le nom, prénom et âge\n2) Changer l'adresse\n3) Retour\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:

                printf("NOM, Prenom et Age : ");
                scanf("%s %s %d", m.nom, m.prenom, &m.age);
                int numt;
                printf("\nentez le numero de la tache que vous effecter\n:");
                scanf("%d",&numt);
                modifier_tache(numt,m.nom);
                printf("\n\n\t**modifier avec succes**\n");
                 while (getchar() != '\n');

                    printf("Appuyez sur Entrée pour continuer...\n");
                    getchar();


                break;
            case 2:
                printf("Adresse : ");
                scanf("%s", m.adresse);
                printf("\n\n\t**modifier avec succes**\n");
                 while (getchar() != '\n');

                    printf("Appuyez sur Entrée pour continuer...\n");
                    getchar();
                break;

            case 3:
                break;

            default:
                printf("! Mauvais chiffre, réessayez\n");
                break;
        }
    } while (choice != 3);

    fwrite(&m, sizeof(membre), 1, f);

    fclose(f);


}

void afficher_structure(){

    FILE *f=fopen("structure.txt","r");
    char c;
    system("clear");
    sleep(0.1);

    while((c=fgetc(f))!=EOF)
        printf("%c",c);

    while (getchar() != '\n');

    printf("\nAppuyez sur Entrée pour continuer...\n");
    getchar();
}

