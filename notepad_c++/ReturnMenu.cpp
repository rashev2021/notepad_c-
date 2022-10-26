#include <Windows.h>
#include <iostream>
#include "Default.h"


using namespace std;


void ReturnMenu()
{

	char menuExit;

	do
	{
		cout << endl << " Выйти в меню - нажмите [1]: ";
		cin >> menuExit;

		if (menuExit == '1')
		{
			system("cls");
			Menu();
		}
		else
		{
			cout << endl << " Ведено неверное значение. Попробуйте ещё раз: " << endl << endl;
		}

	} while (true);
}