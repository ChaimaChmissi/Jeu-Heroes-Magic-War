#include <stdio.h>
#include <stdlib.h>
#define NB_LIGNES_JOUEURS 5
#define NB_COLONNES_JOUEURS 16

#define NB_LIGNES_HEROS 5
#define NB_COLONNES_HEROS 7

#define NB_LIGNES_UNITES 12
#define NB_COLONNES_UNITES 8

#define NB_LIGNES_HEROSJOUEURS 25
#define NB_COLONNES_HEROSJOUEURS 11

#define NB_LIGNES_UNITESJOUEURS 60
#define NB_COLONNES_UNITESJOUEURS 11

#define NB_LIGNES_CARTE 10
#define NB_COLONNES_CARTE 10

#define NB_EMPLACEMENTS 6

typedef enum {NUM_JOUEUR_J, LIGNE_J, COLONNE_J, OR, BOIS, PIERRE, FER, SOUFFRE,
SULFURE, GEMME_ROUGE, GEMME_BLEU, GEMME_JAUNE, NB_UNITES_TUEES,
NB_BATAILLE_GAGNES, NB_UNITES_PERDUES, NB_BATAILLE_PERDUES} E_JOUEURS;

typedef enum {NUM_HERO_H,BONUS_ATTAQUE_H,BONUS_DEFENCE_H,CHANCE_CRITIQUE_H,
MORAL_H,POINTS_ATTAQUE_SPECIALE_H,PRIX_H} E_HEROES;

typedef enum {NUM_UNITE_U,TYPE_U,SANTE_U,ATTAQUE_U,DEFENCE_U,
DEGATS_U,MOUVEMENTs_U,PRIX_U}E_UNITES;

typedef enum {NUM_JOUEUR_HJ,NUM_HERO_HJ,HERO_PRINCIPAL,POINTS_EXPERIENCE,
NIVEAU_HJ,POINTS_COMPETENCE_HJ,BONUS_ATTAQUE_HJ,BONUS_DEFENCE_HJ,
CHANCE_CRITIQUE_HJ,MORAL_HJ,POINTS_ATTAQUE_SPECIALE_HJ} E_HEROSJOUEURS;

typedef enum {NUM_JOUEUR_UJ,NUM_UNITE_UJ,TYPE_UJ,SANTE_UJ,ATTAQUE_UJ,
DEFENCE_UJ,DEGATS_UJ,MOUVEMENTS_UJ,NOMBRE_UJ,NIVEAU_UJ,UNITE_ACTIVE}E_UNITESJOUEURS;

void chargerFichierVersTableau (int nb_lignes, int nb_colonnes, int tab[nb_lignes][nb_colonnes], char*nomFichier)
{ int i,j;
  FILE *F=fopen(nomFichier,"r+");
    if(F==NULL)
          exit(1);
    else{
               for( i=0; i<nb_lignes;i++)
               {
                     for( j=0; j<nb_colonnes;j++)
                         {
                             fscanf(F,"%d",&tab[i][j]);


                         }

               }

    }
    fclose(F);
}

void sauvegarderTableauDansFichier (int nb_lignes, int nb_colonnes, int tab[nb_lignes][nb_colonnes],char* nomFichier)
{
  int i,j;
  FILE *F=fopen(nomFichier,"w+");
    if(F==NULL)
    {
         exit(1);
    }

    else{
            for( i=0; i<=nb_lignes;i++)
               {
                     for( j=0; j<nb_colonnes;j++)
                         {

                            fprintf(F,"%d ",tab[i][j]);


                         }
                         fprintf(F,"\n");

               }

    }
    fclose(F);
}

void afficherTableau (int nb_lignes, int nb_colonnes, int tab[nb_lignes][nb_colonnes], char*nomFichierEntete)
{ FILE *F=fopen(nomFichierEntete,"r+");
   char ch[255];
   int i,j,z,d,y=0;
   int x=0;
   int espaces,width,info,total;
  x=150/nb_colonnes;
           if (x> 9)
             {
               info =7;
               espaces=(x-info-1)/2;
               width =espaces+info+espaces;
               total=((x-1)*nb_colonnes);
               for (d=0;d<=total;d++)
                               {
                                   printf("-");

                               }
                               printf("\n");
               while( fgets(ch,255,F)!=NULL)

               {
                   printf("%s\n",ch);
               }


                       for( i=0; i<nb_lignes;i++)

                    {     for (d=0;d<=total;d++)
                               {
                                   printf("-");

                               }

                               printf("\n");


                         for( j=0; j<nb_colonnes;j++)
                            { printf("|");
                                for (z=0;z<espaces;z++)
                                      {
                                       printf(" ");

                                      }

                                    printf("%*d",info,tab[i][j]);

                                        for (z=0;z<espaces;z++)
                                       {
                                           printf(" ");

                                       }

                            }
                     printf("|");
                       printf("\n");


                   }

                    for (d=1;d<=total;d++)
                               {
                                   printf("-");

                               }

           }

            if(x<=9)
           {
               info=x-1;
           espaces=0;
           width=info;
               total=(x*nb_colonnes);
               for (d=0;d<=total;d++)
                               {
                                   printf("-");

                               }
                               printf("\n");
           while( fgets(ch,255,F)!=NULL)

               {
                   printf("%s\n",ch);
               }

                   for( i=0; i<nb_lignes;i++)
                    {   for (d=1;d<=total;d++)
                               {
                                   printf("-");

                               }

                               printf("\n");

                         for( j=0; j<nb_colonnes;j++)
                                {
                                    for (z=1;z<=espaces;z++)
                                      {
                                       printf(" ");

                                        }


                                    printf("|%*d",info,tab[i][j]);
                                        for (z=1;z<=espaces;z++)
                                       {
                                           printf(" ");

                                       }

                                }
                   printf("|");
                   printf("\n");
   }
   for (d=1;d<=total;d++)
                               {
                                   printf("-");

                               }

  }

}

