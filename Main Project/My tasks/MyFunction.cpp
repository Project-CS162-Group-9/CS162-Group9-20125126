#include "MyFunction.h"

#define foru(i, a, b) for (int i = a; i <= b; ++i)

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
	else cout << "Can't open file!\n";
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
	else cout << "Can't open file!\n";
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
	else cout << "Can't open file!\n";
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
	else cout << "Can't open file!\n";
	fout.close();
}
void createASchoolYear(string path_staffs, string path_classes, string path_semesters, string pathOutput, SchoolYear &scYear)
{
	//cout << "Pls input Name of School year, like 2020-2021: "; getline(cin, scYear.name);
	loadStaff(path_staffs, scYear);
	loadClass(path_classes, scYear);
	loadSemester(path_semesters, scYear);
	saveToFile(pathOutput, scYear);
}
void createClasses1stYearStudent(string path_classes, string pathOutput, SchoolYear &scYear)
{
	loadClass(path_classes, scYear);
	ofstream fout;
	fout.open(pathOutput);
	if (fout.is_open())
	{
		fout << "The 1st year classes:\n";
		for (int i = 0; i < scYear.nClass; ++i)
			if (scYear.classes[i].year == 1)
				fout << scYear.classes[i].name << '\n';
		fout << '\n';
	}
	else cout << "Can't open file!\n";
	fout.close();
}
void addNew1stYearStudents(string path_students, string pathOutput, SchoolYear &scYear)
{
	ifstream fin;
	fin.open(path_students);
	if (!fin.is_open()) { cout << "Can't open file !\n"; return; }

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
	else cout << "Can't open file !\n";
	fout.close();
}
void importCSVFileStudent1Class(string path_CSV, string pathOutput, Class &cl)
{
	ifstream fin;
	fin.open(path_CSV);
	if (!fin.is_open()) { cout << "Can't open file !\n"; return; }

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
	else cout << "Can't open file !\n";
	fout.close();
}
void addOnly1stYearStudentsToClasses(string path_students, string pathOutput, SchoolYear &scYear)
{
	ifstream fin;
	fin.open(path_students);
	if (!fin.is_open()) { cout << "Can't open file !\n"; return; }

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
	else cout << "Can't open file !\n";
	fout.close();
}
void createASemester_SchoolyearThatSemesterBelongsTo(string path_NewSemester, string pathOutput, Semester &sem)
{
	ifstream fin;
	fin.open(path_NewSemester);
	if (fin.is_open())
	{
		getline(fin, sem.name);
		fin >> sem.start.day >> sem.start.month >> sem.start.year;
		fin >> sem.end.day >> sem.end.month >> sem.end.year;
	}
	else cout << "Can't open file!\n";
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
	else cout << "Can't open file !\n";
	fout.close();
}

void createCourseSession(string pathOutput, newCourse &c)
{
	cout << "Date open the course registion: " << endl;
	cin >> c.day1;
	cout << "Date close the course registion: " << endl;
	cin >> c.day2;
	ofstream fout;
	fout.open(pathOutput);
	if (fout.is_open())
	{
		fout << "Date open the course registion: " << c.day1 << endl;
		fout << "Date close the course registion: " << c.day2 << endl;
	}
	else cout << "Can not open file \n";
	fout.close();
}
/*void addCourse(string path_addCourses, string pathOutput, int &nums)
{
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
}*/

