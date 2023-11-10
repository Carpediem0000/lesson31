#pragma once
#include "Software.h"
class FreeSoftware :
    public Software
{
public:
    FreeSoftware();
    FreeSoftware(string name, string prod);
    ~FreeSoftware();

    void print()const override;
    string type()const override;
    bool isAvailable()const override;

    void save(ofstream& file)const override;
    void load(ifstream& file) override;
};

