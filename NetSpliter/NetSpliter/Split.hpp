#pragma once
#include "Commande.hpp"

class Split : public Commande
{
	 void execute(IP ip, int nbSousReseau); // la fonction virtuelle
};

