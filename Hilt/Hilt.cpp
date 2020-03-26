//H.I.L.T.
//Filename: hilt.cpp
//Email Address: blkelly@my.milligan.edu
//Term Project
//Description: A tool to allow batch labelling of files in directory
//Version 0.8
//Last Changed: 3/25/2020
#include <iostream>
#include<fstream>
//#include "C:\Users\weasa\source\repos\fast-cpp-csv-parser\csv.h"
using namespace std;
//Declaration of Variables
string className, assignmentName, fileDirectory, termName, classFileName;
int numberStudents, numberAssignments, totalAssignments, fileLocation, classIndication;//fileDirectory is where the actual file is stored while fileLocation is to help build the menu
char userInputNames, userInputClass,userInputAssignment, userInputCalc,UserInputDir;//Variables for single character user inputs
//Declaration of Constants
int const MAX_STUDENTS = 40;//Originally 6, using 40 to allow testing of larger classes
//Declaration of arrays
string studentName[3];//Six is a placeholder value as it is the number of students EENG 221
string classOne[6];//Sample classes(currently not used as studentName is handling its duties at this point, but will be used within the next version or two
string classTwo[28];
string classOneFiles[MAX_STUDENTS] = {"Q12_001", "Q12_002","Q12_003", "Q12_004" "Q12_005", "Q12_006","Q12_007" };//Array with files to rename.
//Since I am currently just renaming the array elements without using the data contained in a meaningful way, I simply populated classTwofiles with random strings(the synonyms of amazing)
string classTwoFiles[MAX_STUDENTS] = { "astonishing", "astounding", "blindsiding", "dumbfounding", "eye-opening", "flabbergasting", "jarring", "jaw-dropping", "jolting", "shocking", "startling", "stunning", "stupefying", "surprising" };//Will enter actual represenative strings after confirming the structure
//Declartion of functions
void studentNameInput();//Allows for the user to input student names.  
string validator(string input, string desiredInput);
//Preconditon: The input of you want the user to enter
//Postconditon: A validated input from the user will be stored in the input entered
void inputChecker(string input);
void inputChecker(int input);
void inputChecker(double input);
void inputChecker(bool input);
void inputChecker(char input);
//Precondition: String you want to check and desired string/characters to compare against
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
	cout << "What term are we in?\n";
	//cin >> termName;//Will hopefuully be embedded into class list files.
	inputChecker(termName);		
	cout << "How many students are in this class?\n";
	//cin >> numberStudents;
	inputChecker(numberStudents);
	cout << "Would you like to get an estimate for the amount of files you will have at the end of the semester?\n Type y for yes or any other letter for no\n";
	//cin >> userInputCalc;
	inputChecker(userInputCalc);
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
	/*cout << "Now is the time to enter student names into the class list:\n";
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
	} while (userInputNames != 'y');*/
	int l = 0;
	do {
		if (l > 0)
		{
			"Sorry that is an invalid input, please try again.\n";
			cin.clear();
			cin.ignore();
		}
		cout << "What directory do you want to rename files in?\n";
		cout << "1:USB Drive\n";
		cout << "2:Documents\n";
		cout << "3:Custom Location\n";
		cin >> fileLocation;
		l++;
	} while (cin.fail());
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
	//classFileName = className + ".csv";
	ifstream classFile;
	classFile.open("Class.txt");
	if (classFile.fail())
	{
		cout << "\nOpening class file failed\n";
		exit(1);
	}
	int count = 0;
	string next;
	while (classFile >> next)
	{
		
		studentName[count] = next;
		count++;
	}
	classFile.close();
	cout << "Is this Class 1 or Class 2? (Please enter the number)\n";
	//cin >> classIndication;
	inputChecker(classIndication);
	assignmentName = confirmer("assignment", assignmentName);
	//Final output.
	cout << "Thank you!\n All of the selected files will have this format:\n" << fileDirectory << "\\" << className << "-" << assignmentName << "-firstName-lastName.fileExtension\n";
	//I am just outputting to the console for now, but this will be changed to rename the files
	cout << "Here are the file names:\n";
	ofstream newFileName;
	newFileName.open("fileNames.txt");
	if (newFileName.fail())
	{
		cout << "\nOpening file name file failed\n";
		exit(1);
	}
	switch (classIndication)
	{
		case 1:
		{
			for (int i = 0; i < MAX_STUDENTS && i < numberStudents; i++)
			{
				classOneFiles[i] = fileDirectory + "\\" + className + "-" + termName +"-" + assignmentName + "-" + studentName[i] + ".fileExtension\n";//Add what term it is
				cout << classOneFiles[i];
				newFileName << fileDirectory + "\\" + className + "-" + termName + "-" + assignmentName + "-" + studentName[i] + ".fileExtension\n";//Add what term it is
				cout << classOneFiles[i] << endl;
			}
			newFileName.close();
			break;
		}
		case 2:
		{
			for (int i = 0; i < MAX_STUDENTS && i < numberStudents; i++)
			{
				newFileName << fileDirectory + "\\" + className + "-" + termName + "-" + assignmentName + "-" + studentName[i] + ".fileExtension\n";//Add what term it is
				cout << classOneFiles[i] << endl;
			}
			newFileName.close();
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
void csvParser(string fileName)
{
	char currentChar;
	ifstream dataFile;
	dataFile.open(fileName);
	dataFile.get(currentChar);
	if (dataFile.fail())
	{
		cout << "\nOpening class data file failed\n";
		exit(1);
	}
	ofstream nameList;
	nameList.open("names.txt");
	if (nameList.fail())
	{
		cout << "\nCreating name file failed\n";
		exit(1);
	}
	while ((currentChar != ',') && (currentChar != '\n'));
	{

	}
}
void inputChecker(string input)
{
	cin >> input;
	cout << cin.fail()<<endl;
	while (cin.fail())
	{
		cin >> input;
		//cout << cin.fail() << endl;
		cin.clear();
		cin.ignore();
		cout << "Sorry but that input is not valid, please use the requested input type\n";
		cin >> input;
	}
}
void inputChecker(int input)
{
	cin >> input;
	cout << cin.fail()<<endl;
	while (cin.fail())
	{
		cin >> input;
		//cout << cin.fail() << endl;
		cin.clear();
		cin.ignore();
		cout << "Sorry but that input is not valid, please use the requested input type\n";
		cin >> input;
	}
}
void inputChecker(double input)
{
	cin >> input;
	cout << cin.fail()<<endl;
	while (cin.fail())
	{
		cin >> input;
		//cout << cin.fail() << endl;
		cin.clear();
		cin.ignore();
		cout << "Sorry but that input is not valid, please use the requested input type\n";
		cin >> input;
	}
}
void inputChecker(bool input)
{
	cin >> input;
	cout << cin.fail()<<endl;
	while (cin.fail())
	{
		cin >> input;
		//cout << cin.fail() << endl;
		cin.clear();
		cin.ignore();
		cout << "Sorry but that input is not valid, please use the requested input type\n";
		cin >> input;
	}
}
void inputChecker(char input)
{
	cin >> input;
	cout << cin.fail()<<endl;
	while (cin.fail())
	{
		cin >> input;
		//cout << cin.fail() << endl;
		cin.clear();
		cin.ignore();
		cout << "Sorry but that input is not valid, please use the requested input type\n";
		cin >> input;
	}
}