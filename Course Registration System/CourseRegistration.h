#include <iostream>
#include "Student.h"
using namespace std;

class CourseRegistration{
private:
    Course obj_Course;
    int max_student_that_can_register = 40;
    int number_student_currently_registered_to_course;
    Student *p_Student[40];

public:
    CourseRegistration();
    CourseRegistration(const CourseRegistration &);
    ~CourseRegistration();

    Course get_course();
    int get_number_of_students_currently_enrolled();
    void set_obj_course(Course *);
    bool updatePtrStudentArray(Student *);
    bool decrementPtrStudentArray(Student *);
};