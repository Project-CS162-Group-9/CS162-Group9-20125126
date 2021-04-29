#include "MyFunction.h"
using namespace std;

int main()
{
	SchoolYear scYear;

	cout << "Your role (0: staff, 1: student): "; int role; cin >> role;
	if (role == 0) 
	{
		cout << "Input your work as in Project CS162_requirements (1, 2, 3, 4, 5, 6,...): "; int t; cin >> t;
		if ( == 1)		
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
	else // students
	{
	
	}
	
	return 0;
}
