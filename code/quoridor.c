/*************************************************************/
/*************** Informations sur le programme ***************/
/*************************************************************/

// Ce programme a pour but de créer numériquement le jeu Quoridor.
// Ce programme utilise la librairie graphique et affiche différentes
// images.

// Projet réalisé par : Marais Bastien


/*************************************************************/
/***************** Directives préprocesseur ******************/
/*************************************************************/

#include <stdio.h>
#include "../lib/libgraphique.h"

// Boutons de "jeu" :
#define DEPLACEMENT clic.x<= && clic.x>= && clic.y<= && clic.y>=
#define HORIZONTALE clic.x<= && clic.x>= && clic.y<= && clic.y>= 
#define VERTICALE clic.x<= && clic.x>= && clic.y<= && clic.y>= 
 

/*************************************************************/
/************** Structure et variables globales **************/
/*************************************************************/

typedef struct Joueur
{
	char nom[20];
	int nb_bar;
	int p_x;
	int p_y;
	int coul;
} Joueur;

/*************************************************************/
/****************** Prototypes de fonctions ******************/
/*************************************************************/

void menu(Joueur j1,Joueur j2);
void regles(Joueur j1,Joueur j2);
void options(Joueur j1,Joueur j2);
void jeu(Joueur j1,Joueur j2);
void fin(Joueur j1,Joueur j2,int victoire);
void quadrillage();
void aff_entier (int entier,int taille,Point coin,int couleur);
void initialisation_posi_joueur(Joueur j1,Joueur j2);
int verif_deplacement(Point choix);
int centre_case_x(Point choix);
int centre_case_y(Point choix);
int verif_bar_hori(Point Choix);
Point coin_barriere_hori(Point choix);
int verif_bar_hori(Point Choix);
Point coin_barriere_vert(Point choix);
void instruction(int valeur);

/*************************************************************/
/*********************** Fonction MAIN ***********************/
/*************************************************************/

int main()
{

	Joueur j1={"Joueur 1",10,375,370,rouge};
	Joueur j2={"Joueur 2",10,825,370,vert};
	ouvrir_fenetre(1200,800);
	menu(j1,j2);
	
	return 0;
}




/*************************************************************/
/********************* Autres fonctions **********************/
/*************************************************************/

// gère l'affichage et les intéractions du menu
void menu(Joueur j1, Joueur j2)
{

	// affichage du menu
	Point coin_ecran_haut_gauche={0,0};
	afficher_image("../images/interface_menu.bmp",coin_ecran_haut_gauche);
	actualiser();

	// intéractions sur celui-ci
	int choix_fait=0;
	Point clic;
	while (choix_fait==0)
	{
		clic=attendre_clic();

		// si on clique sur jouer
		if (clic.x<=395 && clic.x>=250 && clic.y<=423 && clic.y>=361)
		{
			choix_fait=1;
			dessiner_rectangle(coin_ecran_haut_gauche,1200,800,noir);
			jeu(j1,j2);
	    }
	    // si on clique sur options
		if (clic.x<=671 && clic.x>=527 && clic.y<=539 && clic.y>=477)
		{
			choix_fait=1;
			dessiner_rectangle(coin_ecran_haut_gauche,1200,800,noir);
			options(j1,j2);
	    }
	    // si on clique sur règles
		if (clic.x<=951 && clic.x>=805 && clic.y<=418 && clic.y>=354)
		{
			choix_fait=1;
			dessiner_rectangle(coin_ecran_haut_gauche,1200,800,noir);
			regles(j1,j2);
	    }
	    // si on clique sur quitter
		if (clic.x<=673 && clic.x>=527 && clic.y<=689 && clic.y>=627)
		{
			choix_fait=1;
			fermer_fenetre();
	    }
	}
}

// gère l'affichage et les intéractions de l'interface "regles"
void regles(Joueur j1,Joueur j2)
{
	// affichage de l'interface "règles"
	Point coin_ecran_haut_gauche={0,0};
	afficher_image("../images/interface_regles.bmp",coin_ecran_haut_gauche);
	actualiser();

	// intéractions sur celui-ci
	int choix_fait=0;
	Point clic;
	while (choix_fait==0)
	{
		clic=attendre_clic();

		// si on clique sur jouer
		if (clic.x<=619 && clic.x>=478 && clic.y<=677 && clic.y>=588)
		{
			choix_fait=1;
			dessiner_rectangle(coin_ecran_haut_gauche,1200,800,noir);
			jeu(j1,j2);
	    }
		// si on clique sur menu
		if (clic.x<=1075 && clic.x>=808 && clic.y<=667 && clic.y>=605)
		{
			choix_fait=1;
			dessiner_rectangle(coin_ecran_haut_gauche,1200,800,noir);
			menu(j1,j2);
	    }
	}
}


