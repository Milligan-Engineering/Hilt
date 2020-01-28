#include <iostream>
using namespace std;
//Declaration of Variables
string fileDirectory, assignmentName, className;
int i = 0;//Counter Variable
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
int main()
{
	string userAnswer;
	//Store User input in variables
	directoryEntry(i);
	cout << "You entered " << fileDirectory << ".  Enter Yes if this is the correct file directory?\n";
	cin >> userAnswer;
	if (userAnswer != "Yes") {
		directoryEntry(i);
		cout << "Thank You\n";
	}
	else
	{
		cout << "Thank You";
	}
	//Create
};