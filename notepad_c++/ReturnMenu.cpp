#include <Windows.h>
#include <iostream>
#include "Default.h"


using namespace std;


void ReturnMenu()
{

	char menuExit;

	do
	{
		cout << endl << " ����� � ���� - ������� [1]: ";
		cin >> menuExit;

		if (menuExit == '1')
		{
			system("cls");
			Menu();
		}
		else
		{
			cout << endl << " ������ �������� ��������. ���������� ��� ���: " << endl << endl;
		}

	} while (true);
}