#include "tableauCartes.h"


int gestionCarte(int action, int pos, carteIdentite tab[TAILLE])
//BUT : Cr�er une nouvelle carte d'identit�
//ENTREE : Donn�es saisies par l'utilisateur
//SORTIE : Carte ajout�e au tableau de cartes
{
	int		id = 0;
	string	nom;
	string	prenom;
	int		age = 0;
	string  adresse;
	int		cp = 0;
	string	ville;

	//On demande � l'utilisateur les infos de la carte
	cout << "Bonjour, veuillez entrer les informations de la carte d'identite." << endl;
	cout << "Nom : " << endl;
	cin >> nom;

	cout << "Prenom : " << endl;
	cin >> prenom;

	cout << "Age : " << endl;
	cin >> age;

	cout << "Adresse (sans espaces) : " << endl;
	cin >> adresse;

	cout << "Code postal : " << endl;
	cin >> cp;

	cout << "Ville : " << endl;
	cin >> ville;

	//Si l'utilisateur a demand� � cr�er une carte
	if (action == 1)
	{

		// On incr�mente le nombre de cartes pour cr�er un id unique
		tab[pos].setStatic();
		tab[pos].setID();

		//On enregistre les infos
		tab[pos].nouvelleCarte(nom, prenom, age, adresse, cp, ville);

	}
	//Si l'utilisateur a demand� une modification
	else if (action == 3)
	{

		//On modifie simplement la carte
		tab[pos].modifierCarte(nom, prenom, age, adresse, cp, ville);

	}


	return 0;

}

void suppressionCarte(int pos, carteIdentite tab[TAILLE])
//BUT : Supprimer une carte d'identit�
//ENTREE : Carte choisie par l'utilisateur
//SORTIE : Carte supprim�e du tableau de cartes
{

	int i = 0;

	//On supprime les valeurs contenu dans le tableau pour la carte demand�e
	tab[pos].remiseAZero();

	//Si la carte n'est pas la derni�re du tableau,
	if (pos < TAILLE)
	{

		//Et qu'il y a bien une carte enregistr�e apr�s elle
		if ((tab[pos + 1].getID()) != 0)
		{

			//On d�cale la position des cartes suivantes, pour �viter les "vides" au milieu du tableau et que toute nouvelle carte cr��e s'ajoute � la suite
			for (i = pos; i < (TAILLE - 1); i++)
			{
				tab[i] = tab[i + 1];
			}

			//On oublie pas de r�initialiser la valeur de la derni�re carte pour lib�rer la place
			tab[TAILLE - 1].remiseAZero();

		}

	}

	cout << "La carte a bien ete supprimee." << endl;
	//Note : les ID �tant uniques, les ID de cartes supprim�es ne sont pas r�attribu�s

}