// gère l'affichage et les intéractions de l'interface "options"
void options(Joueur j1,Joueur j2)
{
	// affichage de l'interface "options"
	Point coin_ecran_haut_gauche={0,0};
	afficher_image("../images/interface_options.bmp",coin_ecran_haut_gauche);
	actualiser();

	// intéractions sur celui-ci
	int choix_fait=0;
	Point clic;
	while (choix_fait==0)
	{
		clic=attendre_clic();

		// si on clique sur menu
		if (clic.x<=734 && clic.x>=468 && clic.y<=731 && clic.y>=670)
		{
			choix_fait=1;
			dessiner_rectangle(coin_ecran_haut_gauche,1200,800,noir);
			menu(j1,j2);
	    }
	    // si on souhaite changer de couleur

	    // si on souhaite changer de nom
	}
}

// gère l'interface de jeu
void jeu(Joueur j1,Joueur j2)
{
	// affichage de l'interface "jeu"
	Point coin_ecran_haut_gauche={0,0};
	afficher_image("../images/interface_jeu.bmp",coin_ecran_haut_gauche);
	Point p1={40,295};
	afficher_texte(j1.nom,20,p1,blanc);
	p1.x=990;
	afficher_texte(j2.nom,20,p1,blanc);
	quadrillage();
	initialisation_posi_joueur(j1,j2);
	actualiser();


	// intéractions sur celui-ci
	
	Point clic;
	Point choix;
	Point pj1,pj2;
	int choix_fait=0;
	int victoire=0;
	int joueur=1;
	int boucle;
	
	
	while (choix_fait==0 && victoire==0)
	{
		clic = attendre_clic();

		// si on clique sur menu
		if (clic.x<=1144 && clic.x>=877 && clic.y<=762 && clic.y>=703)
		{
			choix_fait=1;
			dessiner_rectangle(coin_ecran_haut_gauche,1200,800,noir);
			menu(j1,j2);
	    }
/*
	    // jeu en lui même
	    if (joueur==1)
	    {
			// si on clique sur déplacement
			if (DEPLACEMENT)
			{
				instruction(1); // affiche un message lié aux déplacements
				boucle=0;
				do
				{
					choix = attendre_clic();
					if(verif_deplacement(choix))
					{
						j1.p_x= centre_case_x(choix);
						j1.p_y= centre_case_y(choix);
						pj1.x=j1.p_x;
						pj1.y=j1.p_y;
						dessiner_disque(pj1,20,j1.coul);
						boucle = 1;
						actualiser();
					}
						
				}while(boucle==0);
				joueur=2;
			}
			// si on clique sur barrière horizontale
			if (HORIZONTALE && j1.nb_bar>0)
			{
				instruction(2);	 // affiche un message lié aux barrières
				boucle = 0;
				do
				{
					choix = attendre_clic();
					if(verif_bar_hori(choix))
					{
						
						dessiner_rectangle(coin_barriere_hori(choix),100,20,j1.coul);
						boucle = 1;
						j1.nb_bar-=1;
						actualiser();
					}
						
				}while(boucle==0);
				joueur=2;
				
			}
			// si on clique sur barrière verticale 
			if (VERTICALE && j1.nb_bar>0)
			{
				instruction(2);	 // affiche un message lié aux barrières
				boucle = 0;
				do
				{
					choix = attendre_clic();
					if(verif_bar_vert(choix))
					{
						
						dessiner_rectangle(coin_barriere_vert(choix),100,20,j1.coul);
						boucle = 1;
						j1.nb_bar-=1;
						actualiser();
					}
						
				}while(boucle==0);
				joueur=2;
			}
		}
		else
		{
			// si on clique sur déplacement
			if (DEPLACEMENT)
			{
				instruction(1); // affiche un message lié aux déplacements
				boucle=0;
				do
				{
					choix = attendre_clic();
					if(verif_deplacement(choix))
					{
						j2.p_x= centre_case_x(choix);
						j2.p_y= centre_case_y(choix);
						pj2.x=j1.p_x;
						pj2.y=j1.p_y;
						dessiner_disque(pj2,20,j2.coul);
						boucle = 1;
						actualiser();
					}
						
				}while(boucle==0);
				joueur=1;
			}
			// si on clique sur barrière horizontale
			if (HORIZONTALE && j2.nb_bar>0)
			{
				instruction(2);	 // affiche un message lié aux barrières
				boucle = 0;
				do
				{
					choix = attendre_clic();
					if(verif_bar_hori(choix))
					{
						
						dessiner_rectangle(coin_barriere_hori(choix),100,20,j2.coul);
						boucle = 1;
						j2.nb_bar-=1;
						actualiser();
					}
						
				}while(boucle==0);
				joueur=1;
				
			}
			// si on clique sur barrière verticale 
			if (VERTICALE && j2.nb_bar>0)
			{
				instruction(2);	 // affiche un message lié aux barrières
				boucle = 0;
				do
				{
					choix = attendre_clic();
					if(verif_bar_vert(choix))
					{
						
						dessiner_rectangle(coin_barriere_vert(choix),100,20,j2.coul);
						boucle = 1;
						j2.nb_bar-=1;
						actualiser();
					}
						
				}while(boucle==0);
				joueur=1;
			}
		} */
	    
	}	   
	
}

