#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

#include "ressource.h"
#include "tache.h"
#include "membre.h"


void statistique(){
    
    printf("\n-------------------------------------------**********SUIVI DU BUDGET ET STATISTIQUE DU CLUB************--------------------------------------------------------------------------------\n\n\n\n\n\n");
  	printf("\n\n\n------------------------------*****SUIVIE DES STATISTIQUES DES DONS, EQUIPEMENTS ET DES FOURNITURES DU CLUB******------------------\n\n");
     afficher_les_ressources();

     statistique_tache();
     printf("\n\n\n\n\n\n------------------------------***SUIVIE DES COTISATION DES MEMBRE****------------------------------\n\n\n");
     statistique_cotisation();
     statistique_membre_QUI_ONT_PAYER_LEURS_COTISATION();
     printf("\n\n\n\n\n------------------------------***SUIVIE DES INSCRIPTION DES MEMBRE****-------------------------\n\n\n");
     statistique_des_frais_des_inscriptions();
     statistique_membre_QUI_ONT_TOUS_PAYER_LEURS_FRAIS_D_INSCRIPTION();
     statistique_membre_AYANT_PAS_PAYER_UNIQUEMENT_LA_1ére_TRANCHE();
     statistique_membre_AYANT_PAS_PAYER_UNIQUEMENT_LA_1ére_ET__2éme_TRANCHE();
     statistique_buget_depense();
     printf("\n\n\n\n\n\n------------------------------***SUIVI DES PROJETS DU CLUB***------------------------------\n\n\n");
     afficheProget();
     
}
void afficher_les_ressources(){
    printf("\n\n\n\t\t\t\t\t\t\t*****STATISTIQUE ET BUDGET DES DONS******\n\n");
    printf("\nIDDON\t\t\t\t");
    printf("NOM ET PRENOM\t\t\t\t");
    printf("MONTANT DU DON\t\t\t\t");
    printf("STATUT\t\t\t\t");
    printf("DATE\n\n");
    statistique_don();

    printf("\n\n\n\t\t\t\t\t\t****STATISTIQUE ET BUDGET DES EQUIPEMENT DU CLUB****\n\n");
    printf("\nIDEQUIP\t\t\t\t");
    printf("NOM ET PRENOM DU DEPOSITAIRE\t\t\t\t");
    printf("NOM DE L'EQUIPEMENT\t\t\t\t");
    printf("STATUT\t\t\t\t");
    printf("DATE\n");
    statistique_equipement();
    printf("\n\n\n\t\t\t\t\t\t****STATISTIQUE ET BUDGET DES FOURNITURES DU CLUB****\n\n");
    printf("\nIDFOURN\t\t\t\t");
    printf("NOM ET PRENOM DU DEPOSITAIRE\t\t\t\t");
    printf("NOM DE LA FOURNITURE\t\t\t\t");
    printf("STATUT\t\t\t\t");
    printf("DATE\n");
    statistique_fourniture();
}
void statistique_don() {
    FILE *fp = fopen("Ressourcedon.txt", "r");
    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    struct don don;
    int count=0;
    int somme=0;
    while (fread(&don, sizeof(struct don), 1, fp)) {
         printf("\n%d\t\t\t\t%s\t\t\t\t\t%d\t\t\t\t\t%s\t\t\t\t%s\n\n",don.numero,don.nom_donneur,don.argent,don.statut,don.date);          
        fseek(fp, -sizeof(struct don), SEEK_SET);
        count++;
        somme=don.argent+somme;
    }

    printf("\n\n\t\t****LE NOMBRE TOTAL DE DONATAIRE EST \t:[  %d  ]",count);
    printf("\n\t\t***LA SOMME DE DES DONS EST :[   %d  ]\n\n\n\n\n",somme);

    fclose(fp);
    
}

