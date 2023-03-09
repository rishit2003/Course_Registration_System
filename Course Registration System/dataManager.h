#include "CourseRegistration.h"

class dataManager {

private:
    CourseRegistration *courseArray[100];
    Student *studentArray[2000];

public:
    dataManager();
    dataManager(const dataManager &);
    ~dataManager();

    bool insertCourseRegistration(CourseRegistration *new_value);
    bool insertStudent(Student *);
    bool delete_student(Student *);
    bool registering_to_Course(Student *, Course &);
    bool dropping_a_Course(Student *, Course &);
    int courseEnrollment (Course &);
    void studentCourses(int);
    void print();
    bool find_studentInArray(int ID);
    Student return_student_position(int ID);
    bool return_CourseIfExists(string courseNumber, string courseName);
    CourseRegistration return_CourseValue(string courseNumber, string courseName);

};