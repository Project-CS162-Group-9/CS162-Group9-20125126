#ifndef _MYFUNCTION_H_
#define _MYFUNCTION_H_
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

struct Date {
	int day, month, year;
};
struct Staff {
	string fullName, account, password;
};
struct Student {
	int year;
	string No, studentID, firstName, lastName, gender, DOB, socialID;
	string course[5];
	int courseCount;
	double semesterGPA, overallGPA;
	double* finall;
};
struct Class {
	int year;
	string name;		//like 20APCS1, 20CLC1, 20VP
	int nStudent; Student* students;
};
struct Semester {
	string name;		//Fall, Summer, Autumn
	string schoolYear;	//like 2020-2021
	Date start, end;
};
struct SchoolYear {
	string name;		//like 2020-2021
	Semester* semesters;
	int nStaff; Staff* staffs;
	int nClass; Class* classes;
};
struct newCourse {
	string ID, nameCourses, teacher, session1, session2, day1, day2;
	int credit, maxStudent;
	int semester;
};

struct Score {
	int total, final, midterm, other;
};
struct Scoreboard {
	Score* score;
	string nameCourse, ID;
	int nums;
	Student* student;
};


void loadStaff(string path, SchoolYear& scYear);
void loadClass(string path, SchoolYear& scYear);
void loadSemester(string path, SchoolYear& scYear);
void saveToFile(string path, SchoolYear& scYear);
void createASchoolYear(string path_staffs, string path_classes, string path_semesters, string pathOutput, SchoolYear& scYear);
void createClasses1stYearStudent(string path_classes, string pathOutput, SchoolYear& scYear);
void addNew1stYearStudents(string path_students, string pathOutput, SchoolYear& scYear);
void importCSVFileStudent1Class(string path_CSV, string pathOutput, Class& cl);
void addOnly1stYearStudentsToClasses(string path_students, string pathOutput, SchoolYear& scYear);
void createASemester_SchoolyearThatSemesterBelongsTo(string path_NewSemester, string pathOutput, Semester& sem);

void createCourseSession(string pathOutput, newCourse& c);
void addCourse(string path_addCourses);
void viewListOfCourses(string pathInput);
void updateCourseInformation(string pathInput, string pathOutput);
void deleteCourse(string pathInput, string pathOutput);

void enrollCourse(Student &s, string pathInput,string pathOutput);
void viewEnrollCourse(string pathInputCourse, string pathInputStudent);
void removeEnrollCourse(string pathInput,string pathOutput);

void viewStudentCourse(Student &s, newCourse* &nc);
void viewListOfClass(string pathInput);
void viewListOfStudentInAClass(Class &c);

void importScoreboard(string pathIn, Scoreboard& scoreboard);
void exportListOfStudentToCSV(string pathIn,string pathOut);
void viewScoreboardOfCourse(Scoreboard& scoreboard);
void updateAStudentResult(string path, Scoreboard& scoreboard);
void viewScoreboardOfClass(string path);
void viewScoreboard1Stu(string path,int ID);

#endif
