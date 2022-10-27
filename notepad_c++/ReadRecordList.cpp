#include <Windows.h>
#include "Default.h"
#include <synchapi.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;


void ReadRecordList(int number)
{
	SYSTEMTIME time;
	GetLocalTime(&time);

	cout << endl;
	cout << " ���������� ���� ������ �� ������� - ������� [1]" << endl;
	cout << " ���������� ������ �� ����         - ������� [2]" << endl;
	cout << " ���������� ������ �� ������       - ������� [3]" << endl;
	cout << " ���������� ������ �� �����        - ������� [4]" << endl;
	cout << " ��������� � ����                  - ������� [5]" << endl;

	char p;

	do
	{
		cout << endl << " �������� ������ �����: ";
		cin >> p;

		switch (p)
		{
		case '1':
			system("cls");
			TheWholeList(number);
			break;
		case '2':
			system("cls");
			ListForTheDey(number, time);
			break;
		case '3':
			system("cls");
			ListForTheWeek(number, time);
			break;
		case '4':
			system("cls");
			ListForTheMonth(number, time);
		case '5':
			system("cls");			
			Menu();
		default:
			cout << endl << " ������� �������� ��������. ���������� ��� ���." << endl;
			break;
		}

	} while (true);
	
}

void TheWholeList(int number)
{

	static char buff[1024][1024];
	int i = 0;
	int count = 1;
	string buffer;
	Data2 document2;

	//������� ������ � ����� bufferRead
	string filename = "Buffer\\bufferRead.txt";

	if (remove(filename.c_str()) == 0)
	{
		cout << endl << " " << " ���������� ������ ";

		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " ." << endl;
		system("cls");
	}

	for (int j = 1; j <= number; j++)
	{
		buffer = to_string(count);

		//�������� ��������� ����� ���� �� ����� � ���������� �� � ��������� Date2
		ifstream filesWriteListNumber(buffer + ".txt");
		filesWriteListNumber >> document2.contBuf;
		filesWriteListNumber >> document2.nameBuf;
		filesWriteListNumber >> document2.descriptionBuf;
		filesWriteListNumber >> document2.prioritetBuf;
		filesWriteListNumber >> document2.dateBuf;

		ofstream files;

		// ���������� ����� �� ��������� Date2 � ���� bufferRaed �� �������
		files.open(L"Buffer\\bufferRead.txt", ios::app);
		files << endl;
		files << " ������ �����: " << document2.contBuf << endl;
		files << " ��������:     " << document2.nameBuf << endl;
		files << " ��������:     " << document2.descriptionBuf << endl;
		files << " ���������:    " << document2.prioritetBuf << endl;
		files << " ����:         " << document2.dateBuf << endl;

		files << " ________________ " << endl;
		files.close();

		count++;
	}

	cout << " ���� ������: " << endl;

	// ��������� ���� � ������� �� �����
	ifstream files(L"Buffer\\bufferRead.txt");

	if (!files.is_open() == true)
	{
		cout << endl << " �� �� ������� �� ����� ������" << endl;

		Sleep(1000);
		cout << " ������ �� ������ �������������� � ����";

		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " ." << endl;
		system("cls");
		Menu();
	}

	else
	{
		while (!files.eof())
		{
			files.getline(buff[i], sizeof(buff));
			cout << buff[i] << endl;
			++i;
		}
		files.close();
	}

	ReturnMenu();
}

