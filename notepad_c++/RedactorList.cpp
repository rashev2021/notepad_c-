#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Default.h"

using namespace std;

void RedactorList(int del)
{

	cout << endl << " �������� ������." << endl;

	static char buff[1024][1024];
	int i = 0;
	char priorityes;
	string high = "�������";
	string avarage = "�������";
	string low = "������";

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
		document.priority = 1;
		cout << " ������ ��������� - �������." << endl;
		document.prioritet = const_cast<char*>(high.c_str());
		RedactorListEnd(del, document);
		break;
	case '2':
		document.priority = 2;
		cout << " ������ ��������� - �������." << endl;
		document.prioritet = const_cast<char*>(avarage.c_str());
		RedactorListEnd(del, document);
		break;
	case '3':
		document.priority = 3;
		cout << " ������ ��������� - ������." << endl;
		document.prioritet = const_cast<char*>(low.c_str());
		RedactorListEnd(del, document);
		break;
	default:
		document.priority = 2;
		cout << " ������� �������� ��������. ��������� �� ��������� ����� \"�������\"." << endl;
		document.prioritet = const_cast<char*>(avarage.c_str());
		break;
	}

}

