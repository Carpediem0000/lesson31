#pragma once
#include "SoftwareConditionalFree.h"
class CommercialSoftware :
    public SoftwareConditionalFree
{
protected:
    double cost;
public:
    CommercialSoftware();
    CommercialSoftware(string name, string prod, Date installation, int usagePeriod, double cost);
    ~CommercialSoftware();

    void setCost(double cost);

    double getCost()const;

    void print()const override;
    string type()const override;
    bool isAvailable()const override;

    void save(ofstream& file)const override;
    void load(ifstream& file) override;
};

