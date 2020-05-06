//H.I.L.T.
//Filename: hilt.cpp
//Email Address: blkelly@my.milligan.edu
//Term Project
//Description: A tool to allow batch labelling of files in directory
//Version 1.0.0(Final Presentation)
//Last Changed: 5/5/2020
#include "stdafx.h"
#include "classInfo.h"
struct studentInfo
{
	char name[100];
	char id[100];
	bool presence;
};
string searchTermPresence;
int numberStudents, numberAssignments, totalAssignments, fileLocation, classIndication;//fileDirectory is where the actual file is stored while fileLocation is to help build the menu
char userInputNames, userInputClass,userInputAssignment, userInputCalc,UserInputDir, userInputSearch,userInputPresence;//Variables for single character user inputs
//Declartion of a C-Strings
char className[100]; char termName[100]; char assignmentName[100]; char fileDirectory[100]; char classFileName[100];char searchTerm[100];
//string searchTerm;
//Declaration of Constants
int const MAX_STUDENTS = 100;	
//Declaration of arrays
studentInfo studentsArray[MAX_STUDENTS];
string studentName[MAX_STUDENTS];//Six is a placeholder value as it is the number of students EENG 221
string classOne[MAX_STUDENTS];//Sample classes(currently not used as studentName is handling its duties at this point, but will be used within the next version or two
string classTwo[MAX_STUDENTS];
int present[MAX_STUDENTS][1];//The 'x' axis is the students number and the 'y' axis is whether they were there or not.
string classOneFiles[MAX_STUDENTS] = {"Q12_001", "Q12_002","Q12_003", "Q12_004" "Q12_005", "Q12_006","Q12_007" };//Array with files to rename.
//Since I am currently just renaming the array elements without using the data contained in a meaningful way, I simply populated classTwofiles with random strings(the synonyms of amazing)
string classTwoFiles[MAX_STUDENTS] = { "astonishing", "astounding", "blindsiding", "dumbfounding", "eye-opening", "flabbergasting", "jarring", "jaw-dropping", "jolting", "shocking", "startling", "stunning", "stupefying", "surprising" };//Will enter actual represenative strings after confirming the structure
//Declartion of functions
void studentNameInput();//Allows for the user to input student names.  
//string validator(string input, string desiredInput);
//Precondition: String you want to check and desired string/characters to compare against
//Postcondition: The function compares the two and returns the user input when they are the same as a string
string inputChecker(string input);
int inputChecker(int input);
double inputChecker(double input);
bool inputChecker(bool input);
char inputChecker(char input);
//Preconditon: The input of you want the user to enter
//Postconditon: A validated input from the user will be stored in the input entered
void colorChanger(int colorNumber);
//Precondition: Place the number of the color you want the following text to be.
//Postconditon:The output color is changed for the following text until it is changed again.
void arraySearch(string inputArray[], int sizeArray, char searchTerm[], int indexStorageArray[], int indexStorageArraySize);
//Precondition: Put in an array to search for a given search term as well as an array to store the indexes that match the search term given.
//Postcondition: Any index where the element matches the given search term is stored in the indexSotrageArray.
string confirmer(string nameOfInput,char userInput[]);
//Precondition: What input you need to the user to confirm and what it is called in the program, where the userInput is a string and the name of the variable with type string
//Postcondition: Returns the confirmed user input as a string.
int main()
{
	//Greeting Message.  Will likely be expanded to add some basic rules/instructions
	colorChanger(14);
	cout << "HHHHHHHHH     HHHHHHHHH          _          LLLLLLLLLLL                     TTTTTTTTTTTTTTTTTTTTTTT        \nH:::::::H     H:::::::H         (_)         L:::::::::L                     T:::::::::::::::::::::T       \nH:::::::H     H:::::::H         |_|         L:::::::::L                     T:::::::::::::::::::::T       \nHH::::::H     H::::::HH         |_|         LL:::::::LL                     T:::::TT:::::::TT:::::T        \n  H:::::H     H:::::H           |_|           L:::::L                       TTTTTT  T:::::T  TTTTTT        \n  H:::::H     H:::::H           |_|           L:::::L                               T:::::T                \n  H::::::HHHHH::::::H           |_|           L:::::L                               T:::::T                \n  H:::::::::::::::::H       o=========o       L:::::L                               T:::::T                \n  H:::::::::::::::::H           | |           L:::::L                               T:::::T                \n  H::::::HHHHH::::::H           | |           L:::::L                               T:::::T                \n  H:::::H     H:::::H           | |           L:::::L                               T:::::T                \n  H:::::H     H:::::H           | |           L:::::L         LLLLLL                T:::::T                \nHH::::::H     H::::::HH         | |         LL:::::::LLLLLLLLL:::::L              TT:::::::TT              \nH:::::::H     H:::::::H ......  | |  ...... L::::::::::::::::::::::L ......       T:::::::::T ...... \nH:::::::H     H:::::::H .::::.  | |  .::::. L::::::::::::::::::::::L .::::.       T:::::::::T .::::. \nHHHHHHHHH     HHHHHHHHH ......  \\ /  ...... LLLLLLLLLLLLLLLLLLLLLLLL ......       TTTTTTTTTTT ...... \nSword from ASCII Art Archive\n";
	colorChanger(11);
	cout << "Welcome to H.I.L.T!\nHere is the color code quickly: This blue is for the greeting message, white is for the rest of the computer outputs,\ngreen is user input, yellow is a status notice, and red is for errors\n";
	cout << "To start we are going to have you input a few basic pieces of information:\n";
	colorChanger(10);
	do {
		colorChanger(15);
		cout << "How many students are in this class? \n(Numbers greater than 100 WILL break the program with the current class list, you can edit Class.txt to up the limit and will loop this input step until a number less than 100 is entered.)\n";
		colorChanger(10);
		numberStudents = inputChecker(numberStudents);
	} while (numberStudents > 100);
	colorChanger(15);
	cout << "Would you like to get an estimate for the amount of files you will have at the end of the semester?\n Type y for yes or any other letter for no\n";
	colorChanger(10);
	cin.ignore();
	userInputCalc = inputChecker(userInputCalc);
	userInputCalc = tolower(userInputCalc);
	if (userInputCalc == 'y')
	{
		colorChanger(15);
		cout << "How many assignments per student?\n";
		colorChanger(10);
		numberAssignments = inputChecker(numberAssignments);
		totalAssignments = numberAssignments * numberStudents;
		colorChanger(15);
		cout << "There should be a total of " << totalAssignments << " files this semester for this class.\n -------------------------------------------- \n";
	}
	int l = 0;
	do {
		if (l > 0)
		{
			colorChanger(15);
			"Sorry that is an invalid input, please try again.\n";
			cin.clear();
			cin.ignore();
		}
		colorChanger(15);
		cout << "What directory do you want to rename files in?\n";
		cout << "1:USB Drive\n";
		cout << "2:Documents\n";
		cout << "3:Custom Location\n";
		colorChanger(10);
		cin >> fileLocation;
		l++;
	} while (cin.fail());
	switch (fileLocation)
	{
		case 1:
		{
			colorChanger(15);
			strcpy_s(fileDirectory, "F:\\scannedFiles");
			break;
		}
		case 2:
		{
			colorChanger(15);
			strcpy_s(fileDirectory, "C:\\Documents");
			break;
		}
		case 3:
			colorChanger(15);
			cout << "What file directory do you want to read and write from?\n";
			colorChanger(10);
			cin.ignore();
			cin.getline(fileDirectory, 100);
			break;
	}
	int testStorage[100];
	classInfo currentClass;
	currentClass.ingest();
	strcpy_s(classFileName, "test.csv");
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
	int arrayMatches = 0;
	colorChanger(15);
	cout << "Would you like to search for a student in this class?  Use y to indicate yes or another character to not search\n";
	userInputSearch = inputChecker(userInputSearch);
	userInputSearch = tolower(userInputSearch);
	while (userInputSearch == 'y')
	{
		colorChanger(15);
		cout << "What is the student's name?\n";
		colorChanger(10);
		cin.getline(searchTerm, 100,'\n');
		colorChanger(15);
		arraySearch(studentName, numberStudents, searchTerm, testStorage, numberStudents);
		arrayMatches = 0;
		for (int p = 0; p < (numberStudents); p++)
		{
			if (testStorage[p] != -1)
			{
				cout << "Index #:" << testStorage[p]<<"\n";
				arrayMatches++;
			}
			if (p == (numberStudents-1))
			{
				if (arrayMatches != 0)
				{
					cout << "There were " << arrayMatches << " matches\n";
				}
				else
				{
					cout << "There were no matches\n";
				}
			}

		}
		cout << "Would you like to find another student? Any other input than y or Y will exit this routine\n";
		userInputSearch = inputChecker(userInputSearch);
		userInputSearch = tolower(userInputSearch);
	}
	colorChanger(15);
	cout << "Now is the time that you can indicate whether a student is here or not\n Were any students missing?\n";
	userInputPresence = inputChecker(userInputPresence);
	userInputPresence = tolower(userInputPresence);
	while (userInputPresence == 'y')
	{
		colorChanger(15);
		cout << "What is the name of the student?\n";
		searchTermPresence = inputChecker(searchTermPresence);
		cin.ignore();
		for (int i = 0; i < numberStudents; i++)
		{
			if (studentsArray[i].name == searchTermPresence)
			{
				studentsArray[i].presence = false;
			}

		}
		colorChanger(15);
		cout << "Are there any more missing students?\n";
		userInputPresence = inputChecker(userInputPresence);
		userInputPresence = tolower(userInputPresence);
	}
	colorChanger(15);
	cout << "Is this Class 1 or Class 2? (Please enter the number)\n";
	colorChanger(10);
	classIndication = inputChecker(classIndication);
	strcpy_s(assignmentName,confirmer("assignment", assignmentName).c_str());
	//Final output.
	colorChanger(15);
	cout << "Thank you!\n All of the selected files will have this format:\n" << fileDirectory << "\\" << currentClass.getName() << "-" << assignmentName << "-firstName-lastName.fileExtension\n";
	colorChanger(15);
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
			string fileDirectoryString = fileDirectory;
			for (int i = 0; i < MAX_STUDENTS && i < numberStudents; i++)
			{
				classOneFiles[i] = fileDirectoryString + "\\" + currentClass.getName() + "-" + currentClass.getTerm() + "-" + assignmentName + "-" + studentName[i] + ".fileExtension\n";//Add what term it is
				cout << classOneFiles[i];
				newFileName << fileDirectoryString << "\\" << currentClass.getName() << "-" << currentClass.getTerm() << "-" << assignmentName << "-" << studentName[i] << ".fileExtension\n";//Add what term it is
				cout << classOneFiles[i] << endl;
			}
			newFileName.close();
			break;
		}
		case 2:
		{
			string fileDirectoryString = fileDirectory;
			for (int i = 0; i < MAX_STUDENTS && i < numberStudents; i++)
			{
				classTwoFiles[i] = fileDirectoryString + "\\" + currentClass.getName() + "-" + currentClass.getTerm() + "-" + assignmentName + "-" + studentName[i] + ".fileExtension\n";//Add what term it is
				cout << classOneFiles[i];
				newFileName << fileDirectoryString << "\\" << currentClass.getName() << "-" << currentClass.getTerm() << "-" << assignmentName << "-" << studentName[i] << ".fileExtension\n";//Add what term it is
				cout << classTwoFiles[i] << endl;
			}
			newFileName.close();
			break;
		}
	}

	return 0;

}
//Function Definition
string confirmer(string nameOfInput, char userInput[])
{
	string stringOuput;
	char userConfirmation;
	do
	{
		colorChanger(15);
		cout << "Please enter your desired " << nameOfInput << " name (using dashes or underscores for spaces.)\n";
		colorChanger(10);
		cin.ignore();
		cin.getline(userInput,100);
		colorChanger(15);
		cout << "Is this the correct " << nameOfInput << " name?\n";
		colorChanger(10); 
		cout << userInput << " \n";
		colorChanger(10);
		cin >> userConfirmation;
		userConfirmation = tolower(userConfirmation);
	} while (userConfirmation != 'y');
	string stringOutput = string(userInput);
	return stringOutput;
}
//Not yet functional nor needed yet. Probably won't be utilized in this version
void csvParser(string fileName)
{
	char currentChar;
	ifstream dataFile;
	dataFile.open(fileName);
	dataFile.get(currentChar);
	if (dataFile.fail())
	{
		colorChanger(12);
		cout << "\nOpening class data file failed\n";
		exit(1);
	}
	ofstream nameList;
	nameList.open("names.txt");
	if (nameList.fail())
	{
		colorChanger(12);
		cout << "\nCreating name file failed\n";
		exit(1);
	}
	while ((currentChar != ',') && (currentChar != '\n'));
	{

	}
}
string inputChecker(string input)
{
	colorChanger(10);
	cin >> input;
	colorChanger(14);
	cout << "\n Status of input(0 means success and 1 means improper input): "<< cin.fail() << endl;
	while (cin.fail())
	{
		colorChanger(10);
		cin >> input;
		cin.clear();
		cin.ignore();
		colorChanger(12);
		cout << "Sorry but that input is not valid, please use the requested input type\n";
		colorChanger(10);
		cin >> input;
	}
	return input;
}
int inputChecker(int input)
{
	colorChanger(10);
	cin >> input;
	colorChanger(14);
	cout << "\n Status of input(0 means success and 1 means improper input): " << cin.fail() << endl;	
	while (cin.fail())
	{
		colorChanger(10);
		cin >> input;
		cin.clear();
		cin.ignore();
		colorChanger(12);
		cout << "Sorry but that input is not valid, please use the requested input type\n";
		colorChanger(10);
		cin >> input;
	}
	return input;
}

