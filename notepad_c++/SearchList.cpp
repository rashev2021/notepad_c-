#include <Windows.h>
#include <iostream>
#include "Default.h"

using namespace std;

void SearchList(int number)
{
	cout << " ����� �������." << endl;
	cout << " ______________________ " << endl;
	cout << " 1. ����� ������ �� ��������     - ������� [1]" << endl;
	cout << " 2. ����� ������ �� ����������   - ������� [2]" << endl;
	cout << " 3. ����� ������ �� ��������     - ������� [3]" << endl;
	cout << " 4. ����� ������ �� ����         - ������� [4]" << endl;
	cout << " 5. ��������� � ����             - ������� [5]" << endl;

	char num;

	do
	{

		cout << endl << " �������� ������ �����: ";
		cin >> num;


		switch (num)
		{
		case '1':
			system("cls");
			SearchListName();
			break;
		case '2':
			system("cls");
			SearchListPriority();
			break;
		case '3':
			system("cls");
			SearchListDescription();
			break;
		case '4':
			system("cls");
			SearchListData();
			break;
		case '5':
			system("cls");
			Menu();
			break;
		default:
			cout << endl << " ������� �������� ��������. ���������� ��� ���." << endl;
			break;
		}

	} while (true);
}

void SearchListName()
{
	cout << " ������ ������� �� ��������." << endl;

	ReturnMenu();
}

void SearchListPriority()
{
	cout << " ������ ������� �� ����������." << endl;

	ReturnMenu();
}

void SearchListDescription()
{
	cout << " ������ ������� �� ��������." << endl;

	ReturnMenu();
}

void SearchListData()
{
	cout << " ������ ������� �� ����." << endl;

	ReturnMenu();
}