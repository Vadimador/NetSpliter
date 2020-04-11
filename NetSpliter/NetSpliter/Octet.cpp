#include "Octet.hpp"
#include <iostream>
Octet::Octet(char octet)
    : octet(octet)
{
}

bool Octet::getBit(int i)
{
    return ((this->octet >> i) & 1);
}

bool Octet::getInverseBit(int i)
{
    i = (7 - i);
    return ((this->octet >> i) & 1);
}

std::string Octet::toString()
{
    std::string s = "";
    for (int i = 7; i >= 0; --i)
    {
        s += (this->getBit(i) == true)?"1":"0";
    }

    return s;
}

int Octet::toInt()
{
    return (int)this->octet;
}
