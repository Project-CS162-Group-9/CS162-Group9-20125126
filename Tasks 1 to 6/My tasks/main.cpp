#include "MyFunction.h"
#include<bits/stdc++.h>
using namespace std;

int main()
{
	SchoolYear scYear;

	cout << "Your role (0: staff, 1: student): "; int role; cin >> role;
	if (role == 0) {
		cout << "Input your work as in Project CS162_requirements (1, 2, 3, 4, 5, 6,...): "; int task; cin >> task;
		if (task == 1)		// Using: "_staffs.txt", "_classes.txt", "_semesters.txt"
			task1_createASchoolYear("1_outputSchoolYear.txt", scYear);
		if (task == 2)		// Using: "_classes.txt"
			task2_createClasses1stYearStudent("2_classes1stYearStudent.txt", scYear);
		if (task == 3)		// Using: "_students.txt"
			task3_addNew1stYearStudents("3_studentsIn1stYearClasses.txt", scYear);
		if (task == 4) {	// Using: "_CSV file.csv"
			Class cl;
			task4_importCSVFileStudent1Class("4_studentsIn1ClassFromCSVfile.txt", cl);
		}
		cout << "Your work has been all in Text File already !\n";
	}

	return 0;
}