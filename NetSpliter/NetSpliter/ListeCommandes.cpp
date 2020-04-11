#include "ListeCommandes.hpp"

Commande* ListeCommandes::get(std::string nom)
{
	if (nom == "split") {
		return new Split();
	}
	return nullptr;
}
