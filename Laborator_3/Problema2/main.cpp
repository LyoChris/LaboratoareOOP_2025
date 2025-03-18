#include "Canvas.h"
#include <iostream>

int main() {
    Canvas canvas(40, 20);
    
    canvas.DrawRect(2, 2, 15, 10, '#');
    canvas.FillRect(17, 2, 30, 10, '*');
    canvas.DrawCircle(20, 15, 5, 'o');
    canvas.FillCircle(35, 15, 3, '+');
    canvas.DrawLine(0, 0, 39, 19, '/');
    canvas.SetPoint(20, 10, '@');

    
    canvas.Print();

    canvas.Clear();
    canvas.Print();

    return 0;
}