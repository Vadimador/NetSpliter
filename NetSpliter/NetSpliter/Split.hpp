#pragma once
#include "Commande.hpp"

class Split : public Commande
{
private :

public :

	 //--Getteurs

	 //--Setteurs

	 //--M�thodes
	void execute(IP* ip, unsigned int argc, char** argv); // la fonction virtuelle
	void help(); // la fonction virtuelle help

};

