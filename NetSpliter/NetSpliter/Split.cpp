#include "Split.hpp"


int Split::execute(IP* ip,unsigned int argc, char** argv)
{
	for (size_t i = 0; i < argc; i++)
	{
		std::cout << argv[i] << "\n";
	}

	std::string premier_octet = ip->getOctet(0);

	/*int nb_bit = get_nb_bit_mask(); // = ip.nb_bit_machine_mask;
	int bit_sous_mask_utilise;
	for (size_t i = 1; i < nb_bit; i++)
	{
		if ((int)argv[1] >= (int)pow(2, i))
		{
			bit_sous_mask_utilise = i;
			break;
		}
	}*/

	return 0;

	//std::cout << "cette methode est cense etre implemente" << "\n";
}

int Split::get_nb_bit_mask(std::string premiere_nb_adresse)
{
	int nb_bit_mask = 0;

	int pos = premiere_nb_adresse.find('0');

	for (size_t i = 0; i < 4; i++)
	{
		if (pos == i)
		{
			nb_bit_mask += 8;

			return nb_bit_mask;
		}
		nb_bit_mask += 8;
	}
}

void Split::help()
{
	std::cout << "pas encore inistialise";
}
