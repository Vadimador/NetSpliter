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
	Octet* getOctet(int pos);

	//--Setteur

	//--Methode
	IP(int adresse_ip[NB_OCTET_IPVP4]);

	static IP* isAdresse(std::string adresse);
	
	int getBitReseau();

	bool getBit(int pos);

	std::string toString();

	//~IP();

};

