#include "stdafx.h"
#include "classInfo.h"

classInfo::classInfo()
{

}
void classInfo::ingest()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "What is the class name?  Use enter to finish entry\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cin.ignore();
	cin.get(name, 100);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "What term is this? Use enter to finish entry\n";
	cin.ignore();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cin.getline(term, 100);
};
const char* classInfo::getName()
{
	return name;
};
void classInfo::setName(char newName[], int arraySize)
{
	strcpy_s(name, newName);

};
const char* classInfo::getTerm()
{
	return term;
}
void classInfo::setTerm(char newTerm[], int arraySize)
{
	strcpy_s(name, newTerm);
};
