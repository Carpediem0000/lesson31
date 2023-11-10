#include "Software.h"

Software::Software()
{
    this->name = "Undefined";
    this->prod = "Undefined";
}

Software::Software(string name, string prod)
{
    this->name = name;
    this->prod = prod;
}

Software::~Software()
{
}

void Software::setName(string name)
{
    this->name = name;
}

void Software::setProd(string prod)
{
    this->prod = prod;
}

string Software::getName() const
{
    return name;
}

string Software::getProd() const
{
    return prod;
}
