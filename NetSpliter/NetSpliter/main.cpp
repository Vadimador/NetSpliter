#include <iostream>
#include "ListeCommandes.hpp"
#include "Octet.hpp"
using namespace std;

int main(int argc, char** argv) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int erreur = 0; // 0 si il n'y à pas d'erreur, -1 si il y à eu une erreur
	system("title NetSpliter");
	if (argc >= 4) { // forme de commande "NetSpliter @adresse split <nombre de réseau>"

		IP* adresse = IP::isAdresse((string)argv[1]); //IP.isAdresse(argv[1]); // IP*i = new IP(fsdqfdsqf) // return i;
		Commande *commande = nullptr;
		if (adresse != nullptr) {
			commande = ListeCommandes::get(argv[2]); // on initialise une commande split
			if (commande != nullptr) {

				
				char** args = new char* [argc - 3]; // on fait un tableau de char permettant de stocker les arguments de split

				for (size_t i = 3, j = 0; i < argc; ++i, ++j)
				{
					args[j] = argv[i];
				}
				erreur = commande->execute(adresse, argc - 3, args);
				delete[] args;
			}
			else {
				cerr << "la commande \"" << argv[2] << "\" n'existe pas." << "\n";
				erreur = -1;
			}
		}
		else {
			cerr << "L'adresse n'est pas valide." << "\n";
			erreur = -1;
		}
		
		 
		delete adresse;
		delete commande;
	}
	else {
		cerr << "nombre d'argument incorrect" << "\n";
		erreur = -1;
	}

	//cout << argv[0];
	system("pause>nul");
	return erreur;
}