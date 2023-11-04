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


int errorcontrolint() { //this fucntion checks if all int inputs are valid aka numbers
	int input;
	cin >> input;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter valid input" << endl << "input:";
		cin >> input;
	}
	return input;
}

string errorcontrolstr() {
	string input;
	cin.ignore();
	getline(cin, input);

	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter valid input" << endl << "input:";
		getline(cin, input);
	}
	return input;
}

int main() {
	string foldername;
	string filename;
	int answer;
	while (true)
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
		switch (answer) {
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
