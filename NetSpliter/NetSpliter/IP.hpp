#pragma once
#include <iostream>

class IP
{
private:
	int adresse_ip[4] = { 10, 10, 10, 10 };
	int mask[4];
	
public:
	//--Getteur

	//--Setteur
	int* setMask();

	//--Methode
	IP(int adresse_ip[4]);

	IP* isAdresse(std::string adresse);

	bool** adresse_ip_binaire();
	
	void nbBitSousAdresse();
};

