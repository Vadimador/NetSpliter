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

	IP mask_no_modifier = *mask;

	int nb_bit_sous_mask = 0;
	int nb_sous_reseau_max;
	for (size_t i = 1; i < 25; i++)
	{
		nb_sous_reseau_max = (int)pow(2, i);
		if (nb_sous_reseau <= nb_sous_reseau_max)
		{
			nb_bit_sous_mask = i;
			break;
		}
	}

	int nb_bit_reseau = mask->getBitReseau();

	if (32 - nb_bit_reseau >= nb_bit_sous_mask)
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
		std::cout << "nouveau masque: " << mask->toString() << '/' << nb_bit_reseau + nb_bit_sous_mask <<  "\n";

		delete mask;

		int nb_byte_sous_reseau = (nb_bit_sous_mask / 8);
		int nb_bit_restant = (nb_bit_sous_mask % 8);

		int last_pos_byte_sous_reseau = ((nb_bit_reseau + nb_bit_sous_mask) / 8);

		if (nb_byte_sous_reseau > 0 && nb_bit_restant == 0)
		{
			nb_bit_restant = 8;

			last_pos_byte_sous_reseau--;
		}

		

		IP* sous_reseau = IP::isAdresse("0.0.0.0");
		for (size_t j = 0; j < 4; j++)
		{
			if (mask_no_modifier.getOctet(j)->toString().compare("11111111") == 0) 
			{
				sous_reseau->getOctet(j)->setOctet(ip->getOctet(j)->toInt());
			}
		}

		int nb_bit_machine = 32 - nb_bit_reseau - nb_bit_sous_mask;

		int nb_bit_machine_last_byte_sous_reseau = nb_bit_machine % 8;

		Octet *bit_restant = new Octet(0);

		std::string byte_restant_plein = "";

		for (size_t i = 0; i < 8; i++)
		{
			if (8 - nb_bit_restant - 1 == i)
			{
				byte_restant_plein += "1";
			}
			else
			{
				byte_restant_plein += "0";
			}
		}


		for (size_t i = 0; i < nb_sous_reseau_max; i++)
		{
			std::cout << sous_reseau->toString() << "  :  ";

			for (size_t i = 0; i < nb_bit_machine; i++)
			{
				int pos_byte = i / 8;
				int bit_restant = i % 8;
				sous_reseau->getOctet(3 - pos_byte)->setBit(bit_restant,1);
			}

			std::cout<< sous_reseau->toString() << "\n";

			for (size_t i = 0; i < nb_bit_machine; i++)
			{
				int pos_byte = i / 8;
				int bit_restant = i % 8;
				sous_reseau->getOctet(3 - pos_byte)->setBit(bit_restant, 0);
			}

			bit_restant->setOctet(bit_restant->toInt() + 1);

			if (bit_restant->toString().compare(byte_restant_plein) == 0)
			{
				int a = sous_reseau->getOctet(last_pos_byte_sous_reseau - 1)->toInt() + 1;
				sous_reseau->getOctet(last_pos_byte_sous_reseau - 1)->setOctet(a);

				if (a == 256)
				{
					a = 0;
					sous_reseau->getOctet(last_pos_byte_sous_reseau - 1)->setOctet(0);

					sous_reseau->getOctet(last_pos_byte_sous_reseau - 2)->setOctet(sous_reseau->getOctet(last_pos_byte_sous_reseau - 2)->toInt() + 1);
				}

				bit_restant->setOctet(0);

				for (size_t i = 0; i < nb_bit_restant; i++)
				{
					sous_reseau->getOctet(last_pos_byte_sous_reseau)->setBit(nb_bit_machine_last_byte_sous_reseau + i, 0);
				}
	
			}

			for (size_t i = 0; i < nb_bit_restant; i++)
			{
				sous_reseau->getOctet(last_pos_byte_sous_reseau)->setBit(nb_bit_machine_last_byte_sous_reseau + i, bit_restant->getBit(i));
			}

		}

		delete bit_restant;

		delete sous_reseau;

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