void afficherTableauUneCondition (int colonne, int valeur, int nb_lignes, int nb_colonnes, int
tab[nb_lignes][nb_colonnes], char* nomFichierEntete)
{

       FILE *F=fopen(nomFichierEntete,"r+");
   char ch[255];
   int i,j,z,d,y=0;
 int x=150/nb_colonnes;
   int espaces,width,info,total;

   if(x>9)
           {
               info =7;
               espaces=(x-info-1)/2;
               width =espaces+info+espaces;
               total=((x-1)*nb_colonnes);
                     for (d=0;d<=total;d++)
                               {
                                   printf("-");

                               }
                               printf("\n");
           while( fgets(ch,255,F)!=NULL)

               {
                   printf("%s\n",ch);
               }

                     for( i=0; i<nb_lignes;i++)
                    {
                           if (tab[i][colonne]==valeur)
                           {
                                for (d=1;d<=total;d++)
                               {
                                   printf("-");

                               }

                               printf("\n");


                         for( j=0; j<nb_colonnes;j++)
                                {
printf("|");

                                  for (z=1;z<=espaces;z++)
                                      {
                                       printf(" ");

                                        }


                                    printf("%*d",info,tab[i][j]);
                                      for (z=1;z<=espaces;z++)
                                      {
                                       printf(" ");

                                        }

                              }
printf("|");
                   printf("\n");
                                }

   }


for (d=1;d<=total;d++)
                               {
                                   printf("-");

                               }

  }




   if(x<=9)
           {
               info=x-1;
           espaces=0;
           width=info;
               total=(x*nb_colonnes);
               for (d=0;d<=total;d++)
                               {
                                   printf("-");

                               }
                               printf("\n");
           while( fgets(ch,255,F)!=NULL)

               {
                   printf("%s\n",ch);
               }

                   for( i=0; i<nb_lignes;i++)
                    {
                           if (tab[i][colonne]==valeur)
                           {
                                for (d=1;d<=total;d++)
                               {
                                   printf("-");

                               }

                               printf("\n");


                         for( j=0; j<nb_colonnes;j++)
                                {



                                  for (z=1;z<=espaces;z++)
                                      {
                                       printf(" ");

                                        }


                                    printf("|%*d",info,tab[i][j]);

                              }
printf("|");
                   printf("\n");
                                }

   }
   for (d=1;d<=total;d++)
                               {
                                   printf("-");

                               }

  }

}

void afficherTableauDeuxConditions (int colonne1, int valeur1, int colonne2, int valeur2, int nb_lignes,
int nb_colonnes, int tab[nb_lignes][nb_colonnes], char* nomFichierEntete)
{
    FILE *F=fopen(nomFichierEntete,"r+");
   char ch[255];
   int i,j,z,d,y=0;
 int x=150/nb_colonnes;
   int espaces,width,info,total;

   if(x>9)
           {
               info =7;
               espaces=(x-info-1)/2;
               width =espaces+info+espaces;
               total=((x-1)*nb_colonnes);
                     for (d=0;d<=total;d++)
                               {
                                   printf("-");

                               }
                               printf("\n");
           while( fgets(ch,255,F)!=NULL)

               {
                   printf("%s\n",ch);
               }

                     for( i=0; i<nb_lignes;i++)
                    {
                           if (tab[i][colonne1]==valeur1&&tab[i][colonne2]==valeur2)
                           {
                                for (d=1;d<=total;d++)
                               {
                                   printf("-");

                               }

                               printf("\n");


                         for( j=0; j<nb_colonnes;j++)
                                {
printf("|");

                                  for (z=1;z<=espaces;z++)
                                      {
                                       printf(" ");

                                        }


                                    printf("%*d",info,tab[i][j]);
                                      for (z=1;z<=espaces;z++)
                                      {
                                       printf(" ");

                                        }

                              }
printf("|");
                   printf("\n");
                                }

   }


for (d=1;d<=total;d++)
                               {
                                   printf("-");

                               }

  }




   if(x<=9)
           {
               info=x-1;
           espaces=0;
           width=info;
               total=(x*nb_colonnes);
               for (d=0;d<=total;d++)
                               {
                                   printf("-");

                               }
                               printf("\n");
           while( fgets(ch,255,F)!=NULL)

               {
                   printf("%s\n",ch);
               }

                   for( i=0; i<nb_lignes;i++)
                    {
                           if (tab[i][colonne1]==valeur1&&tab[i][colonne2]==valeur2)
                           {
                                for (d=1;d<=total;d++)
                               {
                                   printf("-");

                               }

                               printf("\n");


                         for( j=0; j<nb_colonnes;j++)
                                {



                                  for (z=1;z<=espaces;z++)
                                      {
                                       printf(" ");

                                        }


                                    printf("|%*d",info,tab[i][j]);

                              }
printf("|");
                   printf("\n");
                                }

   }
   for (d=1;d<=total;d++)
                               {
                                   printf("-");

                               }

  }
}


/* module d'affichage du tableau carte */


void afficherCarte (int carte[NB_LIGNES_CARTE][NB_COLONNES_CARTE] )
{
    int i,j,z;
     for (i=0;i<NB_LIGNES_CARTE;i++)
     {printf("---------------------------------------------------\n");

         for (j=0;j<NB_COLONNES_CARTE;j++)

          {
              if (carte[i][j]%10==1)
            printf("| ?? ");

 if (carte[i][j]==2)
                    printf("| J  ");

    if (carte[i][j]==0)
            printf("|    ");

        else if(carte[i][j]%10==0)
        {
            if (carte[i][j]/10 %10==1 )
                    printf("| E%d ",carte[i][j]/100);

               if (carte[i][j]/10 %10==2)
                    printf("| T  ");

                if (carte[i][j]/10 %10==3)
                    printf("| X  ");

        }

 else if(carte[i][j]%10==2)
        {
            if (carte[i][j]/10 %10==1 )
                    printf("| JE%d",carte[i][j]/100);

               if (carte[i][j]/10 %10==2)
                    printf("| JT ");

                if (carte[i][j]/10 %10==3)
                    printf("| JX ");

        }
            }

         printf("|");
         printf("\n");
     }
     printf("---------------------------------------------------\n");
}


/* module de chargement de tous les tableaux du jeu */

