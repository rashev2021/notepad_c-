#include <Windows.h>
#include <iostream>
#include <fstream>
#include "Default.h"
#include <string>

using namespace std;

void Menu()
{
	cout << " Список дел " << endl;
	cout << " ______________________ " << endl;
	cout << " 1. Добавить новую запись             - нажмите [1]" << endl;
	cout << " 2. Редактировать или удалить запись  - нажмите [2]" << endl;
	cout << " 3. Отобразить текущие записи         - нажмите [3]" << endl;
	cout << " 4. Найти запись из списка            - нажмите [4]" << endl;
	cout << " 5. Отсортировать список              - нажмите [5]" << endl;
	cout << " 6. Очистить весь список              - нажмите [6]" << endl;
	cout << " 7. Закрыть блокнот                   - нажмите [7]" << endl;

	char enter;
	int number = 0;
	int numb = 0;
	string w = "0";

	// Создаем папки в деректории
	wstring Num = L"Number";
	CreateDirectoryW(Num.c_str(), NULL);
	wstring Buf = L"Buffer";
	CreateDirectoryW(Buf.c_str(), NULL);

	// Считываем номер записи из файла
	ifstream filesNumber(L"Number\\number.txt");
	// Записываем данные файла в переменную number
	filesNumber >> number;

	////Создаем файл
	//ofstream filesNumber;
	//filesNumber.open(L"Buffer\\bufferRead.txt", ios::out);
	//filesNumber >> w;
	//filesNumber.close();

	do
	{
		cout << endl << " Выберите нужный пункт: ";
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
				cout << " У вас нет записей для редактирования и удаления" << endl;

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
			cout << " Метод не создан";
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
			cout << " Очистка списка." << endl << endl;

			int count = 1;
			string buffer;

			string filename = "Buffer\\bufferWrite.txt";
			string filename1 = "Buffer\\bufferRead.txt";
			string filesNum = "Number\\number.txt";
			string del;


			// здесь происходит удаление всех созданных файлов. Работает
			for (int i = 0; i <= number; i++)
			{
				buffer = to_string(count);
				del = buffer + ".txt";
				remove(del.c_str()) == 0;

				count++;
			}

			if (remove(filename.c_str()) == 0 && remove(filename1.c_str()) == 0)
			{
					cout << " Идет очистка списка, пожалуйста подождите ";
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

					cout << " Список успешно очищен.";
			}
			else
			{
				cout << " Нет данных для удаления." << endl;
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

			Sleep(1000);
			system("cls");

			Menu();
			break;
		}

		if (enter == '7')
		{
			system("cls");
			cout << " Блокнот закрыт." << endl << endl;
			Sleep(1000);
			system("cls");
			break;
		}
		if (enter > '7' || enter == '0')
		{
			cout << " Введены неверные значения. Попробуйте ещё раз " << endl;
			continue;
		}

	} while (true);
}

