#include "MyFunction.h"
#define foru(i, a, b) for (int i = a; i <= b; ++i)
#include <iostream>
#include<fstream>
using namespace std;

void loadStaff(string path, SchoolYear &scYear)
{
	ifstream fin;
	fin.open(path);
	if (fin.is_open())
	{
		fin >> scYear.nStaff;
		fin.ignore();
		scYear.staffs = new Staff[scYear.nStaff];

		for (int i = 0; i < scYear.nStaff; ++i)
		{
			getline(fin, scYear.staffs[i].fullName);
			getline(fin, scYear.staffs[i].account);
			getline(fin, scYear.staffs[i].password);
		}
	}
	else
		cout << "Can't open file!\n";
	//delete[] scYear.staffs;
	fin.close();
}
void loadClass(string path, SchoolYear &scYear)
{
	ifstream fin;
	fin.open(path);
	if (fin.is_open())
	{
		fin >> scYear.nClass;
		scYear.classes = new Class[scYear.nClass];

		for (int i = 0; i < scYear.nClass; ++i)
		{
			fin >> scYear.classes[i].year;
			fin.ignore();
			getline(fin, scYear.classes[i].name);
		}
	}
	else
		cout << "Can't open file!\n";
	fin.close();
}
void loadSemester(string path, SchoolYear &scYear)
{
	ifstream fin;
	fin.open(path);
	if (fin.is_open())
	{
		scYear.semesters = new Semester[3];
		for (int i = 0; i < 3; ++i)
		{
			getline(fin, scYear.semesters[i].name);
			fin >> scYear.semesters[i].start.day >> scYear.semesters[i].start.month >> scYear.semesters[i].start.year;
			fin >> scYear.semesters[i].end.day >> scYear.semesters[i].end.month >> scYear.semesters[i].end.year;
			fin.ignore();
		}
	}
	else
		cout << "Can't open file!\n";
	fin.close();
}
void saveToFile(string path, SchoolYear &scYear)
{
	ofstream fout;
	fout.open(path);
	if (fout.is_open())
	{
		fout << "The staffs:\n";
		for (int i = 0; i < scYear.nStaff; ++i)
			fout << scYear.staffs[i].fullName << '\n'
				 << scYear.staffs[i].account << '\n'
				 << scYear.staffs[i].password << '\n';
		fout << '\n';

		fout << "The classes:\n";
		for (int i = 0; i < scYear.nClass; ++i)
			fout << scYear.classes[i].year << " " << scYear.classes[i].name << '\n';
		fout << '\n';

		fout << "The Semesters:\n";
		for (int i = 0; i < 3; ++i)
		{
			fout << scYear.semesters[i].name << '\n';
			fout << "Start Date: " << scYear.semesters[i].start.day << '/' << scYear.semesters[i].start.month << '/' << scYear.semesters[i].start.year << '\n';
			fout << "End Date: " << scYear.semesters[i].end.day << '/' << scYear.semesters[i].end.month << '/' << scYear.semesters[i].end.year << '\n';
		}
	}
	else
		cout << "Can't open file!\n";
	fout.close();
}
void t1_createASchoolYear(string path_staffs, string path_classes, string path_semesters, string pathOutput, SchoolYear &scYear)
{
	//cout << "Pls input Name of School year, like 2020-2021: "; getline(cin, scYear.name);
	loadStaff(path_staffs, scYear);
	loadClass(path_classes, scYear);
	loadSemester(path_semesters, scYear);

	saveToFile(pathOutput, scYear);
}
void t2_createClasses1stYearStudent(string path_classes, string pathOutput, SchoolYear &scYear)
{
	loadClass(path_classes, scYear);
	ofstream fout;
	fout.open(pathOutput);
	if (fout.is_open())
	{
		fout << "The 1st yeat classes:\n";
		for (int i = 0; i < scYear.nClass; ++i)
			if (scYear.classes[i].year == 1)
				fout << scYear.classes[i].name << '\n';
		fout << '\n';
	}
	else
		cout << "Can't open file!\n";
	fout.close();
}
void t3_addNew1stYearStudents(string path_students, string pathOutput, SchoolYear &scYear)
{
	ifstream fin;
	fin.open(path_students);
	if (!fin.is_open())
	{
		cout << "Can't open file !\n";
		return;
	}

	int nTemp;
	fin >> nTemp;
	scYear.nClass += nTemp; //Updated the number of classes in School Year
	Student *temps = new Student[nTemp];
	for (int i = 0; i < nTemp; ++i)
	{
		fin >> temps[i].year;
		fin.ignore();
		getline(fin, temps[i].studentID);
		getline(fin, temps[i].firstName);
		getline(fin, temps[i].lastName);
		getline(fin, temps[i].gender);
		getline(fin, temps[i].DOB);
		getline(fin, temps[i].socialID);
	}
	fin.close();

	ofstream fout;
	fout.open(pathOutput);
	if (fout.is_open())
	{
		fout << "\tClass 20APCS1:\n";
		for (int i = 0; i < nTemp; ++i)
			if (temps[i].year == 1 && temps[i].studentID[4] == '5')
			{
				fout << temps[i].studentID << '\n'
					 << temps[i].firstName << " " << temps[i].lastName << '\n'
					 << temps[i].gender << '\n'
					 << temps[i].DOB << '\n'
					 << "Social ID: " << temps[i].socialID << '\n';
				fout << '\n';
			}
		fout << "\tClass 20CLC1:\n";
		for (int i = 0; i < nTemp; ++i)
			if (temps[i].year == 1 && temps[i].studentID[4] == '7')
			{
				fout << temps[i].studentID << '\n'
					 << temps[i].firstName << " " << temps[i].lastName << '\n'
					 << temps[i].gender << '\n'
					 << temps[i].DOB << '\n'
					 << "Social ID: " << temps[i].socialID << '\n';
				fout << '\n';
			}
		fout << "\tClass 20VP:\n";
		for (int i = 0; i < nTemp; ++i)
			if (temps[i].year == 1 && temps[i].studentID[4] == '6')
			{
				fout << temps[i].studentID << '\n'
					 << temps[i].firstName << " " << temps[i].lastName << '\n'
					 << temps[i].gender << '\n'
					 << temps[i].DOB << '\n'
					 << "Social ID: " << temps[i].socialID << '\n';
				fout << '\n';
			}
	}
	else
		cout << "Can't open file !\n";
	fout.close();
}
void t4_importCSVFileStudent1Class(string path_CSV, string pathOutput, Class &cl)
{
	ifstream fin;
	fin.open(path_CSV);
	if (!fin.is_open())
	{
		cout << "Can't open file !\n";
		return;
	}

	fin >> cl.nStudent;
	fin.ignore();
	cl.students = new Student[cl.nStudent];

	getline(fin, cl.name);
	for (int i = 0; i < cl.nStudent; ++i)
	{
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
	fout.open(pathOutput);
	if (fout.is_open())
	{
		fout << "Class " << cl.name << '\n';
		for (int j = 0; j < cl.nStudent; ++j)
		{
			fout << "No: " << cl.students[j].No << '\n';
			fout << "Student ID: " << cl.students[j].studentID << '\n';
			fout << "First name: " << cl.students[j].firstName << '\n';
			fout << "Last name: " << cl.students[j].lastName << '\n';
			fout << "Gender: " << cl.students[j].gender << '\n';
			fout << "Date of Birth: " << cl.students[j].DOB << '\n';
			fout << "Social ID: " << cl.students[j].socialID << '\n'
				 << '\n';
		}
	}
	else
		cout << "Can't open file !\n";
	fout.close();
}
void t5_addOnly1stYearStudentsToClasses(string path_students, string pathOutput, SchoolYear &scYear)
{
	ifstream fin;
	fin.open(path_students);
	if (!fin.is_open())
	{
		cout << "Can't open file !\n";
		return;
	}

	int nTemp;
	fin >> nTemp;
	scYear.nClass += nTemp; //Updated the number of classes in School Year
	Student *temps = new Student[nTemp];
	for (int i = 0; i < nTemp; ++i)
	{
		fin >> temps[i].year;
		fin.ignore();
		getline(fin, temps[i].studentID);
		getline(fin, temps[i].firstName);
		getline(fin, temps[i].lastName);
		getline(fin, temps[i].gender);
		getline(fin, temps[i].DOB);
		getline(fin, temps[i].socialID);
	}
	fin.close();

	ofstream fout;
	fout.open(pathOutput);
	if (fout.is_open())
	{
		fout << "\tClass 20APCS1:\n";
		for (int i = 0; i < nTemp; ++i)
			if (temps[i].year == 1 && temps[i].studentID[4] == '5')
			{
				fout << temps[i].studentID << '\n'
					 << temps[i].firstName << " " << temps[i].lastName << '\n'
					 << temps[i].gender << '\n'
					 << temps[i].DOB << '\n'
					 << "Social ID: " << temps[i].socialID << '\n';
				fout << '\n';
			}
		fout << "\tClass 20CLC1:\n";
		for (int i = 0; i < nTemp; ++i)
			if (temps[i].year == 1 && temps[i].studentID[4] == '7')
			{
				fout << temps[i].studentID << '\n'
					 << temps[i].firstName << " " << temps[i].lastName << '\n'
					 << temps[i].gender << '\n'
					 << temps[i].DOB << '\n'
					 << "Social ID: " << temps[i].socialID << '\n';
				fout << '\n';
			}
		fout << "\tClass 20VP:\n";
		for (int i = 0; i < nTemp; ++i)
			if (temps[i].year == 1 && temps[i].studentID[4] == '6')
			{
				fout << temps[i].studentID << '\n'
					 << temps[i].firstName << " " << temps[i].lastName << '\n'
					 << temps[i].gender << '\n'
					 << temps[i].DOB << '\n'
					 << "Social ID: " << temps[i].socialID << '\n';
				fout << '\n';
			}
	}
	else
		cout << "Can't open file !\n";
	fout.close();
}
void t6_createASemester_SchoolyearThatSemesterBelongsTo(string path_NewSemester, string pathOutput, Semester &sem)
{
	ifstream fin;
	fin.open(path_NewSemester);
	if (fin.is_open())
	{
		getline(fin, sem.name);
		fin >> sem.start.day >> sem.start.month >> sem.start.year;
		fin >> sem.end.day >> sem.end.month >> sem.end.year;
	}
	else
		cout << "Can't open file!\n";
	fin.close();

	ofstream fout;
	fout.open(pathOutput);
	if (fout.is_open())
	{
		fout << "The Semester we've created:\n";
		fout << "Semester name: " << sem.name << '\n';
		fout << "Start Date: " << sem.start.day << '/' << sem.start.month << '/' << sem.start.year << '\n';
		fout << "End Date: " << sem.end.day << '/' << sem.end.month << '/' << sem.end.year << '\n';

		fout << "The school year that the newly created semester belongs to: ";
		if (sem.name == "Fall")
			fout << sem.start.year << " - " << sem.end.year;
		else
			fout << sem.end.year - 1 << " - " << sem.end.year;
	}
	else
		cout << "Can't open file !\n";
	fout.close();
}
void createCourseSession(string pathOutput, newCourse& c)
{
	cout << "Date open the course registion: " << endl;
	cin >> c.day1;
	cout << "Date close the course registion: " << endl;
	cin >> c.day2;
	ofstream fout; 
	fout.open(pathOutput);
	if (fout.is_open()) {
		fout << "Date open the course registion: " << c.day1 << endl;
		fout << "Date close the course registion: " << c.day2 << endl;
	}
	else cout << "Can not open file \n";
	fout.close();
}

void task8_addCourse(string path_addCourses, string pathOutput, int &nums)
{

	ifstream fin;

	fin >> nums;
	newCourse *nTemp = new newCourse[nums];
	fin.open(path_addCourses);
	if (fin.is_open())
	{
		for (int i = 0; i < nums; i++)
		{
			getline(fin, nTemp[i].ID);
			getline(fin, nTemp[i].nameCourses);
			getline(fin, nTemp[i].teacher);
			getline(fin, nTemp[i].session1);
			getline(fin, nTemp[i].session2);
			fin >> nTemp[i].maxStudent;
			fin >> nTemp[i].credit;
		}
	}
	else
		cout << "Can not open file \n";
	fin.close();
	ofstream fout;
	fout.open(pathOutput);
	if (fout.is_open())
	{
		for (int i = 0; i < nums; i++)
		{
			if (nTemp[i].semester == 1)
			{
				fout << nTemp[i].ID << endl
					 << nTemp[i].nameCourses << endl
					 << nTemp[i].teacher << endl
					 << nTemp[i].session1 << endl
					 << nTemp[i].session2 << endl
					 << nTemp[i].maxStudent << endl
					 << nTemp[i].credit;
			}
			if (nTemp[i].semester == 2)
			{
				fout << nTemp[i].ID << endl
					 << nTemp[i].nameCourses << endl
					 << nTemp[i].teacher << endl
					 << nTemp[i].session1 << endl
					 << nTemp[i].session2 << endl
					 << nTemp[i].maxStudent << endl
					 << nTemp[i].credit;
			}
			if (nTemp[i].semester == 3)
			{
				fout << nTemp[i].ID << endl
					 << nTemp[i].nameCourses << endl
					 << nTemp[i].teacher << endl
					 << nTemp[i].session1 << endl
					 << nTemp[i].session2 << endl
					 << nTemp[i].maxStudent << endl
					 << nTemp[i].credit;
			}
		}
	}

	else
		cout << "Can't open file " << endl;
	fout.close();
}

void task9_viewListOfCourses(newCourse *&nc, int nums)
{
	int STT;
	for (int i = 0; i < nums; i++)
	{
		cout << "STT" << i + 1;
		cout << nc[i].ID << endl;
		cout << nc[i].nameCourses << endl;
		cout << nc[i].teacher << endl;
		cout << nc[i].semester << endl;
		cout << nc[i].session1 << endl;
		cout << nc[i].session2 << endl;
		cout << nc[i].credit << endl;
		cout << nc[i].maxStudent << endl;
	}
	cout << "Input STT to change information course";
	cin >> STT;
}

void t10_updateCourseSession(newCourse *crs)
{
	cout << "Input new lecturer name:";
	cin >> crs->teacher;
	cout << "Input session 1:";
	cin >> crs->session1;
	cout << "Input session 2:";
	cin >> crs->session2;
	cout << "Input day 1:";
	cin >> crs->day1;
	cout << "Input day 2:";
	cin >> crs->day2;
	cout << "Input credit:";
	cin >> crs->credit;
	cout << "Input max student: ";
	cin >> crs->maxStudent;
	cout << "Input semester:";
	cin >> crs->semester;
}
void deleteCourse(SchoolYear* schYear, newCourse* crs, string crsID)
{
	int i;
	for (i = 0; crs != nullptr; i++)
		if (crs[i].ID == crsID)
			break;
	for (i; crs != nullptr; i++)
		crs[i] = crs[i + 1];


}
void enrollCourse(Student &s, int courseID)
{
	if (s.courseCount < 5)
	{
		foru(i, 0, s.courseCount - 1) if (s.course[i] == courseID) return;
		s.course[++s.courseCount] = courseID;
	}
}

void enrollCourse(Student &s, int courseID)
{
	if (s.courseCount < 5)
	{
		foru(i, 0, s.courseCount - 1) if (s.course[i] == courseID) return;
		s.course[++s.courseCount] = courseID;
	}
}

void viewEnrollCourse(Student &s)
{
	foru(i, 0, s.courseCount)
	{
		cout << s.course[i];
	}
}

void removeEnrollCourse(Student &s, int courseID)
{
	foru(i, 0, s.courseCount) if (courseID == s.course[i])
	{
		foru(j, i, s.courseCount - 1) s[j] = s[j + 1];
		s.courseCount--;
		break;
	}
}