// Dépôt 3 à 2021-10-28T16:36:57.694
void chargerJeuComplet (
int carte[NB_LIGNES_CARTE][NB_COLONNES_CARTE],
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int heros[NB_LIGNES_HEROS][NB_COLONNES_HEROS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS],
int unites[NB_LIGNES_UNITES][NB_COLONNES_UNITES],
int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS] )
{
chargerFichierVersTableau (NB_LIGNES_CARTE, NB_COLONNES_CARTE,carte,"carte_sauvegarde.txt");

chargerFichierVersTableau (NB_LIGNES_JOUEURS, NB_COLONNES_JOUEURS,joueurs,"joueurs_sauvegarde.txt");

chargerFichierVersTableau (NB_LIGNES_HEROS, NB_COLONNES_HEROS,heros,"heros_sauvegarde.txt");

chargerFichierVersTableau (NB_LIGNES_HEROSJOUEURS, NB_COLONNES_HEROSJOUEURS,herosJoueurs,"herosJoueurs_sauvegarde.txt");

 chargerFichierVersTableau (NB_LIGNES_UNITES, NB_COLONNES_UNITES,unites,"unites_sauvegarde.txt");

 chargerFichierVersTableau (NB_LIGNES_UNITESJOUEURS, NB_COLONNES_UNITESJOUEURS,unitesJoueurs,"unitesJoueurs_sauvegarde.txt");


 }


/* module de sauvegarde de tous les tableaux du jeu */

// Dépôt 3 à 2021-10-28T16:36:57.694
void sauvegarderJeuComplet (
int carte[NB_LIGNES_CARTE][NB_COLONNES_CARTE],
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int heros[NB_LIGNES_HEROS][NB_COLONNES_HEROS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS],
int unites[NB_LIGNES_UNITES][NB_COLONNES_UNITES],
int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS] )
{
sauvegarderTableauDansFichier (NB_LIGNES_CARTE, NB_COLONNES_CARTE,carte,"carte_sauvegarde.txt");

sauvegarderTableauDansFichier (NB_LIGNES_JOUEURS, NB_COLONNES_JOUEURS,joueurs,"joueurs_sauvegarde.txt");

sauvegarderTableauDansFichier (NB_LIGNES_HEROS, NB_COLONNES_HEROS,heros,"heros_sauvegarde.txt");

sauvegarderTableauDansFichier (NB_LIGNES_HEROSJOUEURS, NB_COLONNES_HEROSJOUEURS,herosJoueurs,"herosJoueurs_sauvegarde.txt");

 sauvegarderTableauDansFichier (NB_LIGNES_UNITES, NB_COLONNES_UNITES,unites,"unites_sauvegarde.txt");

sauvegarderTableauDansFichier (NB_LIGNES_UNITESJOUEURS, NB_COLONNES_UNITESJOUEURS,unitesJoueurs,"unitesJoueurs_sauvegarde.txt");

}


/* module d'affichage de tous les tableaux du jeu */

// Dépôt 3 à 2021-10-28T16:36:57.694
void afficherTableauxJeu(
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int heros[NB_LIGNES_HEROS][NB_COLONNES_HEROS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS],
int unites[NB_LIGNES_UNITES][NB_COLONNES_UNITES],
int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS] )
{  printf("    <<<<<< tableau Joueurs >>>>>>>   \n \n");
   afficherTableau (NB_LIGNES_JOUEURS, NB_COLONNES_JOUEURS,joueurs,"joueurs_entete.txt");
printf("\n \n");
 printf("    <<<<<< tableau Heros >>>>>>>   \n \n");

         afficherTableau (NB_LIGNES_HEROS, NB_COLONNES_HEROS,heros,"heros_entete.txt");

     printf("\n \n");
 printf("    <<<<<< tableau HerosJoueurs >>>>>>>   \n \n");
              afficherTableau (NB_LIGNES_HEROSJOUEURS, NB_COLONNES_HEROSJOUEURS,herosJoueurs,"herosJoueurs_entete.txt");

     printf("\n \n");
 printf("    <<<<<< tableau Unites >>>>>>>   \n \n");

                   afficherTableau (NB_LIGNES_UNITES, NB_COLONNES_UNITES,unites,"unites_entete.txt");

     printf("\n \n");
 printf("    <<<<<< tableau UnitesJoueurs >>>>>>>   \n \n");
                        afficherTableau (NB_LIGNES_UNITESJOUEURS, NB_COLONNES_UNITESJOUEURS,unitesJoueurs,"unitesJoueurs_entete.txt");

}


/* module d'initialisation d'un nouveau jeu */

// Dépôt 3 à 2021-10-28T16:36:57.694
void initialiserNouveauJeu (
int carte[NB_LIGNES_CARTE][NB_COLONNES_CARTE],
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int heros[NB_LIGNES_HEROS][NB_COLONNES_HEROS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS],
int unites[NB_LIGNES_UNITES][NB_COLONNES_UNITES],
int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS] )
{
chargerFichierVersTableau (NB_LIGNES_CARTE, NB_COLONNES_CARTE,carte,"carte_original.txt");

chargerFichierVersTableau (NB_LIGNES_JOUEURS, NB_COLONNES_JOUEURS,joueurs,"joueurs_original.txt");

chargerFichierVersTableau (NB_LIGNES_HEROS, NB_COLONNES_HEROS,heros,"heros_original.txt");

chargerFichierVersTableau (NB_LIGNES_HEROSJOUEURS, NB_COLONNES_HEROSJOUEURS,herosJoueurs,"herosJoueurs_original.txt");

chargerFichierVersTableau (NB_LIGNES_UNITES, NB_COLONNES_UNITES,unites,"unites_original.txt");

chargerFichierVersTableau (NB_LIGNES_UNITESJOUEURS, NB_COLONNES_UNITESJOUEURS,unitesJoueurs,"unitesJoueurs_original.txt");


}


/* module de recherche d'indice dans tableau avec une condition */

// Dépôt 16 à 2021-12-04T15:41:28.614
int chercherIndiceAvecUneCondition ( int colonneConcernee, int valeur, int nb_lignes, int
nb_colonnes, int tab[nb_lignes][nb_colonnes] )
{
 int i,j,indice;
 indice=-1;
 for(i=0; i<=nb_lignes ;i++)
 {
         if (tab[i][colonneConcernee]==valeur)
         {
           indice=i;
         }

 }

if(indice==-1)
    return -1;
 else
    return indice;
}


/* module de recherche d'indice dans tableau avec deux conditions */

