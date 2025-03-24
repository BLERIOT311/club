#include<stdio.h>
#include<string.h>
#include "ressource.h"
#include "membre.h"
#include "tache.h"
#include<stdlib.h>
#include<unistd.h>



void print_menu()
{
    printf("\n\t\t\t******BIENVENUE AU CLUB********\n\n\n");
    printf("1) Membre du club\n");
    printf("2) Administrateur du club\n");
    printf("3) afficher la structure du CLUB\n");
    printf("4) Quitter\n\n\tchoix: ");

}
void connexion_menbre()
{
    printf("\n\t1)Se connecter\n\t2)s'enregistrer\n\t3)retour\n\t\tchoix :");
}
void print_membre_menu(char* nom)
{
    printf("\t\t***Bienvennue Mr(me) %s ****\n\n\n",nom);
    printf("1) Afficher\n");
    printf("2)Modifier (nom, prenom,adress)\n");
    printf("3) cotiser\n");
    printf("4)payer tranche\n");
    printf("5)Effectuer une tache\n");
    printf("6) QUITTER  LE CLUB\n");
    printf("7) \tRetour\n\tchoix:");
}

void print_admin_menu()
{
    printf("1) PDG\n");
    printf("2) DG\n");
    printf("3) Secretaire\n");
    printf("4) tresorier\n");
    printf("5)administrateur des taches\n");
    printf("6) administrateur de ressources\n");
    printf("7) retour\n\tchoix:");
}

void printf_secretaire(char* nom)
{
    printf("\t\t***Bienvennue Mr(me) %s ****\n\n\n",nom);
    printf("1) Rédiger les procès-verbaux et traiter la correspondance du club\n");
    printf("2) affichez les procès-verbaux et  les correspondance du club\n");
    printf("3) retour\n\tchoix:");
}

void printf_tresorier(char* nom)
{
    printf("\t\t***Bienvennue Mr(me) %s ****\n\n\n",nom);
    printf("1)AFFCHEZ LES SUIVI DU BUDGET ET STATISTIQUE DU CLUB\n");
    printf("2) Ajoutez  les progets  à réaliser du club\n");
    printf("3) Affichez  les progets du club\n");
    printf("4) retour\n\tchoix:");
}
void print_DG(char* nom)
{
    printf("\t\t***Bienvennue  Mr(me) DG %s ****\n\n\n",nom);
    printf("1) afficher tout les membres\n");
    printf("2) afficher un membre\n");
    printf("3) supprimer un membre\n");
    printf("4) afficher toutes taches\n");
    printf("5) afficher une taches\n");
    printf("6) supprimer une  tache\n");
    printf("7) cree une tache\n");
    printf("8)afficher toutes les ressources\n");
    printf("9) retour\n\tchoix:");
}

void print_GT(char* nom)
{
    printf("\t\t***Bienvennue  Mr(me)  %s ****\n\n\n",nom);
    printf("1) afficher toutes taches\n");
    printf("2) afficher une taches\n");
    printf("3) supprimer une  tache\n");
    printf("4) cree une tache\n");
    printf("5) retour\n\tchoix:");
}
void print_PDG(char* nom)
{
    printf("\t\t***Bienvennue  Mr(me) PDG %s ****\n\n\n",nom);
    printf("1) afficher tout les membres\n");
    printf("2) afficher un membre\n");
    printf("3) supprimer un membre\n");
    printf("4) afficher toutes taches\n");
    printf("5) afficher une taches\n");
    printf("6) supprimer une  tache\n");
    printf("7) cree une tache\n");
    printf("8)afficher toutes les ressources\n");
    printf("9) retour\n\tchoix:");
}

void print_MENU_ad_Ressources(char* nom)
{
    printf("\t\t***Bienvennue Mr(me) %s ****\n\n\n",nom);
    printf("1)DONS\n2)equipements\n3)fournitures\n4)quitter");
}

void print_MENU_DON()
{
    printf("1)ajouter un dons\n2)afficher un dons\n3)statuer un dons\n4)modifier un dons\n5)supprimer un dons\n6)retour\n\tchoix:");
}

