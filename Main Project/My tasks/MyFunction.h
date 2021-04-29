#ifndef _MYFUNCTION_H_
#define _MYFUNCTION_H_
#include<bits/stdc++.h>
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
	int course[6];
	int courseCount;
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
struct Scoreboard{
	string name Course, ID;
	Class class;
	double* total, midterm, final, midterm, other; 
}

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

void createCourseSession(string path_createSession, string pathOutput, newCourse& c);
void addCourse(string path_addCourses, string pathOutput);
void viewListOfCourses(newCourse* nc, int nums);
void updateCourseSession(newCourse* crs);

void deleteCourse(SchoolYear* schYear, newCourse* crs, string crsID);
void enrollCourse(Student &s, int courseID);
void viewEnrollCourse(Student &s);
void removeEnrollCourse(Student &s, int courseID);

#endif