// Dépôt 16 à 2021-12-04T15:41:28.614
int chercherIndiceAvecDeuxConditions ( int colonneConcernee1, int valeur1, int colonneConcernee2,
int valeur2, int nb_lignes, int nb_colonnes, int tab[nb_lignes][nb_colonnes] )
{
   int i,j,indice;
   indice=-1;
 for(i=0;i<=nb_lignes;i++)
 {
     for(j=0;j<=nb_colonnes;j++)
     {
         if (tab[i][colonneConcernee1]==valeur1&&tab[i][colonneConcernee2]==valeur2)
        {
           indice=i;

        }

    }

 }

 if(indice==-1)
    return -1;
 else
  return indice;
}


/* module d'affichage de contenu d'une case de la carte */

// Dépôt 10 à 2021-11-24T11:41:45.135
void afficherContenuCaseCarte ( int valeurCase,
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS] )
{
    if (valeurCase/10%10==0)
    {
       printf("                                           ---------------                   \n");
       printf("                                           |  case vide  |                   \n");
       printf("                                           ---------------                   \n");
    }


  else  if(valeurCase/10 %10==1)
    {
         int ennemi=valeurCase/100;
        afficherTableauDeuxConditions(NUM_JOUEUR_HJ,ennemi,HERO_PRINCIPAL,1,NB_LIGNES_HEROSJOUEURS,NB_COLONNES_HEROSJOUEURS,
                                      herosJoueurs,"herosJoueurs_entete.txt");

    }

     else  if(valeurCase/10 %10==2)
     {
        int pieces=(valeurCase/100);
        printf("                                           ----------------------------------------                   \n");
        printf("                                           |  caisse a  tresor : %d  pieces !   |  \n",    pieces       );
        printf("                                           ----------------------------------------                   \n");


     }

    else  if(valeurCase/10 %10==3)
     {
        int points=(valeurCase/100);
        printf("                                           ----------------------------------------                   \n");
        printf("                                           |  caisse d'experience : %d  points ! |  \n",    points     );
        printf("                                           ----------------------------------------                   \n");


     }

}


/* module de lancement du menu achat d'héros */

// Dépôt 16 à 2021-12-04T15:41:28.614
void lancerMenuAchatHeros ( int numJoueur,
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int heros[NB_LIGNES_HEROS][NB_COLONNES_HEROS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS] )
{int choix,numhero,achat,x;
      printf("                                               informations du Joueur humain                            \n ");
      afficherTableauUneCondition (NUM_JOUEUR_J, numJoueur,NB_LIGNES_JOUEURS,NB_COLONNES_JOUEURS,joueurs,"joueurs_entete.txt");
      printf(" \n \n");
            printf("                                               Liste des heroes disponibles pour achat                  \n ");
            afficherTableau(NB_LIGNES_HEROS,NB_COLONNES_HEROS,heros,"heros_entete.txt");
 printf(" \n \n");

      do
     {
     printf("                              ***********************************                  \n");
     printf("                              **          Menu achat heros     **                  \n");
     printf("                              ***********************************                  \n");
     printf("                              **    1-Acheter un nouveau hero  **                  \n");
     printf("                              **    0-Revenir au menu precedent**                  \n");
     printf("                              ***********************************                  \n");
     printf("                              Entrez votre choix(0-1):");
     scanf("%d",&choix);


        if (choix==1)
     {
         do
         {
                      printf("                              Entrez le numero du hero que vous voulez acheter :");
                      scanf("%d",&numhero);

              x=  chercherIndiceAvecUneCondition(NUM_HERO_H,numhero,NB_LIGNES_HEROS,NB_COLONNES_HEROS,heros);

         }while(x==-1);


             int y=chercherIndiceAvecDeuxConditions(NUM_JOUEUR_HJ,0,NUM_HERO_HJ,numhero,NB_LIGNES_HEROSJOUEURS,NB_COLONNES_HEROSJOUEURS, herosJoueurs);
x=  chercherIndiceAvecUneCondition(NUM_HERO_H,numhero,NB_LIGNES_HEROS,NB_COLONNES_HEROS,heros);

 if (heros[x][PRIX_H]>joueurs[numJoueur][OR])
        {
         printf("                              Achat annule ,le joueur ne dispose pas du solde suffisant pour acheter cet hero ! \n ");
        }
 else if(y!=-1)
  {
      printf("                                             hero deja ajoutee                                                           \n");
  }

     else
      {
        do
         {
                printf("                              confirmez l'achat ( non=0 , oui=1 ) :");
         scanf("%d",&achat);


         int z=chercherIndiceAvecUneCondition(NUM_JOUEUR_HJ,-1,NB_LIGNES_HEROSJOUEURS,NB_COLONNES_HEROSJOUEURS,herosJoueurs);


               herosJoueurs[z][NUM_JOUEUR_HJ]=numJoueur;
               herosJoueurs[z][NUM_HERO_HJ]=numhero;
               herosJoueurs[z][HERO_PRINCIPAL]=0;
               herosJoueurs[z][POINTS_EXPERIENCE]=0;
               herosJoueurs[z][NIVEAU_HJ]=0;
               herosJoueurs[z][POINTS_COMPETENCE_HJ] =0;
               herosJoueurs[z][BONUS_ATTAQUE_HJ]=heros[numhero][BONUS_ATTAQUE_H];
               herosJoueurs[z][BONUS_DEFENCE_HJ]=heros[numhero][BONUS_DEFENCE_H];
               herosJoueurs[z][CHANCE_CRITIQUE_HJ]=heros[numhero][CHANCE_CRITIQUE_H];
               herosJoueurs[z][MORAL_HJ]=heros[numhero][MORAL_H];
               herosJoueurs[z][POINTS_ATTAQUE_SPECIALE_HJ]=heros[numhero][POINTS_ATTAQUE_SPECIALE_H];
              joueurs[numJoueur][OR]=joueurs[numJoueur][OR]-heros[numhero][PRIX_H];


             printf("                                     Achat effectue avec succes !!                            \n \n ");
             printf("                                            heros de joueur humain                             \n ");

             afficherTableauDeuxConditions(NUM_JOUEUR_HJ, numJoueur,NUM_HERO_HJ,numhero,NB_LIGNES_HEROSJOUEURS,
                                                     NB_COLONNES_HEROSJOUEURS,herosJoueurs,"herosJoueurs_entete.txt");
                                                     printf("\n");




      } while(achat !=0 && achat !=1);
          }
      }

     }while(choix!=0);
}



