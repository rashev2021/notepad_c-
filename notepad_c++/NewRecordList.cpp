#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Default.h"

using namespace std;

void NewRecordList(int number)
{

	char priorityes;
	string high = "�������";
	string avarage = "�������";
	string low = "������";
	Data1 document;

	cout << " �������� ����� ������." << endl << endl;

	number++;

	cout << " ������� �������� ������: ";
	cin.get();
	gets_s(document.name, 150);

	cout << " ������� �������� ������: ";
	gets_s(document.description, 150);

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
		// ����������� ������� high � ������� ����������
		document.prioritet = const_cast<char*>(high.c_str());
		cout << " ������ ��������� - �������." << endl;
		NewList(number, document);
		break;
	case '2':
		document.priority = 2;
		// ����������� ������� avarage � ������� ����������
		document.prioritet = const_cast<char*>(avarage.c_str());
		cout << " ������ ��������� - �������." << endl;
		NewList(number, document);
		break;
	case '3':
		document.priority = 3;
		// ����������� ������� low � ������� ����������
		document.prioritet = const_cast<char*>(low.c_str());
		cout << " ������ ��������� - ������." << endl;
		NewList(number, document);
		break;
	default:
		cout << " ������� �������� ��������. ��������� �� ��������� ����� \"�������\"." << endl;
		document.priority = 2;
		// ����������� ������� avarage � ������� ����������
		document.prioritet = const_cast<char*>(avarage.c_str());
		NewList(number, document);
		break;
	}

}
