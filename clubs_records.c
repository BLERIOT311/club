#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "membre.h"
// Function to record meeting minutes
void recordMinutes(FILE *file) {
    fgetc(stdin);
    records1 r;
    printf("Enter meeting minutes: ");
    fgets(r.minutes, sizeof(r.minutes), stdin);
    strcpy(r.date,__DATE__);
    fwrite(&r,sizeof(records1),1,file);
     while (getchar() != '\n');

    printf("Appuyez sur Entrée pour continuer...\n");
    getchar();
}
// Function to handle club correspondence
void handleCorrespondence(FILE *file) {
	 fgetc(stdin);
    records2 r;
    strcpy(r.date,__DATE__);
    printf("Enter club correspondence: ");
    fgets(r.correspondence, sizeof(r.correspondence), stdin);
     fwrite(&r,sizeof(records2),1,file);
     while (getchar() != '\n');
    printf("\n\n\t\tAppuyez sur Entrée pour continuer...\n");
    getchar();
    }

void afficherecordMinutes(FILE *file) {
    
    records1 r;
    
   while( fread(&r,sizeof(records1),1,file)){
    printf("\n\nDATE :%s\nMeeting Minutes: \n\t\t%s\n\n\n\n",r.date,r.minutes);
   };
}


void afffichehandleCorrespondence(FILE *file) {
    records2 r;
   while( fread(&r,sizeof(records2),1,file)){
    printf("\n\nDATE :%s\nClub Correspondence: \n\t%s\n\n\n",r.date,r.correspondence);
   };
}
void rediger_les_procesverbaux_ou_traiter_la_correspondance (){
    FILE *file = fopen("club_records.txt", "a"); // Open file for appending
    
    if (file == NULL) {
        printf("Error opening file.\n");
        return ;
    }

    // Record minutes and handle correspondence
    printf("\n1)Rédiger les procès-verbaux \n2) traiter la correspondance\n");
    int n;
    scanf("%d",&n);

    switch (n)
    {
    case 1:
        recordMinutes(file);
       
    
	    fclose(file); // Close the file
	    printf("Meeting minutes  saved.\n");
	    while (getchar() != '\n');

    	printf("\n\n\t\tAppuyez sur Entrée pour continuer...\n");
    	getchar();
     break;
    case 2:
		handleCorrespondence(file);
	    fclose(file); // Close the file
	    printf(" correspondence saved.\n");
	    break;
    default:
        printf("\nERREUR DE CHOIX");
        break;
    }

   
}
void afficher_les_procesverbaux_ou_la_correspondance (){
     FILE *file = fopen("club_records.txt", "r"); // Open file to read

    if (file == NULL) {
        printf("Error opening file.\n");
        return ;
    }

    // Record minutes and handle correspondence
    printf("\n1)affichez les procès-verbaux \n2) affichez les correspondance\n");
    int n;
    scanf("%d",&n);

    switch (n)
    {
    case 1:
        afficherecordMinutes(file);
        while (getchar() != '\n');

    printf("\n\n\t\tAppuyez sur Entrée pour continuer...\n");
    getchar();
        
    
    fclose(file); // Close the file
    break;
    
    case 2:
        afffichehandleCorrespondence(file);
         while (getchar() != '\n');
    printf("\n\n\t\tAppuyez sur Entrée pour continuer...\n");
    getchar();
    fclose(file); // Close the file
    break;
    default:
        printf("\nERREUR DE CHOIX");
        break;
    }

   
}