void statistique_equipement() {
    FILE *fp = fopen("Ressourceequip.txt", "r");
    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    struct equipement equipement;
    int count=0;
    while (fread(&equipement, sizeof(struct equipement), 1, fp)) {
         printf("\n%d\t\t\t\t\t\t%s\t\t\t\t\t%s\t\t\t\t\t%s\t\t\t\t\t%s\n\n", equipement.numero,equipement.nom_donneur,equipement.nom_equipement,equipement.statut,equipement.date);
        fseek(fp, -sizeof(struct equipement), SEEK_SET);
        count++;
    }

    printf("\n\n\n\t\t**LE NOMBRE TOTAL D'EQUIPEMENT EST \t:[  %d  ]\n\n\n\n",count);

    fclose(fp);
    
}
void statistique_fourniture() {
    FILE *fp = fopen("Ressourcefourn.txt", "r");
    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    struct fournitures fournitures;
    int count=0;
    while (fread(&fournitures, sizeof(struct fournitures), 1, fp)) {
        printf("\n%d\t\t\t\t\t\t\t%s\t\t\t\t\t\t%s\t\t\t\t\t%s\t\t\t\t\t%s\n\n", fournitures.numero,fournitures.nom_donneur,fournitures.nom_fourniture,fournitures.statut,fournitures.date);
        fseek(fp, -sizeof(struct fournitures), SEEK_SET);
        count++;
    }
    printf("\n\n\n\t\t**LE NOMBRE TOTAL FOURNITURES EST \t:[  %d  ]\n\n\n\n",count);

    fclose(fp);
    
}
void statistique_cotisation() {
    FILE *fp = fopen("membre.txt", "r");
    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

     membre m;
    int sum=0;
    while (fread(&m, sizeof(membre), 1, fp)) {
        fseek(fp, -sizeof(membre), SEEK_SET);
        sum=m.cotisation+sum;
    }
    printf("\n\n\t\t**LA SOMME TATAL DES COTISATION EST \t:[  %d  ]\n\n\n\n",sum);

    fclose(fp);
    
}
void statistique_membre_QUI_ONT_PAYER_LEURS_COTISATION(){
    FILE *fp = fopen("membre.txt", "r");
    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    membre m;
    int count=0;
    printf("\n\t***MEMBRE QUI ON COTISER***\n");
     printf("\n\tNOM\t\t\tPRENOM\t\t\tMONTANT");
    while (fread(&m, sizeof( membre), 1, fp)) {
       if(m.troi_tranche!=0){
        printf("\n\n\t%s\t\t\t%s\t\t\t%f\n",m.nom,m.prenom,m.cotisation);
        fseek(fp, -sizeof( membre), SEEK_SET);
        count++;
        }
    }
    printf("\n\n\t**LE NOMBRE TOTAL DES MEMBRES AYANTS PAYÉ LEURS COTISATION\t:[  %d  ]\n\n",count);

    fclose(fp);
    
}
void statistique_des_frais_des_inscriptions() {
    FILE *fp = fopen("membre.txt", "r");
    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

     membre m;
    int sum=0;
    while (fread(&m, sizeof(membre), 1, fp)) {
        fseek(fp, -sizeof(membre), SEEK_SET);
        sum=m.pre_tranche + m.deu_tranche + m.troi_tranche +sum;
    }
    printf("\n\t**LA SOMME TOTAL DES FRAIS D'INSCRIPTIONS EST \t:[  %d  ]",sum);

    fclose(fp);
    
}
void statistique_membre_QUI_ONT_TOUS_PAYER_LEURS_FRAIS_D_INSCRIPTION() {
    FILE *fp = fopen("membre.txt", "r");
    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier ");
        return;
    }

    membre m;
    int count=0;
     printf("\n\n\n\t\t***MEMBRES AYANT PAYER LA TOTALITÈ DE LEURS FRAIS D'INSCRIPTION**\n\tNOM\t\t\tPRENOM");
    while (fread(&m, sizeof( membre), 1, fp)) {
       if(m.troi_tranche!=0){
        printf("\n %s\t\t\t\t%s",m.nom,m.prenom);
        fseek(fp, -sizeof( membre), SEEK_SET);
        count++;
        }
    }
    printf("\n\n\n\t\t***LE NOMBRE TOTAL DES MEMBRES AYANTS PAYÉ LA TOTALITE DE LEURS INSCRIPTION: [  %d  ]\n\n",count);

    fclose(fp);
    
}
void statistique_membre_AYANT_PAS_PAYER_UNIQUEMENT_LA_1ére_TRANCHE() {
    FILE *fp = fopen("membre.txt", "r");
    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    membre  m;
    int count=0;
    printf("\n\n\t\t***MEMBRES AYANT PAYER UNIQUEMENT LA PREMIER TRANCHE  \n\tNOM\t\t\tPRENOM");
    while (fread(&m, sizeof(membre), 1, fp)) { 
       if(m.pre_tranche!=0 && m.deu_tranche ==0){
        printf("\n %s\t\t\t%s",m.nom,m.prenom);
        fseek(fp, -sizeof(membre), SEEK_SET);
        count++;
        }

    }
    printf("\n\n\t\t**LE NOMBRE TOTAL DES MEMBRES AYANT PAYER UNIQUEMENT LA PREMIER TRANCHE: [  %d  ]\n\n",count);

    fclose(fp);
    
}