void print_MENU_EQUIPEMENT()
{
    printf("1)ajouter un equipement\n2)afficher un equipement\n3)statuer un equipement\n4)modifier un equipement\n5)supprimer un equipement\n6)retour\n\tchoix");
}

void print_MENU_FOURNITURE()
{
    printf("1)ajouter une fourniture\n2)afficher une fourniture\n3)statuer une fourniture\n4)modifier une fourniture\n5)supprimer une fourniture\n6)retour\n\tchoix");
}

int main()
{
    int n=1;
    while(n!=0)
    {
        system("clear");
        sleep(0.1);
        print_menu();
        scanf("%d",&n);
        switch (n)
        {

        case 1:
            ;

            //information sur les membres
            int h=1;
            while(h!=0)
            {
                system("clear");
                sleep(0.1);
                connexion_menbre();
                int n;
                scanf("%d",&n);
                switch(n)
                {
                case 1:
                    ;
                    system("clear");
                    sleep(0.1);
                    //connexion au compte de membre
                    char nom[30];
                    int num;
                    printf("\nentrez votre nom:");
                    scanf("%s",nom);
                    printf("entrez votre numero");
                    scanf("%d",&num);
                    if(verifier_membre(num,nom)==1)
                    {
                        int q=1;
                        while(q!=0)
                        {
                            system("clear");
                            sleep(0.1);
                            print_membre_menu(nom);
                            int n;
                            scanf("%d",&n);
                            switch(n)
                            {
                            case 1:
                                afficher_membre(nom,num);
                                break;
                            case 2:
                                modifier_membre(num,nom);
                                q=0;
                                break;
                            case 3:
                                printf("entrer la somme a cotiser:");
                                float som;
                                scanf("%f",&som);
                                cotiser(num,som);
                                break;
                             case 4:
                                payer_tranche(num);
                                break;
                            case 5:
                                ;
                                int num3;
                                char nom3[30];
                                printf("entrez le nom de la tache:");
                                scanf("%s",nom3);
                                printf("entrez le numero de la tache:");
                                scanf("%d",&num3);
                                effectuer_tache(nom3,num3);
                                break;

                            case 6:
                                supprimer_membre(num);
                                q=0;
                                break;
                            case 7:
                                q=0;
                                break;
                            default:
                                printf("!Erreur de chiffre reesayer:  ");
                                break;
                            }

                        }
                        break;
                    }
                    else
                    {
                        printf("!membre introuvable reesayer");
                        while (getchar() != '\n');

                        printf("\n\nAppuyez sur Entrée pour continuer...\n");
                        getchar();
                        break;
                    }
                    break;

                case 2:
                    // inscription au club
                    enregistrer();
                    break;

                case 3:
                    h=0;
                    break;
                default:
                    printf("!Erreur de chiffre reesayer:  \n\n");
                    while (getchar() != '\n');

                    printf("\nAppuyez sur Entrée pour continuer...\n");
                    getchar();
                    break;
                }
            }
            break;
        case 2:
            ;

            int m=1;

            while(m!=0)
            {
                system("clear");sleep(0.1);
                print_admin_menu();
                scanf("%d",&m);


                switch (m)
                {

                case 1:
                    printf("entrer votre nom et numero\n:");
                    int num1;
                    char nom1[20];
                    scanf("%s%d",nom1,&num1);
                    if(verifier_PDG(num1,nom1)==1)
                    {
                        int z=1;
                        while(z!=0)
                        {
                            system("clear");sleep(0.1);
                            print_PDG(nom1);
                            scanf("%d",&h);
                            switch(h)
                            {
                            case 1:
                                afficher_tout();
                                break;
                            case 2:
                                printf("entrez le nom et numero de ce membre\n:");
                                int numm1;
                                char nomm1[30];
                                scanf("%s%d",nomm1,&numm1);
                                afficher_membre(nomm1,numm1);
                                break;
                            case 3:
                                printf("entrez le nom et numero du membre a supprimer\n:");
                                int numm2;
                                char nomm2[30];
                                scanf("%s%d",nomm2,&numm2);
                                supprimer_membre(numm2);
                                break;
                            case 4:
                                afficher_tout_tache();
                                break;
                            case 5:

                                afficher_tache();
                                break;
                            case 6:
                                printf("entrez le nom et numero de la tache a supprimer\n:");
                                int numm6;
                                char nomm6[30];
                                scanf("%s%d",nomm6,&numm6);

                                supprimer_tache(nomm6);
                                break;
                            case 7:
                                printf("entrez le nom et numero du responsable de la tache a cree\n:");
                                char nom7[30];int num7;
                                scanf("%s%d",nom7,&num7);
                                if(verifier_membre(num7,nom7)){
                                    cree_tache(nom7);
                                }else{
                                    printf("\n\n\t\t!ERRWUR  ,MEMBRE INTROUVABLE\n\n");
                                    while (getchar() != '\n');

                                    printf("Appuyez sur Entrée pour continuer...\n");
                                    getchar();
                                }
                                break;
                            case 8:
                                afficher_les_ressources();
                                while (getchar() != '\n');

                                    printf("\n\n\t\tAppuyez sur Entrée pour continuer...\n");
                                    getchar();
                                break;
                            case 9:
                                z=0;
                                break;
                            default:
                                printf("!ERREUR DE CHIFFRE\\n\n");
                                break;
                            }
                        }
                    }
                    else
                    {
                        printf("\n\n\t!IDENTIFIANT INCORRECT\n\n");
                        system("clear");sleep(1/5);
                                    printf("\n\n\t!IDENTIFIANT INCORRECT\n\n");
                                     while (getchar() != '\n');

                    printf("\n\n\n\t\tAppuyez sur Entrée pour continuer...\n");
                    getchar();
                    }
                    break;
                //pdg
                case 2:
                    printf("entrer votre nom et numero\n:");
                    int num2;
                    char nom2[20];
                    scanf("%s%d",nom2,&num2);
                    if(verifier_DG(num2,nom2)==1)
                    {
                        int z=1;
                        while(z!=0)
                        {
                            system("clear");sleep(0.1);
                            print_DG(nom2);
                            scanf("%d",&h);
                            switch(h)
                            {
                            case 1:
                                afficher_tout();
                                break;
                            case 2:
                                printf("entrez le nom et numero de ce membre\n:");
                                int numm1;
                                char nomm1[30];
                                scanf("%s%d",nomm1,&numm1);
                                afficher_membre(nomm1,numm1);
                                break;
                            case 3:
                                printf("entrez le nom et numero du membre a supprimer\n:");
                                int numm2;
                                char nomm2[30];
                                scanf("%s%d",nomm2,&numm2);
                                supprimer_membre(numm2);
                                break;
                            case 4:
                                afficher_tout_tache();
                                break;
                            case 5:
                                printf("entrez le nom et numero de cette tache\n:");
                                int nummt;
                                char nommt[30];
                                scanf("%s%d",nommt,&nummt);
                                afficher_tache(nommt,nummt);
                                break;
                            case 6:
                                printf("entrez le nom et numero de la tache a supprimer\n:");
                                int numm3;
                                char nomm3[30];
                                scanf("%s%d",nomm3,&numm3);
                                supprimer_tache(nomm3);
                                break;
                            case 7:
                                printf("entrez le nom et numero du responsable de la tache a cree\n:");
                                char nomm7[30];int numm7;
                                scanf("%s%d",nomm7,&numm7);
                                if(verifier_membre(numm7,nomm7)==1){
                                    cree_tache(nomm7);
                                }else{
                                    printf("\n\n\t\t!ERRWUR  ,MEMBRE INTROUVABLE\n\n");
                                    while (getchar() != '\n');

                                    printf("Appuyez sur Entrée pour continuer...\n");
                                    getchar();
                                }
                                break;
                            case 8:
                                afficher_les_ressources();
                                while (getchar() != '\n');

                                    printf("\n\n\t\tAppuyez sur Entrée pour continuer...\n");
                                    getchar();
                                break;
                            case 9:
                                z=0;
                                break;
                            default:
                                printf("!ERREUR DE CHIFFRE\\n\n");
                                break;
                            }
                        }
                    }
                    else
                    {
                        printf("\n\n\t!IDENTIFIANT INCORRECT\n\n");
                        system("clear");sleep(1/5);
                                    printf("\n\n\t!IDENTIFIANT INCORRECT\n\n");
                                     while (getchar() != '\n');

                    printf("\n\n\n\t\tAppuyez sur Entrée pour continuer...\n");
                    getchar();
                    }
                    break;
                //dg
                case 3:
                    printf("entrer votre nom et numero\n:");
                    int num3;
                    char nom3[20];
                    scanf("%s%d",nom3,&num3);
                    if(verifier_SECRET(num3,nom3)==1)
                    {
                        int z=1;
                        while(z!=0)
                        {
                            system("clear");sleep(0.1);
                            printf_secretaire(nom3);
                            scanf("%d",&h);
                            switch(h)
                            {
                            case 1:
                            printf("\033[H\033[J");
                            sleep(1/2);
                            rediger_les_procesverbaux_ou_traiter_la_correspondance ();
                            break; 
                        case 2:
                            printf("\033[H\033[J");
                            sleep(1/2);
                            afficher_les_procesverbaux_ou_la_correspondance ();
                            break;
                        case 3:
                            printf("\033[H\033[J");
                            sleep(1/2);
                            z=0;
                            break;
                                
                        default:
                            printf("\033[H\033[J");
                            sleep(1/2);
                            printf("vous avez entrer un mauvais numero reesayer\n");
                            break;
                        }
                        }
                    }
                    else
                    {
                        printf("!IDENTIFIANT INCORRECT\n\n");
                         system("clear");sleep(1/5);
                                    printf("\n\n\t!IDENTIFIANT INCORRECT\n\n");
                                     while (getchar() != '\n');

                    printf("\n\n\n\t\tAppuyez sur Entrée pour continuer...\n");
                    getchar();
                    }
                    break;

                //secretaire
                case 4:
                printf("\033[H\033[J");sleep(1/2);          
                //tresorier
                printf("entrer votre nom et numero\n:");
                    int numsec;
                    char nomsec[20];
                    scanf("%s %d",nomsec,&numsec);
                    printf("\033[H\033[J");sleep(1/2);
                    if(verifier_TRESOR(numsec,nomsec)==1){
                        int n;
                        int q=1;
                        while (q!=0)
                        {
                        	printf("\033[H\033[J");
                                        sleep(1/2);
		                    printf_tresorier(nomsec);
		                scanf("%d",&q);
		                
		                switch (q)
		                {
		                case 1:
		                printf("\033[H\033[J");
		                    sleep(1/2);
		                    statistique();
		                    break; 
		                case 2:
		                printf("\033[H\033[J");
		                    sleep(1/2);
		                     ajouteProget();   
		                    break;
		                case 3:
		                    printf("\033[H\033[J");
		                    sleep(1/2);
		                    afficheProget();
		                    break;
		                case 4:
		                    printf("\033[H\033[J");
		                    sleep(1/2);
		                    q=0;
		                    break;
		                default:
		                printf("\033[H\033[J");
		                    sleep(1/2);
		                    printf("vous avez entrer un mauvais numero reesayer\n");
		                    break;
		                }
                        }
                    }
                    else
                    {
                        printf("\n\n\t!IDENTIFIANT INCORRECT\n\n");
                         system("clear");sleep(1/5);
                                    printf("\n\n\t!IDENTIFIANT INCORRECT\n\n");
                                     while (getchar() != '\n');

                    printf("\n\n\n\t\tAppuyez sur Entrée pour continuer...\n");
                    getchar();
                    }
                   break; 
                case 5:
                // gestionnaire des taches
                    printf("entrer votre nom et numero\n:");
                    int numtt;
                    char nomtt[20];
                    scanf("%s%d",nomtt,&numtt);
                    if(verifier_GT(numtt,nomtt)==1)
                    {
                        int z=1;
                        while(z!=0)
                        {
                            system("clear");sleep(0.1);
                            print_GT(nomtt);
                            scanf("%d",&h);
                            switch(h)
                            {
                            
                            case 1:
                                afficher_tout_tache();
                                break;
                            case 2:
                                printf("entrez le nom et numero de cette tache\n:");
                                int nummt;
                                char nommt[30];
                                scanf("%s%d",nommt,&nummt);
                                afficher_tache(nommt,nummt);
                                break;
                            case 3:
                                printf("entrez le nom et numero de la tache a supprimer\n:");
                                int numm3;
                                char nomm3[30];
                                scanf("%s%d",nomm3,&numm3);
                                supprimer_tache(nomm3);
                                break;
                            case 4:
                                printf("entrez le nom et numero du responsable de la tache a cree\n:");
                                char nomm7[30];int numm7;
                                scanf("%s%d",nomm7,&numm7);
                                if(verifier_membre(numm7,nomm7)==1){
                                    cree_tache(nomm7);
                                }else{
                                    printf("\n\n\t\t!ERRWUR  ,MEMBRE INTROUVABLE\n\n");
                                    while (getchar() != '\n');

                                    printf("Appuyez sur Entrée pour continuer...\n");
                                    getchar();
                                }
                                break;
                            
                            case 5:
                                z=0;
                                break;
                            default:
                                printf("!ERREUR DE CHIFFRE\\n\n");
                                break;
                            }
                        }
                    }
                    else
                    {
                        printf("\n\n\t!IDENTIFIANT INCORRECT\n\n");
                         system("clear");sleep(1/5);
                                    printf("\n\n\t!IDENTIFIANT INCORRECT\n\n");
                                     while (getchar() != '\n');

                    printf("\n\n\n\t\tAppuyez sur Entrée pour continuer...\n");
                    getchar();
                    }
                    break;
                case 6:
                    ;
                    //Administrateur de ressource

                    printf("entrer votre nom et numero\n:");
                    int numad;
                    char nomad[20];
                    scanf("%s%d",nomad,&numad);
                    int q=10;
                    if(verifier_GR(numad,nomad)==1)
                    {
                    while(q!=0)
                    {

                        print_MENU_ad_Ressources(nomad);

                        scanf("%d",&q);

                       switch(q){
                            case 1:
                                printf("\033[H\033[J");
                                sleep(1/2);
                                        int z =10;
                                        while(z!=0){
                                            printf("\033[H\033[J");sleep(1/2);
                              
		                                print_MENU_DON();
		                                scanf("%d",&z);
		                                switch(z){
		                                    case 1:
		                                    printf("\033[H\033[J");
		                                    sleep(1/2);
		                                        enregistrer_don();
		                                        break;
		                                    case 2:
		                                        printf("\033[H\033[J");
		                                        sleep(1/2);
		                                        afficher_don();
		                                        
		                                        break;
		                                    case 3:
		                                        printf("\033[H\033[J");
		                                        sleep(1/2);
		                                        statue_don();
		                                        break;
		                                    case 4:
		                                        printf("\033[H\033[J");
		                                        sleep(1/2);
		                                        modifier_don();
		                                        break;
		                                    case 5:
		                                        printf("\033[H\033[J");
		                                        sleep(1/2);
		                                        supprimer_don();
		                                        break;
		                                    case 6:
		                                        printf("\033[H\033[J");
		                                        sleep(1/2);
		                                        z=0;
		                                        break;
		                                    default:
		                                        printf("\033[H\033[J");
		                                        sleep(1/2);
		                                        printf("vous avez entrer un mauvais numero reesayer\n");
		                                        break;
		                                }

                                        }
                                        

                                break;

                                case 2:
                                                    
                                                printf("\033[H\033[J");
                                            sleep(1/2);
                                            int m=10;
                                                    while(m!=0){
                                                     printf("\033[H\033[J");sleep(1/2);
                                                        print_MENU_EQUIPEMENT();


                                                    scanf("%d",&m);
                                                    switch(m){
                                                        case 1:
                                                            printf("\033[H\033[J");
                                                            sleep(1/2);
                            
                                                            enregistrer_equipement();
                                                                
                                                            break;
                                                        case 2:
                                                            printf("\033[H\033[J");
                                                            sleep(1/2);
                                                        afficher_equipement();
                                                            break;
                                                        case 3:
                                                            printf("\033[H\033[J");
                                                            sleep(1/2);
                                                            statue_equipement();
                                                            
                                                            break;
                                                        case 4:
                                                            printf("\033[H\033[J");
                                                            sleep(1/2);
                                                            modifier_equipement();
                                                            break;
                                                        case 5:
                                                            printf("\033[H\033[J");
                                                            sleep(1/2);
                                                            supprimer_equipement();
                                                            break;
                                                        case 6:
                                                            m=0;
                                                            break;
                                                        default:
                                                                printf("\033[H\033[J");
                                                            sleep(1/2);
                                                            printf("vous avez entrer un mauvais numero reesayer\n");
                                                            break;
                                                    }

                                                    }
                                            
                                                break;
                                            case 3:
                                            
                                                    printf("\033[H\033[J");
                                                    sleep(1/2);
                                                    
                                                    int l=10;
                                                    
                                                    
                                                    while(l!=0){
                                                            printf("\033[H\033[J");sleep(1/2); print_MENU_FOURNITURE();
                                                            scanf("%d",&l);
                                                    switch(l){
                                                        case 1:
                                                            
                                                            printf("\033[H\033[J");
                                                            sleep(1/2);
                                                            enregistrer_fourniture();
                                                            break;
                                                        case 2:
                                                            printf("\033[H\033[J");
                                                            sleep(1/2);
                                                            afficher_fourniture();
                                                            break;
                                                        case 3:
                                                                printf("\033[H\033[J");
                                                            sleep(1/2);
                                                            statue_fourniture();
                                                            
                                                            break;
                                                        case 4:
                                                            printf("\033[H\033[J");
                                                            sleep(1/2);
                                                            modifier_fourniture();
                                                            break;
                                                        case 5:
                                                            printf("\033[H\033[J");
                                                            sleep(1/2);
                                                            supprimer_fourniture();
                                                            break;
                                                        case 6:
                                                                printf("\033[H\033[J");
                                                            sleep(1/2);
                                                            l=0;
                                                            break;
                                                        default:
                                                            printf("\033[H\033[J");
                                                            sleep(1/2);
                                                            printf("vous avez entrer un mauvais numero reesayer\n");
                                                            break;
                                                    }

                                                    } 
                                        break;

                                        case 4:
                                            printf("\033[H\033[J");
                                            sleep(1/2);
                                                q=0;
                                                break;

                                    default:  
                                        printf("\033[H\033[J");
                                        sleep(1/2);

                                        printf("vous avez entrer le mauvais numero reesayez\n");
                                        break;         
                                    } 
                                            }
                                }else
                                {
                                system("clear");sleep(1/5);
                                    printf("\n\n\t!IDENTIFIANT INCORRECT\n\n");
                                     while (getchar() != '\n');

                    printf("\n\n\n\t\tAppuyez sur Entrée pour continuer...\n");
                    getchar();
                                }                        

                                break;
                                
                            case 7:
                                m=0;
                                break;
                            default:
                                printf("!ERREUR.ressayer\n\n");
                                break;
                            }
                            }
                            break;
                        case 3:
                            //afficher la structure du CLUB
				afficher_structure();
                            break;
                        case 4:
                            system("clear");
                            sleep(0.1);
                            int p;
                            printf("\n\n vous etes sur le point de quiter: \n\n\t1)continuer\n\t2)retour\n\t\tchoix:");
                            scanf("%d",&p);
                            switch(p){
                                case 1:
                                    n=0;
                                    break;
                                case 2:
                                    break;
                            }
                            break;
                        default:
                            printf("\n!ERREUR DE SAISIE\n\n");
                            break;

         }
     }
 printf("\033[H\033[J");sleep(1/2);
    return 0;
 }



