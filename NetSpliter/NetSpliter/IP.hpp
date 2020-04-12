#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include "Octet.hpp"

class IP
{
private:
	static const int NB_OCTET_IPVP4 = 4;
	static const int NB_BYTE_UN_CHIFFRE = 8;

	Octet adresse_ip[NB_OCTET_IPVP4];
	
public:
	//--Getteur

	//--Setteur

	//--Methode
	IP(int adresse_ip[NB_OCTET_IPVP4]);

	static IP* isAdresse(std::string adresse);

	std::string getOctet(int pos);
	
	std::string toString();

	//~IP();

};

