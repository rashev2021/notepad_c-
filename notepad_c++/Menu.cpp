#include <Windows.h>
#include <iostream>
#include <fstream>
#include "Default.h"

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

	// ������� ����� � ����������
	/*wstring Doc = L"Document";
	CreateDirectoryW(Doc.c_str(), NULL);*/
	wstring Num = L"Number";
	CreateDirectoryW(Num.c_str(), NULL);
	wstring Buf = L"Buffer";
	CreateDirectoryW(Buf.c_str(), NULL);

	// ��������� ����� ������ �� �����
	ifstream filesNumber(L"Number\\number.txt");
	// ���������� ������ ����� � ���������� number
	filesNumber >> number;

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
				/*deleteRecordList(number);*/
			}

			break;
		}
		if (enter == '3')
		{
			system("cls");
			/*readRecordList(number);*/
			cout << " ����� �� ������";
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
			/*sortRecordList(number);*/
			cout << " ����� �� ������";
			break;
		}
		if (enter == '6')
		{
			//system("cls");
			//cout << " ������� ������." << endl << endl;

			//int count = 1;
			//string buffer;

			string filename = "bufferWrite.txt";
			//string filesNum = "number.txt";
			//string del;


			//// ����� ���������� �������� ���� ��������� ������. ��������
			//for (int i = 0; i <= number; i++)
			//{
			//	buffer = to_string(count);
			//	del = buffer + ".txt";
			//	remove(del.c_str()) == 0;

			//	count++;
			//}

			if (remove(filename.c_str()) == 0)
			{
				//	cout << " ���� ������� ������, ���������� ��������� ";
				//	Sleep(700);
				//	cout << " .";
				//	Sleep(700);
				//	cout << " .";
				//	Sleep(700);
				//	cout << " .";
				//	Sleep(700);
				//	cout << " ." << endl;

				//	ofstream filesNum;
				//	filesNum.open("number.txt", ios::out);
				//	filesNum << numb;
				//	filesNum.close();

				//	cout << " ������ ������� ������.";
				cout << " ����� �� ������";
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

void NewRecordList()
{
}
