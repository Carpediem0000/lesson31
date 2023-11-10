#include "ManagementSystem.h"

ManagementSystem::ManagementSystem(){}

void ManagementSystem::addSoft(Software* soft) { arr.push_back(soft); }

void ManagementSystem::removeSoft(int ind)
{
	if (ind >= 0 && ind < arr.size())
	{
		delete arr[ind];
		arr.erase(arr.begin() + ind);
	}
}

void ManagementSystem::sortByProd()
{
	std::sort(arr.begin(), arr.end(), [](const Software* left, const Software* right) {
		return left->getProd() < right->getProd(); });
}

void ManagementSystem::showInfo() const
{
	cout << "\tSoftware\n";
	for (const Software* soft : arr)
	{
		cout << "--------------------------------\n";
		soft->print();
		cout << "--------------------------------\n";
	}
}

void ManagementSystem::showAvailableSoft() const
{
	cout << "\tAvailable Software\n";
	for (const Software* soft : arr)
	{
		if (soft->isAvailable())
		{
			cout << "--------------------------------\n";
			soft->print();
			cout << "--------------------------------\n";
		}
	}
}

void ManagementSystem::saveSystem() const
{
	ofstream file("admin.txt");
	if (file.is_open())
	{
		for (Software* soft:arr)
		{
			soft->save(file);
		}
		file.close();
	}
}

void ManagementSystem::loadSystem()
{
	ifstream file("admin.txt");
	if (file.is_open())
	{
		string typeObj;
		Software* p = nullptr;
		while (!file.eof())
		{
			getline(file, typeObj);
			if (typeObj == "FreeSoftware")
			{
				p = new FreeSoftware;
				p->load(file);
				arr.push_back(p);
			}
			else if (typeObj == "SoftwareConditionalFree") {
				p = new SoftwareConditionalFree;
				p->load(file);
				arr.push_back(p);
			}
			else if(typeObj == "CommercialSoftware")
			{
				p = new CommercialSoftware;
				p->load(file);
				arr.push_back(p);
			}
		}
		file.close();
	}
}
