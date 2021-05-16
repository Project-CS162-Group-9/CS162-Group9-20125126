#ifndef USER_H
#define USER_H
#include"MyFunction.h"
using namespace std;

struct User {
    int role;	//0: staff, 1: student
    string username;
    string password;
    Student student;
    int nUser_staff; User* user_staffs;
    int nUser_student; User* user_students;
};

void readData(string pathIn, User& usr);
void changePass(string userName, string passWord, int role);
void login(int role, bool& loginOK, string &userName, bool& changePassword);

#endif
