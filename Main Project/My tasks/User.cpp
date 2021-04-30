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
void login(int role, bool& loginOK)
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
							loginOK = true;
							return;
						}
						else cout << "Your password is incorrect ! Pls input again !\n";
					} while (--timeStop);
					cout << "You have inputted over 5 times wrong password ! Pls try again !\n\n\n" << "Try the Password again:\n";
					i = 0; continue;
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
							loginOK = true;
							return;
						}
						else cout << "Your password is incorrect ! Pls input again !\n";
					} while (--timeStop);
					cout << "You have inputted over 5 times wrong password ! Pls try again !\n\n\n" << "Try the Password again:\n";
					i = 0; continue;
				}
			}
			system("cls");
			cout << "Your Username doesn't exist, pls try other Username !\n";
		} while (--timeStop);
	}
	loginOK = false;
}