void addCourse(string pathOutput)
{
    cout << "Enter number of course:" << endl;

    int nums; cin >> nums;
	newCourse *nTemp = new newCourse[nums];

    for (int i = 0; i < nums; i++)
    {
        cout << "Input course ID: " << endl;
        cin >> nTemp[i].ID;
        cout << "Input course name: " << endl;
        cin >> nTemp[i].nameCourses;
        cout << "Input course teacher: " << endl;
        cin >> nTemp[i].teacher;
        cout << "Input course day 1: " << endl;
        cin >> nTemp[i].day1;
        cout << "Input course session 1: " << endl;
        cin >> nTemp[i].session1;
        cout << "Input course day 2: " << endl;
        cin >> nTemp[i].day2;
        cout << "Input course session 2: " << endl;
        cin >> nTemp[i].session2;
        cout << "Input course max student: " << endl;
        cin >> nTemp[i].maxStudent;
        if (nTemp[i].maxStudent < 0 || nTemp[i].maxStudent > 50) nTemp[i].maxStudent = 50;
        cout << "Input course credit: " << endl;
        cin >> nTemp[i].credit;
        cout << "Input course semester: " << endl;
        cin >> nTemp[i].semester;
    }

	ofstream fout;
	fout.open(pathOutput);
	fout << nums  << endl;
	if (fout.is_open())
	{
		for (int i = 0; i < nums; i++)
		{
           	 fout << nTemp[i].ID << endl
                 << nTemp[i].nameCourses << endl
                 << nTemp[i].teacher << endl
                 << nTemp[i].day1 << endl
                 << nTemp[i].session1 << endl
                 << nTemp[i].day2 << endl
                 << nTemp[i].session2 << endl
                 << nTemp[i].maxStudent << endl
                 << nTemp[i].credit << endl
                 << nTemp[i].semester << endl;
		}
	}
	else cout << "Can't open file " << endl;
	fout.close();
}

void readListOfCourses(string pathInput, newCourse *&nTemp, int &nums)
{
    ifstream fin;
	fin.open(pathInput);
	fin >> nums;
	getline(fin, nTemp[0].ID);

	if (fin.is_open())
	{
		for (int i = 0; i < nums; i++)
		{
			getline(fin, nTemp[i].ID);
			getline(fin, nTemp[i].nameCourses);
			getline(fin, nTemp[i].teacher);
			getline(fin, nTemp[i].day1);
			getline(fin, nTemp[i].session1);
			getline(fin, nTemp[i].day2);
			getline(fin, nTemp[i].session2);
			fin >> nTemp[i].maxStudent;
			fin >> nTemp[i].credit;
			fin >> nTemp[i].semester;
		}
	}
	else cout << "Can not open file \n";
	fin.close();
}

void viewListOfCourses(string pathInput)
{
    int nums = 100;
	newCourse *nTemp = new newCourse[nums];

	readListOfCourses(pathInput, nTemp, nums);

    for (int i = 0; i < nums; i++)
    {
        cout << "course ID: " << nTemp[i].ID << endl;
        cout << "course name: " << nTemp[i].nameCourses << endl;
        cout << "course teacher: " << nTemp[i].teacher << endl;
        cout << "course day 1: " << nTemp[i].day1 << endl;
        cout << "course session 1: " << nTemp[i].session1 << endl;
        cout << "course day 2: " << nTemp[i].day2 << endl;
        cout << "course session 2: " << nTemp[i].session2 << endl;
        cout << "course max student: " << nTemp[i].maxStudent << endl;
        cout << "course credit: " << nTemp[i].credit << endl;
        cout << "course semester: " << nTemp[i].semester << endl;
    }
}
/*void updateCourseSession(newCourse *crs)
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
}*/