/* module de lancement du menu achat d'unités */

// Dépôt 16 à 2021-12-04T15:41:28.614
void lancerMenuAchatUnites ( int numJoueur,
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int unites[NB_LIGNES_UNITES][NB_COLONNES_UNITES],
int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS] )
{
int choix,numunite,achat,nb_soldat,x,y;
      printf("                                               informations du Joueur humain                            \n ");
      afficherTableauUneCondition (NUM_JOUEUR_J, numJoueur,NB_LIGNES_JOUEURS,NB_COLONNES_JOUEURS,joueurs,"joueurs_entete.txt");
      printf(" \n \n");
            printf("                                               Liste des unites disponibles pour achat                  \n ");
            afficherTableau(NB_LIGNES_UNITES,NB_COLONNES_UNITES,unites,"unites_entete.txt");
 printf(" \n \n");
do
     {
     printf("                              ***********************************                  \n");
     printf("                              **          Menu achat unites    **                  \n");
     printf("                              ***********************************                  \n");
     printf("                              **1-Acheter des nouvelles unites **                  \n");
     printf("                              **0-Revenir au menu precedent    **                  \n");
     printf("                              ***********************************                  \n");
     printf("                              Entrez votre choix(0-1):");
     scanf("%d",&choix);

        if (choix==1)
     {
              do
             { printf("                              Entrez le numero du unite que vous voulez acheter :");
               scanf("%d",&numunite);
                x=  chercherIndiceAvecUneCondition(NUM_UNITE_U,numunite,NB_LIGNES_UNITES,NB_COLONNES_UNITES,unites);
             }while(x==-1);


             printf("                              Entrez le nombre  de soldats que vous voulez acheter de ce type d'unites :");
            scanf("%d",&nb_soldat);

        if(nb_soldat* unites[x][PRIX_U]>joueurs[numJoueur][OR])
        {
            printf("                             joueur n'a pas de solde suffisant pour acheter des autres unites !          \n");
        }
        else
        {
                    do
                 {
                         printf("                              confirmez l'achat ( non=0 , oui=1 ) :");
                          scanf("%d",&achat);
                    int z=chercherIndiceAvecDeuxConditions(NUM_JOUEUR_UJ,0,NUM_UNITE_UJ,numunite,NB_LIGNES_UNITESJOUEURS
                                                    ,NB_COLONNES_UNITESJOUEURS, unitesJoueurs);
                           if(unitesJoueurs[z][NUM_UNITE_UJ]==numunite && unitesJoueurs[z][NUM_JOUEUR_UJ]==numJoueur)
                           {
                              unitesJoueurs[z][NOMBRE_UJ] = unitesJoueurs[z][NOMBRE_UJ]+nb_soldat;
                              afficherTableauDeuxConditions(NUM_JOUEUR_UJ, numJoueur,NUM_UNITE_UJ,numunite,NB_LIGNES_UNITESJOUEURS,
                                                     NB_COLONNES_UNITESJOUEURS,unitesJoueurs,"unitesJoueurs_entete.txt");
                                                     printf("\n");
                           }
                    else
                    {

                       unitesJoueurs[y][NUM_JOUEUR_UJ]=numJoueur;
                      unitesJoueurs[y][NUM_UNITE_UJ]=numunite;
                      unitesJoueurs[y][TYPE_UJ]=unites[x][TYPE_U];
                      unitesJoueurs[y][SANTE_UJ]=unites[x][SANTE_U];
                      unitesJoueurs[y][ATTAQUE_UJ]=unites[x][ATTAQUE_U];
                      unitesJoueurs[y][DEFENCE_UJ]=unites[x][DEFENCE_U];
                      unitesJoueurs[y][DEGATS_UJ]=unites[x][DEGATS_U];
                      unitesJoueurs[y][MOUVEMENTS_UJ]=unites[x][MOUVEMENTs_U];
                      unitesJoueurs[y][NOMBRE_UJ]=nb_soldat;
                      unitesJoueurs[y][NIVEAU_UJ]=0;
                      unitesJoueurs[y][UNITE_ACTIVE]=0;
                      afficherTableauDeuxConditions(NUM_JOUEUR_UJ, numJoueur,NUM_UNITE_UJ,numunite,NB_LIGNES_UNITESJOUEURS,
                                                     NB_COLONNES_UNITESJOUEURS,unitesJoueurs,"unitesJoueurs_entete.txt");
                                                     printf("\n");
                                                     joueurs[numJoueur][OR]=joueurs[numJoueur][OR]-nb_soldat* unites[x][PRIX_U];


                      }

                  } while(achat !=0 && achat !=1);

        }

     }
  }while(choix!=0);

}


/* module de lancement du menu configuration d'héros */

// Dépôt 16 à 2021-12-04T15:41:28.614
void lancerMenuConfigurationHeros ( int numJoueur,
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS] )
{
int choix,numhero,achat,i,j;
      printf("                                               informations des heros de joueur humain                          \n ");
      afficherTableauUneCondition (NUM_JOUEUR_HJ, numJoueur,NB_LIGNES_HEROSJOUEURS,NB_COLONNES_HEROSJOUEURS,herosJoueurs,"herosJoueurs_entete.txt");
      printf(" \n \n");
      do
     {
     printf("                              *********************************************                  \n");
     printf("                              **          Menu configuration hero        **                  \n");
     printf("                              *********************************************                  \n");
     printf("                              **1-Mettre un nouveau hero comme principal **                  \n");
     printf("                              **0-Revenir au menu precedent              **                  \n");
     printf("                              *********************************************                  \n");
     printf("                              Entrez votre choix(0-1):");
     scanf("%d",&choix);
        if (choix==1)
        {
            printf("                              Entrez le numero de votre nouveau hero principal :");
            scanf("%d",&numhero);
          int x=chercherIndiceAvecDeuxConditions(NUM_JOUEUR_HJ,0,NUM_HERO_HJ,numhero,NB_LIGNES_HEROSJOUEURS,NB_COLONNES_HEROSJOUEURS,
                                                 herosJoueurs);
             if(x==-1)
              {
                   printf("                              vous n'averz pas d'un hero avec ce numero     \n");
               }
              else
              {    for(i=0;i<=NB_LIGNES_HEROSJOUEURS;i++)
                     {
                         for(j=0;j<=NB_COLONNES_HEROSJOUEURS;j++)
                         {
                             if(herosJoueurs[i][HERO_PRINCIPAL]==1)
                             {
                                 herosJoueurs[i][HERO_PRINCIPAL]=0;
                             }
                          }
                     }
                  herosJoueurs[x][HERO_PRINCIPAL]=1;
                  printf("                              hero %d est l'hero principal  \n",numhero);
                  printf("\n");
                   printf("                                               informations du Joueur humain                            \n ");
      afficherTableauUneCondition (NUM_JOUEUR_HJ, numJoueur,NB_LIGNES_HEROSJOUEURS,NB_COLONNES_HEROSJOUEURS,herosJoueurs,"herosJoueurs_entete.txt");
      printf("\n");
              }

        }
  }while(choix!=0);

}


