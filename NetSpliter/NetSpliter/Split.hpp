#pragma once
#include "Commande.hpp"
#include <iostream>
#include <math.h>

#include "IP.hpp"

class Split : public Commande
{
private :

public :

	 //--Getteurs

	 //--Setteurs

	 //--Méthodes
	int execute(IP* ip, unsigned int argc, char** argv); // la fonction virtuelle
	void help(); // la fonction virtuelle help

	/// revoie le masque du reseau en fonction du 1er byte de l'adresse IP en binaire
	/////////////////////////
	IP* getMask(std::string premiere_nb_adresse); 
};

