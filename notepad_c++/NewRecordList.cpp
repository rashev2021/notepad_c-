#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "Default.h"



using namespace std;

void NewRecordList(int number)
{

	char priorityes;
	Data1 document;

	cout << " Добавить новую запись." << endl << endl;

	number++;

	cout << " Введите название записи: ";
	cin.get();
	gets_s(document.name, 150);

	cout << " Введите описание записи: ";
	cin.get();
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
		document.prioritet;
		cout << " Выбран приоритет - Высокий." << endl;
		NewList(number);
		break;
	case '2':
		document.priority = 2;
		document.prioritet;
		cout << " Выбран приоритет - Средний." << endl;
		NewList(number);
		break;
	case '3':
		document.priority = 3;
		document.prioritet;
		cout << " Выбран приоритет - Низкий." << endl;
		NewList(number);
		break;
	default:
		cout << " Введено неверное значение. Приоритет по умолчанию будет \"Средний\"." << endl;
		document.priority = 2;
		document.prioritet;
		NewList(number);
		break;
	}

}
