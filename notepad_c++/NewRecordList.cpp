#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Default.h"

using namespace std;

void NewRecordList(int number)
{

	char priorityes;
	string high = "Высокий";
	string avarage = "Средний";
	string low = "Низкий";
	Data1 document;

	cout << " Добавить новую запись." << endl << endl;

	number++;

	cout << " Введите название записи: ";
	cin.get();
	gets_s(document.name, 150);

	cout << " Введите описание записи: ";
	gets_s(document.description, 150);

	cout << " Выберите приоритет записи: " << endl << endl;
	cout << "   " << " Высокий - нажмите [1]" << endl;
	cout << "   " << " Средний - нажмите [2]" << endl;
	cout << "   " << " Низкий  - нажмите [3]" << endl << endl;
	cout << " Введите 1, 2 или 3: ";


	cin >> priorityes;

	switch (priorityes)
	{

	case '1':
		document.priority = 1;
		// присваиваем стироку high к чаровой переменной
		document.prioritet = const_cast<char*>(high.c_str());
		cout << " Выбран приоритет - Высокий." << endl;
		NewList(number, document);
		break;
	case '2':
		document.priority = 2;
		// присваиваем стироку avarage к чаровой переменной
		document.prioritet = const_cast<char*>(avarage.c_str());
		cout << " Выбран приоритет - Средний." << endl;
		NewList(number, document);
		break;
	case '3':
		document.priority = 3;
		// присваиваем стироку low к чаровой переменной
		document.prioritet = const_cast<char*>(low.c_str());
		cout << " Выбран приоритет - Низкий." << endl;
		NewList(number, document);
		break;
	default:
		cout << " Введено неверное значение. Приоритет по умолчанию будет \"Средний\"." << endl;
		document.priority = 2;
		// присваиваем стироку avarage к чаровой переменной
		document.prioritet = const_cast<char*>(avarage.c_str());
		NewList(number, document);
		break;
	}

}
