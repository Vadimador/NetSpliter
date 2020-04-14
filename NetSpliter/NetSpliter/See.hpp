#pragma once
#include "Commande.hpp"

/// Cette commande sert à inspecter un sous-réseau ou une machine
///////////////////////////
class See : public Commande
{
private :

	int nbBitMasqueSousRéseau = 8; // représente le nombre de bit de la parti réseau de l'adresse IP si elle est valide 
	int nbBitsReseau = 8; // représente le nombre de bit du masque réseau (et pas sous réseau !)

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

