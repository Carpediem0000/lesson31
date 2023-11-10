#include "SoftwareConditionalFree.h"

SoftwareConditionalFree::SoftwareConditionalFree()
{
    this->installation = Date();
    this->usagePeriod = 30;
}

SoftwareConditionalFree::SoftwareConditionalFree(string name, string prod, Date installation, int usagePeriod)
    :Software(name, prod)
{
    this->installation = installation;
    this->usagePeriod = usagePeriod;
}

SoftwareConditionalFree::~SoftwareConditionalFree()
{
}

void SoftwareConditionalFree::setDateInstallation(Date installation)
{
    this->installation = installation;
}

void SoftwareConditionalFree::setDateInstallation(int day, int month, int year)
{
    this->installation = Date();
    installation.setDay(day);
    installation.setMonth(month);
    installation.setYear(year);
}

void SoftwareConditionalFree::setUsagePeriod(int usagePeriod)
{
    this->usagePeriod = usagePeriod;
}

Date SoftwareConditionalFree::getInstallation() const
{
    return installation;
}

int SoftwareConditionalFree::getUsagePeriod() const
{
    return usagePeriod;
}

void SoftwareConditionalFree::print() const
{
    cout << "Type: " << type() << endl;
    cout << "Name: " << name << endl;
    cout << "Company: " << prod << endl;
    cout << "Date installation: "; installation.showDate();
    cout << "Usage period: " << usagePeriod << " day\n";
    cout << "Available: " << (isAvailable() ? "Yes" : "No") << endl;
}

string SoftwareConditionalFree::type() const
{
    return "SoftwareConditionalFree";
}

bool SoftwareConditionalFree::isAvailable() const
{
    return installation + usagePeriod >= Date();
}

void SoftwareConditionalFree::save(ofstream& file) const
{
    file << type() << endl;
    file << name << endl;
    file << prod << endl;
    file << installation.getDay() << " " << installation.getMonth()
        << " " << installation.getYear();
    file << usagePeriod << endl;
}

void SoftwareConditionalFree::load(ifstream& file)
{
    getline(file, name);
    getline(file, prod);
    int d, m, y;
    file >> d >> m >> y;
    installation = Date(y, m, d);
    file >> usagePeriod;
}