/* module de lancement du menu configuration d'unités */

// Dépôt 16 à 2021-12-04T15:41:28.614
void lancerMenuConfigurationUnites ( int numJoueur,
int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS] )
{
    int choix,numuniteprincipal,numunitereserve,achat,i,j;
      printf("                                               informations des unites de joueur humain                             \n");
      afficherTableauUneCondition (NUM_JOUEUR_UJ, numJoueur,NB_LIGNES_UNITESJOUEURS,NB_COLONNES_UNITESJOUEURS,unitesJoueurs,"unitesJoueurs_entete.txt");
     // printf(" \n \n");
       do
     { printf("\n");
     printf("                              *********************************************                  \n");
     printf("                              **          Menu configuration unites      **                  \n");
     printf("                              *********************************************                  \n");
     printf("                              **   1-Mettre une unite comme principal    **                  \n");
     printf("                              **   2-Mettre une unite comme reserve      **                  \n");
     printf("                              **   0-Revenir au menu precedent           **                  \n");
     printf("                              *********************************************                  \n");
     printf("                              Entrez votre choix(0-2):");
     scanf("%d",&choix);
     if (choix==1)
        {
            printf("                              Entrez le numero de l'unite a rendre comme  principal :");
            scanf("%d",&numuniteprincipal);
            int x=chercherIndiceAvecDeuxConditions(NUM_JOUEUR_UJ,0,NUM_UNITE_UJ,numuniteprincipal,NB_LIGNES_UNITESJOUEURS,NB_COLONNES_UNITESJOUEURS,
                                                    unitesJoueurs);
                                                    int somme=0;
            if(x==-1)
              {
                   printf("                              vous n'averz pas d'unites avec ce numero     ");
               }
               else if(somme==NB_EMPLACEMENTS)
              { for(i=0;i<=NB_LIGNES_HEROSJOUEURS;i++)
                     {

                             if(unitesJoueurs[i][UNITE_ACTIVE]==1&& unitesJoueurs[i][NUM_JOUEUR_UJ]==numJoueur)
                             {
                                 somme=somme+unitesJoueurs[i][UNITE_ACTIVE];
                             }
                         }
                  printf("                                      toutes les emplacements sont occupees   ");
              }
               else
                {    printf("                                  unite %d devenue principale ",numuniteprincipal);
                printf("\n \n");
                 unitesJoueurs[x][UNITE_ACTIVE]=1;
                printf("                                               informations des unites de joueur humain                             \n");

                afficherTableauUneCondition (NUM_JOUEUR_UJ, numJoueur,NB_LIGNES_UNITESJOUEURS,NB_COLONNES_UNITESJOUEURS,unitesJoueurs,"unitesJoueurs_entete.txt");


               }


        }
     else if (choix==2)
        {
              printf("                              Entrez le numero de l'unite a rendre comme  reserve :");
            scanf("%d",&numunitereserve);
               int x=chercherIndiceAvecDeuxConditions(NUM_JOUEUR_UJ,0,NUM_UNITE_UJ,numunitereserve,NB_LIGNES_UNITESJOUEURS,NB_COLONNES_UNITESJOUEURS, unitesJoueurs);

             printf("                                  unite %d devenue reserve ",numunitereserve);
                printf("\n \n");
                 unitesJoueurs[x][UNITE_ACTIVE]=0;
                printf("                                               informations des unites de joueur humain                             \n");

                afficherTableauUneCondition (NUM_JOUEUR_UJ, numJoueur,NB_LIGNES_UNITESJOUEURS,NB_COLONNES_UNITESJOUEURS,unitesJoueurs,"unitesJoueurs_entete.txt");

        }

     }while(choix!=0);
}



/* module d'exécution d'une action du joueur sur le contenu d'une case */

// Dépôt 16 à 2021-12-04T15:41:28.614
void executerAction (
int carte[NB_LIGNES_CARTE][NB_COLONNES_CARTE],
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS],
int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS] )
{
    int i,j,choix;
                i=joueurs[0][LIGNE_J];
                j=joueurs[0][COLONNE_J];
int dizaines=carte[i][j]/10 %10;
       if(dizaines==1)
          {
               printf("                  confirmez vous l'entree en bataille avec l'ennemi %d ? ( non=0 ,oui=1 ) : ",carte[i][j]/100);
               scanf ("%d",&choix);

                if(choix==1)
                    {
                        printf("                     NON ENCORE PROGRAMMEE !   ");
                    }
          }
   else  if(dizaines==2)
          {
               printf("                  confirmez vous l'ajout de %d pieces d'or a votre fortune personnelle ? ( non=0 ,oui=1 ) : ",carte[i][j]/100);
               scanf ("%d",&choix);
                if(choix==1)
                    {     if(carte[i][j]/100==0)
                            printf("                     coffre de  tresor deja ouvert ");
                          else
                          {
                              joueurs[0][OR]=joueurs[0][OR]+carte[i][j]/100;
                        printf("                     un tresor de montant  %d  a ete decouvert et a ete ajoute a votre fortune  ! \n ",carte[i][j]/100);
                          carte[i][j]=carte[i][j]%100;

                          }

                    }
          }

         else  if(dizaines==3)
          {
               printf("                  confirmez vous l'ajout de %d points  ? ( non=0 ,oui=1 ) : \n",carte[i][j]/100);
               scanf ("%d",&choix);
                if(choix==1)
                    {  if(carte[i][j]/100==0)
                            printf("                      points deja ojoutees ");
                         else
                         {
                             int ligne=chercherIndiceAvecDeuxConditions(NUM_JOUEUR_HJ,0,HERO_PRINCIPAL,1,NB_LIGNES_HEROSJOUEURS,
                                NB_COLONNES_HEROSJOUEURS,herosJoueurs);
                        herosJoueurs[ligne][POINTS_EXPERIENCE]=herosJoueurs[ligne][POINTS_EXPERIENCE]+carte[i][j]/100;
                        printf("                      %d   points a ete  ajoutee a votre hero  ! \n ",carte[i][j]/100);
                          carte[i][j]=carte[i][j]%100;
                         }


                    }
          }

}



