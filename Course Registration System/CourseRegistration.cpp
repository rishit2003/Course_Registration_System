#include "CourseRegistration.h"
#include <iostream>
using namespace std;

CourseRegistration::CourseRegistration() {

    for(int i=0; i<max_student_that_can_register; i++) {
        p_Student[i] = new Student();
    }

    for(int i=0; i<max_student_that_can_register; i++) {
        p_Student[i] = nullptr;
    }

    number_student_currently_registered_to_course = 0;
}

CourseRegistration::CourseRegistration(const CourseRegistration &cR) {
    obj_Course = Course(cR.obj_Course);
    max_student_that_can_register = cR.max_student_that_can_register;
    number_student_currently_registered_to_course = cR.number_student_currently_registered_to_course;
    for(int i=0; i<max_student_that_can_register; i++) {
        p_Student[i] = new Student();
    }
    for(int i=0; i<max_student_that_can_register; i++) {
        p_Student[i] = nullptr;
    }
    for(int i=0; i<40; i++) {
        *p_Student[i] = *cR.p_Student[i];
    }

}

CourseRegistration::~CourseRegistration() {}

Course CourseRegistration::get_course() {
    return obj_Course;
}

int CourseRegistration::get_number_of_students_currently_enrolled() {
    int count = 0;
    for(int i=0; i<40; i++) {
        if(p_Student[i] != nullptr) {
            count++;
        }
    }
    return count;
}

void CourseRegistration::set_obj_course(Course *obj_Course) {
    this->obj_Course = *obj_Course;
}

bool CourseRegistration::updatePtrStudentArray(Student *s1) {
    for(int i=0; i<40; i++) {
        if(p_Student[i] == nullptr) {
            p_Student[i] = s1;
            return true;
        }
    }
    return false;
}

bool CourseRegistration::decrementPtrStudentArray(Student *s1) {
    for(int i=0; i<40; i++) {
        if(p_Student[i] != nullptr) {
            if(p_Student[i]->get_studentID() == s1->get_studentID()) {
                p_Student[i] = nullptr;
                return true;
            }
        }
    }
    return false;
}