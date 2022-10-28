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
	cout << " Поиск записей." << endl;
	cout << " ______________________ " << endl;
	cout << " 1. Найти запись по названию     - нажмите [1]" << endl;
	cout << " 2. Найти запись по приоритету   - нажмите [2]" << endl;
	cout << " 3. Найти запись по описанию     - нажмите [3]" << endl;
	cout << " 4. Найти запись по дате         - нажмите [4]" << endl;
	cout << " 5. Вернуться в меню             - нажмите [5]" << endl;

	string filename = "Buffer\\bufferReadName.txt";

	if (remove(filename.c_str()) == 0)
	{
		cout << endl << " Обновление списка. Пожалуйста подождите ";

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

	int next = 0;
	bool temp = false;

	char num;

	do
	{

		cout << endl << " Выберите нужный пункт: ";
		cin >> num;


		switch (num)
		{
		case '1':
			system("cls");
			SearchListName(number, next, temp, document2);
			break;
		case '2':
			system("cls");
			SearchListPriority(number, next, temp, document2);
			break;
		case '3':
			system("cls");
			SearchListDescription(number, next, temp, document2);
			break;
		case '4':
			system("cls");
			SearchListData(number, next, temp, document2);
			break;
		case '5':
			system("cls");
			Menu();
			break;
		default:
			cout << endl << " Введены неверные значения. Попробуйте еще раз." << endl;
			break;
		}

	} while (true);
}

void SearchListName(int number, int next, bool temp, Data2 document2)
{

	if (number == 0)
	{
		cout << endl << " Нет записей для поиска" << endl;

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

	cout << " Список записей по названию." << endl;
	cout << " Введите название записи: ";
	cin.get();
	gets_s(document3.nameBufS, 150);

	int count = 1;
	char* tempi;

	ofstream files;

	//Замена пробелов в структуре на '_'
	while (tempi = strchr(document3.nameBufS, ' '))
	{
		*tempi = '_';
		strcpy_s(document3.nameBufS + (strlen(document3.nameBufS) - strlen(tempi)), strlen(document3.nameBufS), tempi);
	}

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

		if (strcmp(document2.nameBuf, document3.nameBufS) == 0)
		{
			files.open(L"Buffer\\bufferReadName.txt", ios::app);
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
		
		system("cls");
		cout << " Выведен список записей по названию: " << document3.nameBufS << endl;

		ifstream files(L"Buffer\\bufferReadName.txt");

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
		cout << endl << " Нет записей под названием: " << document3.nameBufS << endl;
		cout << " Либо название введено не верно или не полностью" << endl;
		ReturnMenu();
	}
	
}

void SearchListPriority(int number, int next, bool temp, Data2 document2)
{

	if (number == 0)
	{
		cout << endl << " Нет записей для поиска" << endl;

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

	cout << " Список записей по приоритету." << endl;
	cout << " Введите приоритет записи (Высокий, Средний, Низкий): ";
	cin.get();
	gets_s(document3.prioritetBufS, 150);

	int count = 1;

	ofstream files;

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

		if (strcmp(document2.prioritetBuf, document3.prioritetBufS) == 0)
		{
			files.open(L"Buffer\\bufferReadPriority.txt", ios::app);
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

		system("cls");
		cout << " Выведен список записей по приоритету: " << document3.prioritetBufS << endl;
	

		ifstream files(L"Buffer\\bufferReadPriority.txt");


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
		cout << endl << " Нет записей под приоритетом: " << document3.prioritetBufS << endl;
		cout << " Либо приоритет введен не верно." << endl;
		ReturnMenu();
	}

}

void SearchListDescription(int number, int next, bool temp, Data2 document2)
{

	if (number == 0)
	{
		cout << endl << " Нет записей для поиска" << endl;

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

	cout << " Список записей по описанию." << endl;
	cout << " Введите описание записи: ";
	cin.get();
	gets_s(document3.descriptionBufS, 150);

	int count = 1;
	char* tempi;

	ofstream files;

	//Замена пробелов в структуре на '_'
	while (tempi = strchr(document3.descriptionBufS, ' '))
	{
		*tempi = '_';
		strcpy_s(document3.descriptionBufS + (strlen(document3.descriptionBufS) - strlen(tempi)), strlen(document3.descriptionBufS), tempi);
	}

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

		if (strcmp(document2.descriptionBuf, document3.descriptionBufS) == 0)
		{
			files.open(L"Buffer\\bufferReadName.txt", ios::app);
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

		system("cls");
		cout << " Выведен список записей по описанию: " << document3.descriptionBufS << endl;

		ifstream files(L"Buffer\\bufferReadName.txt");

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
		cout << endl << " Нет записей по описанию: " << document3.descriptionBufS << endl;
		cout << " Либо описание введено не верно или не полностью" << endl;
		ReturnMenu();
	}
}

void SearchListData(int number, int next, bool temp, Data2 document2)
{
	if (number == 0)
	{
		cout << endl << " Нет записей для поиска" << endl;

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

	cout << " Список записей по дате." << endl;
	cout << " Введите дату создания записи(28.10.2022 / 16:6:36): ";
	cin.get();
	gets_s(document3.dateBufS, 150);

	int count = 1;
	char* tempi;

	ofstream files;

	//Замена пробелов в структуре на '_'
	while (tempi = strchr(document3.dateBufS, ' '))
	{
		*tempi = '_';
		strcpy_s(document3.dateBufS + (strlen(document3.dateBufS) - strlen(tempi)), strlen(document3.dateBufS), tempi);
	}

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

		if (strcmp(document2.dateBuf, document3.dateBufS) == 0)
		{
			files.open(L"Buffer\\bufferReadName.txt", ios::app);
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

		system("cls");
		cout << " Выведен список записей по дате: " << document3.dateBufS << endl;

		ifstream files(L"Buffer\\bufferReadName.txt");

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
		cout << endl << " Нет записей по дате: " << document3.dateBufS << endl;
		cout << " Либо дата введена не верно или не полностью" << endl;
		ReturnMenu();
	}

	ReturnMenu();
}