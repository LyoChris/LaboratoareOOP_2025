#include "MovieCompare.h"
#include <cstring>

int movie_compare_name(Movie& m1, Movie& m2) {
    int result = strcmp(m1.get_name(), m2.get_name());
    if (result < 0) return -1;
    if (result > 0) return 1;
    return 0;
}

int movie_compare_year( Movie& m1, Movie& m2) {
    if (m1.get_year() < m2.get_year()) return -1;
    if (m1.get_year() > m2.get_year()) return 1;
    return 0;
}

int movie_compare_score(Movie& m1, Movie& m2) {
    if (m1.get_score() < m2.get_score()) return -1;
    if (m1.get_score() > m2.get_score()) return 1;
    return 0;
}

int movie_compare_length(Movie& m1, Movie& m2) {
    if (m1.get_length() < m2.get_length()) return -1;
    if (m1.get_length() > m2.get_length()) return 1;
    return 0;
}

int movie_compare_passed_years(Movie& m1, Movie& m2) {
    if (m1.get_passed_years() < m2.get_passed_years()) return -1;
    if (m1.get_passed_years() > m2.get_passed_years()) return 1;
    return 0;
}