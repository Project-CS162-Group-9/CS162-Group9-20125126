#ifndef _MYFUNCTION_H_
#define _MYFUNCTION_H_
#include<bits/stdc++.h>
using namespace std;

struct Staff {
	string fullName, account, password;
};
struct Student {
	int ID, day, month, year, gender;	// 0: male, 1: female
	string fullName, account, password;
};
struct Class {
	string name;
	//int nStudent; Student* students;
};
struct SchoolYear {
	int nStaff;	Staff* staffs;
	int nClass;	Class* classes;
};

void loadStaff(string path, Staff& sta);
void loadClass(string path, Class& cl);
void createASchoolYear(string path, SchoolYear& scYear);
void save2File(string path, SchoolYear& scYear);

#endif