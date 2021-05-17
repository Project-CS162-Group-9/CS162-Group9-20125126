#include "Global.h"
using namespace std;

int main()
{
	bool loginOK, changePassword = false;
	SchoolYear scYear;
	Scoreboard scoreboard;
	newCourse course;
    Semester sem;
    Student student;
    string userName;
	int n = 0, m = 0;

	cout << "Welcome to our Course Registration !\n\n\t- LOGIN SYSTEM -\n";
	cout << "Your role (0: staff, 1: student): "; int role; cin >> role;

	cin.ignore();
	login(role, loginOK, userName, changePassword);
	if (loginOK == false) {
		cout << "You login fail more than 5 times ! Please try again later !\n";
		return 0;
	}
	if (changePassword) {
		cout << "\nYour Password has been changed already ! Now you can exit and login again !\nTHANK YOU !\n";
		return 0;
	}

	if (role == 0)
	{
		cout << "\n\t~ As a Staff, You can do following work in our system: ~\n"
			<< "1. Create a school year (2020-2021, for example)\n"
			<< "2. Create several classes for 1st year students. For example : class 20APCS1..., class 20CLC1..., class 20VP\n"
			<< "3. Add new 1st year students to 1st-year classes.\n"
			<< "4. For quick input, he/she can import a CSV file in a specific class, instead of adding one by one.\n"
			<< "5. He/she does not need to add 2nd year, 3rd year, or 4th-year students, because these students had been added.\n"
			<< "6. Create a semester. Choose the school year that the newly created semester belongs to.\n"
			<< "7. Create a course registration session: start date, end date.\n"
			<< "8. Add a course to this semester: course id, course name, teacher name, number of credits,...\n"
			<< "9. View list of courses.\n"
			<< "10. Update course information.\n"
			<< "11. Delete a course.\n"
			<< "21. Export list of students in a course to a CSV file.\n"
			<< "22. Import the scoreboard of a course.\n"
			<< "23. View the scoreboard of a course.\n"
			<< "24. Update a student result.\n"
			<< "25. View the scoreboard of a class, including final marks, GPA in this semester and the overall.\n\n";
		while (true) {
			cout << "Which work you want to do, input '0' to stop working: "; int t; cin >> t;
			if (t == 0) { cout << "\n\t- Thank you for using our System ! -\n"; return 0; }

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
				importScoreboard("scoreboard.csv", scoreboard, n);
				cout << "Successfully. Now you can see the scoreboard that you just import!!"<< endl;
			}
			if (t == 24)
			{
				updateAStudentResult("scoreboard.csv", scoreboard, n);
				cout << "Your work has been all in CSV File already !\n";
			}
			if (t == 25)
			{
				cout << "Now you can view scoreboard of this class: " << endl;
				viewScoreboardOfClass("scoreboardClass.txt", m);
			}
			if (t == 23)
			{
				cout << "Scoreboard of this course: " << endl;
				viewScoreboardOfCourse(scoreboard,n);
			}
		}
	}
	else    // students' work
	{
		cout << "\n\t~ As a Student, You can do following work in our system: ~\n"
		<< "13. Enroll in a course.\n"
		<< "14. View list of enrolled courses.\n"
		<< "15. Remove a course from the enrolled list.\n"
		<< "16. View list of his/her courses. He/she will study these courses in this semester.\n"
		<< "17. View list of classes.\n"
		<< "18. View list of students in a class (for example, 20APCS1...)\n"
		<< "19. View list of courses.\n"
		<< "20. View list of students in a course.\n"
		<< "26. View his/her scoreboard.\n\n";
		while (true) {
			cout << "Which work you want to do, input '0' to stop working: "; int t; cin >> t;
			if (t == 0) { cout << "\n\t- Thank you for using our System ! -\n"; return 0; }

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
				cout << " Enter your ID to view your scoreboard: "<<endl;
				int ID;
				cin >> ID;
				cout << "Now you can view your scoreboard : " << endl;
				viewScoreboard1Stu("scoreboard1.txt", ID);
			}
		}
	}

	return 0;
}