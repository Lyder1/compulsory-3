#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstdio>
#include <cctype>
using namespace std;
#pragma warning(disable : 4996)

class file { //creates a file class with values like name and size and all the rest
public:
	string name;
	int size;
	int day;
	int month;
	int year;
	int hour;
	int min;
	file() { //had to add default constructor because c++ got mad
		time_t now = time(0);
		tm* ltm = localtime(&now);
		name = "DefaultFile";
		size = 1 + (rand() % 100);
		day = ltm->tm_mday;
		month = 1 + ltm->tm_mon;
		year = 1900 + ltm->tm_year;
		hour = ltm->tm_hour;
		min = ltm->tm_min;
	}
	file(string setname) { //constructor for all files that i want to add
		time_t now = time(0);
		tm* ltm = localtime(&now);
		name = setname;
		size = 1 + (rand() % 100);
		day = ltm->tm_mday;
		month = 1 + ltm->tm_mon;
		year = 1900 + ltm->tm_year;
		hour = ltm->tm_hour;
		min = ltm->tm_min;
	}

};

class folder { // creates a folder class with the same values as files. name and size etc
public:
	int foldercount = 0;
	int filecount = 0;
	file files[10];
	folder* folders[5];
	string name;
	folder* parentfolder;
	int size;
	int day;
	int month;
	int year;
	int hour;
	int min;

