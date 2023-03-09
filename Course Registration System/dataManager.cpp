#include <iostream>
#include "dataManager.h"
using namespace std;

dataManager::dataManager() {
    for(int i=0; i<100; i++) {
        courseArray[i] = new CourseRegistration();
    }
    for(int i=0; i<2000; i++) {
        studentArray[i] = new Student();
    }

    for(int i=0; i<100; i++) {
        courseArray[i] = nullptr;
    }
    for(int i=0; i<2000; i++) {
        studentArray[i] = nullptr;
    }
}

dataManager::dataManager(const dataManager &dM) {
    for(int i=0; i<100; i++) {
        courseArray[i] = new CourseRegistration();
    }
    for(int i=0; i<2000; i++) {
        studentArray[i] = new Student();
    }

    for(int i=0; i<100; i++) {
        courseArray[i] = nullptr;
    }
    for(int i=0; i<2000; i++) {
        studentArray[i] = nullptr;
    }
    for(int i=0; i<100; i++) {
        *courseArray[i] = *dM.courseArray[i];
    }
    for(int i=0; i<2000; i++) {
        *studentArray[i] = *dM.studentArray[i];
    }
}

dataManager::~dataManager() {}

bool dataManager::insertCourseRegistration(CourseRegistration *new_value) {
    int temp=0;
    for(int i=0; i<100; i++) {
        if(courseArray[i] == nullptr) {
            courseArray[i] = new_value;
            temp=1;
            break;
        }
    }
    if(temp==0)
        return false;
    else
        return true;
}


bool dataManager::insertStudent(Student *new_value) {
    for(int i=0; i<2000; i++) {
        if(studentArray[i] == nullptr) {
            studentArray[i] = new_value;
            return true;
        }
    }
    return false;
}

bool dataManager::delete_student(Student *Std1) {
    for(int i=0; i<2000; i++) {
        if(studentArray[i] != nullptr) {
            if (studentArray[i]->get_studentID() == Std1->get_studentID()) {
                studentArray[i] = nullptr;
                return true;
            }
        }
    }
    return false;
}

bool dataManager::registering_to_Course(Student *s1, Course &c1) {
    if((s1->islectureTimeOverlap(c1)==false) && ((s1->get_number_of_credit_student_registered() + c1.get_number_of_credits_of_course())<=15) && (s1->get_number_of_course_registered()<6)) {
        s1->set_course(c1);
        return true;
    }
    else
        return false;
}

bool dataManager::dropping_a_Course(Student *s1, Course &c1) {
    for(int i=0; i<2000; i++) {
        if(studentArray[i] != nullptr) {
            if (studentArray[i]->get_studentID() == s1->get_studentID()) {
                studentArray[i]->drop_course(c1);
                return true;
            }
        }
    }
    return false;
}

int dataManager::courseEnrollment(Course &c1) {
    for(int i=0; i<100; i++) {
        if(courseArray[i] != nullptr) {
            if((courseArray[i]->get_course().get_courseNumber()==c1.get_courseNumber()) && (courseArray[i]->get_course().get_courseName()==c1.get_courseName())) {
                return courseArray[i]->get_number_of_students_currently_enrolled();
            }
        }
    }
    return 0;
}

void dataManager::studentCourses(int stdID) {
    for(int i=0; i<2000; i++) {
        if(studentArray[i] != nullptr) {
            if(studentArray[i]->get_studentID() == stdID) {
                studentArray[i]->show_courses_credits();
                break;
            }
        }
    }
}

void dataManager::print() {
    for(int i=0; i<100; i++) {
        if(courseArray[i] != nullptr) {
            cout<<"Course "<<i+1<<endl;
            cout<<"Course Number: "<<courseArray[i]->get_course().get_courseNumber()<<endl;
            cout<<"Course Name: "<<courseArray[i]->get_course().get_courseName()<<endl;
            cout<<"Number of Credits: "<<courseArray[i]->get_course().get_number_of_credits_of_course()<<endl;
            cout<<"1st Lecture Day: "<<courseArray[i]->get_course().get_obj1_LectureTime().get_first_day_lecture()<<endl;
            cout<<"2nd Lecture Day: "<<courseArray[i]->get_course().get_obj1_LectureTime().get_second_day_lecture()<<endl;
            cout<<"Timing: "<<courseArray[i]->get_course().get_obj1_LectureTime().get_start_hour()<<":00 - "<<courseArray[i]->get_course().get_obj1_LectureTime().get_start_hour()<<":50 "<<endl;
            cout<<endl;
        }
    }
}

bool dataManager::find_studentInArray(int ID) {
    for(int i=0; i<2000; i++) {
        if(studentArray[i] != nullptr) {
            if(studentArray[i]->get_studentID() == ID) {
                return true;
            }
        }
    }
    return false;
}

Student dataManager::return_student_position(int ID) {
    for(int i=0; i<2000; i++) {
        if(studentArray[i] != nullptr) {
            if(studentArray[i]->get_studentID() == ID) {
                return *studentArray[i];
            }
        }
    }
}

bool dataManager::return_CourseIfExists(string courseNumber, string courseName) {
    for(int i=0; i<100; i++) {
        if(courseArray[i] != nullptr) {
            if((courseArray[i]->get_course().get_courseNumber()==courseNumber) && (courseArray[i]->get_course().get_courseName()==courseName)) {
                return true;
            }
        }
    }
    return false;
}

CourseRegistration dataManager::return_CourseValue(string courseNumber, string courseName) {
    for(int i=0; i<100; i++) {
        if(courseArray[i] != nullptr) {
            if((courseArray[i]->get_course().get_courseNumber()==courseNumber) && (courseArray[i]->get_course().get_courseName()==courseName)) {
                return *courseArray[i];
            }
        }
    }
}