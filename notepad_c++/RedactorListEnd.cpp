#include <Windows.h>
#include "Default.h"
#include <ctime>
#include <synchapi.h>
#include <sysinfoapi.h>
#include <iostream>
#include <string>
#include <fstream>


using namespace std;


void RedactorListEnd(int number, Data1 document)
{

	char* temp;
	string numberRecordList;
	char sav;

	SYSTEMTIME time;
	GetLocalTime(&time);

	cout << " ���� � ����� �������� ������: " << time.wDay << "." << time.wMonth << "." << time.wYear << " / " << time.wHour << ":"
		 << time.wMinute << ":" << time.wSecond << endl;

	numberRecordList = to_string(number);

	//������ �������� � ��������� �� '_'
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
	filesWriteListNumber << document.priority << endl;
	filesWriteListNumber << endl;
	filesWriteListNumber.close();

	cout << endl;
	cout << " ������� ����� ������� ����� ��������� ������: ";
	cin >> sav;
	cout << endl << " ��� ����������, ���������� ���������";

	Sleep(700);
	cout << " .";
	Sleep(700);
	cout << " .";
	Sleep(700);
	cout << " .";
	Sleep(700);
	cout << " ." << endl;

	cout << " ������ ������� ���������. " << endl << endl;
	Sleep(700);

	system("cls");
	Menu();

}