	folder(string setName){ //constructor for all folders
		time_t now = time(0);
		tm* ltm = localtime(&now);
		name = setName;
		size = 1 + (rand() % 100);
		day = ltm->tm_mday;
		month = 1 + ltm->tm_mon;
		year = 1900 + ltm->tm_year;
		hour = ltm->tm_hour;
		min = ltm->tm_min;
	}
	int errorcontrolint() { //errorcontrol for all int values, checks if they are valid numbers ant dont contain letters for example
		string inputstr;
		int input;
		bool digitcheck;
		cin >> inputstr;

		for (int i = 0; i < inputstr.length(); i++) { //for loop to check every letter or number and returns true if string only contains numbers
			digitcheck = isdigit(inputstr[i]);
			if (!digitcheck) {
				break;
			}
		}
		while (!digitcheck) { //makes user reenter if digitcheck returns false
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

		while(cin.fail()) { //the above should fix most problems but here is a simple fix if something wierd happens. a simple if failed, reenter input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter valid input" << endl << "input:";
			cin >> input;
		}
		input = stoi(inputstr); //converts string to int
		return input;
	}

	string errorcontrolstr() { //error control for all strings. names and stuff
		string input;
		cin.ignore();
		getline(cin, input); // the getline command allows the user to actually enter a "space"

		while (cin.fail()) { //if input failed, reenter input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter valid input" << endl << "input:";
			cin >> input;
		}
		return input;
	}

	void printfiles() { // print all files in the current folder
		for (int i = 0; i < filecount; i++) {
			if (files[i].min < 10 && files[i].hour < 10) {//the time created is a bit wierd, when one of the time sections are bellow 10 for example  if the time is 09:08 it returns the time 9:8, so i made a if statement to add the zeroes if it is needed
				cout << i + 1 << ". " << files[i].name << " (File)   " << files[i].day << "." << files[i].month << "." << files[i].year << " 0" << files[i].hour << ":0" << files[i].min << "   " << files[i].size << "mb" << endl;
			}
			else if (files[i].min < 10) {
				cout << i + 1 << ". " << files[i].name << " (File)   " << files[i].day << "." << files[i].month << "." << files[i].year << " " << files[i].hour << ":0" << files[i].min << "   " << files[i].size << "mb" << endl;
			}
			else if (files[i].hour < 10) {
				cout << i + 1 << ". " << files[i].name << " (File)   " << files[i].day << "." << files[i].month << "." << files[i].year << " 0" << files[i].hour << ":" << files[i].min << "   " << files[i].size << "mb" << endl;
			}
			else{
				cout << i + 1 << ". " << files[i].name << " (File)   " << files[i].day << "." << files[i].month << "." << files[i].year << " " << files[i].hour << ":" << files[i].min << "   " << files[i].size << "mb" << endl;
			}
		}
		cout << endl;
	}

	void printfolders() { //prints all folders in current folder
		cout << endl;
		for (int i = 0; i < foldercount; i++) {
			if (folders[i]->min < 10 && folders[i]->hour < 10) {
				cout << i + 1 << ". " << folders[i]->name << " (Folder)   " << folders[i]->day << "." << folders[i]->month << "." << folders[i]->year << " 0" << folders[i]->hour << ":0" << folders[i]->min << "   " << folders[i]->size << "mb" << endl;
			}
			else if (folders[i]->min < 10) {
				cout << i + 1 << ". " << folders[i]->name << " (Folder)   " << folders[i]->day << "." << folders[i]->month << "." << folders[i]->year << " " << folders[i]->hour << ":0" << folders[i]->min << "   " << folders[i]->size << "mb" << endl;
			}
			else if(folders[i]->hour < 10) {
				cout << i + 1 << ". " << folders[i]->name << " (Folder)   " << folders[i]->day << "." << folders[i]->month << "." << folders[i]->year << " 0" << folders[i]->hour << ":" << folders[i]->min << "   " << folders[i]->size << "mb" << endl;
			}
			else{
				cout << i + 1 << ". " << folders[i]->name << " (Folder)   " << folders[i]->day << "." << folders[i]->month << "." << folders[i]->year << " " << folders[i]->hour << ":" << folders[i]->min << "   " << folders[i]->size << "mb" << endl;
			}
		}
	}

	void renamefolder() { //renames whatever folder you pick in currentfolder
		string newname;
		if (foldercount == 0) { //checks if there are any folders in currentfolder
			cout << "You do not have a folder to rename" << endl << endl;
		}else{
			int index;
			cout << "What folder do you want to rename?" << endl << "Folder number:";
			index = errorcontrolint();
			if (index >= 1 && index <= foldercount) { //checks if the entered folder number actaully exists
				cout << "What do you want to rename the folder?" << endl << "New folder name:";
				newname = errorcontrolstr();
				folders[index - 1]->name = newname;
				cout << endl << getname() << ":"; //prints the name of the currentfolder
				printfolders();
				printfiles();

			}
			else {
				while (index < 1 || index > foldercount) { // while loop to reenter input if entered folder number does not exist in current folder. 
					cout << "You do not have a folder with that number, please reenter" << endl << "Folder number:";
					index = errorcontrolint();
				}
				cout << "What do you want to rename the folder?" << endl << "New folder name:";
				newname = errorcontrolstr();
				folders[index - 1]->name = newname;
				cout << endl << getname() << ":";
				printfolders();
				printfiles();
			}
		}
	}

	void renamefile() { //renames whatever file you pick in currentfolder. it works the exact same way as the above rename folder function, just replace every folder with file, so i am not typing the same notes again
		string newname;
		if (filecount == 0) { 
			cout << "You do not have a file to rename" << endl << endl;
		}
		else {
			int index;
			cout << "What file do you want to rename?" << endl << "File number:";
			index = errorcontrolint();
			if (index >= 1 && index <= filecount) {
				cout << "What do you want to rename the file?" << endl << "New file name:";
				newname = errorcontrolstr();
				files[index - 1].name = newname;
				cout << endl << getname() << ":";
				printfolders();
				printfiles();

			}
			else {
				while (index < 1 || index > filecount) {
					cout << "You do not have a file with that number, please reenter" << endl << "File number:";
					index = errorcontrolint();
				}
				cout << "What do you want to rename the file?" << endl << "New file name:";
				newname = errorcontrolstr();
				files[index - 1].name = newname;
				cout << endl << getname() << ":";
				printfolders();
				printfiles();
			}
		}
	}

	void biggestfile() { //pciks out the biggest file inside whatever folder you choose to search
		time_t now = time(0);
		tm* ltm = localtime(&now);
		int index;
		string bfname;
		int bfsize = 0;
		int bfday;
		int bfmonth;
		int bfyear;
		int bfhour;
		int bfmin;

		if (foldercount == 0) { // checks if there are any fodlers to check
			cout << "You do not have a folder to check" << endl << endl;
		}else {
			cout << "What folder do you want to check?" << endl << "Folder number:";
			index = errorcontrolint();
			if (folders[index - 1]->filecount == 0) { // checks if the entered folder cotains anything
				cout << endl << "This folder is empty" << endl;
			}else if (index >= 1 && index <= foldercount) {
				for(int i = 0; i < folders[index-1]->filecount; i ++){ // for loop to remember the biggest searched file
					if (bfsize < folders[index - 1]->files[i].size) { // if the next searched file is bigger then the current biggest, the new one takes its place as teh biggest file
						bfname = folders[index - 1]->files[i].name;
						bfsize = folders[index - 1]->files[i].size;
						bfday = folders[index - 1]->files[i].day;
						bfmonth = folders[index - 1]->files[i].month;
						bfyear = folders[index - 1]->files[i].year;
						bfhour = folders[index - 1]->files[i].hour;
						bfmin = folders[index - 1]->files[i].min;
					}
				}
				if (bfmin < 10) { //print the information of the biggest file in the searched folder
					cout << endl << "Biggest file in searched folder: " << bfname << "   " << bfday << "." << bfmonth << "." << bfyear << " " << bfhour << ":0" << bfmin << "   " << bfsize << "mb" << endl;
				}
				else {
					cout << endl << "Biggest file in searched folder: " << bfname << "   " << bfday << "." << bfmonth << "." << bfyear << " " << bfhour << ":" << bfmin << "   " << bfsize << "mb" << endl;
				}
			}
			else {
				while (index < 1 || index > foldercount) { // makes user reenter if user enters a invalid number
					cout << "You do not have a folder with that number, please reenter" << endl << "Folder number:";
					index = errorcontrolint();
				}
				for (int i = 0; i < folders[index - 1]->filecount; i++) {
					if (bfsize < folders[index - 1]->files[i].size) {
						bfname = folders[index - 1]->files[i].name;
						bfsize = folders[index - 1]->files[i].size;
						bfday = folders[index - 1]->files[i].day;
						bfmonth = folders[index - 1]->files[i].month;
						bfyear = folders[index - 1]->files[i].year;
						bfhour = folders[index - 1]->files[i].hour;
						bfmin = folders[index - 1]->files[i].min;
					}
				}
				if (bfmin < 10) {
					cout << "Biggest file in searched folder: " << bfname << "   " << bfday << "." << bfmonth << "." << bfyear << " " << bfhour << ":0" << bfmin << "   " << bfsize << "mb" << endl;
				}
				else {
					cout << "Biggest file in searched folder: " << bfname << "   " << bfday << "." << bfmonth << "." << bfyear << " " << bfhour << ":" << bfmin << "   " << bfsize << "mb" << endl;
				}
			}
		}
		cout << endl << getname() << ":";
		printfolders();
		printfiles();
	}

	string getname() { //fetches name of a folder
		return name;
	}

	folder** getsubfolder() { //fetches sub folders
		return folders;
	}

	folder* enterfolder(folder* filearray[]) { //enters whatever folder you choose in currentfolder, also gives you the option to go back to the previous folder
		if (foldercount == 0 && parentfolder == 0) { // checks if there are any folders to enter and if the user is in the root folder it automatically adds a folder
			cout << "You do not have any folder to enter so a folder has been added automatically" << endl;
			folder* subfolder1 = new folder("New folder");
			addfolder(subfolder1);
			printfolders();
			printfiles();
		}
		int index;
		cout << "Enter a folder number to enter or enter (0) to return to previous folder" << endl << "Folder number:";
		index = errorcontrolint();

		if (index >= 1 && index <= foldercount) { //checks if teh folder entered exists in current folder
			folders[index - 1]->getname();
		}
		if(index > foldercount){ //makes user reenter if entered folder number does not exist
			while (index < 1 || index > foldercount) {
				cout << "You do not have a folder with that number, please reenter" << endl << "Folder number:";
				index = errorcontrolint();
				
			}
			return filearray[index - 1];
		}
		if (index == 0) {
			if(parentfolder != 0){ //checks if user is in the root folder
				return parentfolder;
			}else {
				cout << "You are in root folder, please enter a folder number" << endl << "Folder number:";
				while (index < 1 || index > foldercount) {
					index = errorcontrolint();
					if (index == 0) {
						cout << "You are in the root folder, please enter a folder number" << endl << "Folder number:";
					}
					if(index > foldercount) {
						cout << "You dont have a folder with that number, please reenter" << endl << "Folder number:";
					}
				}
				return filearray[index - 1];
			}
		}
		else {
			return filearray[index - 1];
		}
		
	}

	void addfile(const file& newFile) { //adds file to currentfolder
		if (filecount < 10) { // checks if there are less then 10 files
			files[filecount] = newFile;
			filecount++;
		}
		else {
			cout << endl << "There is no room for another file, file was not added" << endl;
		}
	}

	void addfolder(folder* newfolder) { //adds folder to currentfolder
		if (foldercount < 5) { // checks if there are less then 5 folders
			folders[foldercount] = newfolder;
			newfolder->parentfolder = this;
			foldercount++;
		}
		else {
			cout << endl << "There is no room for another folder, folder was not added" << endl;
		}
	}
};
