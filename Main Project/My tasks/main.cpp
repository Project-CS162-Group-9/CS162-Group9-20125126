#include "Global.h"
using namespace std;

int main()
{
	bool loginOK;
	SchoolYear scYear;
	Scoreboard scoreboard;
	newCourse course;
    Semester sem;
    Student student;
    string userName;
	cout << "Your role (0: staff, 1: student): "; int role; cin >> role;

	cin.ignore();
	login(role, loginOK, userName);
	if (loginOK == false) {
		cout << "You login fail more than 5 times ! Please try again later !\n";
		return 0;
	}

	if (role == 0)
	{
		while (true) {
			cout << "Input which work in Project (1, 2, 3,...) Staff want to do, input '0' to stop working: "; int t; cin >> t;
			if (t == 0) { cout << "Thank you for using our Project !\n"; return 0; }

			if (t == 1) {
				createASchoolYear("_staffs.txt", "_classes.txt", "_semesters.txt", "1_outputSchoolYear.txt", scYear);
				cout << "Your work has been all in Text File already !\n";
			}
			if (t == 2) {
				createClasses1stYearStudent("_classes.txt", "2_classes1stYearStudent.txt", scYear);
				cout << "Your work has been all in Text File already !\n";
			}
			if (t == 3) {
				addNew1stYearStudents("_students.txt", "3_studentsIn1stYearClasses.txt", scYear);
				cout << "Your work has been all in Text File already !\n";
			}
			if (t == 4) {
				Class cl;
				importCSVFileStudent1Class("_CSV file.csv", "4_studentsIn1ClassFromCSVfile.txt", cl);
				cout << "Your work has been all in Text File already !\n";
			}

			if (t == 5) {
				addOnly1stYearStudentsToClasses("_students.txt", "5_AddOnly1stYearStudents.txt", scYear);
				cout << "Your work has been all in Text File already !\n";
			}


			if (t == 6) {
				createASemester_SchoolyearThatSemesterBelongsTo("_createNewSemester.txt", "6_createASemesters_SchoolyearThatSemesterBelongsTo.txt", sem);
				cout << "Your work has been all in Text File already !\n";
			}

			if (t == 7)
            {
                createCourseSession("7_courseSession.txt", course);
            }

            if (t == 8)
            {
                addCourse("8_courses.txt");
            }

            if (t == 9)
            {
                viewListOfCourses("8_courses.txt");
            }

            if (t == 10)
            {
                updateCourseInformation("8_courses.txt", "8_courses.txt");
            }

            if (t == 11)
            {
                deleteCourse("8_courses.txt", "8_courses.txt");
            }

			if (t == 21)
			{
				exportListOfStudentToCSV("listofstudent.txt", "studentCSV.csv");
				cout << "Your work has been all in CSV File already !\n";
			}
			if (t == 22)
			{
				importScoreboard("scoreboard.csv", scoreboard);
				cout << "Successfully. Now you can see the scoreboard that you just import!!"<< endl;
			}
			if (t == 24)
			{
				updateAStudentResult("scoreboard.csv", scoreboard);
				cout << "Your work has been all in CSV File already !\n";
			}
			if (t == 25)
			{
				cout << "Now you can view scoreboard of this class: " << endl;
				viewScoreboardOfClass("scoreboardClass.txt");
			}

			if (t == 23)
			{
				cout << "Scoreboard of this course: " << endl;
				viewScoreboardOfCourse(scoreboard);
			}
		}
	}
	else    // students' work
	{
		while (true) {
			cout << "Input which work in Project (1, 2, 3,...) a Student want to do, input '0' to stop working: "; int t; cin >> t;
			if (t == 0) { cout << "Thank you for using our Project !\n"; return 0; }

			if (t == 13)
            {
                string tmp = userName + "13_enrollCourse.txt";
                enrollCourse(student, tmp, tmp);
            }

			if (t == 14)
            {
                string tmp = userName + "13_enrollCourse.txt";
                viewEnrollCourse("8_courses.txt", tmp);
            }

            if (t == 15)
            {
                string tmp = userName + "13_enrollCourse.txt";
                removeEnrollCourse(tmp, tmp);
            }

            if (t == 16)
            {
                string tmp = userName + "13_enrollCourse.txt";
                viewEnrollCourse("8_courses.txt", tmp);
            }

            if (t == 17)
            {
                viewListOfClass("_classes.txt");
            }


			if (t == 18) {
				cout << "You can View list of students in a class (for example: 20APCS1,...):\n";
				Class c; viewListOfStudentInAClass(c);
			}

			if (t == 19)
            {
                viewListOfCourses("8_courses.txt");
            }

			if (t == 20) {
				cout << "You can View list of students in a class (for example: 20APCS1,...):\n";
				Class c; viewListOfStudentInAClass(c);
			}

			if (t == 26)
			{
				cout << " Enter your full name to view your scoreboard: "<<endl;
				string name;
				cin>> name;
				cout << "Now you can view your scoreboard : " << endl;
				viewScoreboard1Stu("scoreboard1.txt");
			}

		}
	}

	return 0;
}
