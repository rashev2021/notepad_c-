#include <Windows.h>
#include "Default.h"
#include <synchapi.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

void ReadRecordList(int number)
{

	static char buff[1024][1024];
	int i = 0;
	int count = 1;
	string buffer;
	Data2 document2;

	//Очищаем данные в файле bufferRead
	string filename = "Buffer\\bufferRead.txt";

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

	for (int j = 1; j <= number; j++)
	{
		buffer = to_string(count);

		//считывам текстовые файлы один за одним и записываем их в структуру Date2
		ifstream filesWriteListNumber(buffer + ".txt");
		filesWriteListNumber >> document2.contBuf;
		filesWriteListNumber >> document2.nameBuf;
		filesWriteListNumber >> document2.descriptionBuf;
		filesWriteListNumber >> document2.prioritetBuf;
		filesWriteListNumber >> document2.dateBuf;
		
		ofstream files;

		// записываем даные из структуры Date2 в файл bufferRaed по порядку
		files.open(L"Buffer\\bufferRead.txt", ios::app);
		files << endl;
		files << " Запись номер: " << document2.contBuf << endl;
		files << " Название:     " << document2.nameBuf << endl;
		files << " Описание:     " << document2.descriptionBuf << endl;
		files << " Приоритет:    " << document2.prioritetBuf << endl;
		files << " Дата:         " << document2.dateBuf << endl;;

		files << " ________________ " << endl;
		files.close();

		count++;
	}

	cout << " Список: " << endl;

	// считываем файл и выводим на экран
	ifstream files(L"Buffer\\bufferRead.txt");

	if (!files.is_open() == true)
	{
		cout << endl << " Вы не создали ни одной записи" << endl;

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
		while (!files.eof())
		{
			files.getline(buff[i], sizeof(buff));
			cout << buff[i] << endl;
			++i;
		}
		files.close();
	}

	ReturnMenu();
}