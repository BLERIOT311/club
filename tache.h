#include<stdio.h>



typedef struct tache{

int numero_tache;
char libelle[8];
float budget;

char nom[30];
char nom_respo[30];
char heure_cree[30];
char heure_fin[30];

}tache;


void cree_tache();
int rechercher_tache(char*);
void supprimer_tache(char*);
void modifier_tache();
void afficher_tache();
void afficher_tout_tache();
float budget_total_tache();
void effectuer_tache(char*,int);
void afficher_analyste();
void afficher_infor();
void afficher_agent();
void afficher_techniciens();
