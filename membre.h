
#include<stdio.h>
#include<stdbool.h>

typedef struct membre {
    char nom[30];
    char prenom[30];
    int numero;
    char adresse[30];
    int age;
    int pre_tranche;
    int deu_tranche;
    int troi_tranche;
    char horaire[30];
    float cotisation;
    char tache[30];

} membre;

typedef struct records1{
    char  minutes[1000];
     char date[50];
} records1;

typedef struct records2{
    char correspondence[1000];
     char date[50];
} records2;



void afficher_structure();
membre rechercher_membre(int num);
void afficher_membre(char*,int);
void enregistrer();
void afficher_tout();
void supprimer_membre(int);
void cotiser(int,float);
void payer_tranche(int);
float tranche_total();
float cotisation_total();
int verifier_DG(int ,char *);
int verifier_PDG(int ,char *);
int verifier_SECRET(int ,char *);
int verifier_TRESOR(int ,char *);
int verifier_GR(int ,char *);
int verifier_GT(int ,char *);
int verifier_membre(int ,char *);
void modifier_membre(int,char*);
void recordMinutes(FILE *file);
void handleCorrespondence(FILE *file);
void afficherecordMinutes(FILE *file);
void afffichehandleCorrespondence(FILE *file);
void rediger_les_procesverbaux_ou_traiter_la_correspondance ();
void afficher_les_procesverbaux_ou_la_correspondance ();
