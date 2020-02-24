//H.I.L.T.
//Filename: hilt.cpp
//Email Address: blkelly@my.milligan.edu
//Term Project
//Description: A tool to allow batch labelling of files in directory
//Version 0.5
//Last Changed: 2/24/2020
#include <iostream>
using namespace std;
//Declaration of Variables
string className, assignmentName, fileDirectory, termName;
int numberStudents, numberAssignments, totalAssignments, fileLocation, classIndication;//fileDirectory is where the actual file is stored while fileLocation is to help build the menu
char userInputNames, userInputClass,userInputAssignment, userInputCalc,UserInputDir;//Variables for single character user inputs
//Declaration of Constants
int const MAX_STUDENTS = 40;//Originally 6, using 40 to allow testing of larger classes
//Declaration of arrays
string studentName[6];//Six is a placeholder value as it is the number of students EENG 221
string classOne[6];//Sample classes(currently not used as studentName is handling its duties at this point, but will be used within the next version or two
string classTwo[28];
string classOneFiles[6] = {"Q12_001", "Q12_002","Q12_003", "Q12_004" "Q12_005", "Q12_006","Q12_007" };//Array with files to rename.
string classTwoFiles[28];//Do not have names for this group of files
//Declartion of functions
void studentNameInput();//Allows for the user to input student names.  
string validator(string input, string desiredInput);
//Precondition: String you want to check and desired string/characters as strings
//Post-Condition: The function compares the two and returns the user input when they are the same as a string
string confirmer(string nameOfInput,string userInput);
//Precondition: What input you need to the user to confirm and what it is called in the program, where the userInput is a string and the name of the variable with type string
//Post-Condition: Returns the confirmed user input as a string.
int main()
{
	//Greeting Message.  Will likely be expanded to add some basic rules/instructions
	cout << "Welcome to H.I.L.T!\n To start we are going to have you input a few basic pieces of information:\n";
	/*This for the calculation part of the assignment.  
	Likely will not last longterm or will be moved to more approriate part of the program. 
	This feature could be reworked for checking to make sure that complete set of assignments have been turned-in/scanned at the end of the year,
	but is unnessacary to the current proposed functionality of the program.  Any thoughts?*/
	termName = "Spring_2020";//Will be replaced with a user input in next version
	cout << "How many students are in this class?\n";
	cin >> numberStudents;
	cout << "Would you like to get an estimate for the amount of files you will have at the end of the semester?\n Type y for yes or n for no\n";
	cin >> userInputCalc;
	userInputCalc = tolower(userInputCalc);
	if (userInputCalc == 'y')
	{
		cout << "How many assignments per student?\n";
		cin >> numberAssignments;
		totalAssignments = numberAssignments * numberStudents;
		cout << "There should be a total of " << totalAssignments << " files this semester for this class.\n";
	}
	//While loop to populate array with student names

	/*This is the section for the user to input the basic information for the labeler.  Text entry will likely not be the ideal input system, 
	especially for file directory and class names, but should be relatively simple to get working and/or replace*/
	//User inputs.  File directory will possibly be reworked into original file directory and the option to move the files while renaming them
	cout << "Now is the time to enter student names into the class list:\n";
	do
	{
		studentNameInput();
		cout << "\n###################################\n Student Names:\n";//Adds a dividing line from the last user input and the computers output
		for (int k = 0; k < MAX_STUDENTS && k < numberStudents; k++)
		{
			cout << studentName[k] << "\n";
		}
		cout << "Are these names correct?\n";
		cin >> userInputNames;
		userInputNames = tolower(userInputNames);
	} while (userInputNames != 'y');
	cout << "What directory do you want to rename files in?\n";
	cout << "1:USB Drive\n";
	cout << "2:Documents\n";
	cout << "3:Custom Location\n";
	cin >> fileLocation;
	switch (fileLocation)
	{
		case 1:
		{
			fileDirectory = "F:\\scannedFiles";
			break;
		}
		case 2:
		{
			fileDirectory = "C:\\Documents";
			break;
		}
		case 3:
			cout << "What file directory do you want to read and write from?\n";
			cin >> fileDirectory;
			validator(fileDirectory, "test");
	}
	//Below are loops for the user to confirm the name of the class and the assignment
	className = confirmer("class", className);
	cout << "Is this Class 1 or Class 2? (Please enter the number)\n";
	cin >> classIndication;
	assignmentName = confirmer("assignment", assignmentName);
	//Final output.
	cout << "Thank you!\n All of the selected files will have this format:\n" << fileDirectory << "\\" << className << "-" << assignmentName << "-firstName-lastName.fileExtension\n";
	//I am just outputting to the console for now, but this will be changed to rename the files
	cout << "Here are the file names:\n";
	switch (classIndication)
	{
		case 1:
		{
			for (int i = 0; i < MAX_STUDENTS && i < numberStudents; i++)
			{
				classOneFiles[i] = fileDirectory + "\\" + className + "-" + termName +"-" + assignmentName + "-" + studentName[i] + ".fileExtension\n";//Add what term it is
				cout << classOneFiles[i];
			}
			break;
		}
		case 2:
		{
			for (int i = 0; i < MAX_STUDENTS && i < numberStudents; i++)
			{
				classTwoFiles[i] = fileDirectory + "\\" + className + "-" + termName+ "-" + assignmentName + "-" + studentName[i] + ".fileExtension\n";
				cout << classTwoFiles[i];
			}
			break;
		}
	}

	return 0;

}
//Function Definition
void studentNameInput() //Allows for student name inputs to be implemented outside of the main function
{
	for (int j = 0; j < MAX_STUDENTS && j < numberStudents; j++)
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

	}return;
}
string validator(string input, string desiredInput)
{
	while (input != desiredInput)
	{
		cout << "Sorry, but " << input << "is not a valid input.  Please try again:\n";
		cin >> input;
	}
	return(input);
}
string confirmer(string nameOfInput, string userInput)
{
	char userConfirmation;
	do
	{
		cout << "Please enter your desired " << nameOfInput << " name (using dashes or underscores for spaces.)\n";
		cin >> userInput;
		cout << "Is this the correct " << nameOfInput<<" name?\n" << userInput << " \n";
		cin >> userConfirmation;
		userConfirmation = tolower(userConfirmation);
	} while (userConfirmation != 'y');
	return userInput;
}