void updateCourseInformation(string pathInput, string pathOutput)
{
    string id;
    cout << "Enter course id need to update" << endl;
    cin >> id;

    int nums = 100;
    newCourse *nTemp = new newCourse[100];
	readListOfCourses(pathInput, nTemp, nums);

	foru (i, 0, nums - 1)
	if (nTemp[i].ID == id)
    {
        cout << "Input course ID: " << endl;
        cin >> nTemp[i].ID;
        cout << "Input course name: " << endl;
        cin >> nTemp[i].nameCourses;
        cout << "Input course teacher: " << endl;
        cin >> nTemp[i].teacher;
        cout << "Input course day 1: " << endl;
        cin >> nTemp[i].day1;
        cout << "Input course session 1: " << endl;
        cin >> nTemp[i].session1;
        cout << "Input course day 2: " << endl;
        cin >> nTemp[i].day2;
        cout << "Input course session 2: " << endl;
        cin >> nTemp[i].session2;
        cout << "Input course max student: " << endl;
        cin >> nTemp[i].maxStudent;
        if (nTemp[i].maxStudent < 0 || nTemp[i].maxStudent > 50) nTemp[i].maxStudent = 50;
        cout << "Input course credit: " << endl;
        cin >> nTemp[i].credit;
        cout << "Input course semester: " << endl;
        cin >> nTemp[i].semester;
    }

    ofstream fout;
	fout.open(pathOutput);
	fout << nums  << endl;
	if (fout.is_open())
	{
		for (int i = 0; i < nums; i++)
		{
            fout << nTemp[i].ID << endl
                 << nTemp[i].nameCourses << endl
                 << nTemp[i].teacher << endl
                 << nTemp[i].day1 << endl
                 << nTemp[i].session1 << endl
                 << nTemp[i].day2 << endl
                 << nTemp[i].session2 << endl
                 << nTemp[i].maxStudent << endl
                 << nTemp[i].credit << endl
                 << nTemp[i].semester << endl;
		}
	}
	else
		cout << "Can't open file " << endl;
	fout.close();
}

/*void deleteCourse(SchoolYear *schYear, newCourse *crs, string crsID)
{
	int i;
	for (i = 0; crs != nullptr; i++)
		if (crs[i].ID == crsID)
			break;
	for (i; crs != nullptr; i++)
		crs[i] = crs[i + 1];
}*/

void deleteCourse(string pathInput, string pathOutput)
{
    int nums = 100;
    newCourse *nTemp = new newCourse[100];
	readListOfCourses(pathInput, nTemp, nums);

    string id;
    cout << "Enter course id need to delete" << endl;
    cin >> id;

    foru (i, 0, nums - 1)
    if (id == nTemp[i].ID)
    {
        foru (j, i, nums - 1) nTemp[j] = nTemp[j+1];
        cout << "Remove OK" << endl;
        break;
    }

    nums -- ;
    ofstream fout;
	fout.open(pathOutput);
	fout << nums  << endl;
	if (fout.is_open())
	{
		for (int i = 0; i < nums; i++)
		{
            fout << nTemp[i].ID << endl
                 << nTemp[i].nameCourses << endl
                 << nTemp[i].teacher << endl
                 << nTemp[i].day1 << endl
                 << nTemp[i].session1 << endl
                 << nTemp[i].day2 << endl
                 << nTemp[i].session2 << endl
                 << nTemp[i].maxStudent << endl
                 << nTemp[i].credit << endl
                 << nTemp[i].semester << endl;
		}
	}
	else cout << "Can't open file " << endl;
	fout.close();
}

void readEnrollCourse(string pathInput, Student &s)
{
    	ifstream fin;
	fin.open(pathInput);

	if (fin.is_open())
    	{
        	fin >> s.courseCount;
        	foru (i, 0, s.courseCount)
            		fin >> s.course[i];
    	}
    	fin.close();
}

void writeEnrollCourse(string pathOutput, Student s)
{
    	ofstream fout;
	fout.open(pathOutput);
	if (fout.is_open())
	{
	    fout << s.courseCount << endl;
		for (int i = 0; i < s.courseCount; i++)
		{
            fout << s.course[i] << endl;
		}
	}
	else
		cout << "Can't open file " << endl;
	fout.close();
}

