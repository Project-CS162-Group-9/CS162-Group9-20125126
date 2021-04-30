#ifndef USER_H
#define USER_H
#include"MyFunction.h"
using namespace std;

struct User
{
    int role;	//0: staff, 1: student
    string username;
    string password;
    int nUser_staff; User* user_staffs;
    int nUser_student; User* user_students;
};

void readData(string pathIn, User& usr);
void login(int role, bool& loginOK);

#endif