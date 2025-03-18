#pragma once

class Movie {
	char name[256];
	int year, length, passed;
	double score;
public:
	void set_name(const char* new_name);
	const char* get_name();

	void set_year(int new_year);
	int get_year();

	void set_score(double new_score);
	double get_score();

	void set_length(int new_length);
	int get_length();

	int get_passed_years();

};