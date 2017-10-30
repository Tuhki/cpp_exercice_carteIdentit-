// Programme principal

#include "menu.h"

int main()
//BUT : Gérer un tableau de cartes d'identité
//ENTREE : Choix et saisies de l'utilisateur
//SORTIE : Gestion des cartes d'identité
{
	//On crée le tableau contenant les cartes d'identité
	carteIdentite cidTab[TAILLE];
	int choix = 0;
	int placeTab = 0;

	//On demande à l'utilisateur de créer une première carte
	gestionCarte(1, placeTab, cidTab);
	placeTab++;

	//On le laisse manipuler le tableau de carte, jusqu'à ce qu'il choisisse de quitter
	do
	{

		choix = afficheMenu(cidTab);
		gestionMenu(choix, &placeTab, cidTab);

	} while (choix != 5);
	

    return 0;
}