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

	cout << " У вас имеется " << number << " записи." << endl << endl;
	cout << " Введите номер записи которую хотите удалить. " << endl;

	do
	{
		cout << " Ввести номер от 1 до " << number << ": ";
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
		filesListNumber << " Запись номер: " << document2.contBuf << endl;
		filesListNumber << " Название:     " << document2.nameBuf << endl;
		filesListNumber << " Описание:     " << document2.descriptionBuf << endl;
		filesListNumber << " Приоритет:    " << document2.priorityBuf << endl;
		filesListNumber << " Дата:         " << document2.dateBuf << endl;
		filesListNumber << " ________________ " << endl;
		filesListNumber.close();

		if (del > number || del <= 0)
		{
			cout << " Записи под номером " << del << " нет." << endl;
			cout << " Попробуйте снова. " << endl << endl;
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

			cout << " Изменить запись - нажмите [1]" << endl;
			cout << " Удалить запись  - нажмите [2]" << endl;

			do
			{
				cout << " Выберите действие: ";
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

					cout << " Выполняется удаление записи. Пожалуйста подождите ";

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
						cout << " Ошибка удаления файла. " << endl;
					}

					number--;


					// здесь  не происходит удаление определенного файла. Он остается в папке.

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

					cout << endl << " Запись успешно удалена. " << endl << endl;
					Sleep(700);

					system("cls");
					Menu();
					break;
				}
				else
				{
					cout << " Введено неверное значение. Повторите попытку" << endl;
					continue;
				}

			} while (true);
		}

	} while (true);

}