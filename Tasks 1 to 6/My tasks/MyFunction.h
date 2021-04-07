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
	string ID, fullName, gender, account, password;
	Date dob;
};
struct Class {
	int year;
	string name;	//20APCS1, 20CLC1, 20VP
	int nStudent; Student* students;
};
struct Semester {
	string name;	//Fall, Summer, Autumn
	//int year;
	Date start, end;
};
struct SchoolYear {	
	string name;	//2020-2021
	int nSemester; Semester* semesters;
	int nStaff; Staff* staffs;
	int nClass; Class* classes;
};

void loadStaff(string path, SchoolYear& scYear);
void loadClass(string path, SchoolYear& scYear);
void loadSemester(string path, SchoolYear& scYear);
void saveToFile(string path, SchoolYear& scYear);
void task1_createASchoolYear(string path, SchoolYear& scYear);
void task2_createClasses1stYearStudent(string path, SchoolYear& scYear);

#endif