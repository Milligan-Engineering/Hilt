#include "classInfo.h"
#include<fstream>
#include<iostream>
#include<Windows.h>
using namespace std;
void classInfo::ingest()
{
	cout << "What is the class name?  Use enter to finish entry\n";
	cin.ignore();
	cin.get(name, 100);
	cout << "What term is this? Use enter to finish entry\n";
	cin.ignore();
	cin.getline(term, 100);
}