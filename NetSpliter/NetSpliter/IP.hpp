#pragma once
class IP
{
private:
	int adresse_ip[4] = {10,10,10,10};
	int mask[4];
	
public:
	//--Getteur

	//--Setteur
	void setMask();

	//--Methode
	void IP(int adresse_ip[4]);

	IP* isAdresse(string adresse);

	bool[][] adresse_ip_binaire();
	
	void nbBitSousAdresse();
};

