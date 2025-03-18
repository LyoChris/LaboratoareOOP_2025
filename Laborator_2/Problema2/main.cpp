#include <iostream>
#include <cstring>

#include "Students.h"
#include "Functions.h"

using namespace std;

int main()
{
    Student students[2];

    char name1[256], name2[256];
    cin.getline(name1, 256);
    cin.getline(name2, 256);

    int grade_math[2], grade_engl[2], grade_hist[2];
    cin >> grade_math[0] >> grade_math[1];
    cin >> grade_engl[0] >> grade_engl[1];
    cin >> grade_hist[0] >> grade_hist[1];

    students[0].InitName(name1);
    students[0].addMath(grade_math[0]);
    students[0].addEng(grade_engl[0]);
    students[0].addHist(grade_hist[0]);
    float average1 = students[0].Avg();

    students[1].InitName(name2);
    students[1].addMath(grade_math[1]);
    students[1].addEng(grade_engl[1]);
    students[1].addHist(grade_hist[1]);
    float average2 = students[1].Avg();

    cout << students[0].GetName() << " : " << average1 << "\n" << students[1].GetName() << " : " << average2 << "\n";

}