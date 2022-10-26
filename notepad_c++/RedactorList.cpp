#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Default.h"

using namespace std;

void RedactorList(int number)
{

	cout << endl << " Изменить запись." << endl;

	static char buff[1024][1024];
	int i = 0;
	int priority = 0;
	string sav;
	char priorityes;
	char* temp;
	string numberRecordList;
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
		priority = 1;
		cout << " Выбран приоритет - Высокий." << endl;
		break;
	case '2':
		priority = 2;
		cout << " Выбран приоритет - Средний." << endl;
		break;
	case '3':
		priority = 3;
		cout << " Выбран приоритет - Низкий." << endl;
		break;
	default:
		priority = 2;
		cout << " Введено неверное значение. Приоритет по умолчанию будет \"Средний\"." << endl;
		break;
	}

	SYSTEMTIME time;
	GetLocalTime(&time);

	cout << " Дата и время создания записи: " << time.wDay << "." << time.wMonth << "." << time.wYear << " / " << time.wHour << ":"
	     << time.wMinute << ":" << time.wSecond << endl;

	numberRecordList = to_string(number);

	//Замена пробелов в структуре на '_'
	while (temp = strchr(document.name, ' '))
	{
		*temp = '_';
		strcpy_s(document.name + (strlen(document.name) - strlen(temp)), strlen(document.name), temp);
	}

	while (temp = strchr(document.description, ' '))
	{
		*temp = '_';
		strcpy_s(document.description + (strlen(document.description) - strlen(temp)), strlen(document.description), temp);
	}

	ofstream filesWriteListNumber;
	filesWriteListNumber.open(numberRecordList + ".txt", ios::out);
	filesWriteListNumber << endl;
	filesWriteListNumber << number << endl;
	filesWriteListNumber << document.name << endl;
	filesWriteListNumber << document.description << endl;
	filesWriteListNumber << document.prioritet << endl;
	filesWriteListNumber << time.wDay << "." << time.wMonth << "." << time.wYear << " / " << time.wHour << ":"
		                 << time.wMinute << ":" << time.wSecond << endl;
	filesWriteListNumber << priority << endl;
	filesWriteListNumber << endl;
	filesWriteListNumber.close();

	cout << endl;
	cout << " Нажмите любую клавишу чтобы сохранить запись: ";
	cin >> sav;
	cout << endl << " Идёт сохранение, пожалуйста подождите";

	Sleep(700);
	cout << " .";
	Sleep(700);
	cout << " .";
	Sleep(700);
	cout << " .";
	Sleep(700);
	cout << " ." << endl;

	cout << " Запись успешно сохранена. " << endl << endl;
	Sleep(700);

	system("cls");
	Menu();

}