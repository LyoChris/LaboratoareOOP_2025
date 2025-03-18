#pragma once

#include "Movie.h"

class MovieSeries {
private:
    Movie* movies[16];
    int count;

public:
    void init();
    void add(Movie* movie);
    void print() const;
    void sort();
};