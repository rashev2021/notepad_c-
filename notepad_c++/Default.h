#pragma once

struct Data1
{
	char* name = new char[150];
	char* description = new char[150];
	int priority = 0;
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
	
};

void Menu();
void NewRecordList(int number);
void NewList(int number, Data1 document);
void PreviewRecordList();
void ReturnMenu();
void ReadRecordList(int number);
void SortingRecordList(int number);
void SortingHigh(int number, int next, bool temp);
void SortingAvarage(int number, int next, bool temp);
void SortingLow(int number, int next, bool temp);
void DeleteRedactorList(int number);
void RedactorList(int del);
void RedactorListEnd(int number, Data1 document);

