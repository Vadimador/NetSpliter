#pragma once
#include "Commande.hpp"

class See : public Commande
{
private :
	bool isMasqueSousR�seau(IP& i);
public :
	/// ip : l'adresse du r�seau
	/// argc : le nombre d'arguments
	/// argv : les arguments
	////
	int execute(IP* ip, unsigned int argc, char** argv);

	/// Cette m�thode sert � d�crire le fonctionnement de la commande en question.
	////
	void help();
};