double inputChecker(double input)
{
	colorChanger(10);
	cin >> input;
	cout << "\n Status of input(0 means success and 1 means improper input): " << cin.fail() << endl;
	while (cin.fail())
	{
		colorChanger(10);
		cin >> input;
		cin.clear();
		cin.ignore();
		colorChanger(12);
		cout << "Sorry but that input is not valid, please use the requested input type\n";
		colorChanger(10);
		cin >> input;
	}
	return input;
}

bool inputChecker(bool input)
{
	colorChanger(10);
	cin >> input;
	colorChanger(14);
	cout << "\n Status of input(0 means success and 1 means improper input): " << cin.fail() << endl;
	while (cin.fail())
	{
		colorChanger(10);
		cin >> input;
		cin.clear();
		cin.ignore();
		colorChanger(12);
		cout << "Sorry but that input is not valid, please use the requested input type\n";
		colorChanger(10);
		cin >> input;
	}
	return input;
}
char inputChecker(char input)
{
	colorChanger(10);
	char inputWord[100];
	cin.getline(inputWord,100);
	input=inputWord[0];
	colorChanger(14);
	cout << "\n Status of input(0 means success and 1 means improper input): " << cin.fail() << endl;
	while (cin.fail())
	{
		colorChanger(10);
		cin >> input;
		cin.clear();
		cin.ignore();
		colorChanger(12);
		cout << "Sorry but that input is not valid, please use the requested input type\n";
		colorChanger(10);
		cin >> input;
	}
	return input;
}
void colorChanger(int colorNumber)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNumber);
}
void arraySearch(string inputArray[], int sizeArray,char searchTerm[], int indexStorageArray[],int indexStorageArraySize)
{
	if (sizeArray > indexStorageArraySize)
	{
		colorChanger(12);
		cout << "Sorry this array is to big to be searched and stored safely in the given storage array, please try again.";
		exit(0);
	}
	int j = 0;
	for (int i = 0; i < sizeArray; i++) 
	{
		if (inputArray[i] == searchTerm)
		{
			indexStorageArray[j] = i;
			j++;
		}
		else
		{
			indexStorageArray[j] = -1;
			j++;
		}
	}
}
//The rest of the arraySearches will be implemented when further validated. 
/*void arraySearch(int inputArray[], int sizeArray, int searchTerm)
{
	int j = 0;
	for (int i = 0; i < sizeArray; i++)
	{
		if (inputArray[i] == searchTerm)
		{
			indexes[j] = i;
			j++;
		}
	}
}
void arraySearch(double inputArray[], int sizeArray, double searchTerm)
	{
		int j = 0;
		for (int i = 0; i < sizeArray; i++)
		{
			if (inputArray[i] == searchTerm)
			{
				indexes[j] = i;
				j++;
			}
		}
	}
void arraySearch(float inputArray[], int sizeArray, float searchTerm)
{
	int j = 0;
	for (int i = 0; i < sizeArray; i++)
	{
		if (inputArray[i] == searchTerm)
		{
			indexes[j] = i;
			j++;
		}
	}
}
void arraySearch(bool inputArray[], int sizeArray, bool searchTerm)
{
	int j = 0;
	for (int i = 0; i < sizeArray; i++)
	{
		if (inputArray[i] == searchTerm)
		{
			indexes[j] = i;
			j++;
		}
	}
}

*/
