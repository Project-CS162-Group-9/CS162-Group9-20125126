#include "MyFunction.h"
#include<bits/stdc++.h>
using namespace std;

void loadStaff(string path, SchoolYear& scYear)
{
	ifstream fin;
	fin.open(path);
	if (fin.is_open()) {
		fin >> scYear.nStaff; fin.ignore(1000, '\n');
		scYear.staffs = new Staff[scYear.nStaff];

		for (int i = 0; i < scYear.nStaff; ++i) {
			getline(fin, scYear.staffs[i].fullName);
			getline(fin, scYear.staffs[i].account);
			getline(fin, scYear.staffs[i].password);
		}
	}
	else cout << "Can't open file!\n";
	fin.close();
}
void loadClass(string path, SchoolYear& scYear)
{
	ifstream fin;
	fin.open(path);
	if (fin.is_open()) {
		fin >> scYear.nClass;
		scYear.classes = new Class[scYear.nClass];

		for (int i = 0; i < scYear.nClass; ++i) {
			fin >> scYear.classes[i].year; fin.ignore();
			getline(fin, scYear.classes[i].name);
		}
	}
	else cout << "Can't open file!\n";
	fin.close();
}
void loadSemester(string path, SchoolYear& scYear)
{
	ifstream fin;
	fin.open(path);
	if (fin.is_open()) {
		fin >> scYear.nSemester; fin.ignore();
		scYear.semesters = new Semester[scYear.nSemester];

		for (int i = 0; i < scYear.nSemester; ++i) {
			getline(fin, scYear.semesters[i].name);
		}
	}
	else cout << "Can't open file!\n";
	fin.close();
}
void saveToFile(string path, SchoolYear& scYear)
{
	ofstream fout;
	fout.open(path);
	if (fout.is_open()) {
		fout << "The staffs:\n";
		for (int i = 0; i < scYear.nStaff; ++i)
			fout << scYear.staffs[i].fullName << '\n' << scYear.staffs[i].account << '\n' << scYear.staffs[i].password << '\n';
		fout << '\n';

		fout << "The classes:\n";
		for (int i = 0; i < scYear.nClass; ++i)
			fout << scYear.classes[i].year << " " << scYear.classes[i].name << '\n';
		fout << '\n';

		fout << "The Semesters:\n";
		for (int i = 0; i < scYear.nSemester; ++i)
			fout << scYear.semesters[i].name << '\n';
	}
	else cout << "Can't open file!\n";
	fout.close();
}
void task1_createASchoolYear(string path, SchoolYear& scYear)
{
	//cout << "Pls input Name of School year, like 2020-2021: "; getline(cin, scYear.name);
	loadStaff("_staffs.txt", scYear);
	loadClass("_classes.txt", scYear);
	loadSemester("_semesters.txt", scYear);

	saveToFile("_outputSchoolYear.txt", scYear);
}

