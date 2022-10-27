#include <Windows.h>
#include <iostream>
#include "Default.h"

using namespace std;

void SearchList(int number)
{
	cout << " Поиск записей." << endl;
	cout << " ______________________ " << endl;
	cout << " 1. Найти запись по названию     - нажмите [1]" << endl;
	cout << " 2. Найти запись по приоритету   - нажмите [2]" << endl;
	cout << " 3. Найти запись по описанию     - нажмите [3]" << endl;
	cout << " 4. Найти запись по дате         - нажмите [4]" << endl;
	cout << " 5. Вернуться в меню             - нажмите [5]" << endl;

	char num;

	do
	{

		cout << endl << " Выберите нужный пункт: ";
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
			cout << endl << " Введены неверные значения. Попробуйте еще раз." << endl;
			break;
		}

	} while (true);
}

void SearchListName()
{
	cout << " Список записей по названию." << endl;

	ReturnMenu();
}

void SearchListPriority()
{
	cout << " Список записей по приоритету." << endl;

	ReturnMenu();
}

void SearchListDescription()
{
	cout << " Список записей по описанию." << endl;

	ReturnMenu();
}

void SearchListData()
{
	cout << " Список записей по дате." << endl;

	ReturnMenu();
}