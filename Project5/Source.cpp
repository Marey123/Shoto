#include <iostream>
#include <Windows.h>
#include "List.cpp"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List<int> ls;

	bool menu = true;

	cout << "          Laboratory work ¹4" << endl << endl;

	while (menu)
	{
		int n;

		cout << "1.  Add to the top of the list;" << endl;
		cout << "2.  Add to end of list;" << endl;
		cout << "3.  Add item by index;" << endl;
		cout << "4.  Remove from the beginning of the list;" << endl;
		cout << "5.  Remove from the end of the list;" << endl;
		cout << "6.  Delete by value;" << endl;
		cout << "7.  Delete by index;" << endl;
		cout << "8.  Ñlear the list;" << endl;
		cout << "9.  Invert list;" << endl;
		cout << "10. Show list;" << endl;
		cout << "11. Exit." << endl;
		cout << "Select item: "; cin >> n;

		while (n > 11 || n < 1)
		{
			cout << "Re-select item: "; cin >> n;
		}

		system("cls");

		switch (n)
		{
		case 1:
		{
			int integer;
			cout << "Enter item: "; cin >> integer;
			ls.push_front(integer);
			system("cls");
			break;
		}
		case 2:
		{
			int integer;
			cout << "Enter item: "; cin >> integer;
			ls.push_back(integer);
			system("cls");
			break;
		}
		case 3:
		{
			int integer, index;
			cout << "Enter item: "; cin >> integer;
			cout << "Enter index: "; cin >> index;
			ls.insert(integer, index - 1);
			system("cls");
			break;
		}
		case 4:
		{
			ls.pop_front();
			break;
		}
		case 5:
		{
			ls.pop_back();
			break;
		}
		case 6:
		{
			int integer;
			cout << "Enter item: "; cin >> integer;
			ls.remove_d(integer);
			system("cls");
			break;
		}
		case 7:
		{
			int index;
			cout << "Enter index: "; cin >> index;
			ls.remove_i(index - 1);
			system("cls");
			break;
		}
		case 8:
		{
			ls.clear();
			break;
		}
		case 9:
		{
			ls.reverse();
			break;
		}
		case 10:
		{
			ls.show();
			system("pause");
			system("cls");
			break;
		}
		case 11:
		{
			menu = false;
		}
		default:
		{
			break;
		}
		}
	}
	return 0;
}