
#include<stdio.h>
#include<time.h>
struct don {
    char nom_donneur[100]; // Adjust the size as needed
    int argent;
    char statut[20]; // Adjust the size as needed
    int numero;
    char date[50];
};

struct equipement {
    char nom_donneur[100]; // Ajustez la taille selon vos besoins
    char nom_equipement[30]; // Ajustez la taille selon vos besoins
    char statut[20]; // Ajustez la taille selon vos besoins
    int numero;
    char date[50];
};



struct fournitures {
    char nom_donneur[100]; // Adjust the size as needed
    char nom_fourniture[30]; // Adjust the size as needed
    char statut[20]; // Adjust the size as needed
    int numero;
    char date[50];
};
struct proget
{
   char prog[30];
    int depense;
    char statut[30];
    time_t dateDebut;
    time_t dateLimite; 
    double délai;

};

void enregistrer_don();
void statue_don();
void afficher_don();
void modifier_don();
void supprimer_don();

void enregistrer_equipement();
void statue_equipement();
void afficher_equipement();
void modifier_equipement();
void supprimer_equipement() ;

void enregistrer_fourniture();
void statue_fourniture();
void afficher_fourniture();
void modifier_fourniture();
void supprimer_fourniture() ;

void statistique();
void statistique_don();
void statistique_equipement();
void statistique_fourniture();
void statistique_des_tache();
void statistique_cotisation();
void statistique_des_frais_des_inscriptions();
void statistique_membre_QUI_ONT_PAYER_LEURS_COTISATION();
void statistique_membre_QUI_ONT_TOUS_PAYER_LEURS_FRAIS_D_INSCRIPTION();
void statistique_membre_AYANT_PAS_PAYER_UNIQUEMENT_LA_1ére_TRANCHE() ;
void statistique_membre_AYANT_PAS_PAYER_UNIQUEMENT_LA_1ére_ET__2éme_TRANCHE() ;
void statistique_buget_depense();
void ajouteProget();
void afficheProget();
void afficher_les_ressources();
void statistique_tache();


