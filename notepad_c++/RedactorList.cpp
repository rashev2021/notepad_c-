#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Default.h"

using namespace std;

void RedactorList(int del)
{

	cout << endl << " Изменить запись." << endl;

	static char buff[1024][1024];
	int i = 0;
	char priorityes;
	string high = "Высокий";
	string avarage = "Средний";
	string low = "Низкий";

	Data1 document;

	ifstream filesListNumber(L"Buffer\\bufferDelete.txt");

	while (!filesListNumber.eof())
	{
		filesListNumber.getline(buff[i], sizeof(buff));
		cout << buff[i] << endl;
		++i;
	}
	filesListNumber.close();

	cout << endl;
	cout << " Введите название записи: ";
	cin.get();
	cin.getline(document.name, 50);

	cout << " Введите описание записи: ";
	cin.getline(document.description, 100);

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
		cout << " Выбран приоритет - Высокий." << endl;
		document.prioritet = const_cast<char*>(high.c_str());
		RedactorListEnd(del, document);
		break;
	case '2':
		document.priority = 2;
		cout << " Выбран приоритет - Средний." << endl;
		document.prioritet = const_cast<char*>(avarage.c_str());
		RedactorListEnd(del, document);
		break;
	case '3':
		document.priority = 3;
		cout << " Выбран приоритет - Низкий." << endl;
		document.prioritet = const_cast<char*>(low.c_str());
		RedactorListEnd(del, document);
		break;
	default:
		document.priority = 2;
		cout << " Введено неверное значение. Приоритет по умолчанию будет \"Средний\"." << endl;
		document.prioritet = const_cast<char*>(avarage.c_str());
		break;
	}

}

