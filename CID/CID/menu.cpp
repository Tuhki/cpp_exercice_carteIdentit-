#include "menu.h"

int afficheMenu(carteIdentite tab[TAILLE])
//BUT : Afficher le menu
//ENTREE : aucune
//SORTIE : Affichge du menu
{
	int choix = 0;

	cout << "\n ---- Menu ----" << endl;
	cout << "1: Creer une nouvelle carte d'identite" << endl;
	cout << "2: Afficher une carte d'identite" << endl;
	cout << "3: Modifier une carte d'identite" << endl;
	cout << "4: Supprimer une carte d'identite" << endl;
	cout << "5: Quitter" << endl;
	cout << "6: Afficher tout" << endl;
	cin >> choix;

	return choix;

}

int gestionMenu(int choix, int *place, carteIdentite tab[TAILLE])
//BUT : Gérer les choix de l'utilisateur
//ENTREE : Choix du menu
//SORTIE : Résultat de ce choix
{

	int choixCarte = 0;
	int i = 0;
	int pos = 0;
	pos = *place;

	switch (choix)
	{
		//CREATION
	case 1:
		if (pos < TAILLE)
		{
			gestionCarte(choix, pos, tab);
			*place += 1;
			return 0;
		}
		else
		{
			//Si le tableau est plein, on ne peut plus créer de carte
			messageInfo(choix);
		}

		return 0;

		//AFFICHAGE D'UNE CARTE
	case 2:
		messageInfo(choix);
		cin >> choixCarte;

		if (choixCarte > 0)
		{
			//On cherche la carte demandée
			for (i = 0; i < TAILLE; i++)
			{
				//Si on trouve la carte...
				if (tab[i].getID() == choixCarte)
				{
					//...on l'affiche
					tab[i].afficherCarte();

					return 0;
				}

			}
		}

		//Si on n'a pas trouvé la carte
		messageInfo(0);

		return 0;

		//MODIFICATION
	case 3:
		messageInfo(choix);
		cin >> choixCarte;

		if (choixCarte > 0)
		{
			//On cherche la carte demandée
			for (i = 0; i < TAILLE; i++)
			{
				//Quand on a trouvé la place de la carte
				if (tab[i].getID() == choixCarte)
				{
					//On la modifie
					gestionCarte(choix, i, tab);

					return 0;
				}

			}
		}

		//Si on n'a pas trouvé la carte
		messageInfo(0);

		return 0;

		//SUPPRESSION
	case 4:
		messageInfo(choix);
		cin >> choixCarte;

		if (choixCarte > 0)
		{
			//On cherche la carte demandée
			for (i = 0; i < TAILLE; i++)
			{
				//Quand on a trouvé la place de la carte
				if (tab[i].getID() == choixCarte)
				{
					//On la supprime
					suppressionCarte(i, tab);

					//On libère une place
					*place -= 1;

					return 0;
				}

			}
		}

		//Si on n'a pas trouvé la carte
		messageInfo(0);

		return 0;

		//AFFICHAGE DU TABLEAU ENTIER
	case 6:

		for (i = 0; i < TAILLE; i++)
		{

			tab[i].afficherCarte();

		}

		return 0;

	default:
		return 0;

	}


}

void messageInfo(int nb)
//BUT : Afficher un message d'iformation
//ENTREE : Saisie utilisateur
//SORTIE : Info ou explication d'erreur
{
	if (nb == 0)
	{
		cout << "La carte demandee n'existe pas." << endl;
	}
	else if (nb == 1)
	{
		cout << "Vous ne pouvez pas ajouter de nouvelle carte." << endl;
	}
	else
	{
		cout << "Saisir l'ID de la carte à ";
		switch (nb)
		{
		case 2:
			cout << "afficher : " << endl;
			break;
		case 3:
			cout << "modifier : " << endl;
			break;
		case 4:
			cout << "supprimer : " << endl;
			break;
		default:
			break;
		}
	}
}

