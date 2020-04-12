#pragma once
#include "IP.hpp"

 class Commande
{
public :
	 /// ip : l'adresse du réseau
	 /// argc : le nombre d'arguments
	 /// argv : les arguments
	 ////
	virtual int execute(IP* ip, unsigned int argc, char** argv) = 0;

	/// Cette méthode sert à décrire le fonctionnement de la commande en question.
	////
	virtual void help() = 0;
};