// affiche et gère l'interface "fin"
void fin(Joueur j1,Joueur j2,int victoire)
{
	// affichage de l'interface "fin"
	Point coin_ecran_haut_gauche={0,0};
	afficher_image("../images/interface_fin.bmp",coin_ecran_haut_gauche);
	Point p1={300,115};

	if (victoire==1)
	{
		afficher_texte("Félicitation au Joueur 1 pour cette magnifique victoire !",40,p1,blanc);
	}
	else
	{
		afficher_texte("Félicitation au Joueur 2 pour cette magnifique victoire !",40,p1,blanc);
	}
	actualiser();

	// intéractions sur celui-ci
	int choix_fait=0;
	Point clic;
	while (choix_fait==0)
	{
		clic=attendre_clic();

		// si on clique sur jouer
		if (clic.x<=672 && clic.x>=527 && clic.y<=532 && clic.y>=471)
		{
			choix_fait=1;
			dessiner_rectangle(coin_ecran_haut_gauche,1200,800,noir);
			jeu(j1,j2);
	    }
		// si on clique sur menu
		if (clic.x<=734 && clic.x>=467 && clic.y<=431 && clic.y>=369)
		{
			choix_fait=1;
			dessiner_rectangle(coin_ecran_haut_gauche,1200,800,noir);
			menu(j1,j2);
	   	}
	} 
}




// affiche le quadrillage
void quadrillage()
{


	Point p1;
	
	// affiche les cases
	for (p1.x=350;p1.x<850;p1.x+=75)
	{
		for (p1.y=120;p1.y<620;p1.y+=75)
		{
			dessiner_rectangle(p1,50,50,noir);
		}
	}
	
	// affiche les emplacements des futurs barrières
	p1.y=120;
	for (p1.x=400;p1.x<800;p1.x+=75)
	{
		dessiner_rectangle(p1,25,500,gris);
	}

	p1.x=350;
	for (p1.y=170;p1.y<620;p1.y+=75)
	{
		dessiner_rectangle(p1,500,25,gris);
	}

	actualiser();
}


// affiche un entier a l'écran
void aff_entier (int entier,int taille,Point coin,int couleur)
{
	char texte[5];
	sprintf(texte,"%d",entier);
	afficher_texte(texte,taille,coin,couleur);
}


// place les pions a leur position initiale
void initialisation_posi_joueur(Joueur j1,Joueur j2)
{
	Point p1={375,370};
	Point p2={825,370};
	dessiner_disque(p1,20,j1.coul);
	dessiner_disque(p2,20,j2.coul);
	actualiser();
}


// affiche les instructions 
/* problème de paramètre pour les affiche_texte() suivant
void instruction(int valeur)
{
		if (valeur == 1)
			afficher_texte("Veuillez séléctionner une case adjacente");
		else 
			afficher_texte("Veuillez séléctionner un emplacement de barrière");
		actualiser();
}


// vérifie si le point donné est bien dans une case
int verif_deplacement(Point choix)
{ 
	
}

// vérifie si le point donné est bien dans une barrière horizontale
int verif_bar_hori(Point choix)
{
	
}

// vérifie si le point donné est bien dans une barrière verticale
int verif_bar_vert(Point choix)
{
	
}

// donne la valeur x du centre de la case séléctionnée
int centre_case_x(Point choix)
{
	
}

// donne la valeur y du centre de la case séléctionnée
int centre_case_y(Point choix)
{
	
}

// donne les coordonnées du coin gauche de la barrière horizontale
Point coin_barriere_hori(Point choix)
{
	
}

// donne les coordonnées du coin gauche de la barrière verticale
Point coin_barriere_vert(Point choix)
{
	
}

*/
