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

void loadStaff(string path, SchoolYear& scYear);
void loadClass(string path, SchoolYear& scYear);
void loadSemester(string path, SchoolYear& scYear);
void saveToFile(string path, SchoolYear& scYear);
void task1_createASchoolYear(string path_staffs, string path_classes, string path_semesters, string pathOutput, SchoolYear& scYear);
void task2_createClasses1stYearStudent(string path_classes, string pathOutput, SchoolYear& scYear);
void task3_addNew1stYearStudents(string path_students, string pathOutput, SchoolYear& scYear);
void task4_importCSVFileStudent1Class(string path_CSV, string pathOutput, Class& cl);
void task5_addOnly1stYearStudentsToClasses(string path_students, string pathOutput, SchoolYear& scYear);
void task6_createASemester_SchoolyearThatSemesterBelongsTo(string path_NewSemester, string pathOutput, Semester& sem);

#endif
