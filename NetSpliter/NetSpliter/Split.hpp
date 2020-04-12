#pragma once
#include "Commande.hpp"
#include <iostream>
#include <math.h>

class Split : public Commande
{
private :

public :

	 //--Getteurs

	 //--Setteurs

	 //--Méthodes
	int execute(IP* ip, unsigned int argc, char** argv); // la fonction virtuelle
	void help(); // la fonction virtuelle help
	int get_nb_bit_mask(std::string premiere_nb_adresse);
};

