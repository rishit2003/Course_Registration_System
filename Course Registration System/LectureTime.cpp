#include <iostream>
#include "LectureTime.h"
using namespace std;

LectureTime::LectureTime() {
    start_hour = 0;
    first_day_lecture = "";
    second_day_lecture = "";
}

LectureTime::LectureTime(const LectureTime &lT) {
    first_day_lecture = lT.first_day_lecture;
    second_day_lecture = lT.second_day_lecture;
    start_hour = lT.start_hour;
}

LectureTime::~LectureTime() {}

void LectureTime::set_first_day_lecture(string first_day_lecture) {
    this->first_day_lecture = first_day_lecture;
}

void LectureTime::set_second_day_lecture(string second_day_lecture) {
    this->second_day_lecture = second_day_lecture;
}

void LectureTime::set_start_hour(int start_hour) {
    this->start_hour = start_hour;
}

string LectureTime::get_first_day_lecture() {
    return first_day_lecture;
}

string LectureTime::get_second_day_lecture() {
    return second_day_lecture;
}

int LectureTime::get_start_hour() {
    return start_hour;
}
