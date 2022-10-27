#include <Windows.h>
#include <iostream>
#include "Default.h"
#include <fstream>
#include <string>

using namespace std;

static char buffS[1024][1024];
string bufferS;
int l = 0;

Data3 document3;

void SearchList(int number, Data2  document2)
{
	cout << " ����� �������." << endl;
	cout << " ______________________ " << endl;
	cout << " 1. ����� ������ �� ��������     - ������� [1]" << endl;
	cout << " 2. ����� ������ �� ����������   - ������� [2]" << endl;
	cout << " 3. ����� ������ �� ��������     - ������� [3]" << endl;
	cout << " 4. ����� ������ �� ����         - ������� [4]" << endl;
	cout << " 5. ��������� � ����             - ������� [5]" << endl;

	int next = 0;
	bool temp = false;

	char num;

	do
	{

		cout << endl << " �������� ������ �����: ";
		cin >> num;


		switch (num)
		{
		case '1':
			system("cls");
			SearchListName(number, next, temp, document2);
			break;
		case '2':
			system("cls");
			SearchListPriority(number, next, temp);
			break;
		case '3':
			system("cls");
			SearchListDescription(number, next, temp);
			break;
		case '4':
			system("cls");
			SearchListData(number, next, temp);
			break;
		case '5':
			system("cls");
			Menu();
			break;
		default:
			cout << endl << " ������� �������� ��������. ���������� ��� ���." << endl;
			break;
		}

	} while (true);
}

void SearchListName(int number, int next, bool temp, Data2 document2)
{
	cout << " ������ ������� �� ��������." << endl;
	cout << " ������� �������� ������: ";
	cin.get();
	gets_s(document3.nameBufS, 150);

	string a;
	string b;

	int count = 1;

	for (int j = 1; j <= number; j++)
	{
		bufferS = to_string(count);

		ifstream filesWriteListNumber(bufferS + ".txt");
		filesWriteListNumber >> document2.contBuf;
		filesWriteListNumber >> document2.nameBuf;
		filesWriteListNumber >> document2.descriptionBuf;
		filesWriteListNumber >> document2.prioritetBuf;
		filesWriteListNumber >> document2.dateBuf;
		filesWriteListNumber >> document2.fileNumPr;
		filesWriteListNumber >> document2.fileNumDay;
		filesWriteListNumber >> document2.fileNumMonth;

		a = document3.nameBufS;
		b = document2.nameBuf;

		if (a == b)
		{
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

		ifstream files(L"Buffer\\bufferRead.txt");

		while (!files.eof())
		{
			files.getline(buffS[l], sizeof(buffS));
			cout << buffS[l] << endl;
			++l;
		}

		files.close();
		ReturnMenu();
	}

	if (next == 1)
	{
		cout << " ��� ������� ��� ���� �����������." << endl;
		ReturnMenu();
	}

	
}

void SearchListPriority(int number, int next, bool temp)
{
	cout << " ������ ������� �� ����������." << endl;

	ReturnMenu();
}

void SearchListDescription(int number, int next, bool temp)
{
	cout << " ������ ������� �� ��������." << endl;

	ReturnMenu();
}

void SearchListData(int number, int next, bool temp)
{
	cout << " ������ ������� �� ����." << endl;

	ReturnMenu();
}