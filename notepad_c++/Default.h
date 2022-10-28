#pragma once

struct Data1
{
	char* name = new char[150];
	char* description = new char[150];
	int priority = 0;
	int day = 0;
	int month = 0;
	char* prioritet{};
};

struct Data2
{
	char* contBuf = new char[100];
	char* nameBuf = new char[100];
	char* descriptionBuf = new char[100];
	char* priorityBuf = new char[100];
	char* prioritetBuf = new char[100];
	char* dateBuf = new char[100];
	int fileNumPr = 0;
	int fileNumDay = 0;
	int fileNumMonth = 0;
	
};

struct Data3
{
	char* contBufS = new char[100];
	char* nameBufS = new char[100];
	char* descriptionBufS = new char[100];
	char* priorityBufS = new char[100];
	char* prioritetBufS = new char[100];
	char* dateBufS = new char[100];
	int fileNumPrS = 0;
	int fileNumDayS = 0;
	int fileNumMonthS = 0;

};

void Menu();
void NewRecordList(int number);
void NewList(int number, Data1 document);
void PreviewRecordList();
void ReturnMenu();
void ReadRecordList(int number);
void ReadRecordListVisible(int number);
void MenuList(int number);
void ListForTheDay(int number);
void ListForTheWeek(int number);
void ListForTheMonth(int number);
void SortingRecordList(int number);
void SortingHigh(int number, int next, bool temp);
void SortingAvarage(int number, int next, bool temp);
void SortingLow(int number, int next, bool temp);
void DeleteRedactorList(int number);
void RedactorList(int del);
void RedactorListEnd(int number, Data1 document);
void SearchList(int number, Data2 document2);
void SearchListName(int number, int next, bool temp, Data2 document2);
void SearchListPriority(int number, int next, bool temp, Data2 document2);
void SearchListDescription(int number, int next, bool temp);
void SearchListData(int number, int next, bool temp);

