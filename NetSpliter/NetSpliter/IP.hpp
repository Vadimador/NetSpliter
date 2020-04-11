#pragma once
#include <iostream>
#include <string>
#include <math.h>

class IP
{
private:
	static const int NB_OCTET_IPVP4 = 4;
	static const int NB_BYTE_UN_CHIFFRE = 8;

	int* adresse_ip = new int[NB_OCTET_IPVP4];
	bool** mask = new bool*[NB_OCTET_IPVP4];
	
public:
	//--Getteur

	//--Setteur
	int* setMask();

	//--Methode
	IP(int *adresse_ip);

	static IP* isAdresse(std::string adresse);

	bool** toBinaire(int adresse[NB_OCTET_IPVP4]);

	int* toDecimal(bool adresse[NB_OCTET_IPVP4][NB_BYTE_UN_CHIFFRE]);
	
	void nbBitSousAdresse();

};