//�� ��������
void ListForTheDey(int number, SYSTEMTIME time)
{
	static char buff[1024][1024];
	int u;
	int i = 0;
	int count = 1;
	string buffer;
	Data2 document2;

	//������� ������ � ����� bufferRead
	string filename = "Buffer\\bufferRead.txt";

	if (remove(filename.c_str()) == 0)
	{
		cout << " ������� �����/����: ";
		cin >> u;
		cout << endl << " " << " ���������� ������ ";

		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " ." << endl;
		system("cls");
	}

	for (int j = 1; j <= number; j++)
	{
		buffer = to_string(count);

		//�������� ��������� ����� ���� �� ����� � ���������� �� � ��������� Date2
		ifstream filesWriteListNumber(buffer + ".txt");
		filesWriteListNumber >> document2.contBuf;
		filesWriteListNumber >> document2.nameBuf;
		filesWriteListNumber >> document2.descriptionBuf;
		filesWriteListNumber >> document2.prioritetBuf;
		/*filesWriteListNumber >> document2.dateBuf;*/
		filesWriteListNumber >> time.wDay;

		ofstream files;

		// ���������� ����� �� ��������� Date2 � ���� bufferRaed �� �������
		files.open(L"Buffer\\bufferRead.txt", ios::app);
		files << endl;
		files << " ������ �����: " << document2.contBuf << endl;
		files << " ��������:     " << document2.nameBuf << endl;
		files << " ��������:     " << document2.descriptionBuf << endl;
		files << " ���������:    " << document2.prioritetBuf << endl;
		/*files << " ����:         " << document2.dateBuf << endl;*/
		files << " ����:         " << time.wDay << " �����" << endl;

		files << " ________________ " << endl;
		files.close();

		count++;
		
	}

	cout << " ��������� ������ �� ����: " << endl;

	// ��������� ���� � ������� �� �����
	ifstream files(L"Buffer\\bufferRead.txt");

	if (!files.is_open() == true)
	{
		cout << endl << " �� �� ������� �� ����� ������" << endl;

		Sleep(1000);
		cout << " ������ �� ������ �������������� � ����";

		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " ." << endl;
		system("cls");
		Menu();
	}

	else
	{
		while (!files.eof())
		{
			files.getline(buff[i], sizeof(buff));
			cout << buff[i] << endl;
			++i;
		}
		files.close();
	}

	ReturnMenu();
}

// �� ��������
void ListForTheWeek(int number, SYSTEMTIME time)
{
	static char buff[1024][1024];
	int i = 0;
	int count = 1;
	string buffer;
	Data2 document2;

	//������� ������ � ����� bufferRead
	string filename = "Buffer\\bufferRead.txt";

	if (remove(filename.c_str()) == 0)
	{
		cout << endl << " " << " ���������� ������ ";

		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " ." << endl;
		system("cls");
	}

	for (int j = 1; j <= number; j++)
	{
		buffer = to_string(count);

		//�������� ��������� ����� ���� �� ����� � ���������� �� � ��������� Date2
		ifstream filesWriteListNumber(buffer + ".txt");
		filesWriteListNumber >> document2.contBuf;
		filesWriteListNumber >> document2.nameBuf;
		filesWriteListNumber >> document2.descriptionBuf;
		filesWriteListNumber >> document2.prioritetBuf;
		/*filesWriteListNumber >> document2.dateBuf;*/
		filesWriteListNumber >> time.wMonth;

		ofstream files;

		// ���������� ����� �� ��������� Date2 � ���� bufferRaed �� �������
		files.open(L"Buffer\\bufferRead.txt", ios::app);
		files << endl;
		files << " ������ �����: " << document2.contBuf << endl;
		files << " ��������:     " << document2.nameBuf << endl;
		files << " ��������:     " << document2.descriptionBuf << endl;
		files << " ���������:    " << document2.prioritetBuf << endl;
		/*files << " ����:         " << document2.dateBuf << endl;*/
		files << " ����:         " << time.wMonth << " �����" << endl;

		files << " ________________ " << endl;
		files.close();

		count++;
	}

	cout << " ��������� ������ �� ����: " << endl;

	// ��������� ���� � ������� �� �����
	ifstream files(L"Buffer\\bufferRead.txt");

	if (!files.is_open() == true)
	{
		cout << endl << " �� �� ������� �� ����� ������" << endl;

		Sleep(1000);
		cout << " ������ �� ������ �������������� � ����";

		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " .";
		Sleep(700);
		cout << " ." << endl;
		system("cls");
		Menu();
	}

	else
	{
		while (!files.eof())
		{
			files.getline(buff[i], sizeof(buff));
			cout << buff[i] << endl;
			++i;
		}
		files.close();
	}

	ReturnMenu();
}

// �� ��������
void ListForTheMonth(int number, SYSTEMTIME time)
{
}
