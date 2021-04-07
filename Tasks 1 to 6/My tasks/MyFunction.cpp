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
	//delete[] scYear.staffs;
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

	saveToFile(path, scYear);
}
void task2_createClasses1stYearStudent(string path, SchoolYear& scYear)
{
	loadClass("_classes.txt", scYear);
	ofstream fout;
	fout.open(path);
	if (fout.is_open()) {
		fout << "The 1st yeat classes:\n";
		for (int i = 0; i < scYear.nClass; ++i)
			if (scYear.classes[i].year == 1) fout << scYear.classes[i].name << '\n';
		fout << '\n';
	}
	else cout << "Can't open file!\n";
	fout.close();
}
void task3_addNew1stYearStudents(string path, SchoolYear& scYear)
{
	ifstream fin;
	fin.open("_students.txt");
	if (!fin.is_open()) { cout << "Can't open file !\n"; return; }

	int nTemp; fin >> nTemp;
	scYear.nClass += nTemp;	//Updated the number of classes in School Year
	Student* temps = new Student[nTemp];
	for (int i = 0; i < nTemp; ++i) {
		fin >> temps[i].year; fin.ignore();
		getline(fin, temps[i].studentID);
		getline(fin, temps[i].firstName);
		getline(fin, temps[i].lastName);
		getline(fin, temps[i].gender);
		getline(fin, temps[i].DOB);
		getline(fin, temps[i].socialID);
	}
	fin.close();

	ofstream fout;
	fout.open(path);
	if (fout.is_open()) {
		fout << "Class 20APCS1:\n";
		for (int i = 0; i < nTemp; ++i)
			if (temps[i].year ==1 && temps[i].studentID[4] == '5') {
				fout << temps[i].studentID << '\n' << temps[i].firstName << " " << temps[i].lastName << '\n' << temps[i].gender << '\n' << temps[i].DOB << '\n' << "Social ID: " << temps[i].socialID << '\n';
				fout << '\n';
			}
		fout << "Class 20CLC1:\n";
		for (int i = 0; i < nTemp; ++i)
			if (temps[i].year == 1 && temps[i].studentID[4] == '7') {
				fout << temps[i].studentID << '\n' << temps[i].firstName << " " << temps[i].lastName << '\n' << temps[i].gender << '\n' << temps[i].DOB << '\n' << "Social ID: " << temps[i].socialID << '\n';
				fout << '\n';
			}
		fout << "Class 20VP:\n";
		for (int i = 0; i < nTemp; ++i)
			if (temps[i].year == 1 && temps[i].studentID[4] == '6') {
				fout << temps[i].studentID << '\n' << temps[i].firstName << " " << temps[i].lastName << '\n' << temps[i].gender << '\n' << temps[i].DOB << '\n' << "Social ID: " << temps[i].socialID << '\n';
				fout << '\n';
			}
	}
	else cout << "Can't open file !\n";
	fout.close();
}
void task4_importCSVFileStudent1Class(string path, Class& cl)
{
	ifstream fin;
	fin.open("_CSV file.csv");
	if (!fin.is_open()) { cout << "Can't open file !\n"; return; }

	fin >> cl.nStudent; fin.ignore();
	cl.students = new Student[cl.nStudent];

	getline(fin, cl.name);
	for (int i = 0; i < cl.nStudent; ++i) {
		getline(fin, cl.students[i].No, ',');
		getline(fin, cl.students[i].studentID, ',');
		getline(fin, cl.students[i].firstName, ',');
		getline(fin, cl.students[i].lastName, ',');
		getline(fin, cl.students[i].gender, ',');
		getline(fin, cl.students[i].DOB, ',');
		getline(fin, cl.students[i].socialID, '\n');
	}
	fin.close();

	ofstream fout;
	fout.open(path);
	if (fout.is_open()) {
		fout << "Class " << cl.name << '\n';
		for (int j = 0; j < cl.nStudent; ++j)
		{
			fout << "No: " << cl.students[j].No << '\n';
			fout << "Student ID: " << cl.students[j].studentID << '\n';
			fout << "First name: " << cl.students[j].firstName << '\n';
			fout << "Last name: " << cl.students[j].lastName << '\n';
			fout << "Gender: " << cl.students[j].gender << '\n';
			fout << "Date of Birth: " << cl.students[j].DOB << '\n';
			fout << "Social ID: " << cl.students[j].socialID << '\n' << '\n';
		}
	}
	else cout << "Can't open file !\n";
	fout.close();
}
void task5_addOnly1stYearStudentsToClasses(string path, SchoolYear& scYear)
{
	ifstream fin;
	fin.open("_students.txt");
	if (!fin.is_open()) { cout << "Can't open file !\n"; return; }

	int nTemp; fin >> nTemp;
	scYear.nClass += nTemp;	//Updated the number of classes in School Year
	Student* temps = new Student[nTemp];
	for (int i = 0; i < nTemp; ++i) {
		fin >> temps[i].year; fin.ignore();
		getline(fin, temps[i].studentID);
		getline(fin, temps[i].firstName);
		getline(fin, temps[i].lastName);
		getline(fin, temps[i].gender);
		getline(fin, temps[i].DOB);
		getline(fin, temps[i].socialID);
	}
	fin.close();

	ofstream fout;
	fout.open(path);
	if (fout.is_open()) {
		fout << "Class 20APCS1:\n";
		for (int i = 0; i < nTemp; ++i)
			if (temps[i].year == 1 && temps[i].studentID[4] == '5') {
				fout << temps[i].studentID << '\n' << temps[i].firstName << " " << temps[i].lastName << '\n' << temps[i].gender << '\n' << temps[i].DOB << '\n' << "Social ID: " << temps[i].socialID << '\n';
				fout << '\n';
			}
		fout << "Class 20CLC1:\n";
		for (int i = 0; i < nTemp; ++i)
			if (temps[i].year == 1 && temps[i].studentID[4] == '7') {
				fout << temps[i].studentID << '\n' << temps[i].firstName << " " << temps[i].lastName << '\n' << temps[i].gender << '\n' << temps[i].DOB << '\n' << "Social ID: " << temps[i].socialID << '\n';
				fout << '\n';
			}
		fout << "Class 20VP:\n";
		for (int i = 0; i < nTemp; ++i)
			if (temps[i].year == 1 && temps[i].studentID[4] == '6') {
				fout << temps[i].studentID << '\n' << temps[i].firstName << " " << temps[i].lastName << '\n' << temps[i].gender << '\n' << temps[i].DOB << '\n' << "Social ID: " << temps[i].socialID << '\n';
				fout << '\n';
			}
	}
	else cout << "Can't open file !\n";
	fout.close();
}