#include "FreeSoftware.h"

FreeSoftware::FreeSoftware(){}

FreeSoftware::FreeSoftware(string name, string prod)
    :Software(name, prod){}

FreeSoftware::~FreeSoftware()
{
}

void FreeSoftware::print() const
{
    cout << "Type: " << type() << endl;
    cout << "Name: " << name << endl;
    cout << "Company: " << prod << endl;
    cout << "Available: " << (isAvailable() ? "Yes" : "No") << endl;
}

string FreeSoftware::type() const
{
    return "FreeSoftware";
}

bool FreeSoftware::isAvailable() const
{
    return true;
}

void FreeSoftware::save(ofstream& file) const
{
    file << type() << endl;
    file << name << endl;
    file << prod << endl;
}

void FreeSoftware::load(ifstream& file)
{
    getline(file, name);
    getline(file, prod);
}
