#include "IP.hpp"
#include "Octet.hpp"

using namespace std;
IP::IP(int tab[NB_OCTET_IPVP4])
{
	for (size_t i = 0; i < NB_OCTET_IPVP4; i++)
	{
		this->adresse_ip[i].setOctet(tab[i]);
	}
}

IP* IP::isAdresse(string adresse)
{
	int stock[4];
	for (size_t i = 0; i < NB_OCTET_IPVP4; i++)
	{
		size_t coor = adresse.find('.');

		 if (((i >= 3) && !(coor > 12 || coor < 0)) || (!(i >= 3) && (coor > 12 || coor < 0)))
		{
			return nullptr;
		}

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
			return nullptr;
		}
		
	}
	
	IP* adresse_bonne = new IP(stock);

	return adresse_bonne;
}

int IP::getBitReseau()
{
	int nb_bit = 0;
	for (size_t i = 0; i < NB_OCTET_IPVP4; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			if (adresse_ip[i].toString()[j] == '1')
			{
				nb_bit++;
			}
			else
			{
				break;
			}
		}
	}
	return nb_bit;
}

Octet* IP::getOctet(int pos)
{
	return &adresse_ip[pos];
}

bool IP::getBit(int pos)
{
	int pos_byte = pos / 8;
	int bit_restant = pos % 8;
	return adresse_ip[3-pos_byte].getBit(bit_restant);
}


std::string IP::toString()
{
	string res = "";

	for (size_t i = 0; i < NB_OCTET_IPVP4; i++)
	{
		res += std::to_string(adresse_ip[i].toInt());
		if (i < 3)
		{
			res += '.';
		}
	}

	return res;
}

/*
IP::~IP()
{

	for (size_t i = 0; i < NB_OCTET_IPVP4; i++)
	{
		delete[] this->mask[i];
	}
	delete[] this->mask;
}
*/

