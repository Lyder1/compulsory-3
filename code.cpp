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

};

class folder {
	public:
		string name;
		int size;
		int day;
		int month;
		int year;
		int hour;
		int min;
		file files[10];

		/*
		folder* folders[5] = { 0 };

		folder* parentFolder = 0;

		folder()
		{
			name = "unknown";
		}

		folder(string setName, folder* setParentFolder)
		{
			name = setName;
			parentFolder = setParentFolder;
		}

		folder* GoBack()
		{
			if (parentFolder == 0)
			{
				cout << "This folder doesnt have a parent!";
			}
		}

		void AddFile()
		{
			for (int i = 0; i < 10; i++)
			{
				if (files[i] == 0)
				{
					files[i] = new file();
					return;
				}

				cout << "There are no available spots for a new file!";
			}


				
		}
		*/
};

int newfolder() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	string foldername;
	string filename;
	cin >> foldername;
	cout << "enter name of file in folder" << endl;
	cin >> filename;

	folder folder1;
	folder1.name = foldername;
	folder1.size = 1 + (rand() % 100);
	folder1.day = ltm->tm_mday;
	folder1.month = 1 + ltm->tm_mon;
	folder1.year = 1900 + ltm->tm_year;
	folder1.hour = ltm->tm_hour;
	folder1.min = ltm->tm_min;

	file file1;
	file1.name = filename;
	file1.size = 1 + (rand() % 100);
	file1.day = ltm->tm_mday;
	file1.month = 1 + ltm->tm_mon;
	file1.year = 1900 + ltm->tm_year;
	file1.hour = ltm->tm_hour;
	file1.min = ltm->tm_min;

	folder1.files[0] = file1;
	cout << endl << foldername << ":" << endl;
	for (int i = 0; i < 11; i++) {
		cout << folder1.files[i].name << "   " << folder1.files[i].day << "." << folder1.files[i].month << "." << folder1.files[i].year << " " << folder1.files[i].hour << ":" << folder1.files[i].min << " " << folder1.files[i].size << "mb " << endl;
	}

	return 0;
}
int main() {
	int answer;
	cout << "make folder?" << endl << "enter 1 for yes" << endl;
	cin >> answer;
	if (answer == 1) {
		newfolder();
	}

	/*
	folder* currentFolder;

	folder* subFolder = new folder("name", 0);

	if (currentFolder->folders[0] != 0) currentFolder->folders[0] = subFolder;

	currentFolder = currentFolder->folders[0];

	if (currentFolder->parentFolder != 0) currentFolder = currentFolder->parentFolder;

	currentFolder->GoBack();

	currentFolder->name;

	*/

	main();
}