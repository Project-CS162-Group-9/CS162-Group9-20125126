#ifndef USER_H
#define USER_H
using namespace std;

struct User
{
    int role;	//0: staff, 1: student
    string username;
    string password;
    Student *pStudent;
};

#endif