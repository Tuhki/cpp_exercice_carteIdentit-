#include "carteIdentite.h"

int carteIdentite::nbCartes = 0;

carteIdentite::carteIdentite()
{
	this->id = NULL;
	this->age = NULL;
	this->cp = NULL;
}

int carteIdentite::getStatic()
{
	return this->nbCartes;
}

int carteIdentite::getID()
{
	return this->id;
}

string carteIdentite::getNom()
{
	return string(this->nom);
}

string carteIdentite::getPrenom()
{
	return string(this->prenom);
}

int carteIdentite::getAge()
{
	return this->age;
}

string carteIdentite::getAdresse()
{
	return string(this->adresse);
}

int carteIdentite::getCP()
{
	return this->cp;
}

string carteIdentite::getVille()
{
	return string(this->ville);
}

void carteIdentite::setStatic()
{
	this->nbCartes++;
}

void carteIdentite::setID()
{
	this->id = this->nbCartes;
}

void carteIdentite::setNom(string name)
{
	this->nom = name;
}

void carteIdentite::setPrenom(string fname)
{
	this->prenom = fname;
}

void carteIdentite::setAge(int age)
{
	this->age = age;
}

void carteIdentite::setAdresse(string address)
{
	this->adresse = address;
}

void carteIdentite::setCP(int cp)
{
	this->cp = cp;
}

void carteIdentite::setVille(string city)
{
	this->ville = city;
}

void carteIdentite::nouvelleCarte(string nom, string prenom, int age, string adresse, int cp, string ville)
{
	this->id = this->nbCartes;
	this->modifierCarte(nom, prenom, age, adresse, cp, ville);
}

void carteIdentite::modifierCarte(string nom, string prenom, int age, string adresse, int cp, string ville)
{
	this->setNom(nom);
	this->setPrenom(prenom);
	this->setAge(age);
	this->setAdresse(adresse);
	this->setCP(cp);
	this->setVille(ville);
}

void carteIdentite::afficherCarte()
{
	cout << "ID : "			<< this->getID()		<< endl;
	cout << "Nom : "		<< this->getNom()		<< endl;
	cout << "Prenom : "		<< this->getPrenom()	<< endl;
	cout << "Age : "		<< this->getAge()		<< endl;
	cout << "Adresse : "	<< this->getAdresse()	<< endl;
	cout << "Code Postal : "<< this->getCP()		<< endl;
	cout << "Ville : "		<< this->getVille()		<< endl;
}

void carteIdentite::remiseAZero()
{
	this->id = NULL;
	this->setNom("");
	this->setPrenom("");
	this->setAge(NULL);
	this->setAdresse("");
	this->setCP(NULL);
	this->setVille("");
}


carteIdentite::~carteIdentite()
{
}
