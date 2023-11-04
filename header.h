#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#pragma warning(disable : 4996)

class file {
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
	file(string setname) {
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

class folder {
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

	folder(string setName){
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
	int errorcontrolint() {
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
			cin >> input;
		}
		return input;
	}

	void printfiles() {
		for (int i = 0; i < filecount; i++) {
			if (files[i].min < 10) {
			cout << i+1 << ". " << files[i].name << " (File)   " << files[i].day << "." << files[i].month << "." << files[i].year << " " << files[i].hour << ":0" << files[i].min << "   " << files[i].size << "mb" << endl;
			}else{
				cout << i+1 << ". " << files[i].name << " (File)   " << files[i].day << "." << files[i].month << "." << files[i].year << " " << files[i].hour << ":" << files[i].min << "   " << files[i].size << "mb" << endl;
			}
		}
		cout << endl;
	}

	void printfolders() {
		cout << endl;
		for (int i = 0; i < foldercount; i++) {
			if (folders[i]->min < 10) {
			cout << i+1 << ". " << folders[i]->name << " (Folder)   " << folders[i]->day << "." << folders[i]->month << "." << folders[i]->year << " " << folders[i]->hour << ":0" << folders[i]->min << "   " << folders[i]->size << "mb" << endl;
			}else{
				cout << i+1 << ". " << folders[i]->name << " (Folder)   " << folders[i]->day << "." << folders[i]->month << "." << folders[i]->year << " " << folders[i]->hour << ":" << folders[i]->min << "   " << folders[i]->size << "mb" << endl;
			}
		}
	}

	void renamefolder() {
		string newname;
		if (foldercount == 0) {
			cout << "You do not have a folder to rename" << endl << endl;
		}else{
			int index;
			cout << "What folder do you want to rename?" << endl << "Folder number:";
			index = errorcontrolint();
			if (index >= 1 && index <= foldercount) {
				cout << "What do you want to rename the folder?" << endl << "New folder name:";
				newname = errorcontrolstr();
				folders[index - 1]->name = newname;
				printfolders();
				printfiles();

			}
			else {
				while (index < 1 || index > foldercount) {
					cout << "You do not have a folder with that number, please reenter" << endl << "Folder number:";
					index = errorcontrolint();
				}
				cout << "What do you want to rename the folder?" << endl << "New folder name:";
				newname = errorcontrolstr();
				folders[index - 1]->name = newname;
				printfolders();
				printfiles();
			}
		}
	}

	void renamefile() {
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
				printfolders();
				printfiles();
			}
		}
	}

	void biggestfile() {
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

		if (foldercount == 0) {
			cout << "You do not have a folder to check" << endl << endl;
		}else {
			cout << "What folder do you want to check?" << endl << "Folder number:";
			index = errorcontrolint();
			if (folders[index - 1]->filecount == 0) {
				cout << endl << "This folder is empty" << endl;
			}else if (index >= 1 && index <= foldercount) {
				for(int i = 0; i < folders[index-1]->filecount; i ++){
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
					cout << endl << "Biggest file in searched folder: " << bfname << "   " << bfday << "." << bfmonth << "." << bfyear << " " << bfhour << ":0" << bfmin << "   " << bfsize << "mb" << endl << endl;
				}
				else {
					cout << endl << "Biggest file in searched folder: " << bfname << "   " << bfday << "." << bfmonth << "." << bfyear << " " << bfhour << ":" << bfmin << "   " << bfsize << "mb" << endl << endl;
				}
			}
			else {
				while (index < 1 || index > foldercount) {
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
		printfolders();
		printfiles();
	}

	string getname() {
		return name;
	}

	folder** getsubfolder() {
		return folders;
	}

	folder* enterfolder(folder* filearray[]) {
		if (foldercount == 0 && parentfolder == 0) {
			cout << "You do not have any folder to enter so a folder has been added automatically" << endl;
			folder* subfolder1 = new folder("New folder");
			addfolder(subfolder1);
			printfolders();
			printfiles();
		}
		int index;
		cout << "Enter a folder number to enter or enter (-1) to return to previous folder" << endl << "Folder number:";
		index = errorcontrolint();

		if (index >= 1 && index <= foldercount) {
			folders[index - 1]->getname();
		}
		if(index > foldercount){
			while (index < 1 || index > foldercount) {
				cout << "You do not have a folder with that number, please reenter" << endl << "Folder number:";
				index = errorcontrolint();
				
			}
			return filearray[index - 1];
		}
		if (index == -1) {
			if(parentfolder != 0){
				return parentfolder;
			}else {
				cout << "You are in root folder, please enter a folder number" << endl << "Folder number:";
				while (index < 1 || index > foldercount) {
					index = errorcontrolint();
					if (index == -1) {
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

	void addfile(const file& newFile) {
		if (filecount < 10) {
			files[filecount] = newFile;
			filecount++;
		}
		else {
			cout << endl << "There is no room for another file, file was not added" << endl;
		}
	}

	void addfolder(folder* newfolder) {
		if (foldercount < 5) {
			folders[foldercount] = newfolder;
			newfolder->parentfolder = this;
			foldercount++;
		}
		else {
			cout << endl << "There is no room for another folder, folder was not added" << endl;
		}
	}
};
