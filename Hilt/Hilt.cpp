//H.I.L.T.
//
#include <iostream>
using namespace std;
//Declaration of Variables
string className, assignmentName, fileDirectory;
int numberStudents, numberAssignments, totalAssignments;
char userInput;
int main()
{
	//Greeting Message.  Will likely be expanded to add some basic rules/instructions
	cout << "Welcome to H.I.L.T!\n To start we are going to have you input a few basic pieces of information:\n";
	/*This for the calculation part of the assignment.  
	Likely will not last longterm or will be moved to more approriate part of the program. 
	This feature could be reworked for checking to make sure that complete set of assignments have been turned-in/scanned at the end of the year,
	but is unnessacary to the current proposed functionality of the program.  Any thoughts?*/
	cout << "Would you like to get an estimate for the amount of files you will have at the end of the semester?\n Type y for yes or anything else for no\n";
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

	/*This is the section for the user to input the basic information for the labeler.  Text entry will likely not be the ideal input system, 
	especially for file directory and class names, but should be relatively simple to get working and/or replace*/
	//User inputs.  File directory will possibly be reworked into original file directory and the option to move the files while renaming them
	cout << "What directory do you want to rename files in?\n";
	cin >> fileDirectory;
	while (fileDirectory != "test")
	{
		cout << "Sorry, " << fileDirectory << " is not a valid directory. \n";
		cin >> fileDirectory;
	}
	cout << "What is the name of the class (using dashes or underscores for spaces)?\n";
	cin >> className;
	cout << "What assignment is this(using dashes or underscores for spaces)?\n";
	cin >> assignmentName;
	//Final output.
	cout << "Thank you!\n All of the selected files will have this format:\n" << fileDirectory << "\\" << className << "-" << assignmentName << "-firstName-lastName.fileExtension\n";
	return 0;
};