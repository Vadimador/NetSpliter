#include "Split.hpp"
#include <iostream>

void Split::execute(IP* ip,unsigned int argc, char** argv)
{
	for (size_t i = 0; i < argc; i++)
	{
		std::cout << argv[i] << "\n";
	}
	//std::cout << "cette methode est cense etre implemente" << "\n";
}

void Split::help()
{
	std::cout << "pas encore inistialise";
}
