#include <Windows.h>
#include <iostream>
#include <fstream>
#include "Default.h"
#include <string>

using namespace std;

void Menu()
{
	cout << " ������ ��� " << endl;
	cout << " ______________________ " << endl;
	cout << " 1. �������� ����� ������             - ������� [1]" << endl;
	cout << " 2. ������������� ��� ������� ������  - ������� [2]" << endl;
	cout << " 3. ���������� ������� ������         - ������� [3]" << endl;
	cout << " 4. ����� ������ �� ������            - ������� [4]" << endl;
	cout << " 5. ������������� ������              - ������� [5]" << endl;
	cout << " 6. �������� ���� ������              - ������� [6]" << endl;
	cout << " 7. ������� �������                   - ������� [7]" << endl;

	char enter;
	int number = 0;
	int numb = 0;
	string w = "0";

	// ������� ����� � ����������
	wstring Num = L"Number";
	CreateDirectoryW(Num.c_str(), NULL);
	wstring Buf = L"Buffer";
	CreateDirectoryW(Buf.c_str(), NULL);

	// ��������� ����� ������ �� �����
	ifstream filesNumber(L"Number\\number.txt");
	// ���������� ������ ����� � ���������� number
	filesNumber >> number;

	////������� ����
	//ofstream filesNumber;
	//filesNumber.open(L"Buffer\\bufferRead.txt", ios::out);
	//filesNumber >> w;
	//filesNumber.close();

	do
	{
		cout << endl << " �������� ������ �����: ";
		cin >> enter;

		if (enter == '1')
		{
			system("cls");
			NewRecordList(number);
			break;
		}
		if (enter == '2')
		{
			system("cls");

			if (number == 0)
			{
				cout << " � ��� ��� ������� ��� �������������� � ��������" << endl;

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
				system("cls");
				DeleteRedactorList(number);
			}

			break;
		}
		if (enter == '3')
		{
			system("cls");
			ReadRecordList(number);
			break;
		}
		if (enter == '4')
		{
			system("cls");
			/*searchRecordList();*/
			cout << " ����� �� ������";
			break;
		}
		if (enter == '5')
		{
			system("cls");
			SortingRecordList(number);
			break;
		}
		if (enter == '6')
		{
			system("cls");
			cout << " ������� ������." << endl << endl;

			int count = 1;
			string buffer;

			string filename = "Buffer\\bufferWrite.txt";
			string filename1 = "Buffer\\bufferRead.txt";
			string filesNum = "Number\\number.txt";
			string del;


			// ����� ���������� �������� ���� ��������� ������. ��������
			for (int i = 0; i <= number; i++)
			{
				buffer = to_string(count);
				del = buffer + ".txt";
				remove(del.c_str()) == 0;

				count++;
			}

			if (remove(filename.c_str()) == 0 && remove(filename1.c_str()) == 0)
			{
					cout << " ���� ������� ������, ���������� ��������� ";
					Sleep(700);
					cout << " .";
					Sleep(700);
					cout << " .";
					Sleep(700);
					cout << " .";
					Sleep(700);
					cout << " ." << endl;

					ofstream filesNum;
					filesNum.open(L"Number\\number.txt", ios::out);
					filesNum << numb;
					filesNum.close();

					cout << " ������ ������� ������.";
			}
			else
			{
				cout << " ��� ������ ��� ��������." << endl;
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

			Sleep(1000);
			system("cls");

			Menu();
			break;
		}

		if (enter == '7')
		{
			system("cls");
			cout << " ������� ������." << endl << endl;
			Sleep(1000);
			system("cls");
			break;
		}
		if (enter > '7' || enter == '0')
		{
			cout << " ������� �������� ��������. ���������� ��� ��� " << endl;
			continue;
		}

	} while (true);
}

