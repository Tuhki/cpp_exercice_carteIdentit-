// Programme principal

#include "menu.h"

int main()
//BUT : G�rer un tableau de cartes d'identit�
//ENTREE : Choix et saisies de l'utilisateur
//SORTIE : Gestion des cartes d'identit�
{
	//On cr�e le tableau contenant les cartes d'identit�
	carteIdentite cidTab[TAILLE];
	int choix = 0;
	int placeTab = 0;

	//On demande � l'utilisateur de cr�er une premi�re carte
	gestionCarte(1, placeTab, cidTab);
	placeTab++;

	//On le laisse manipuler le tableau de carte, jusqu'� ce qu'il choisisse de quitter
	do
	{

		choix = afficheMenu(cidTab);
		gestionMenu(choix, &placeTab, cidTab);

	} while (choix != 5);
	

    return 0;
}