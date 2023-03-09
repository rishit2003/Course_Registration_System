#include <iostream>
#include "LectureTime.h"
using namespace std;

class Course{

private:
    string courseNumber;
    string courseName;
    LectureTime obj1_LectureTime;
    int number_of_credits_of_course;

public:
    Course();
    Course(const Course &);
    ~Course();

    void set_courseNumber(string);
    void set_courseName(string);
    void set_obj1_LectureTime(string d1, string d2, int st);
    void set_number_of_credits_of_course(int);

    LectureTime get_obj1_LectureTime();
    string get_courseNumber();
    string get_courseName();
    int get_number_of_credits_of_course();
    bool find_course(string );
};