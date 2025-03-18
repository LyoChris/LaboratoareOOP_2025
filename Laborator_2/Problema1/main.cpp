// Lucru.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "NumberList.h"
using namespace std;

int main()
{
    NumberList a;
    int n, x;
    cin >> n;
    a.Init();
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.Add(x);
    }
    a.Sort();
    a.Print();

    return 0;
}
