#include <Windows.h>
#include <iostream>
#include <fstream>
#include <synchapi.h>
#include <string>
#include <ctime>
#include <sysinfoapi.h>
#include "Default.h"


using namespace std;

void NewList(int number, Data1 document)
{
	char* temp;
	string sav;
	string numberRecordList;

	SYSTEMTIME time;
	GetLocalTime(&time);

	cout << " Дата и время создания записи: " << time.wDay << "." << time.wMonth << "." << time.wYear << " / " << time.wHour << ":"
		<< time.wMinute << ":" << time.wSecond << endl;

	// Запись номера записи в number.txt
	ofstream filesNumber;
	filesNumber.open(L"Number\\number.txt", ios::out);
	filesNumber << number;
	filesNumber.close();

	// Преобразование int number в строку
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

	// Запись данных из структуры в файл txt
	ofstream filesWriteListNumber;
	filesWriteListNumber.open(numberRecordList + ".txt", ios::out);
	filesWriteListNumber << endl;
	filesWriteListNumber << number << endl;
	filesWriteListNumber << document.name << endl;
	filesWriteListNumber << document.description << endl;
	filesWriteListNumber << document.prioritet << endl;
	filesWriteListNumber << time.wDay << "." << time.wMonth << "." << time.wYear << "_/_" << time.wHour << ":"
		                 << time.wMinute << ":" << time.wSecond << endl;
	filesWriteListNumber << document.priority << endl;
	filesWriteListNumber << endl;
	filesWriteListNumber.close();

	// Запись данных в bufferWrite из структуры
	ofstream filesListNumber;
	filesListNumber.open(L"Buffer\\bufferWrite.txt", ios::out);
	filesListNumber << endl;
	filesListNumber << " Запись номер: " << number << endl;
	filesListNumber << " Название:     " << document.name << endl;
	filesListNumber << " Описание:     " << document.description << endl;
	filesListNumber << " Приоритет:    " << document.prioritet << endl;
	filesListNumber << " Дата:         " << time.wDay << "." << time.wMonth << "." << time.wYear << " / " << time.wHour << ":"
		                                 << time.wMinute << ":" << time.wSecond << endl;
	filesListNumber << " ________________ " << endl;
	filesListNumber.close();


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
	PreviewRecordList();
}

void PreviewRecordList()
{
	static char buff[1024][1024];
	int i = 0;

	cout << " Запись успешно создана: " << endl << endl;

	ifstream files(L"Buffer\\bufferWrite.txt");

	while (!files.eof())
	{
		files.getline(buff[i], sizeof(buff));
		cout << buff[i] << endl;
		++i;
	}

	files.close();

	ReturnMenu();
}

