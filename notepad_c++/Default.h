#pragma once

struct Data1
{
	char name[150]{};
	char description[150]{};
	int priority = 0;
	char prioritet[150]{};
	/*char date[150];*/

};

void Menu();
void NewRecordList(int number);
void NewList(int number);
void PreviewRecordList();

