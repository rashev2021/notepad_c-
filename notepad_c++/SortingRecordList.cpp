#include <Windows.h>
#include "Default.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static char buff[1024][1024];
string buffer;
int i = 0;

Data2 document2;

void SortingRecordList(int number)
{

	string filename = "Buffer\\bufferReadSorting.txt";

	char c;
	int next = 0;
	bool temp = false;

	if (remove(filename.c_str()) == 0)
	{
		cout << endl << " " << " Обновление списка ";

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

	if (number == 0)
	{
		cout << endl << " Вы не создали ни одной записи для сортировки." << endl;

		Sleep(1000);
		cout << " Сейчас вы будете перенаправлены в меню";

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
		do
		{
			cout << " Выберите приоритет записи: " << endl << endl;
			cout << "   " << " Высокий - нажмите [1]" << endl;
			cout << "   " << " Средний - нажмите [2]" << endl;
			cout << "   " << " Низкий  - нажмите [3]" << endl << endl;
			cout << " Введите 1, 2 или 3: ";

			cin >> c;

			switch (c)
			{
			case '1':
				system("cls");
				SortingHigh(number, next, temp);
				break;
			case '2':
				system("cls");
				SortingAvarage(number, next, temp);
				break;
			case '3':
				system("cls");
				SortingLow(number, next, temp);
				break;
			default:
				cout << endl << " Введены неверные значения. Попробуйте еще раз." << endl;
				break;
			}
		} while (true);

	} 

}

void SortingHigh(int number, int next, bool temp)
{
	cout << " Список отсортирован по приоритету - Высокий" << endl;

	int count = 1;

	for (int j = 1; j <= number; j++)
	{
		buffer = to_string(count);

		ifstream filesWriteListNumber(buffer + ".txt");
		filesWriteListNumber >> document2.contBuf;
		filesWriteListNumber >> document2.nameBuf;
		filesWriteListNumber >> document2.descriptionBuf;
		filesWriteListNumber >> document2.prioritetBuf;
		filesWriteListNumber >> document2.dateBuf;
		filesWriteListNumber >> document2.fileNumPr;

		if (document2.fileNumPr == 1)
		{
			ofstream files;
			files.open(L"Buffer\\bufferReadSorting.txt", ios::app);
			files << endl;
			files << " Запись номер: " << document2.contBuf << endl;
			files << " Название:     " << document2.nameBuf << endl;
			files << " Описание:     " << document2.descriptionBuf << endl;
			files << " Приоритет:    " << document2.prioritetBuf << endl;
			files << " Дата:         " << document2.dateBuf << endl;
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

		ifstream files(L"Buffer\\bufferReadSorting.txt");

		while (!files.eof())
		{
			files.getline(buff[i], sizeof(buff));
			cout << buff[i] << endl;
			++i;
		}

		files.close();
	}

	if (next == 1)
	{
		cout << " Нет записей под этим приоритетом." << endl;
		ReturnMenu();
	}

	ReturnMenu();
}

void SortingAvarage(int number, int next, bool temp)
{
	cout << " Список отсортирован по приоритету - Средний" << endl;

	int count = 1;

	for (int j = 1; j <= number; j++)
	{
		buffer = to_string(count);

		ifstream filesWriteListNumber(buffer + ".txt");
		filesWriteListNumber >> document2.contBuf;
		filesWriteListNumber >> document2.nameBuf;
		filesWriteListNumber >> document2.descriptionBuf;
		filesWriteListNumber >> document2.prioritetBuf;
		filesWriteListNumber >> document2.dateBuf;
		filesWriteListNumber >> document2.fileNumPr;

		if (document2.fileNumPr == 2)
		{
			ofstream files;
			files.open(L"Buffer\\bufferReadSorting.txt", ios::app);
			files << endl;
			files << " Запись номер: " << document2.contBuf << endl;
			files << " Название:     " << document2.nameBuf << endl;
			files << " Описание:     " << document2.descriptionBuf << endl;
			files << " Приоритет:    " << document2.prioritetBuf << endl;
			files << " Дата:         " << document2.dateBuf << endl;
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

		ifstream files(L"Buffer\\bufferReadSorting.txt");

		while (!files.eof())
		{
			files.getline(buff[i], sizeof(buff));
			cout << buff[i] << endl;
			++i;
		}

		files.close();
	}

	if (next == 1)
	{
		cout << " Нет записей под этим приоритетом." << endl;
		ReturnMenu();
	}

	ReturnMenu();
}

void SortingLow(int number, int next, bool temp)
{
	cout << " Список отсортирован по приоритету - Низкий" << endl;

	int count = 1;

	for (int j = 1; j <= number; j++)
	{
		buffer = to_string(count);

		ifstream filesWriteListNumber(buffer + ".txt");
		filesWriteListNumber >> document2.contBuf;
		filesWriteListNumber >> document2.nameBuf;
		filesWriteListNumber >> document2.descriptionBuf;
		filesWriteListNumber >> document2.prioritetBuf;
		filesWriteListNumber >> document2.dateBuf;
		filesWriteListNumber >> document2.fileNumPr;

		if (document2.fileNumPr == 3)
		{
			ofstream files;
			files.open(L"Buffer\\bufferReadSorting.txt", ios::app);
			files << endl;
			files << " Запись номер: " << document2.contBuf << endl;
			files << " Название:     " << document2.nameBuf << endl;
			files << " Описание:     " << document2.descriptionBuf << endl;
			files << " Приоритет:    " << document2.prioritetBuf << endl;
			files << " Дата:         " << document2.dateBuf << endl;
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

		ifstream files(L"Buffer\\bufferReadSorting.txt");

		while (!files.eof())
		{
			files.getline(buff[i], sizeof(buff));
			cout << buff[i] << endl;
			++i;
		}

		files.close();
	}

	if (next == 1)
	{
		cout << " Нет записей под этим приоритетом." << endl;
		ReturnMenu();
	}

	ReturnMenu();
}

