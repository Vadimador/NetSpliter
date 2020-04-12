#include "Octet.hpp"
#include <iostream>
Octet::Octet(char octet)
    : octet(octet)
{
}

Octet::Octet(std::string octet)
{
    this->octet = 0;
    for (size_t i = 0; i < 8; i++)
    {
        if (octet.at(i) == '1')
            this->setBit((7 - i), 1);
        else
            this->setBit((7 - i), 0);
    }
}

Octet::Octet()
{
    this->octet = 0;
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

void Octet::setOctet(char octet)
{
    this->octet = octet;
}

void Octet::setOctetWithString(std::string octet)
{
    *this = Octet(octet);
}

void Octet::setBit(int index, bool valeur)
{
    if (valeur == 1) {
        this->octet = this->octet | (1 << index);
    }
    else
    {
        this->octet = this->octet & ~(1 << index);
    }
}

void Octet::setMasqueOR(int mask)
{
    this->octet = (this->octet | mask);
}

void Octet::setMasqueInverseOR(int mask)
{
    this->octet = ~this->octet;
    this->setMasqueOR(mask);
    this->octet = ~this->octet;
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
