#include <iostream>
#include "Course.h"
using namespace std;

class Student{
private:
    string studentName;
    int studentId;
    int number_of_credit_student_registered;
    Course *p_Course[6];

public:
    Student();
    Student(string sName, int sID);
    Student(const Student &);
    ~Student();

    void set_studentName(string);
    void set_studentID(int);
    void set_course(Course &);

    int get_studentID();

    bool islectureTimeOverlap(Course );

    void drop_course(Course &);

    int get_number_of_credit_student_registered();

    int get_number_of_course_registered();

    bool find_course(Course &);

    void show_courses_credits();

    bool set_number_of_credits_student_registered();

};