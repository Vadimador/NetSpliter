#pragma once
#include "IP.hpp"

 class Commande
{
public :
	 /// ip : l'adresse du réseau
	 /// argc : le nombre d'arguments
	 /// argv : les arguments
	 ////
	virtual void execute(IP* ip, int argc, char** argv) = 0;
};

