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

	static char buff[1024][1024];
	int i = 0;
	int count = 1;
	string buffer;
	Data2 document2;

	//������� ������ � ����� bufferRead
	string filename = "Buffer\\bufferRead.txt";

	if (remove(filename.c_str()) == 0)
	{
		cout << endl << " ���������� ������ ";

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

		
		// ���������� ����� �� ��������� Date2 � ���� bufferRaed �� �������
		ofstream files;
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

	MenuList(number);
	
}

void MenuList(int number)
{
	cout << endl;
	cout << " ���������� ������ �� ����         - ������� [1]" << endl;
	cout << " ���������� ������ �� ������       - ������� [2]" << endl;
	cout << " ���������� ������ �� �����        - ������� [3]" << endl;
	cout << " ��������� � ����                  - ������� [4]" << endl;

	char p;

	do
	{
		cout << endl << " �������� ������ �����: ";

		cin >> p;

		switch (p)
		{
		case '1':
			system("cls");
			ListForTheDay(number);
			break;
		case '2':
			system("cls");
			ListForTheWeek(number);
			break;
		case '3':
			system("cls");
			ListForTheMonth(number);
		case '4':
			system("cls");
			Menu();
		default:
			cout << endl << " ������� �������� ��������. ���������� ��� ���." << endl;
			break;
		}

	} while (true);

}

void ListForTheDay(int number)
{
	static char buff[1024][1024];
	int u = 0;
	char f;
	int i = 0;
	bool temp = false;
	int next = 0;
	int count = 1;
	string buffer;
	Data2 document2;

	ofstream files;

	//������� ������ � ����� bufferRead
	string filename = "Buffer\\bufferRead.txt";

	if (remove(filename.c_str()) == 0)
	{
		cout << " ����������� ������� �� ����." << endl;
		cout << " ������� �����/����: ";
		cin >> u;
		cout << endl << " ���������� ������ ";

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
		filesWriteListNumber >> document2.fileNumPr;
		filesWriteListNumber >> document2.fileNumDay;

		if (document2.fileNumDay == u)
		{
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
			temp = true;
		}

		else
		{
			count++;
			next = 1;
		}
		
	}

	if (temp == true)
	{
		next = 0;

		cout << " ����������� ������� �� ����." << endl;
		cout << " ��������� ������ �� "  << u << "-� �����" << endl;

		ifstream files(L"Buffer\\bufferRead.txt");

		while (!files.eof())
		{
			files.getline(buff[i], sizeof(buff));
			cout << buff[i] << endl;
			++i;
		}

		files.close();
		ReturnMenu();
	}

	if (next == 1)
	{
		cout << " ����������� ������� �� ����." << endl;
		cout << " ��� ������� �� " << u << "-� �����" << endl;
		ReturnMenu();
	}

}

void ListForTheWeek(int number)
{
	cout << " ����������� ������� �� ������." << endl;
	cout << " ��� � ��������� ������ " << endl;
	ReturnMenu();

}

void ListForTheMonth(int number)
{
	static char buff[1024][1024];
	int u = 0;
	char f;
	int i = 0;
	bool temp = false;
	int next = 0;
	int count = 1;
	string buffer;
	Data2 document2;

	ofstream files;

	//������� ������ � ����� bufferRead
	string filename = "Buffer\\bufferRead.txt";

	if (remove(filename.c_str()) == 0)
	{
		cout << " ����������� ������� �� �����." << endl;
		cout << " ������� �����/�����: ";
		cin >> u;
		cout << endl << " ���������� ������ ";

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
		filesWriteListNumber >> document2.fileNumPr;
		filesWriteListNumber >> document2.fileNumDay;
		filesWriteListNumber >> document2.fileNumMonth;


		if (document2.fileNumMonth == u)
		{	
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
			temp = true;
		}

		else
		{
			count++;
			next = 1;
		}

	}

	if (temp == true)
	{
		next = 0;

		cout << " ����������� ������� �� �����." << endl;
		cout << " ��������� ������ �� " << u << "-�� �����" << endl;

		ifstream files(L"Buffer\\bufferRead.txt");

		while (!files.eof())
		{
			files.getline(buff[i], sizeof(buff));
			cout << buff[i] << endl;
			++i;
		}

		files.close();
		ReturnMenu();
	}

	if (next == 1)
	{
		cout << " ����������� ������� �� �����." << endl;
		cout << " ��� ������� �� " << u << "-�� �����" << endl;
		ReturnMenu();
	}
}
