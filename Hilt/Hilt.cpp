//H.I.L.T.
//Filename: hilt.cpp
//Email Address: blkelly@my.milligan.edu
//Term Project
//Description: A tool to allow batch labelling of files in directory
//Version 0.3
//Last Changed: 2/6/2020
#include <iostream>
using namespace std;
//Declaration of Variables
string className, assignmentName, fileDirectory;
int numberStudents, numberAssignments, totalAssignments, fileLocation;//fileDirectory is where the actual file is stored while fileLocation is to help build the menu
char userInput;
int const MAX_STUDENTS = 6;
//Declaration of array
string studentName[6];//Six is a placeholder value as it is the number of students EENG 221
int main()
{
	//Greeting Message.  Will likely be expanded to add some basic rules/instructions
	cout << "Welcome to H.I.L.T!\n To start we are going to have you input a few basic pieces of information:\n";
	/*This for the calculation part of the assignment.  
	Likely will not last longterm or will be moved to more approriate part of the program. 
	This feature could be reworked for checking to make sure that complete set of assignments have been turned-in/scanned at the end of the year,
	but is unnessacary to the current proposed functionality of the program.  Any thoughts?*/
	cout << "Would you like to get an estimate for the amount of files you will have at the end of the semester?\n Type y for yes or n for no\n";
	cin >> userInput;
	if (userInput == 'y')
	{
		cout << "How many students are in this class?\n";
		cin >> numberStudents;
		cout << "How many assignments per student?\n";
		cin >> numberAssignments;
		totalAssignments = numberAssignments * numberStudents;
		cout << "There should be a total of " << totalAssignments << " files this semester for this class.\n";
	}
	//While loop to populate array with student names
	for(int j=0;j<MAX_STUDENTS;j++)
	{
		if (j == 0)
		{
			cout << "What is the first student's name?\n";
			cin >> studentName[j];
		}
		else
		{
			cout << "What is the next students name?\n";
			cin >> studentName[j];
		}

	}
	/*This is the section for the user to input the basic information for the labeler.  Text entry will likely not be the ideal input system, 
	especially for file directory and class names, but should be relatively simple to get working and/or replace*/
	//User inputs.  File directory will possibly be reworked into original file directory and the option to move the files while renaming them
	cout << "What directory do you want to rename files in?\n";
	cout << "1:USB Drive\n";
	cout << "2:Documents\n";
	cout << "3:Custom Location\n";
	cin >> fileLocation;
	switch (fileLocation)
	{
		case 1:
		{
			fileDirectory = "F:\scannedFiles";
			break;
		}
		case 2:
		{
			fileDirectory = "C:\Documents";
			break;
		}
		case 3:
			cout << "What file directory do you want to read and write from?\n";
			cin >> fileDirectory;
			while (fileDirectory != "test")
			{
				cout << "Sorry, " << fileDirectory << " is not a valid directory. \n";
				cin >> fileDirectory;
			}
	}
	cout << "What is the name of the class (using dashes or underscores for spaces)?\n";
	cin >> className;
	cout << "What assignment is this(using dashes or underscores for spaces)?\n";
	cin >> assignmentName;
	//Final output.
	cout << "Thank you!\n All of the selected files will have this format:\n" << fileDirectory << "\\" << className << "-" << assignmentName << "-firstName-lastName.fileExtension\n";
	//I am just outputting to the console for now, but this will be changed to rename the files
	cout << "Here are the file names:\n";
	for(int i=0;i<MAX_STUDENTS;i++)
	{
		cout << fileDirectory << "\\" << className << "-" << assignmentName << "-" << studentName[i] << ".fileExtension\n";
	}
	return 0;
};