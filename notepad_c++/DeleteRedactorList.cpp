#include <Windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include "Default.h"


using namespace std;

void DeleteRedactorList(int number)
{

	static char buff[1024][1024];
	int del;
	int i = 0;
	char removeRedactor;
	string fileName;

	Data2 document2;

	cout << " � ��� ������� " << number << " ������." << endl << endl;
	cout << " ������� ����� ������ ������� ������ �������. " << endl;

	do
	{
		cout << " ������ ����� �� 1 �� " << number << ": ";
		cin >> del;
		fileName = to_string(del);

		ifstream filesNumRead(fileName + ".txt");
		filesNumRead >> document2.contBuf;
		filesNumRead >> document2.nameBuf;
		filesNumRead >> document2.descriptionBuf;
		filesNumRead >> document2.priorityBuf;
		filesNumRead >> document2.dateBuf;

		ofstream filesListNumber;
		filesListNumber.open(L"Buffer\\bufferDelete.txt", ios::out);
		filesListNumber << endl;
		filesListNumber << " ________________ " << endl << endl;
		filesListNumber << " ������ �����: " << document2.contBuf << endl;
		filesListNumber << " ��������:     " << document2.nameBuf << endl;
		filesListNumber << " ��������:     " << document2.descriptionBuf << endl;
		filesListNumber << " ���������:    " << document2.priorityBuf << endl;
		filesListNumber << " ����:         " << document2.dateBuf << endl;
		filesListNumber << " ________________ " << endl;
		filesListNumber.close();

		if (del > number || del <= 0)
		{
			cout << " ������ ��� ������� " << del << " ���." << endl;
			cout << " ���������� �����. " << endl << endl;
			continue;
		}

		else
		{

			ifstream filesListNumber(L"Buffer\\bufferDelete.txt");

			while (!filesListNumber.eof())
			{
				filesListNumber.getline(buff[i], sizeof(buff));
				cout << buff[i] << endl;
				++i;
			}
			filesListNumber.close();

			cout << " �������� ������ - ������� [1]" << endl;
			cout << " ������� ������  - ������� [2]" << endl;

			do
			{
				cout << " �������� ��������: ";
				cin >> removeRedactor;

				if (removeRedactor == '1')
				{
					system("cls");
					RedactorList(del);
					break;
				}
				if (removeRedactor == '2')
				{
					string buffer;
					string delt;

					cout << " ����������� �������� ������. ���������� ��������� ";

					string bufDel = "Buffer\\bufferDelete.txt";

					if (remove(bufDel.c_str()) == 0)
					{
						Sleep(700);
						cout << " .";
						Sleep(700);
						cout << " .";
						Sleep(700);
						cout << " .";
						Sleep(700);
						cout << " ." << endl;

					}
					else
					{
						cout << " ������ �������� �����. " << endl;
					}

					number--;


					// �����  �� ���������� �������� ������������� �����. �� �������� � �����.

					for (int i = 0; i <= number; i++)
					{
						buffer = to_string(del);
						delt = buffer + ".txt";
						remove(delt.c_str()) == 0;

					}
				
					ofstream filesNumber;
					filesNumber.open(L"Number\\number.txt", ios::out);
					filesNumber << number;
					filesNumber.close();

					cout << endl << " ������ ������� �������. " << endl << endl;
					Sleep(700);

					system("cls");
					Menu();
					break;
				}
				else
				{
					cout << " ������� �������� ��������. ��������� �������" << endl;
					continue;
				}

			} while (true);
		}

	} while (true);

}