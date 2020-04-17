#include "See.hpp"
#include <math.h>

bool See::isMasqueSousRéseau(IP& ip)
{
	if (ip.getOctet(0)->toInt() != 255)
		return false;
	bool plusUn = false;
	for (int i = 23; i >= 0; i--)
	{
		if (ip.getBit(i) != 1) {
			plusUn = true;
			//this->positionFinRéseau = (32 - i - 1);
		}
		else {
			this->nbBitMasqueSousRéseau++;
			if (plusUn) {
				return false;
			}
		}
	}

	return true;
}

int See::execute(IP* ip, unsigned int argc, char** argv)
{
	// <masque sous réseau> <numéro de réseau>
	int erreur = 0;
	if (argc >= 2) {
		IP* masque_sous_reseau = IP::isAdresse(argv[0]);
		if (masque_sous_reseau != nullptr) {
			if (this->isMasqueSousRéseau(*masque_sous_reseau)) {
				int numéro = 0;
				try
				{
					numéro = std::stoi(argv[1]);

				}
				catch (const std::invalid_argument&)
				{
					std::cerr << "Le num\202ro de sous r\202seau est invalide" << "\n";
					erreur = -1;
				}
				int classReseau = ip->getOctet(0)->toInt(); // y'a ptet un soucis là, de memory leak
				if (classReseau > 0) {
					if (classReseau >= 192)
						this->nbBitsReseau *= 3;
					else if (classReseau >= 128)
						this->nbBitsReseau *= 2;
					else if (classReseau == 127) {
						std::cerr << "Votre IP est invalide il ne peut pas \x88tre dans les 127.0.0.0" << "\n"; // x88 = ê
						erreur = -1;
						goto flag;
					}

					if (this->nbBitsReseau > this->nbBitMasqueSousRéseau) {
						std::cerr << "La classe de r\202seau de votre IP ne correspond pas \x85 votre masque de sous r\202seau." << "\n";
						erreur = -1;
					}
					else {
						int nbRéseau = std::pow(2,(this->nbBitMasqueSousRéseau - this->nbBitsReseau)); // le nombre de sous réseau existant dans ce réseau
						if (numéro > (nbRéseau) - 1 || numéro < 0) {
							
							std::cerr << "Le num\202ro de r\202seau que vous avez donn\202 est invalide. D'apr\202s vos informations il devrait \x88tre compris entre [ " << 0 << " ] et [ " << nbRéseau - 1 << " ]" << "\n";
							erreur = -1;
						}
						else {
							// si tout est bon :
							std::cout << "nombre de bit en reseau : " << this->nbBitMasqueSousRéseau << "nombre de bit du masque de reseau : " << this->nbBitsReseau << "\n";
						}
					}

				}
				else {
					std::cerr << "votre IP est invalide il ne peut pas \x88tre dans les 0.0.0.0" << "\n";
					erreur = -1;
					goto flag;
				}
				
				
			}
			else
			{
				std::cerr << "Le masque sous r\202seau que vous avez donn\202 n'en est pas un" << "\n";
				erreur = -1;
			}
		}
		else {
			std::cerr << "Le masque sous r\202seau que vous avez donn\202 est incorrect" << "\n";
			erreur = -1;
		}
		flag: // ce flag permet de delete au cas ou le masque sous réseau
		delete masque_sous_reseau;
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
	std::cout << "Pas encore d'aide désolé va falloir se débrouiller tout seul" << "\n";
}
