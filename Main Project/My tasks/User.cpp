#include"User.h"
using namespace std;

void readData(string pathIn, User& usr)
{
	ifstream fin;
	fin.open(pathIn);
	if (!fin.is_open()) { cout << "Can't open file !\n"; return; }

	fin >> usr.nUser_staff; fin.ignore();
	usr.user_staffs = new User[usr.nUser_staff];
	for (int i = 0; i < usr.nUser_staff; ++i)
	{
		getline(fin, usr.user_staffs[i].username);
		getline(fin, usr.user_staffs[i].password);
	}
	fin >> usr.nUser_student; fin.ignore();
	usr.user_students = new User[usr.nUser_student];
	for (int i = 0; i < usr.nUser_staff; ++i)
	{
		getline(fin, usr.user_students[i].username);
		getline(fin, usr.user_students[i].password);
	}
}
void changePass(string userName, string passWord, int role)
{
	ifstream fin;
	fin.open("_User.txt");
	if (!fin.is_open()) { cout << "Can't open file!\n"; return; }

	// Copy text file
	int n0; fin >> n0; fin.ignore();
	User* users0 = new User[n0];
	for (int i = 0; i < n0; ++i)
	{
		getline(fin, users0[i].username);
		getline(fin, users0[i].password);
	}
	int n1; fin >> n1; fin.ignore();
	User* users1 = new User[n1];
	for (int i = 0; i < n1; ++i)
	{
		getline(fin, users1[i].username);
		getline(fin, users1[i].password);
	}
	fin.close();

	// Update new text file
	if (role == 0) {	//staff
		for (int i = 0; i < n0; ++i)
			if (userName == users0[i].username)
				users0[i].password = passWord;
	}
	else
		for (int i = 0; i < n1; ++i)
			if (userName == users1[i].username)
				users1[i].password = passWord;

	// Write new text file
	ofstream fout;
	fout.open("_User.txt", ios::trunc);
	if (!fout.is_open()) { cout << "Can't open file!\n"; return; }

	fout << n0 << '\n';
	for (int i = 0; i < n0; ++i)
		fout << users0[i].username << '\n' << users0[i].password << '\n';
	fout << n1 << '\n';
	for (int i = 0; i < n1; ++i)
		fout << users1[i].username << '\n' << users1[i].password << '\n';
	
	fout.close();
}
void login(int role, bool& loginOK, string& userName, bool& changePassword)
{
	User usr;
	readData("_User.txt", usr);

	if (role == 0)
	{
		int timeStop = 5;
		do {
			string username, password;
			cout << "Pls input your Username: "; getline(cin, username);
			for (int i = 0; i < usr.nUser_staff; ++i)
			{
				if (username == usr.user_staffs[i].username)
				{
					timeStop = 5;
					do {
						cout << "Pls input your Password: "; getline(cin, password);
						if (password == usr.user_staffs[i].password)
						{
						    userName = usr.user_staffs[i].username;
							loginOK = true;
							return;
						}
						else cout << "Your password is incorrect ! Pls input again !\n";
					} while (--timeStop);
					cout << "\n\n\nYou have inputted over 5 times wrong password ! Pls set new Password for you !\n";
					string s1, s2;
					cout << "New Password: "; getline(cin, s1);
					do {
						cout << "Confirm your new Password: "; getline(cin, s2);
					} while (s2 != s1);
					changePass(username, s1, role); changePassword = true;
					return;
				}
			}
			system("cls");
			cout << "Your Username doesn't exist, pls try other Username !\n";
		} while (--timeStop);
	}
	else //role == 1
	{
		int timeStop = 5;
		do {
			string username, password;
			cout << "Pls input your Username: "; getline(cin, username);
			for (int i = 0; i < usr.nUser_student; ++i)
			{
				if (username == usr.user_students[i].username)
				{
					timeStop = 5;
					do {
						cout << "Pls input your Password: "; getline(cin, password);
						if (password == usr.user_students[i].password)
						{
						    userName = usr.user_students[i].username;
							loginOK = true;
							return;
						}
						else cout << "Your password is incorrect ! Pls input again !\n";
					} while (--timeStop);
					cout << "\n\n\nYou have inputted over 5 times wrong password ! Pls set new Password for you !\n";
					string s1, s2;
					cout << "New Password: "; getline(cin, s1);
					do {
						cout << "Confirm your new Password: "; getline(cin, s2);
					} while (s2 != s1);
					changePass(username, s1, role); changePassword = true;
					return;
				}
			}
			system("cls");
			cout << "Your Username doesn't exist, pls try other Username !\n";
		} while (--timeStop);
	}
	loginOK = false;
}
