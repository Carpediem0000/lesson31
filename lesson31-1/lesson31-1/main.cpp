#include "ManagementSystem.h"
#include <Windows.h>

int main()
{
	/*Software* a1 = new FreeSoftware("Chrome", "Google");
	Software* a2 = new FreeSoftware("Opera", "Google");


	Software* b1 = new SoftwareConditionalFree("Photoshop", "Xz", Date()-7, 10);
	Software* b2 = new SoftwareConditionalFree("VisualStudio", "Xz", Date()-15, 10);


	Software* c1 = new CommercialSoftware("QT", "QTCompany", Date()-20, 14, 1000);
	Software* c2 = new CommercialSoftware("Youtube", "Google", Date(), 14, 500);*/

	ManagementSystem arr;

	/*arr.addSoft(a1);
	arr.addSoft(a2);
	arr.addSoft(b1);
	arr.addSoft(b2);
	arr.addSoft(c1);
	arr.addSoft(c2);*/

	int menu = 0;
	string str1;
	string str2;
	double p;
	int d;

	do
	{
		cout << "1 - Show Info\n";
		cout << "2 - Show available soft\n";
		cout << "3 - Add free soft\n";
		cout << "4 - Add commercial soft\n";
		cout << "5 - Add Software Conditional Free soft\n";
		cout << "6 - Remove Software\n";
		cout << "7 - Sort by company\n";
		cout << "8 - Save system\n";
		cout << "9 - Load system\n";
		cin >> menu;

		switch (menu)
		{
		case 1:
			arr.showInfo();
			Sleep(10000);
			break;
		case 2:
			arr.showAvailableSoft();
			Sleep(7000);
			break;
		case 3:
			cout << "Input name: ";
			cin.ignore();
			getline(cin, str1);
			cout << "Input company: ";
			getline(cin, str2);
			arr.addSoft(new FreeSoftware(str1, str2));
			break;
		case 4:
			cout << "Input name: ";
			cin.ignore();
			getline(cin, str1);
			cout << "Input company: ";
			getline(cin, str2);
			cout << "Input turms: ";
			cin >> d;
			cout << "Input price: ";
			cin >> p;
			arr.addSoft(new CommercialSoftware(str1, str2, Date(), d, p));
			break;
		case 5:
			cout << "Input name: ";
			cin.ignore();
			getline(cin, str1);
			cout << "Input company: ";
			getline(cin, str2);
			cout << "Input turms: ";
			cin >> d;
			arr.addSoft(new SoftwareConditionalFree(str1, str2, Date(), d));
			break;
		case 6:
			cout << "Input num: ";
			cin>> d;
			arr.removeSoft(d);
			break;
		case 7:
			arr.sortByProd();
			break;
		case 8:
			arr.saveSystem();
			break;
		case 9:
			arr.loadSystem();
			break;
		case 0:
			cout << "Bye..\n";
			break;
		default:
			break;
		}
		system("cls");
	} while (menu);

	

}