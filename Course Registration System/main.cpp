#include <iostream>
#include "dataManager.h"
using namespace std;

int main() {

    dataManager obj_dataManager;
    Course *obj_Course = new Course[100];
    CourseRegistration *obj_CourseRegistration = new CourseRegistration[100];
    Student *objStudent = new Student[2000];

    char end1, end2;

    cout<<"----------------- SETTING THE COURSES IN SYSTEM -----------------"<<endl;

    for(int i=0; i<100; i++) {
        string courseNumber, courseName, day1, day2;
        char over;
        int startTime, numCredits;

        cout<<"Course "<<i+1<<endl;
        cout << "Enter Course Number "<<": ";
        cin>>courseNumber;
        obj_Course[i].set_courseNumber(courseNumber);

        cout<<"Enter Course Name: "<<courseName;
        cin>>courseName;
        obj_Course[i].set_courseName(courseName);

        cout<<"Enter Number of Credits for the Course: ";
        cin>>numCredits;
        obj_Course[i].set_number_of_credits_of_course(numCredits);

        cout<<"Enter 1st day of Lecture: ";
        cin>>day1;
        cout<<"Enter 2nd day of Lecture: ";
        cin>>day2;
        cout<<"Enter Start Time: ";
        cin>>startTime;
        obj_Course[i].set_obj1_LectureTime(day1,day2,startTime);

        obj_CourseRegistration[i].set_obj_course(&obj_Course[i]);
        if(obj_dataManager.insertCourseRegistration(&obj_CourseRegistration[i]))
            cout<<"Added the course to the system"<<endl;
        cout<<"Do you want to add more courses? (y/n): ";
        cin>>over;

        cout<<endl;

        if(over == 'n')
            break;
    }

    cout<<"----------------- ADD STUDENTS TO SYSTEM -----------------"<<endl;
    for(int i=0; i<2000; i++) {

        string stdName;
        char over;
        int stdID;
        cout<<"Student "<<i+1<<endl;
        cout<<"Enter Student Name: ";
        cin>>stdName;
        objStudent[i].set_studentName(stdName);

        cout<<"Enter Student ID: ";
        cin>>stdID;
        objStudent[i].set_studentID(stdID);

        if(obj_dataManager.insertStudent(&objStudent[i]))
            cout<<"Added Student to the system"<<endl;

        cout<<"Do you want to add more Students? (y/n): ";
        cin>>over;
        cout<<endl;
        if(over == 'n')
            break;
    }


    while(end1 != 'y') {
        cout << "----------------- REGISTERING SYSTEM -----------------" << endl;
        cout << "Welcome to the Registration System" << endl;

        int stdID;
        string stdName;

        cout << "Enter your name: ";
        cin >> stdName;
        cout << "Enter your Student ID: ";
        cin >> stdID;

        int temp = 0;

        if (obj_dataManager.find_studentInArray(stdID)) {
            cout << "----------------- Access Granted! -----------------" << endl;

            while (end2 != 'n') {
                char type;

                cout<< "Do you want to: \nRegister a course (R) \nDrop a course (D) \nSee the course list (S) \nSee Number of Students in a Course (N) \nDe-register yourself from the system (Y) \nexit (E) \n(R/D/S/N/Y/E): ";
                cin >> type;

                if (type == 'R') {
                    string courseNumber, courseName;
                    cout << "Enter course number to register: ";
                    cin >> courseNumber;
                    cout << "Enter course name to register: ";
                    cin >> courseName;
                    if (obj_dataManager.return_CourseIfExists(courseNumber, courseName)) {
                        for (int i = 0; i < 100; i++) {
                            if (((obj_Course[i].get_courseNumber() == courseNumber) && (obj_Course[i].get_courseName() == courseName)) || ((obj_CourseRegistration[i].get_course().get_courseNumber()==courseNumber)&&(obj_CourseRegistration[i].get_course().get_courseName()==courseName))) {
                                for (int j = 0; j < 2000; j++) {
                                    if (objStudent[j].get_studentID() == stdID) {
                                        if ((obj_dataManager.registering_to_Course(&objStudent[j], obj_Course[i])) == true) {
                                            if(obj_CourseRegistration[i].updatePtrStudentArray(&objStudent[j]))
                                                cout << obj_Course[i].get_courseNumber() << " Course Registered" << endl << endl;
                                        }
                                    }
                                }
                            }
                        }

                    }
                    else
                        cout << "The entered course is not in the system!" << endl << endl;
                }

                else if (type == 'D') {
                    string courseNumber, courseName;
                    cout << "Enter course number to drop: ";
                    cin >> courseNumber;
                    cout << "Enter course name to drop: ";
                    cin >> courseName;
                    if (obj_dataManager.return_CourseIfExists(courseNumber, courseName)) {
                        for (int i = 0; i < 100; i++) {
                            if (((obj_Course[i].get_courseNumber()==courseNumber)&&(obj_Course[i].get_courseName()==courseName)) || ((obj_CourseRegistration[i].get_course().get_courseNumber()==courseNumber)&&(obj_CourseRegistration[i].get_course().get_courseName()==courseName))) {
                                for (int j = 0; j < 2000; j++) {
                                    if (objStudent[j].get_studentID() == stdID) {
                                        if (obj_dataManager.dropping_a_Course(&objStudent[j], obj_Course[i])) {
                                            if(obj_CourseRegistration[i].decrementPtrStudentArray(&objStudent[j]))
                                                cout << obj_Course[i].get_courseNumber() << " Course Dropped" << endl << endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else
                        cout << "The entered course is not in the system!" << endl << endl;
                }

                else if (type == 'S') {
                    cout << "\n----------------- AVAILABLE COURSES ARE AS FOLLOWS -----------------" << endl;
                    obj_dataManager.print();
                }

                else if (type == 'N') {
                    string courseNumber;
                    cout << "Enter the Course Number: ";
                    cin >> courseNumber;
                    for (int i = 0; i < 100; i++) {
                        if (obj_Course[i].get_courseNumber() == courseNumber) {
                            cout << obj_dataManager.courseEnrollment(obj_Course[i]) << " Students are registered to " << obj_Course[i].get_courseNumber() << " course" << endl << endl;
                        }
                    }
                }

                else if (type == 'Y') {
                    for (int i = 0; i < 2000; i++) {
                        if (objStudent[i].get_studentID() == stdID) {
                            if (obj_dataManager.delete_student(&objStudent[i])) {
                                cout << "The Student with ID " << objStudent[i].get_studentID() << " is De-registered from the system!" << endl << endl;
                                temp = 1;
                                break;
                            }
                        }
                    }
                    break;
                }

                else if (type == 'E')
                    break;

            }

        }
        else {
            cout << "The System was not able to find the student with Student ID: " << stdID << endl;
            temp = 1;
        }

        if(temp!=1) {
            cout << "You are registered to the following courses: " << endl;
            obj_dataManager.studentCourses(stdID);
        }

        cout<<"Do you want to terminate the program? (y/n) : ";
        cin>>end1;

    }



    return 0;
}
