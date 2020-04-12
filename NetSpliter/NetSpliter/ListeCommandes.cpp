#include "ListeCommandes.hpp"

Commande* ListeCommandes::get(std::string nom)
{
	if (nom == "split") {
		return new Split();
	}
	if (nom == "see") {
		return new See();
	}
	return nullptr;
}
