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

	/// set la valeur au bit design� par l'index
	/// index : l'index du bit (0 = bit le plus faible, 7 = bit le plus fort)
	/// valeur : la valeur de remplacement du bit
	/// [example : setBit(0,1) : met la valeur du bit le plus faible � 1]
	////////////////////////////////////
	//void setBit(int index, bool valeur);

	/// Met tous les bits � 1 du masque � 1 dans l'octet
	/// mask : le mask sous forme de int (192 = 1100 0000)
	///////////////////////////
	void setMasqueOR(int mask);

	/// Met tous les bits � 1 du masque � 0 dans l'octet (fait l'inverse de la m�thodes "setMasqueInverseOR")
	/// mask : le masque sous forme de int (192 = 1100 0000)
	//////////////////////////////////
	void setMasqueInverseOR(int mask);

	/// renvoie une visualisation en string de l'octet
	///////////////////////
	std::string toString();

	/// renvoie l'octet sous forme de int
	////////////
	int toInt();
	
};