void enrollCourse(Student &s, string pathInput,string pathOutput)
{
    string id;
    cout << "Input course ID you want enroll: " << endl;
    cin  >> id;

    s.courseCount = 0;
    readEnrollCourse(pathInput, s);

	if (s.courseCount < 5)
	{
		foru(i, 0, s.courseCount - 1) if (s.course[i] == id)
		{
		    cout << "You cannot enroll same course you had enroll."<< endl;
		    return;
		}
		s.course[s.courseCount] = id;
		s.courseCount ++;
	}
	else
        cout << "You cannot enroll more than 5 course." << endl;

    writeEnrollCourse(pathOutput, s);
}
void viewEnrollCourse(string pathInputCourse, string pathInputStudent)
{
    int nums = 100;
	newCourse *nTemp = new newCourse[nums];
	readListOfCourses(pathInputCourse, nTemp, nums);

	Student s;
    s.courseCount = 0;
    readEnrollCourse(pathInputStudent, s);

    bool check;

	foru(i, 0, s.courseCount - 1)
	{
	    check = true;
		foru (j, 0, nums - 1)
		if (nTemp[j].ID == s.course[i])
        {
            cout << "STT :" << i + 1 << endl;
            cout << nTemp[j].ID << endl;
            cout << nTemp[j].nameCourses << endl;
            cout << nTemp[j].teacher << endl;
            cout << nTemp[j].semester << endl;
            cout << nTemp[j].session1 << endl;
            cout << nTemp[j].session2 << endl;
            cout << nTemp[j].credit << endl;
            cout << nTemp[j].maxStudent << endl;
            check = false;
        }

        if (check) cout << "There is no course with ID: " << s.course[i]  << endl;
	}
	cout << endl;
}
void removeEnrollCourse(string pathInput,string pathOutput)
{
    Student s;
	s.courseCount = 0;
    readEnrollCourse(pathInput, s);

    string id;
    cout << "Input course ID you want remove: " << endl;
    cin  >> id;

    foru (i, 0, s.courseCount - 1)
    if (s.course[i] == id)
    {
        foru (j, i, s.courseCount - 1) s.course[j] = s.course[j+1];
        cout << "Remove OK" << endl;
        break;
    }

    writeEnrollCourse(pathOutput, s);
}

void viewStudentCourse(Student &s, newCourse *&nc)
{

}

void viewListOfClass(string pathInput)
{
    ifstream fin;
	fin.open(pathInput);

	int a[100];
	string b[100];

	int nums;
	SchoolYear sy;

	if (fin.is_open())
    {
        fin >> nums;
        foru (i, 0, nums - 1)
        {
            fin >> a[i];
            getline(fin, b[i]);
        }
    }
    fin.close();


	foru(i, 0, nums - 1)
	{
		cout << b[i] << " " << a[i] << endl;
	}
	cout << endl;
}

void viewListOfStudentInAClass(Class &c)
{
	/*cout << left << setw(8) << setfill(" ") << c.name << ": ";
    foru (j, 0, c.nStudent) cout << left << setw(8) << setfill(" ") << c.nStudent[j];
    cout << endl;*/

	ifstream fin;
	fin.open("_CSV file.csv");

	fin >> c.nStudent;
	fin.ignore();
	c.students = new Student[c.nStudent];

	getline(fin, c.name);
	for (int i = 0; i < c.nStudent; ++i)
	{
		getline(fin, c.students[i].No, ',');
		getline(fin, c.students[i].studentID, ',');
		getline(fin, c.students[i].firstName, ',');
		getline(fin, c.students[i].lastName, ',');
		getline(fin, c.students[i].gender, ',');
		getline(fin, c.students[i].DOB, ',');
		getline(fin, c.students[i].socialID, '\n');
	}
	fin.close();

	cout << "Class " << c.name << '\n';
	for (int j = 0; j < c.nStudent; ++j)
	{
		cout << "No: " << c.students[j].No << '\n';
		cout << "Student ID: " << c.students[j].studentID << '\n';
		cout << "First name: " << c.students[j].firstName << '\n';
		cout << "Last name: " << c.students[j].lastName << '\n';
		cout << "Gender: " << c.students[j].gender << '\n';
		cout << "Date of Birth: " << c.students[j].DOB << '\n';
		cout << "Social ID: " << c.students[j].socialID << '\n';
		cout << '\n';
	}
}

