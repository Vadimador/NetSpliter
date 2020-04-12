#pragma once
#include <string>

class Octet
{

private:
	char octet;

public :
	Octet(char octet);
	Octet();

	//--m�thodes

	/// renvoie le bit d'un endroit pr�cis
	/// Attention : 0 = le bit le plus faible et 7 = le bit le plus fort
	///////////////////
	bool getBit(int i);

	/// renvoie le bit d'un endroit pr�cis de mani�re invers� � la m�thodes "getBit"
	/// Attention : 0 = le bit le plus fort et 7 = le bit le plus faible
	/////////////////////
	bool getInverseBit(int i);

	/// change l'octet
	//////////////////////////
	void setOctet(char octet);

	/// renvoie une visualisation en string de l'octet
	///////////////////////
	std::string toString();

	/// renvoie l'octet sous forme de int
	////////////
	int toInt();
	
};

