#include <iostream>
#include <ctime>
#include "Movie.h"
using namespace std;

void Movie::set_name(const char* new_name) {
	strncpy_s(name, new_name, sizeof(name) - 1);
	name[sizeof(name) - 1] = '\0';
}

const char* Movie::get_name() {
	return name;
}

void Movie::set_year(int new_year) {
	year = new_year;
}

int Movie::get_year(){
    return year;
}

void Movie::set_score(double new_score) {
    if (new_score >= 1.0 && new_score <= 10.0)
        score = new_score;
}

double Movie::get_score() {
    return score;
}

void Movie::set_length(int new_length) {
    length = new_length;
}

int Movie::get_length(){
    return length;
}

int Movie::get_passed_years(){
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    return now->tm_year + 1900 - year;
}
