#include "Global.h"
using namespace std;

int main()
{
	bool loginOK;
	SchoolYear scYear;

	cout << "Your role (0: staff, 1: student): "; int role; cin >> role;

	cin.ignore();
	login(role, loginOK);
	if (loginOK == false) {
		cout << "You login fail more than 5 times ! Please try again later !\n";
		return 0;
	}

	if (role == 0) 
	{
		while (true) {
			cout << "Input which work in Project (1, 2, 3,...) Staff want to do, input '0' to stop working: "; int t; cin >> t;
			if (t == 0) { cout << "Thank you for using out Project !\n"; return 0; }

			if (t == 1)
				createASchoolYear("_staffs.txt", "_classes.txt", "_semesters.txt", "1_outputSchoolYear.txt", scYear);
			if (t == 2)
				createClasses1stYearStudent("_classes.txt", "2_classes1stYearStudent.txt", scYear);
			if (t == 3)
				addNew1stYearStudents("_students.txt", "3_studentsIn1stYearClasses.txt", scYear);
			if (t == 4) {
				Class cl;
				importCSVFileStudent1Class("_CSV file.csv", "4_studentsIn1ClassFromCSVfile.txt", cl);
			}
			if (t == 5)
				addOnly1stYearStudentsToClasses("_students.txt", "5_AddOnly1stYearStudents.txt", scYear);
			cout << "Your work has been all in Text File already !\n";
			if (t == 6) {
				Semester sem;
				createASemester_SchoolyearThatSemesterBelongsTo("_createNewSemester.txt", "6_createASemesters_SchoolyearThatSemesterBelongsTo.txt", sem);
			}
		}
	}
	else    // students' work
	{
		while (true) {
			cout << "Input which work in Project (1, 2, 3,...) a Student want to do, input '0' to stop working: "; int t; cin >> t;
			if (t == 0) { cout << "Thank you for using out Project !\n"; return 0; }
			
			if (t == 19) {
				cout << "You can View list of students in a class (for example: 20APCS1,...):\n";
				Class c; viewListOfStudentInAClass(c);
			}

		}
	}
	
	return 0;
}
