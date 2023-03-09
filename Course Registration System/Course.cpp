#include "Course.h"
#include <iostream>
using namespace std;

Course::Course() {
    courseNumber = {};
    courseName = {};
    number_of_credits_of_course = 0;
}

Course::Course(const Course &c1) {
    courseNumber = c1.courseNumber;
    courseName = c1.courseName;
    number_of_credits_of_course = c1.number_of_credits_of_course;
    obj1_LectureTime = LectureTime(c1.obj1_LectureTime);
}

Course::~Course() {}

void Course::set_courseNumber(string courseNumber) {
    this->courseNumber = courseNumber;
}

void Course::set_courseName(string courseName) {
    this->courseName = courseName;
}

void Course::set_obj1_LectureTime(string day1, string day2, int st) {
    obj1_LectureTime.set_first_day_lecture(day1);
    obj1_LectureTime.set_second_day_lecture(day2);
    obj1_LectureTime.set_start_hour(st);
}

void Course::set_number_of_credits_of_course(int number_of_credits_of_course) {
    if((number_of_credits_of_course >=1) && (number_of_credits_of_course <=4)) {
        this->number_of_credits_of_course = number_of_credits_of_course;
    }
    else
        cout<<"The number "<<number_of_credits_of_course<<" cannot be assigned to the course!"<<endl;
}

LectureTime Course::get_obj1_LectureTime() {
    return obj1_LectureTime;
}

string Course::get_courseNumber() {
    return courseNumber;
}

string Course::get_courseName() {
    return courseName;
}

int Course::get_number_of_credits_of_course() {
    return number_of_credits_of_course;
}
