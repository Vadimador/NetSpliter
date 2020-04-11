#pragma once
#include "Split.hpp"

class ListeCommandes
{
public:

	///renvoir  l'instanciation de la commande en question si elle existe, sinon renvoie nullptr
	///////
	static Commande* get(std::string nom);
};

