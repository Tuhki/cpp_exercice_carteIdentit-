#pragma once

#include "tableauCartes.h"

int afficheMenu(carteIdentite tab[TAILLE]);
int gestionMenu(int choix, int &place, carteIdentite tab[TAILLE]);
void messageInfo(int nb);