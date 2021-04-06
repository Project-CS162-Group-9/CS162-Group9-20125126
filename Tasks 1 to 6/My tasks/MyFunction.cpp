#include "MyFunction.h"
#include<bits/stdc++.h>
using namespace std;

void loadStaff(string path, Staff& sta)
{
	ifstream fin;
	fin.open(path);
	if (fin.is_open()) {
		getline(fin, sta.fullName);
		getline(fin, sta.account);
		getline(fin, sta.password);
	}
	else cout << "Can't open file!\n";
	fin.close();
}
void loadClass(string path, Class& cl)
{
	ifstream fin;
	fin.open(path);
	if (fin.is_open()) {
		getline(fin, cl.name);
	}
	else cout << "Can't open file!\n";
	fin.close();
}
void createASchoolYear(string path, SchoolYear& scYear)
{
	ifstream fin;
	fin.open(path);
	if (fin.is_open())
	{
		fin >> scYear.nStaff; fin.ignore();
		scYear.staffs = new Staff[scYear.nStaff];
		for (int i = 0; i < scYear.nStaff; ++i)
			loadStaff("_staff.txt", scYear.staffs[i]);

		fin >> scYear.nClass; fin.ignore();
		scYear.classes = new Class[scYear.nClass];
		for (int i = 0; i < scYear.nClass; ++i)
			loadClass("_classes.txt", scYear.classes[i]);
	}
	else cout << "Can't open file!\n";
	fin.close();
}
void save2File(string path, SchoolYear& scYear)
{
	ofstream fout;
	fout.open(path);
	if (fout.is_open()) {
		fout << scYear.nStaff << '\n';
		for (int i = 0; i < scYear.nStaff; ++i)
			fout << scYear.staffs[i].fullName << '\n' << scYear.staffs[i].account << '\n' << scYear.staffs[i].password << '\n';

		fout << scYear.nClass << '\n';
		for (int i = 0; i < scYear.nClass; ++i)
			fout << scYear.classes[i].name << '\n';
	}
	else cout << "Can't open file!\n";
	fout.close();
}