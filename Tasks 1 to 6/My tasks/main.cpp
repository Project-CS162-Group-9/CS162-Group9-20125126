#include "MyFunction.h"
#include<bits/stdc++.h>
using namespace std;

int main()
{
	SchoolYear scYear;

	cout << "Your role (0: staff, 1: student): "; int role; cin >> role;
	if (role == 0) {
		cout << "Input your work as in Project CS162_requirements (1, 2, 3, 4, 5, 6,...): "; int task; cin >> task;
		if (task == 1)		
			task1_createASchoolYear("_staffs.txt", "_classes.txt", "_semesters.txt", "1_outputSchoolYear.txt", scYear);
		if (task == 2)		
			task2_createClasses1stYearStudent("_classes.txt", "2_classes1stYearStudent.txt", scYear);
		if (task == 3)		
			task3_addNew1stYearStudents("_students.txt", "3_studentsIn1stYearClasses.txt", scYear);
		if (task == 4) {	
			Class cl;
			task4_importCSVFileStudent1Class("_CSV file.csv", "4_studentsIn1ClassFromCSVfile.txt", cl);
		}
		if (task == 5)		
			task5_addOnly1stYearStudentsToClasses("_students.txt", "5_AddOnly1stYearStudents.txt", scYear);
		cout << "Your work has been all in Text File already !\n";
		if (task == 6) {	
			Semester sem;
			task6_createASemester_SchoolyearThatSemesterBelongsTo("_createNewSemester.txt", "6_createASemesters_SchoolyearThatSemesterBelongsTo.txt", sem);
		}
	}
	return 0;
}