void statistique_membre_AYANT_PAS_PAYER_UNIQUEMENT_LA_1ére_ET__2éme_TRANCHE() {
    FILE *fp = fopen("membre.txt", "r");
    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    membre  m;
    int count=0;
     printf("\n\n\n\t\t******MEMBRES AYANT PAYER UNIQUEMENT LA PREMIER ET LA DEUXIEME TRANCHE****\n\tNOM\t\t\tPRENOM");
     
    while (fread(&m, sizeof(membre), 1, fp)) {
         if(m.deu_tranche!=0 && m.troi_tranche==0){
        printf("\n %s\t\t\t%s",m.nom,m.prenom);
        fseek(fp, -sizeof(membre), SEEK_SET);
        count++;
        }

    }
    printf("\n\n\t\t****LE NOMBRE TOTAL DES MEMBRES AYANT PAYER UNIQUEMENT LA PREMIER ET LA DEUXIEME TRANCHE \t:[  %d  ]\n\n",count);

    fclose(fp);
    
}


void statistique_buget_depense() {

    FILE *fp = fopen("membre.txt", "r");
    FILE *fp1 = fopen("Ressourcedon.txt", "r");
    FILE *fp2 = fopen("proget.txt", "r");
    FILE *fp3 = fopen("tache.txt","r");
    
    if (fp1 == NULL || fp == NULL || fp2 == NULL || fp3 ==NULL) {
        perror("Erreur lors de l'ouverture du fichier4444");
        return;
    }
	printf("\\\\\\\\");
    membre m;
    tache t;
    struct don don;
    struct proget p;
    float budgetIn=1000000;
    int sum1=0;
    int sum2=0;
    int sum3=0;
    int sum4=0;
    int sum5=0;
    int budjet;
    
    while (fread(&m, sizeof( membre), 1, fp)&& fread(&don, sizeof(struct don), 1, fp1)&&fread(&p, sizeof(struct proget), 1, fp) && fread(&t,sizeof(tache),1,fp3)) {
        fseek(fp, -sizeof(membre), SEEK_SET);
         fseek(fp1, -sizeof(struct don), SEEK_SET);
         fseek(fp2, -sizeof(struct proget), SEEK_SET);
        sum5 +=t.budget;
        sum1 = m.pre_tranche + m.deu_tranche + m.troi_tranche + sum1;
        sum2 = don.argent+sum2;
        sum3 = p.depense+sum1;
        sum4 = m.cotisation+sum4;
        
    }
    
    budjet =( budgetIn+sum1+sum2+sum4)-sum3-sum5;
      printf("\n \n\t\t\t***BUDGET INITIAL DU CLUB***\t\t****BUDGET FINAL DU CLUB**** \t\t\t***DÉPENSE DU CLUB***");
      printf("\n \n\t\t\t%f\t\t\t\t\t%d \t\t\t\t\t %d",budgetIn,budjet,sum3);      
    

    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    
}

