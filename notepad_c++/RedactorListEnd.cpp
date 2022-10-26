#include <Windows.h>
#include <iostream>
#include <fstream>
#include <synchapi.h>
#include <string>
#include <ctime>
#include <sysinfoapi.h>
#include "Default.h"

using namespace std;


void RedactorListEnd(int del, Data1 document)
{

	char* temp;
	string numberRecordList;
	char sav;

	SYSTEMTIME time;
	GetLocalTime(&time);\

	cout << " Дата и время создания записи: " << time.wDay << "." << time.wMonth << "." << time.wYear << " / " << time.wHour << ":"
		 << time.wMinute << ":" << time.wSecond << endl;

	numberRecordList = to_string(del);

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
	filesWriteListNumber << del << endl;
	filesWriteListNumber << document.name << endl;
	filesWriteListNumber << document.description << endl;
	filesWriteListNumber << document.prioritet << endl;
	filesWriteListNumber << time.wDay << "." << time.wMonth << "." << time.wYear << " / " << time.wHour << ":"
		                 << time.wMinute << ":" << time.wSecond << endl;
	filesWriteListNumber << document.priority << endl;
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
