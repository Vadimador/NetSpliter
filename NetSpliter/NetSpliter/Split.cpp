#include "Split.hpp"


int Split::execute(IP* ip,unsigned int argc, char** argv)
{
	for (size_t i = 0; i < argc; i++)
	{
		std::cout << argv[i] << "\n";
	}

	std::string premier_octet = ip->getOctet(0)->toString();

	int nb_sous_reseau = atoi(argv[0]);

	IP *mask = getMask(premier_octet);

	int nb_bit_sous_mask;
	for (size_t i = 1; i < 24; i++)
	{
		int res_pow = (int)pow(2, i);
		if (nb_sous_reseau <= res_pow)
		{
			nb_bit_sous_mask = i;
			break;
		}
	}

	int nb_bit_reseau = mask->getBitReseau();

	if (32 - nb_bit_reseau > nb_bit_sous_mask)
	{
		int octet_remplir = nb_bit_sous_mask;

		for (size_t i = 0; i <= 4; i++)
		{
			if (mask->getOctet(i)->toString().compare("11111111") != 0)
			{
				if (octet_remplir >= 8)
				{
					mask->getOctet(i)->setOctet(255);
					octet_remplir -= 8;
				}
				else if (0 < octet_remplir < 8)
				{
					std::string bit_restant = "";
					for (size_t i = 0; i < 8; i++)
					{
						if (octet_remplir > 0)
						{
							bit_restant += "1";
							octet_remplir--;
						}
						else
						{
							bit_restant += "0";
						}
					}
					mask->getOctet(i)->setOctetWithString(bit_restant);
					break;
				}
				else
				{
					break;
				}
			}
		}

		std::cout << "adresse IP: " << ip->toString() << "\n";
		std::cout << "nouveau masque: " << mask->toString() << "\n";


	}
	else
	{
		std::cout << "Cette adresse ip ne peut pas avoir le nombre de sous reseau voulu";
		return -1;
	}

	return 0;

	//std::cout << "cette methode est cense etre implemente" << "\n";
}

IP* Split::getMask(std::string premiere_nb_adresse)
{
	IP *mask = IP::isAdresse("0.0.0.0");
	int nb_bit_mask = 0;

	int pos = premiere_nb_adresse.find('0');

	for (size_t i = 0; i < 4; i++)
	{
		if (pos == i)
		{
			mask->getOctet(i)->setOctet(255);

			return mask;
		}
		else
		{
			mask->getOctet(i)->setOctet(255);
		}
	}
}

void Split::help()
{
	std::cout << "pas encore inistialise";
}
