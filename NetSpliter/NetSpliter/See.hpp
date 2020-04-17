#pragma once
#include "Commande.hpp"

/// Cette commande sert � inspecter un sous-r�seau ou une machine
///////////////////////////
class See : public Commande
{
private :

	int nbBitMasqueSousR�seau = 8; // repr�sente le nombre de bit de la parti r�seau de l'adresse IP si elle est valide 
	int nbBitsReseau = 8; // repr�sente le nombre de bit du masque r�seau (et pas sous r�seau !)

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

