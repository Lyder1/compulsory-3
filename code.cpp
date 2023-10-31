#include <iostream>
#include <cstdlib>
#include <ctime>
#include "header.h"
using namespace std;
#pragma warning(disable : 4996)

folder root("root");
folder currentfolder = root;
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
int main() {
	string foldername;
	string filename;
	int answer;
	cout << "press 1 to add folder" << endl;
	cout << "press 2 to add file" << endl;
	cout << "press 3 to enter folder" << endl;
	cin >> answer;
	switch (answer) {
	case 1:
		if (answer == 1) {
			cout << "folder name: ";
			cin >> foldername;
			folder* subfolder1 = new folder(foldername);
			currentfolder.addfolder(subfolder1);
			break;
		}
	case 2:
		cout << "file name: ";
		cin >> filename;
		currentfolder.addfile(file(filename));
		break;
	}
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

/*
bugs:
if folders or files has a space in it, it crashes
*/
