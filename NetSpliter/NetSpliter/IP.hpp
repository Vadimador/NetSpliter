#pragma once
#include <iostream>
#include <string>
#include "Octet.hpp"

class IP
{
private:
	static const int NB_OCTET_IPVP4 = 4; 

	Octet adresse_ip[NB_OCTET_IPVP4];
	
public:
	//--Getteur

	/// revoie le byte précis 
	/// pos = 0 est le byte le plus à gauche 
	/// pos = 3 est le byte le plus à droite
	/////////////////////////
	Octet* getOctet(int pos);

	//--Setteur

	//--Methode


	IP(int adresse_ip[NB_OCTET_IPVP4]);

	/// verifie que le string "adresse" est bien une adresse IP en decimal
	/////////////////////////
	static IP* isAdresse(std::string adresse);
	
	/// revoie le nombre de bit utilisé pour identifier le réseau
	/////////////////////////
	int getBitReseau();

	/// revoie un bit précis
	/// pos = 0 est le bit le plus à droite
	/// pos = 31 est le bit plus à gauche
	/////////////////////////
	bool getBit(int pos);

	/// revoie une visualisation en string de l'adresse IP en decimal
	/////////////////////////
	std::string toString();

};