/* module de dégagement des nuages */

// Dépôt 16 à 2021-12-04T15:41:28.614
void degagerNuages ( int lig, int col, int carte[NB_LIGNES_CARTE][NB_COLONNES_CARTE] )
{int i,j,lig_min,lig_max,col_min,col_max;

lig_min=lig-2;
lig_max=lig+2;

col_min=col-2;
col_max=col+2;

if (lig_max>9)
  lig_max=9;

else if (col_max>9)
  col_max=9;

   else if(col_min<0)
        col_min=0;

else if(lig_min<0)
lig_min=0;

  for(i=lig_min;i<=lig_max;i++)
  {
          for(j=col_min;j<=col_max;j++)
          {     if(carte[i][j]%10!=2)
                {
                               carte[i][j]=carte[i][j]-carte[i][j]%10;

                }


         }
  }

}


/* module d'avancement du joueur */

// Dépôt 16 à 2021-12-04T15:41:28.614
void avancer ( char action,
int carte[NB_LIGNES_CARTE][NB_COLONNES_CARTE],
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS] )
{  int i,j,unites_anc,unites_nv;
   int value=0;
printf("\n");
                i=joueurs[0][LIGNE_J];
                j=joueurs[0][COLONNE_J];

    if (action=='d')
        {
         carte[i][j]=carte[i][j]-carte[i][j]%10;
             int nvligne=i;
              int nvcolonne=j+1;
                 joueurs[0][LIGNE_J]=nvligne;
               joueurs[0][COLONNE_J]=nvcolonne;
               carte[nvligne][nvcolonne]= (carte[nvligne][nvcolonne]-(carte[nvligne][nvcolonne]%10))+2;
               degagerNuages(nvligne,nvcolonne,carte);
        }
 if (action=='g')
        {
         carte[i][j]=carte[i][j]-carte[i][j]%10;
             int nvligne=i;
              int nvcolonne=j-1;
                 joueurs[0][LIGNE_J]=nvligne;
               joueurs[0][COLONNE_J]=nvcolonne;
                             carte[nvligne][nvcolonne]= (carte[nvligne][nvcolonne]-(carte[nvligne][nvcolonne]%10))+2;
               degagerNuages(nvligne,nvcolonne,carte);


        }

     if (action=='h')
        {  carte[i][j]=carte[i][j]-carte[i][j]%10;
             int nvligne=i-1;
              int nvcolonne=j;
                 joueurs[0][LIGNE_J]=nvligne;
               joueurs[0][COLONNE_J]=nvcolonne;

 carte[nvligne][nvcolonne]= (carte[nvligne][nvcolonne]-(carte[nvligne][nvcolonne]%10))+2;
               degagerNuages(nvligne,nvcolonne,carte);
        }
         if (action=='b')
        {
                 carte[i][j]=carte[i][j]-carte[i][j]%10;
             int nvligne=i+1;
              int nvcolonne=j;
                 joueurs[0][LIGNE_J]=nvligne;
               joueurs[0][COLONNE_J]=nvcolonne;

carte[nvligne][nvcolonne]= (carte[nvligne][nvcolonne]-(carte[nvligne][nvcolonne]%10))+2;
               degagerNuages(nvligne,nvcolonne,carte);

        }

}


/* module de déroulement du jeu */

// Dépôt 16 à 2021-12-04T15:41:28.614
void deroulerJeu (
int carte[NB_LIGNES_CARTE][NB_COLONNES_CARTE],
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int heroes[NB_LIGNES_HEROS][NB_COLONNES_HEROS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS],
int unites[NB_LIGNES_UNITES][NB_COLONNES_UNITES],
int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS] )
{char choix; int i,j;
do
{
  printf("                              <<<<<<    JOUEUR HUMAIN      >>>>>>                  \n");
  afficherTableauUneCondition (0, 0,NB_LIGNES_JOUEURS,NB_COLONNES_JOUEURS,joueurs,"joueurs_entete.txt");
  printf("\n \n \n");
  printf("                              <<<<<<    CARTE DE JEU       >>>>>>                  \n");
  afficherCarte(carte);
  printf("\n \n ");
  printf("                              <<<<<<    CONTENU DE LA CASE DU JOUEUR  >>>>>>       \n");
  printf("\n");
                i=joueurs[0][LIGNE_J];
                j=joueurs[0][COLONNE_J];
                   afficherContenuCaseCarte (carte[i][j] ,herosJoueurs );

  printf("\n");
  printf("        Cliquez sur (h=haut, b=bas, g=gauche, d=droite, a= action, 0=menu principal) : ");
  scanf("%s",&choix);
  if(choix=='a')
          {
              executerAction(carte,joueurs,herosJoueurs,unitesJoueurs);
          }

  else if(choix=='d'||choix=='h'||choix=='b'||choix=='g')
          {
            avancer(choix,carte,joueurs);
          }

printf("\n \n");

} while(choix!='0');

}


/* module de lancement du menu campement */

