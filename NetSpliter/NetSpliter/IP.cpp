#include "IP.hpp"

using namespace std;
IP::IP(int adresse_ip[NB_OCTET_IPVP4])
{
	adresse_ip = adresse_ip;
}

IP* IP::isAdresse(string adresse)
{
	std::cout << " adresse recu :" << adresse << "\n";
	int stock[4];
	for (size_t i = 0; i < NB_OCTET_IPVP4; i++)
	{
		size_t coor = adresse.find('.');

		try
		{
			int verif = stoi(adresse.substr(0,coor));

			if (verif > 255) 
			{
				return nullptr;
			}
			
			stock[i] = verif; 
			adresse = adresse.substr(coor + 1);
		}
		catch (const std::exception&)
		{
			
		}
		
	}
	if (adresse.length() >= 1)
	{
		return nullptr;
	}

	IP* adresse_bonne = new IP(stock);

	return adresse_bonne;
}


int* IP::setMask()
{
	bool class_adresse_ip[3];

	for (size_t i = 0; i < sizeof class_adresse_ip; i++)
	{
		class_adresse_ip[i] = toBinaire(*adresse_ip)[0][i];
	}

	/*if (class_adresse_ip[0] == 0)
		return { 255,0,0,0 };
	else if (class_adresse_ip[0] == 0)
		return { 255,255,0,0 };
	else (class_adresse_ip[0] == 0)
		return { 255,255,255,0 };*/
	return nullptr;
}

bool** IP::toBinaire(int adresse[NB_OCTET_IPVP4])
{
	bool **adresse_ip_binaire = new bool*[NB_OCTET_IPVP4];
	for (size_t i = 0; i < NB_OCTET_IPVP4; ++i)
	{
		adresse_ip_binaire[i] = new bool[NB_BYTE_UN_CHIFFRE];
	}

	for (signed int i = 0; i < NB_OCTET_IPVP4; i++)
	{
		int nb_adresse_ip = adresse[i];

		for (size_t j = NB_BYTE_UN_CHIFFRE - 1; j >= 0; j--)
		{
			adresse_ip_binaire[i][j] = nb_adresse_ip % 2;
			nb_adresse_ip = nb_adresse_ip / 2;
		}
	}

	return adresse_ip_binaire;
}

int* IP::toDecimal(bool adresse[NB_OCTET_IPVP4][NB_BYTE_UN_CHIFFRE])
{
	int *adresse_ip_binaire = new int[NB_OCTET_IPVP4];
	
	for (size_t i = 0; i < NB_OCTET_IPVP4; i++)
	{
		for (size_t j = 0; j < NB_BYTE_UN_CHIFFRE; j++)
		{
			if (adresse[i][j]) {
				adresse_ip_binaire[i] += adresse[i][j] * pow(2, i);
			}
		}
	}

	return adresse_ip_binaire;
}

void IP::nbBitSousAdresse()
{
}

