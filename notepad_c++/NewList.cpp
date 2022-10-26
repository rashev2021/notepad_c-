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

	cout << " ���� � ����� �������� ������: " << time.wDay << "." << time.wMonth << "." << time.wYear << " / " << time.wHour << ":"
		<< time.wMinute << ":" << time.wSecond << endl;

	// ������ ������ ������ � number.txt
	ofstream filesNumber;
	filesNumber.open(L"Number\\number.txt", ios::out);
	filesNumber << number;
	filesNumber.close();

	// �������������� int number � ������
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

	// ������ ������ �� ��������� � ���� txt
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

	// ������ ������ � bufferWrite �� ���������
	ofstream filesListNumber;
	filesListNumber.open(L"Buffer\\bufferWrite.txt", ios::out);
	filesListNumber << endl;
	filesListNumber << " ������ �����: " << number << endl;
	filesListNumber << " ��������:     " << document.name << endl;
	filesListNumber << " ��������:     " << document.description << endl;
	filesListNumber << " ���������:    " << document.prioritet << endl;
	filesListNumber << " ����:         " << time.wDay << "." << time.wMonth << "." << time.wYear << " / " << time.wHour << ":"
		                                 << time.wMinute << ":" << time.wSecond << endl;
	filesListNumber << " ________________ " << endl;
	filesListNumber.close();


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
	PreviewRecordList();
}

void PreviewRecordList()
{
	static char buff[1024][1024];
	int i = 0;

	cout << " ������ ������� �������: " << endl << endl;

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

