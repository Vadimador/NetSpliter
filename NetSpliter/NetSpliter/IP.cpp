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

std::string IP::getOctet(int pos)
{
	return adresse_ip[pos].toString();
}


std::string IP::toString()
{
	string res = "";

	for (size_t i = 0; i < NB_OCTET_IPVP4; i++)
	{
		res += adresse_ip[i].toInt();
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

