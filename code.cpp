#include <iostream>
#include <cstdlib>
#include <ctime>
#include "header.h"
#include <string>
using namespace std;
#pragma warning(disable : 4996)
folder* mainfolder = new folder("Root folder");
folder* currentfolder = mainfolder;
folder* parentfolder = currentfolder;
folder* foldercheck;


int errorcontrolint() { //checks if all int inputs are valid aka numbers
	string inputstr;
	int input;
	bool digitcheck;
	cin >> inputstr;

	for (int i = 0; i < inputstr.length(); i++) {//for loop to check every letter or number and returns true if string only contains numbers
		digitcheck = isdigit(inputstr[i]);
		if(!digitcheck) {
			break;
		}
	}
	while (!digitcheck) {//makes user reenter if digitcheck returns false
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter valid input" << endl << "input:";
		cin >> inputstr;
		for (int i = 0; i < inputstr.length(); i++) {
			digitcheck = isdigit(inputstr[i]);
			if (!digitcheck) {
				break;
			}
		}
	}

	while (cin.fail()) {//the above should fix most problems but here is a simple fix if something wierd happens. a simple if failed, reenter input
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter valid input" << endl << "input:";
		cin >> inputstr;
	}
	input = stoi(inputstr); // converts string to int
	return input;
}

string errorcontrolstr() { //checks if all strings are valid, dont know how you can fuck up a string but this should fix it if its possible
	string input;
	cin.ignore();
	getline(cin, input); // the getline command allows the user to actually enter a "space"

	while (cin.fail()) {//if input failed, reenter input
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter valid input" << endl << "input:";
		getline(cin, input);
	}
	return input;
}

int main() { //this the main menu, here the code calls for all main functions
	string foldername;
	string filename;
	int answer;
	while (true) //just a loop to make it run again and again forever
	{
		cout << "Press 1 to add folder" << endl;
		cout << "Press 2 to add file" << endl;
		cout << "Press 3 to enter or return to previous folder" << endl;
		cout << "Press 4 to rename folder" << endl;
		cout << "Press 5 to rename file" << endl;
		cout << "Press 6 to find biggest file in a folder" << endl;
		cout << "Press 7 to exit program" << endl;
		cout << "Operation number:";
		answer = errorcontrolint();
		while(answer < 1 || answer >7){
			cout << "Please enter a valid operation number" << endl << "Operation number:";
			answer = errorcontrolint();
		}
		switch (answer) { //case switch to select the right operation
		case 1:
			if(answer == 1)	{	
				cout << "Folder name: ";
				foldername = errorcontrolstr();
				folder* subfolder1 = new folder(foldername);
				currentfolder->addfolder(subfolder1);
				cout << endl << currentfolder->getname() << ":";
				currentfolder->printfolders();
				currentfolder->printfiles();
				break;
			}
		case 2:
			cout << "File name: ";
			filename = errorcontrolstr();
			currentfolder->addfile(file(filename));
			cout << endl << currentfolder->getname() << ":";
			currentfolder->printfolders();
			currentfolder->printfiles();
			break;
		case 3:
			cout << currentfolder->getname() << ":" << endl;
			currentfolder = currentfolder->enterfolder(currentfolder->getsubfolder());
			cout << endl << currentfolder->getname() << ":";
			currentfolder->printfolders();
			currentfolder->printfiles();
			break;
		case 4:
			currentfolder->renamefolder();
			break;
		case 5:
			currentfolder->renamefile();
			break;
		case 6:
			currentfolder->biggestfile();
			break;
		case 7:
			return 0;
		}
	}
}
