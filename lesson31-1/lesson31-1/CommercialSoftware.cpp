#include "CommercialSoftware.h"

CommercialSoftware::CommercialSoftware()
{
    this->cost = 100;
}

CommercialSoftware::CommercialSoftware(string name, string prod, Date installation, int usagePeriod, double cost)
    :SoftwareConditionalFree(name, prod, installation, usagePeriod)
{
    this->cost = cost;
}

CommercialSoftware::~CommercialSoftware()
{
}

void CommercialSoftware::setCost(double cost)
{
    this->cost = cost;
}

double CommercialSoftware::getCost() const
{
    return cost;
}

void CommercialSoftware::print() const
{
    cout << "Type: " << type() << endl;
    cout << "Name: " << name << endl;
    cout << "Company: " << prod << endl;
    cout << "Cost: " << cost << endl;
    cout << "Date installation: "; installation.showDate();
    cout << "Usage period: " << usagePeriod << " day\n";
    cout << "Available: " << (isAvailable() ? "Yes" : "No") << endl;
}

string CommercialSoftware::type() const
{
    return "CommercialSoftware";
}

bool CommercialSoftware::isAvailable() const
{
    return installation + usagePeriod >= Date();
}

void CommercialSoftware::save(ofstream& file) const
{
    file << type() << endl;
    file << name << endl;
    file << prod << endl;
    file << installation.getDay() << " " << installation.getMonth()
        << " " << installation.getYear() << endl;
    file << usagePeriod << endl;
    file << cost<<endl;
}

void CommercialSoftware::load(ifstream& file)
{
    getline(file, name);
    getline(file, prod);
    int d, m, y;
    file >> d >> m >> y;
    installation = Date(y, m, d);
    file >> usagePeriod;
    file >> cost;
}
