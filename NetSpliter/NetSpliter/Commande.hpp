#pragma once
#include "IP.hpp"

 class Commande
{
	virtual void execute(IP ip, int nbSousReseau) = 0;
};

