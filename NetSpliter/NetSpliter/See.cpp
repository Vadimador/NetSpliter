#include "See.hpp"

bool See::isMasqueSousR�seau(IP& ip)
{
	if (ip.getOctet(0)->toInt() != 255)
		return false;
	bool plusUn = false;
	for (int i = 23; i >= 0; i--)
	{
		if (ip.getBit(i) != 1) {
			plusUn = true;
		}
		else {
			if (plusUn) {
				return false;
			}
		}
	}

	return true;
}

int See::execute(IP* ip, unsigned int argc, char** argv)
{
	// <masque sous r�seau> <num�ro de r�seau>
	int erreur = 0;
	if (argc >= 2) {
		IP* masque_sous_reseau = IP::isAdresse(argv[0]);
		if (masque_sous_reseau != nullptr) {
			if (this->isMasqueSousR�seau(*masque_sous_reseau)) {
				// tout est bon
				try
				{
					int num�ro = std::stoi(argv[1]);

				}
				catch (const std::invalid_argument&)
				{
					std::cerr << "Le num\202ro de sous r\202seau est invalide" << "\n";
					erreur = -1;
				}
			}
			else
			{
				
			}
		}
		else {
			std::cerr << "Le masque sous r\202seau que vous avez donn\202 est incorrect" << "\n";
			erreur = -1;
		}
	}
	else
	{
		std::cerr << "Le nombre d'argument est insuffisant" << "\n";
		erreur = -1;
	}
	return erreur;
}

void See::help()
{
	std::cout << "Pas encore d'aide d�sol� va falloir se d�brouiller tout seul" << "\n";
}