// Dépôt 16 à 2021-12-04T15:41:28.614
void lancerMenuCampement (
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS],
int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS] )
{
int choix;
int carte [NB_LIGNES_CARTE][NB_COLONNES_CARTE];
int  heroes[NB_LIGNES_HEROS][NB_COLONNES_HEROS];
int unites [NB_LIGNES_UNITES][NB_COLONNES_UNITES];
printf("\n \n");

      do
     {
     printf("                              ***********************************                  \n");
     printf("                              **          Menu campement       **                  \n");
     printf("                              ***********************************                  \n");
     printf("                              **    1-Configuration heros      **                  \n");
     printf("                              **    2- Configuration unites    **                  \n");
     printf("                              **    0-Revenir au menu precedent**                  \n");
     printf("                              ***********************************                  \n");
     printf("                              Entrez votre choix(0-2):");
     scanf("%d",&choix);
          printf("\n \n");

        if (choix==1)
     {
            lancerMenuConfigurationHeros(0,joueurs,herosJoueurs);
            printf("\n \n");


     }

      else if (choix==2)
     {
          lancerMenuConfigurationUnites(0,unitesJoueurs);
          printf("\n \n");
     }
     }while(choix!=0);

}


/* module de lancement du menu magasin */

// Dépôt 16 à 2021-12-04T15:41:28.614
void lancerMenuMagasin (
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int heroes[NB_LIGNES_HEROS][NB_COLONNES_HEROS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS],
int unites[NB_LIGNES_UNITES][NB_COLONNES_UNITES],
int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS] )
{int choix;
int carte [NB_LIGNES_CARTE][NB_COLONNES_CARTE];
printf("\n \n");
     do
     {
     printf("                              ***********************************                  \n");
     printf("                              **          Menu Magasin         **                  \n");
     printf("                              ***********************************                  \n");
     printf("                              **    1-Acheter des heros        **                  \n");
     printf("                              **    2-Acheter des unites       **                  \n");
     printf("                              **    0-Revenir au menu precedent**                  \n");
     printf("                              ***********************************                  \n");
     printf("                              Entrez votre choix(0-2):");
     scanf("%d",&choix);
     printf("\n \n");
     if (choix==1)
     {
         lancerMenuAchatHeros(0,joueurs,heroes,herosJoueurs);
         printf("\n \n");


     }

     else if (choix==2)
     {
        lancerMenuAchatUnites(0,joueurs,unites,unitesJoueurs);
           printf("\n \n");


     }

     }while(choix!=0);

}


/* module de lancement du menu principal */

// Dépôt 10 à 2021-11-24T11:41:45.135
void lancerMenuPrincipal (
int carte[NB_LIGNES_CARTE][NB_COLONNES_CARTE],
int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS],
int heroes[NB_LIGNES_HEROS][NB_COLONNES_HEROS],
int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS],
int unites[NB_LIGNES_UNITES][NB_COLONNES_UNITES],
int unitesJoueurs[NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS] )
{ int choix;
     do
     {
     printf("                              ***********************************                  \n");
     printf("                              **     Menu principal            **                  \n");
     printf("                              ***********************************                  \n");
     printf("                              **    1-Magasin                  **                  \n");
     printf("                              **    2-Campement                **                  \n");
     printf("                              **    3-Reprendre le jeu en cours**                  \n");
     printf("                              **    4-Nouvelle partie          **                  \n");
     printf("                              **    5-Quitter                  **                  \n");
     printf("                              ***********************************                  \n");
     printf("                              Entrez votre choix(1-5):");
     scanf("%d",&choix);
      printf("\n \n");

        if(choix==1)
   {
       lancerMenuMagasin(joueurs,heroes,herosJoueurs,unites,unitesJoueurs);
       sauvegarderJeuComplet(carte,joueurs,heroes,herosJoueurs,unites,unitesJoueurs);
                 printf("\n \n");

   }

 else if(choix==2)
   {
       lancerMenuCampement(joueurs,herosJoueurs,unitesJoueurs);
       sauvegarderJeuComplet(carte,joueurs,heroes,herosJoueurs,unites,unitesJoueurs);
                 printf("\n \n");

   }

  else if(choix==3)
   {
       deroulerJeu(carte,joueurs,heroes,herosJoueurs,unites,unitesJoueurs);
        printf("\n \n");

   }

else if(choix==4)
   {
     initialiserNouveauJeu(carte,joueurs,heroes,herosJoueurs,unites,unitesJoueurs);
     sauvegarderJeuComplet(carte,joueurs,heroes,herosJoueurs,unites,unitesJoueurs);
               printf("\n \n");
   }

     }while(choix!=5);

}


/* module main */

// Dépôt 16 à 2021-12-04T15:41:28.614
int main()
{
    int joueurs[NB_LIGNES_JOUEURS][NB_COLONNES_JOUEURS];
     int  heroes[NB_LIGNES_HEROS][NB_COLONNES_HEROS];
     int herosJoueurs[NB_LIGNES_HEROSJOUEURS][NB_COLONNES_HEROSJOUEURS];
     int unites [NB_LIGNES_UNITES][NB_COLONNES_UNITES];
     int unitesJoueurs [NB_LIGNES_UNITESJOUEURS][NB_COLONNES_UNITESJOUEURS];
     int carte [NB_LIGNES_CARTE][NB_COLONNES_CARTE];
     int choix;

     printf("                              ***********************************                  \n");
     printf("                              **Heros magic war-caractere mode **                  \n");
     printf("                              ***********************************                  \n");
     printf("                              **    1-Nouvelle partie          **                  \n");
     printf("                              **    2-Changer  partie          **                  \n");
     printf("                              ***********************************                  \n");
  printf("                              Entrez votre choix(1-2):");
     scanf("%d",&choix);



     if (choix==1)
     {

         initialiserNouveauJeu(carte,joueurs,heroes,herosJoueurs,unites,unitesJoueurs);
          printf("\n \n");
          sauvegarderJeuComplet(carte,joueurs,heroes,herosJoueurs,unites,unitesJoueurs);
         printf("\n \n");
     }

    else if(choix==2)
     {
         chargerJeuComplet(carte,joueurs,heroes,herosJoueurs,unites,unitesJoueurs);
         afficherTableauxJeu(joueurs,heroes,herosJoueurs,unites,unitesJoueurs);
                   printf("\n \n");
     }

       printf("\n \n");
       lancerMenuPrincipal(carte,joueurs,heroes,herosJoueurs,unites,unitesJoueurs);

   return 0;
}
