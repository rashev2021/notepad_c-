#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Default.h"

using namespace std;

void RedactorList(int number)
{

	cout << endl << " �������� ������." << endl;

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
	cout << " ������� �������� ������: ";
	cin.get();
	cin.getline(document.name, 50);

	cout << " ������� �������� ������: ";
	cin.getline(document.description, 100);

	cout << " �������� ��������� ������: " << endl << endl;
	cout << "   " << " ������� - ������� [1]" << endl;
	cout << "   " << " ������� - ������� [2]" << endl;
	cout << "   " << " ������  - ������� [3]" << endl << endl;
	cout << " ������� 1, 2 ��� 3: ";

	cin >> priorityes;

	switch (priorityes)
	{

	case '1':
		priority = 1;
		cout << " ������ ��������� - �������." << endl;
		break;
	case '2':
		priority = 2;
		cout << " ������ ��������� - �������." << endl;
		break;
	case '3':
		priority = 3;
		cout << " ������ ��������� - ������." << endl;
		break;
	default:
		priority = 2;
		cout << " ������� �������� ��������. ��������� �� ��������� ����� \"�������\"." << endl;
		break;
	}

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
	filesWriteListNumber << priority << endl;
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