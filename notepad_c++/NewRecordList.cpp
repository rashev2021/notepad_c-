#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "Default.h"



using namespace std;

void NewRecordList(int number)
{

	char priorityes;
	Data1 document;

	cout << " �������� ����� ������." << endl << endl;

	number++;

	cout << " ������� �������� ������: ";
	cin.get();
	gets_s(document.name, 150);

	cout << " ������� �������� ������: ";
	cin.get();
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
		document.prioritet;
		cout << " ������ ��������� - �������." << endl;
		NewList(number);
		break;
	case '2':
		document.priority = 2;
		document.prioritet;
		cout << " ������ ��������� - �������." << endl;
		NewList(number);
		break;
	case '3':
		document.priority = 3;
		document.prioritet;
		cout << " ������ ��������� - ������." << endl;
		NewList(number);
		break;
	default:
		cout << " ������� �������� ��������. ��������� �� ��������� ����� \"�������\"." << endl;
		document.priority = 2;
		document.prioritet;
		NewList(number);
		break;
	}

}
