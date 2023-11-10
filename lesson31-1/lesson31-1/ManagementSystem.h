#pragma once
#include "FreeSoftware.h"
#include "SoftwareConditionalFree.h"
#include "CommercialSoftware.h"
#include <algorithm>
#include <vector>

class ManagementSystem
{
	vector<Software*> arr;
public:
	ManagementSystem();
	~ManagementSystem()
	{
		for (Software* soft : arr)
		{
			delete soft;
		}
		arr.clear();
	}

	void addSoft(Software* soft);
	void removeSoft(int ind);
	void sortByProd();
	void showInfo()const;
	void showAvailableSoft()const;

	void saveSystem()const;
	void loadSystem();
};

