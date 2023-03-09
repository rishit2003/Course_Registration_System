#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() {
    for(int i=0; i<6; i++) {
        p_Course[i] = new Course();
    }
    for(int i=0; i<6; i++) {
        p_Course[i] = nullptr;
    }
    number_of_credit_student_registered = 0;
}

Student::Student(string sName, int sID) {
    studentName = sName;
    studentId = sID;
}

Student::Student(const Student &s1) {
    studentName = s1.studentName;
    studentId = s1.studentId;
    number_of_credit_student_registered = s1.number_of_credit_student_registered;
    for(int i=0; i<6; i++) {
        p_Course[i] = new Course();
    }
    for(int i=0; i<6; i++) {
        p_Course[i] = nullptr;
    }
    for(int i=0; i<6; i++) {
        *p_Course[i] = *s1.p_Course[i];
    }
}

Student::~Student() {}

void Student::set_studentName(string studentName) {
    this->studentName = studentName;
}

void Student::set_studentID(int studentID) {
    this->studentId = studentID;
}

void Student::set_course(Course &c1) {
    int temp = 0;
    for(int i=0; i<6; i++) {
        if(p_Course[i] == nullptr) {
            p_Course[i] = &c1;
            temp=1;
            break;
        }
    }
    number_of_credit_student_registered+=c1.get_number_of_credits_of_course();
    if(temp == 0) {
        cout<<"No available slots left to add more courses! "<<endl;
    }
}

int Student::get_studentID() {
    return studentId;
}

bool Student::islectureTimeOverlap(Course c1) {
    for(int i=0; i<6; i++) {
        if(p_Course[i] != nullptr) {
            if (p_Course[i]->get_obj1_LectureTime().get_first_day_lecture() == c1.get_obj1_LectureTime().get_first_day_lecture()) {
                if (p_Course[i]->get_obj1_LectureTime().get_start_hour() == c1.get_obj1_LectureTime().get_start_hour()) {
                    return true;
                }
            }
            else if (p_Course[i]->get_obj1_LectureTime().get_first_day_lecture() == c1.get_obj1_LectureTime().get_second_day_lecture()) {
                if (p_Course[i]->get_obj1_LectureTime().get_start_hour() == c1.get_obj1_LectureTime().get_start_hour()) {
                    return true;
                }
            }
            else if (p_Course[i]->get_obj1_LectureTime().get_second_day_lecture() == c1.get_obj1_LectureTime().get_first_day_lecture()) {
                if (p_Course[i]->get_obj1_LectureTime().get_start_hour() == c1.get_obj1_LectureTime().get_start_hour()) {
                    return true;
                }
            }
            else if (p_Course[i]->get_obj1_LectureTime().get_second_day_lecture() == c1.get_obj1_LectureTime().get_second_day_lecture()) {
                if (p_Course[i]->get_obj1_LectureTime().get_start_hour() == c1.get_obj1_LectureTime().get_start_hour()) {
                    return true;
                }
            }
        }
    }
    return false;
}

void Student::drop_course(Course &c1) {
    int temp=0;
    for(int i=0; i<6; i++) {
        if(p_Course[i] != nullptr) {
            if ((p_Course[i]->get_courseNumber()==c1.get_courseNumber()) && (p_Course[i]->get_courseName()==c1.get_courseName())) {
                p_Course[i] = nullptr;
                number_of_credit_student_registered -= c1.get_number_of_credits_of_course();
                temp=1;
                break;
            }
        }
    }
    if(temp==0)
        cout<<"Could not drop the Course "<<c1.get_courseNumber()<<" as it was not found in the student's course list"<<endl;
}

int Student::get_number_of_credit_student_registered() {
    return number_of_credit_student_registered;
}


int Student::get_number_of_course_registered() {
    int count=0;
    for(int i=0; i<6; i++) {
        if(p_Course[i] != nullptr) {
            count++;
        }
    }
    return count;
}

bool Student::find_course(Course &c1) {
    for(int i=0; i<6; i++) {
        if((c1.get_courseNumber()==p_Course[i]->get_courseNumber()) && (c1.get_courseName()==p_Course[i]->get_courseName())) {
            return true;
        }
    }
    return false;
}

void Student::show_courses_credits() {
    int temp=0;
    for(int i=0; i<6; i++) {
        if(p_Course[i] != nullptr) {
            cout<<"Course "<<i+1<<endl;
            cout<<"Course Number: "<<p_Course[i]->get_courseNumber()<<endl;
            cout<<"Course Name: "<<p_Course[i]->get_courseName()<<endl;
            temp=1;
            cout<<endl;
        }
    }
    cout<<"Total Number of Credits Student Registered: "<<number_of_credit_student_registered<<"\n\n";
    if(temp==0)
        cout<<"No course registered by the student "<<studentName<<endl;
}