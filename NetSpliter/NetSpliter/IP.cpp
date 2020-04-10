#include "IP.hpp"

IP::IP(int adresse_ip[4])
{
	this.adresse_ip = adresse_ip;
}

IP* IP::isAdresse(string adresse)
{

}

int[] IP::setMask()
{
	bool class_adresse_ip[3];

	for (int i = 0; i < sizeof class_adresse_ip; i++)
	{
		class_adresse_ip[i] = adresse_ip_binaire()[0][i];
	}

	if (class_adresse_ip[0] == 0)
		return { 255,0,0,0 };
	else if (class_adresse_ip[0] == 0)
		return { 255,255,0,0 };
	else (class_adresse_ip[0] == 0)
		return { 255,255,255,0 };

}

bool[][] IP::adresse_ip_binaire()
{
	bool adresse_ip_binaire[4][8];

	for (signed int i = 0; i < 4; i++)
	{
		int nb_adresse_ip = adresse_ip[i];

		for (int j = 7; j >= 0; j--)
		{
			adresse_ip_binaire[i][j] = nb_adresse_ip % 2;
			nb_adresse_ip = nb_adresse_ip / 2;
		}
	}

	return adresse_ip_binaire;
}

void IP::nbBitSousAdresse()
{
}

int main()
{

}