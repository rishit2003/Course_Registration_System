#include <iostream>
using namespace std;

class LectureTime {

private:
    string first_day_lecture;
    string second_day_lecture;
    int start_hour;

public:
    LectureTime();
    LectureTime(const LectureTime &);
    ~LectureTime();

    void set_first_day_lecture(string first_day_lecture);
    void set_second_day_lecture(string second_day_lecture);
    void set_start_hour(int start_hour);

    string get_first_day_lecture();
    string get_second_day_lecture();
    int get_start_hour();

};