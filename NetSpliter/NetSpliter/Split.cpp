#include "Split.hpp"
#include <iostream>

void Split::execute(IP* ip, int argc, char** argv)
{
	for (size_t i = 0; i < argc; i++)
	{
		std::cout << argv[i] << "\n";
	}
	//std::cout << "cette methode est cense etre implemente" << "\n";
}