void ajouteProget() {
    struct proget p;
    int date;
    p.dateDebut=time(NULL);
    
 
    printf("Entre le  nom du proget à réaliser");
    scanf("%s" ,p.prog);

    printf("Entre la totalité des dépense du proget ");
    scanf("%d",&p.depense);
  
    printf("Entre le date de fin du proget\n1)une semaine\n2)un mois\n3)six mois\n4) un ans ");
    scanf("%d" ,&date);
    switch (date)
    {
    case 1:
        p.dateLimite= time(NULL) + 7 * 24 * 60 * 60;

        break;
    case 2:
        p.dateLimite= time(NULL) + 4 * 7 * 24 * 60 * 60;
        break;

    case 3:
        p.dateLimite= time(NULL) + 24 * 7 * 24 * 60 * 60;
        break;

    case 4:
        p.dateLimite= time(NULL) + 52 * 7 * 24 * 60 * 60;
        break;        
    default:
        printf("Délai invalide");
        break;
    }

    p.délai=0;

    FILE *fp = fopen("proget.txt", "a+");
    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }
     fwrite(&p,sizeof(struct proget),1,fp);
        

    fclose(fp);
    
    while (getchar() != '\n');

    printf("\n\n\t\t\tAppuyez sur Entrée pour continuer...\n");
    getchar();
    
}
void afficheProget() {
    struct proget p;
    FILE *fp = fopen("proget.txt", "r");

    printf("\n\n\n\t***PROGET DU CLUB***\t\t\t**DÉPENSE**\t\t\t**STATUT**\n\n");
    while (fread(&p,sizeof(struct proget),1,fp))
    {   
         p.délai = difftime(p.dateLimite, p.dateDebut);
         if (p.délai > 0) {
        printf(" \t\t%s\t\t\t%dFCFA\t\t\t\tEn cours\t\t %f jours avant la date limite \n", p.prog,p.depense, p.délai / (24 * 60 * 60));
    } else {
        printf(" \t\t%s\t\t\t%dFCFA\t\t\t\tTerminé \n", p.prog, p.depense);
    }
    }
    
  fclose(fp);
  
  while (getchar() != '\n');

printf("\n\n-----------------------------------------------------------------------------------------------------------------------------------------------\n\n");
   printf("\n\nAppuyez sur Entrée pour continuer...\n");
    getchar();
    
}

void statistique_tache(){

	float sum1=0,sum2=0,sum3=0,sum4=0,total=0;
	
	tache t;
	
	FILE *f=fopen("tache.txt","r");
	
	while(fread(&t,sizeof(tache),1,f)){
		if(strcmp(t.nom,"equipe_de_medias")==0)
			sum1+=t.budget;
		if(strcmp(t.nom,"equipe_technique")==0)
			sum3+=t.budget;
		if(strcmp(t.nom,"equipe_d_analystes")==0)
			sum2+=t.budget;
		if(strcmp(t.nom,"equipe_d_entretient")==0)
			sum4+=t.budget;
	}
	fclose(f);
	
	total=sum1+sum2+sum3+sum4;
	
	printf("\n\n\n\n\n\n\t\t\t\t\t\t*****BUDGET DES TACHE DU CLUB*****\n\n\n");
	printf("\n\t*equipe medias*\t\t*equipe d'analyse*\t\t*equipe technique*\t\t*equipe d'agent d'entretient*\t\t **TOTAL**\n\n");
	printf("\t\t%.1f\t\t\t%.1f\t\t\t\t%.1f\t\t\t\t%.1f\t\t\t\t%.1f",sum1,sum2,sum3,sum4,total);
}

	
	
	

