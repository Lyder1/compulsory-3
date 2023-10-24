#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#pragma warning(disable : 4996)

class folder {
	public:
		string name;
		int size;
		int day;
		int month;
		int year;
		int hour;
		int min;
};
class file {
	public:
		string name;
		int size;
		int date;
};
int main() {
	time_t now = time(0);
	tm* ltm = localtime(&now);

	folder folder1;
	folder1.name = "folder 1";
	folder1.size = 1 + (rand() % 100);
	folder1.day = ltm->tm_mday;
	folder1.month = 1 + ltm->tm_mon;
	folder1.year = 1900 + ltm->tm_year;
	folder1.hour = ltm->tm_hour;
	folder1.min = ltm->tm_min;

	cout << folder1.name << "   " << folder1.day << "." << folder1.month << "." << folder1.year << " " << folder1.hour << ":" << folder1.min << " " << folder1.size << "mb " << endl;

}