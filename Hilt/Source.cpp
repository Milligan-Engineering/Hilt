#include <iostream>
using namespace std;
//Declaration of Variables
string fileDirectory, assignmentName, className;
int i = 0, j=0, k=0;//Counter Variable
//Create Functions for storing of variables
string directoryEntry(int x)
{
	if (x == 0)
	{
		cout << "What File Directory do you want to edit?\n";
		cin >> fileDirectory;
		i++;
		//return i;
		return fileDirectory;
	}
	else
	{
		cout << "Please enter correct File Directory.\n";
		cin >> fileDirectory;
		return fileDirectory;
	}
	//return i
};
string classEntry(int x)
{
	if (x == 0)
	{
		cout << "What is the class name?\n";
		cin >> className;
		j++;
		return className;
	}
	else
	{
		cout << "Please enter correct name\n";
		cin >> className;
		return className;
	}
};
string assignEntry(int x)
{
	if (x == 0)
	{
		cout << "What is the assignment name?\n";
		cin >> assignmentName;
		k++;
		return assignmentName;
	}
	else
	{
		cout << "Please enter correct name\n";
		cin >> assignmentName;
		return assignmentName;
	}
};
int main()
{
	cout << "Welcome to H.I.L.T.: ";
	string userAnswerClass,userAnswerAssignment,userAnswerDir;
	//Store User input in variables
	classEntry(j);
	assignEntry(k);
	directoryEntry(i);
	cout << "You entered " << fileDirectory << ".  Enter Yes if this is the correct file directory?\n";
	cin >> userAnswerDir;
	if (userAnswerDir != "Yes") {
		directoryEntry(i);
		cout << "Thank You\n";
	}
	else
	{
		cout << "Thank You\n";
	};
	cout << "You entered:\n" << "Class Name: " << className << endl << "Assignment Name: " << assignmentName << endl << "File Location: " << fileDirectory << endl;
};