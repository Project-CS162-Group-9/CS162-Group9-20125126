#include "MyFunction.h"
#include<bits/stdc++.h>
using namespace std;

int main()
{
	SchoolYear scYear;

	cout << "Please input your role (0: staff, 1: student): "; int role; cin >> role;
	if (role == 0) {
		cout << "Input your work as in Project CS162_requirements (1, 2,...): "; int work; cin >> work;
		if (work == 1) {
			createASchoolYear("_schoolYear.txt", scYear);
			save2File("_outputSchoolYear.txt", scYear);
		}
	}

	return 0;
}