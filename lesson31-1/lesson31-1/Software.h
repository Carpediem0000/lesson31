#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Software
{
protected:
	string name;
	string prod;
public:
	Software();
	Software(string name, string prod);
	virtual ~Software();

	void setName(string name);
	void setProd(string prod);

	string getName()const;
	string getProd()const;

	virtual void print()const = 0;
	virtual string type()const = 0;
	virtual bool isAvailable()const = 0;

	virtual void save(ofstream& file)const = 0;
	virtual void load(ifstream& file) = 0;

};

