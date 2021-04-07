#include "MyFunction.h"
#include<bits/stdc++.h>
using namespace std;

int main()
{
	SchoolYear scYear;

	cout << "Your role (0: staff, 1: student): "; int role; cin >> role;
	if (role == 0) {
		cout << "Input your work as in Project CS162_requirements (1, 2,...): "; int task; cin >> task;
		if (task == 1)
			task1_createASchoolYear("1_outputSchoolYear.txt", scYear);
		if (task == 2)
			task2_createClasses1stYearStudent("2_classes1stYearStudent.txt", scYear);
		if (task == 3)
			task3_addNew1stYearStudents("3_studentsIn1stYearClasses.txt", scYear);
	}

	return 0;
}