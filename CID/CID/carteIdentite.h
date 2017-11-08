#pragma once

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class carteIdentite
{
	static int nbCartes;
	int		id;
	string	nom;
	string	prenom;
	int		age;
	string  adresse;
	int		cp;
	string	ville;

public:
	//Constructeur
	carteIdentite();

	//GET
	int		getStatic();
	int		getID();
	string	getNom();
	string	getPrenom();
	int		getAge();
	string  getAdresse();
	int		getCP();
	string  getVille();

	//SET
	void setStatic();
	void setID();
	void setNom(string name);
	void setPrenom(string fname);
	void setAge(int age);
	void setAdresse(string address);
	void setCP(int cp);
	void setVille(string city);

	//Créer, modifier et afficher
	void nouvelleCarte(string nom, string prenom, int age, string  adresse, int cp, string ville);
	void modifierCarte(string nom, string prenom, int age, string  adresse, int cp, string ville);
	void afficherCarte();
	void remiseAZero();

	//Destructeur
	~carteIdentite();
};

