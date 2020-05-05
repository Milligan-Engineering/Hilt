#pragma once
class classInfo
{
public:
	classInfo();
	void ingest();
	const char* getName();
	//Precondition: None; Accessor
	//Postcondition: The class name is returned
	void setName(char newName[],int arraySize);
	//Precondition: Enter new name for for the name of a class
	//Postcondition: The class name is now set to the entered name
	const char* getTerm();
	//Precondition: None; Accessor
	//Postcondition: The term name is returned
	void setTerm(char newTerm[],int arraySize);
	//Precondition: Enter new name for for the name of a term
	//Postcondition: The term name is now set to the entered name
private:
	char name[100];
	char term[100];
};