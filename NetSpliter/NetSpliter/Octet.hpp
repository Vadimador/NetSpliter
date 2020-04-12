#pragma once
#include <string>

class Octet
{

private:
	char octet;

public :
	Octet(char octet);
	Octet();

	//--méthodes

	/// renvoie le bit d'un endroit précis
	/// Attention : 0 = le bit le plus faible et 7 = le bit le plus fort
	///////////////////
	bool getBit(int i);

	/// renvoie le bit d'un endroit précis de manière inversé à la méthodes "getBit"
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

