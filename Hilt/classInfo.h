#pragma once
class classInfo
{
public:
	classInfo();
	void ingest();
	const char* getName();
	void setName(char newName[],int arraySize);
	const char* getTerm();
	void setTerm(char newTerm[],int arraySize);
private:
	char name[100];
	char term[100];
};