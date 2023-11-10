#pragma once
#include "Software.h"
#include "Date.h"

class SoftwareConditionalFree :
    public Software
{
protected:
    Date installation;
    int usagePeriod;
public:
    SoftwareConditionalFree();
    SoftwareConditionalFree(string name, string prod, Date installation, int usagePeriod);
    ~SoftwareConditionalFree();

    void setDateInstallation(Date installation);
    void setDateInstallation(int day, int month, int year);
    void setUsagePeriod(int usagePeriod);

    Date getInstallation()const;
    int getUsagePeriod()const;

    void print()const override;
    string type()const override;
    bool isAvailable()const override;

    void save(ofstream& file)const override;
    void load(ifstream& file) override;
};

