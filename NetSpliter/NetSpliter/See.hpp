#pragma once
#include "Commande.hpp"

class See : public Commande
{
private :
	bool isMasqueSousRéseau(IP& i);
public :
	/// ip : l'adresse du réseau
	/// argc : le nombre d'arguments
	/// argv : les arguments
	////
	int execute(IP* ip, unsigned int argc, char** argv);

	/// Cette méthode sert à décrire le fonctionnement de la commande en question.
	////
	void help();
};

