//#include"SchoolYear.h"
//#include"Student.h"
#include"User.h"
//#include"Semester.h"
//#include"Class.h"
//#include"Course.h"
struct allSemester
{
    Semester *semeter;
    allSemester *pNext,*pPrev;
    int index,size;
};
struct allStudent
{
    Student *student;
    allStudent *pNext,*pPrev;
    int index,size;
};
struct allClass
{
    Class *clasS;
    allClass *pNext,*pPrev;
    int index,size;
};
struct allUser
{
    User *user;
    allUser *pNext,*pPrev;
    int index,size;
};
struct allSchoolYear
{
    SchoolYear *schoolYear;
    allSchoolYear *pNext,*pPrev;
    int index,size;
};
struct allCourse
{
    Course *course;
    allCourse *pNext,*pPrev;
    int index,size;
};