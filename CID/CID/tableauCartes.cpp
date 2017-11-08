#include "tableauCartes.h"


int gestionCarte(int action, int pos, carteIdentite tab[TAILLE])
//BUT : Créer une nouvelle carte d'identité
//ENTREE : Données saisies par l'utilisateur
//SORTIE : Carte ajoutée au tableau de cartes
{
	int		id = 0;
	string	nom;
	string	prenom;
	int		age = 0;
	string  adresse;
	int		cp = 0;
	string	ville;

	//On demande à l'utilisateur les infos de la carte
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

	//Si l'utilisateur a demandé à créer une carte
	if (action == 1)
	{

		// On incrémente le nombre de cartes pour créer un id unique
		tab[pos].setStatic();
		tab[pos].setID();

		//On enregistre les infos
		tab[pos].nouvelleCarte(nom, prenom, age, adresse, cp, ville);

	}
	//Si l'utilisateur a demandé une modification
	else if (action == 3)
	{

		//On modifie simplement la carte
		tab[pos].modifierCarte(nom, prenom, age, adresse, cp, ville);

	}


	return 0;

}

void suppressionCarte(int pos, carteIdentite tab[TAILLE])
//BUT : Supprimer une carte d'identité
//ENTREE : Carte choisie par l'utilisateur
//SORTIE : Carte supprimée du tableau de cartes
{

	int i = 0;

	//On supprime les valeurs contenu dans le tableau pour la carte demandée
	tab[pos].remiseAZero();

	//Si la carte n'est pas la dernière du tableau,
	if (pos < TAILLE)
	{

		//Et qu'il y a bien une carte enregistrée après elle
		if ((tab[pos + 1].getID()) != 0)
		{

			//On décale la position des cartes suivantes, pour éviter les "vides" au milieu du tableau et que toute nouvelle carte créée s'ajoute à la suite
			for (i = pos; i < (TAILLE - 1); i++)
			{
				tab[i] = tab[i + 1];
			}

			//On oublie pas de réinitialiser la valeur de la dernière carte pour libérer la place
			tab[TAILLE - 1].remiseAZero();

		}

	}

	cout << "La carte a bien ete supprimee." << endl;
	//Note : les ID étant uniques, les ID de cartes supprimées ne sont pas réattribués

}

