//Name :Syed Ali Ahmed                          department: FBAS/BSSE/F-21
//Roll No :4308                                 university:International Islamic University Islamabad

//Our programme does the following functions :
//Save the students records
//Amend the student records
//Search the student records
//Delete the student records
//Display all the students' records
//By using object - oriented programming approach, we assure the security of data.


#include <iostream>
using namespace std;
struct myDate {
    unsigned int day, month ,year;
};
class student {
    string stNum, stName, stFName;
	unsigned int stCGPA;
    myDate stDOB, stDOA;
public:
	student() {
		this->stNum = "";
		this->stName = "";
		this->stFName = "";
		this->stCGPA = 0;
		this->stDOB.day = 0;
		this->stDOB.month = 0;
		this->stDOB.year = 0;
		this->stDOA.day = 0;
		this->stDOA.month = 0;
		this->stDOA.year = 0;
}
    void read();
	void display();
    bool search(string);
};

void student::display() {
	cout << "Student No         :" << stNum << "  ";
	cout << "Name               :" << stName << "  ";
	cout << "Father name        :" << stFName << "  ";
	cout << "CGPA               :" << stCGPA << "  ";
	cout << "Date of birth   :" << stDOB.day << " / " << " / " <<
		stDOB.month << " / " << stDOB.year << endl;
	cout << "Date of admission  :" << stDOA.day << " / " << " / " <<
		stDOA.month << " / " << stDOA.year << endl;
	cout << endl;
	cout << endl;
}

void student:: read() {
	cout << endl;
	cout << "Enter the student number                     " << endl;
	cin >> stNum;
	cout << "Enter the name" << endl;
	cin >> stName;
	cout << "Enter the father name" << endl;
	cin >> stFName;
	cout << "Enter the CGPA" << endl;
	cin >> stCGPA;
	cout << "Enter the date of birts" << endl;
	cout << "Day " << " ";
	cin >> stDOB.day;
	cout << "month " << " ";
	cin >> stDOB.month;
	cout << "Year " << " ";
	cin >> stDOB.year;
	cout << "Enter the date of admission" << endl;
	cout << "Day " << " ";
	cin >> stDOA.day;
	cout << "month " << " ";
	cin >> stDOA.month;
	cout << "Year " << " ";
	cin >> stDOA.year;
}
void menu() {
	cout << "                                1. To Create DB             " << endl;
	cout << "                                2. To Append  Record        " << endl;
	cout << "                                3. To Search  Record        " << endl;
	cout << "                                4. To Update  Record        " << endl;
	cout << "                                5. To Delete  Record        " << endl;
	cout << "                                6. To Display all Record    " << endl;
	cout << "                                7. To Exit                  " << endl << endl;
}

bool student::search(string regNo) {
	if (stNum == regNo) {
		return true;
}
	else {
		return false;
	}
}



int main()
{
	int size;
	int n;
	cout << "enter the maximum number of records" << endl;
	cin >> size;
	if (size >= 0 && size < 70) {
		student* st = new student[size];
		do {
			menu();
			int option;
			cout << "chose your option" << endl;
			cin >> option;
			switch (option) {
			case 1:
			     //no of student you want to create while creating data base
				cout << "enter the number of student you want to create the data base of" << endl;
				cin >> n;
				for (int i = 0; i < n; i++) {
					cout << "enter the data of "<< i + 1 << " student" << endl;
					st[i].read();
				}
				break;
			case 2:
				cout << "enter the data of " << n +1 << " student" << endl;
				st[n++].read();
				
				break;
			case 3:
			{string regNo;          //student no you want to search
				cout << "enter the student no you want to search for" << endl;
				cin >> regNo;
				int index = -1;
				for (int i = 0; i < n; i++) {
					if (st[i].search(regNo)) {
						index = i;
						break;
					}
				}
				if (index != -1) {
					st[index].display();
				}
				else {
					cout << "enter the valid data" << endl;
				}
				}
				break;
			case 4:
			{string regNo2;       //student no you want to search
			cout << "enter the student no you want to update" << endl;
			cin >> regNo2;
			int index2 = -1;
			for (int i = 0; i < n; i++) {
				if (st[i].search(regNo2)) {
					index2 = i;
					break;
				}
			}
			if (index2 != -1) {
				st[index2].read();
			}
			else {
				cout << "enter the valid data" << endl;
			}
			}
				break;
			case 5:
			{	string regNo3;       //student no you want to delete
				cout << "enter the student no you want to delete" << endl;
				cin >> regNo3;
				int index3 = -1;
				for (int i = 0; i < n; i++) {
					if (st[i].search(regNo3)) {
						index3 = i;
						break;
					}
				}
					if (index3 != -1) {
						for (int i = index3; i < n; i++) {
							st[i] = st[i + 1];
						}
						n--;
						cout << "the record of student No" << index3 << "is DELETED" << endl << endl;
					}
					else {
						cout << "enter the valid data" << endl;
					}

				}
					break;
			case 6:
				for (int i = 0; i < n; i++) {
					cout << "data of" << i + 1 << "student" << endl<<endl;
					st[i].display();
				}
				break;
			case 7:
				exit(0);
				break;
			default:
				cout << "chose the valid option" << endl;
				}
			}
		while (true);
	}
	else {
		cout << "enter the value between 0-71" << endl<<endl;
		main();
	}
	
}


