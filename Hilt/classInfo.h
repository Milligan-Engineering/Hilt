#pragma once
class classInfo
{
public:
	classInfo();
	void ingest();
	char* getName();
	void setName(char newName[],int arraySize);
	char* getTerm();
	void setTerm(char newTerm[],int arraySize);
private:
	char name[100];
	char term[100];
};