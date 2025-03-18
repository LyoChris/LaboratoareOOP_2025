#pragma once

class Student
{
    char name[40];
    float math, history, english, avg;
public:
    void InitName(char _name[]);
    char* GetName();
    void addEng(float _eng);
    void addMath(float _math);
    void addHist(float _history);
    float Avg();

    float GetEng();
    float GetMath();
    float GetHist();
};
