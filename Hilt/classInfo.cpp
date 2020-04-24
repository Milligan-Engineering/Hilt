#include "stdafx.h"
#include "classInfo.h"

classInfo::classInfo()
{

}
void classInfo::ingest()
{
	cout << "What is the class name?  Use enter to finish entry\n";
	cin.ignore();
	cin.get(name, 100);
	cout << "What term is this? Use enter to finish entry\n";
	cin.ignore();
	cin.getline(term, 100);
};