void exportListOfStudentToCSV(string pathIn, string pathOut)
{
	int nums;
	ifstream fin;
	fin.open(pathIn);
	if (fin.is_open())
	{
		fin >> nums;
		Student *student = new Student[nums];
		fin.ignore();
		for (int i = 0; i < nums; i++)
		{
			getline(fin, student[i].No);
			getline(fin, student[i].studentID);
			getline(fin, student[i].firstName);
			getline(fin, student[i].lastName);
		}
		fin.close();

		ofstream fout;
		fout.open(pathOut);
		if (fout.is_open())
		{

			for (int i = 0; i < nums; i++)
			{

				fout << student[i].No << "," << student[i].studentID << "," << student[i].firstName << " " << student[i].lastName << endl;
			}
		}
		else
			cout << "Can't open file !\n";
		fout.close();
	}
}
void importScoreboard(string pathIn, Scoreboard &scoreboard)
{
	int n;
	cout << "How many students in course: "<<endl;
	cin >> n;
	ifstream fin;
	fin.open(pathIn);
	if (fin.is_open())
	{
		//fin.ignore();
		scoreboard.student = new Student[n];
		scoreboard.score = new Score[n];
		for (int i = 0; i < n; i++)
		{
			getline(fin, scoreboard.student[i].No, ',');
			getline(fin, scoreboard.student[i].studentID, ',');
			getline(fin, scoreboard.student[i].firstName, ' ');
			getline(fin, scoreboard.student[i].lastName, ',');
			string Total, Final, Midterm, Other;
			getline(fin, Total, ',');
			getline(fin, Final, ',');
			getline(fin, Midterm, ',');
			getline(fin, Other, '\n');
			scoreboard.score[i].total = stoi(Total);
			scoreboard.score[i].final = stoi(Final);
			scoreboard.score[i].midterm = stoi(Midterm);
			scoreboard.score[i].other = stoi(Other);
		}
	}
	else
		cout << "Can not open file \n";
	fin.close();
}
void viewScoreboardOfCourse(Scoreboard &scoreboard)
{
	int n;
	cout << "How many students in course: "<<endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << scoreboard.student[i].No << ",";
		cout << scoreboard.student[i].studentID << ",";
		cout << scoreboard.student[i].firstName << "";
		cout << scoreboard.student[i].lastName << ",";
		cout << scoreboard.score[i].total << ",";
		cout << scoreboard.score[i].final << ",";
		cout << scoreboard.score[i].midterm << ",";
		cout << scoreboard.score[i].other << "\n";
	}
}
void updateAStudentResult(string path, Scoreboard &scoreboard)
{
	int n;
	cout << "How many students in course: " << endl;
	cin >> n;
	ifstream fin;
	fin.open(path);
	if (fin.is_open())
	{
		//fin.ignore();
		scoreboard.student = new Student[n];
		scoreboard.score = new Score[n];
		for (int i = 0; i < n; i++)
		{
			getline(fin, scoreboard.student[i].No, ',');
			getline(fin, scoreboard.student[i].studentID, ',');
			getline(fin, scoreboard.student[i].firstName, ' ');
			getline(fin, scoreboard.student[i].lastName, ',');
			string Total, Final, Midterm, Other;
			getline(fin, Total, ',');
			getline(fin, Final, ',');
			getline(fin, Midterm, ',');
			getline(fin, Other, '\n');
			scoreboard.score[i].total = stoi(Total);
			scoreboard.score[i].final = stoi(Final);
			scoreboard.score[i].midterm = stoi(Midterm);
			scoreboard.score[i].other = stoi(Other);
		}
	}
	else
		cout << "Can not open file \n";
	fin.close();
}
void viewScoreboardOfClass(string path)
{
	int n;
	cout << "How many students in class: "<<endl;
	cin >> n;
	Class clas;
	clas.students = new Student[n];
	ifstream fin;
	fin.open(path);
	if (fin.is_open())
	{
		getline(fin, clas.name);
		string nums;
		getline(fin, nums);
		clas.nStudent = stoi(nums);
		for (int i = 0; i < clas.nStudent; i++)
		{

			getline(fin, clas.students[i].No);
			getline(fin, clas.students[i].studentID);
			getline(fin, clas.students[i].firstName);
			getline(fin, clas.students[i].lastName);
			string temp3;
			getline(fin, temp3);
			clas.students[i].courseCount = stoi(temp3);
			clas.students[i].finall = new double[clas.students[i].courseCount];
			for (int j = 0; j < clas.students[i].courseCount; j++)
			{
				string temp;
				getline(fin, temp);
				clas.students[i].finall[j] = stoi(temp);
			}
			string temp1, temp2;
			getline(fin, temp1);
			getline(fin, temp2);
			clas.students[i].semesterGPA = stoi(temp1);
			clas.students[i].overallGPA = stoi(temp2);
		}
	}
	else cout << "Can not open file \n";
	fin.close();
	cout << "Class name: " << clas.name << endl;
	cout << "Number of student: " << clas.nStudent << endl;
	for (int i = 0; i < clas.nStudent; i++)
	{
		cout << "No: " << clas.students[i].No << endl;
		cout << "ID: " << clas.students[i].studentID << endl;
		;
		cout << "Name: " << clas.students[i].firstName << " ";
		cout << clas.students[i].lastName << endl;
		;
		cout << " Number of courses: " << clas.students[i].courseCount << endl;
		for (int j = 0; j < clas.students[i].courseCount; j++)
		{
			cout << " Final mark of course " << j << ":" << clas.students[i].finall[j] << endl;
		}
		cout << "Semseter GPA: " << clas.students[i].semesterGPA << endl;
		cout << "Overall GPA: " << clas.students[i].overallGPA << endl;
		cout << endl;
	}
}
void viewScoreboard1Stu(string path,int ID)
{
	ifstream fin;
	fin.open(path);
	int nums;
	string num;
	getline(fin, num);
	nums = stoi(num);
	Student* student = new Student[nums];
	string classname[100];
	int ID1[100];
	for (int i = 0; i < nums; i++)
	{
		getline(fin, classname[i]);
		getline(fin, student[i].No);
		getline(fin, student[i].studentID);
		ID1[i] = stoi(student[i].studentID);
		getline(fin, student[i].firstName);
		getline(fin, student[i].lastName);
		string temp3;
		getline(fin, temp3);
		student[i].courseCount = stoi(temp3);
		student[i].finall = new double[student[i].courseCount];
		for (int j = 0; j < student[i].courseCount; j++)
		{
			string temp;
			getline(fin, temp);
			student[i].finall[j] = stoi(temp);
		}
		string temp1, temp2;
		getline(fin, temp1);
		getline(fin, temp2);
		student[i].semesterGPA = stoi(temp1);
		student[i].overallGPA = stoi(temp2);
	}
	bool check = false;
	for (int i = 0; i < nums; i++)
	{
		if (ID1[i] == ID)
		{
			check = true;
			cout << "Class name: " << classname[i] << endl;
			cout << "No: " << student[i].No << endl;
			cout << "ID: " << student[i].studentID << endl;
			cout << "Name: " << student[i].firstName << " ";
			cout << student[i].lastName << endl;
			cout << " Number of courses: " << student[i].courseCount << endl;
			for (int j = 0; j < student[i].courseCount; j++)
			{
				cout << " Final mark of course " << (j+1) << ":" << student[i].finall[j] << endl;
			}
			cout << "Semseter GPA: " << student[i].semesterGPA << endl;
			cout << "Overall GPA: " << student[i].overallGPA << endl;
			cout << endl;
		}
	}
	if (!check)
	{
		cout << "Your scoreboard hasn't imported!!\n";
	}
	fin.close();
	
}
