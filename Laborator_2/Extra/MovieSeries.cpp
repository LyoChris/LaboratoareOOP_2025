#include "MovieSeries.h"
#include <iostream>
using namespace std;

void MovieSeries::init() {
    count = 0;
}

void MovieSeries::add(Movie* movie) {
    if (count < 16) {
        movies[count++] = movie;
    }
}

void MovieSeries::print() const {
    for (int i = 0; i < count; ++i) {
        cout<< movies[i]->get_name() << '\n';
        cout<< movies[i]->get_year() << '\n';
        cout<< movies[i]->get_score() << '\n';
        cout<< movies[i]->get_length() << '\n';
        cout<< movies[i]->get_passed_years() << '\n';
    }
}

void MovieSeries::sort() {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (movies[i]->get_passed_years() < movies[j]->get_passed_years()) {
                Movie* temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }
}