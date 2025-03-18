#include "Canvas.h"
#include <iostream>
#include <cstdarg>

using namespace std;

Canvas::Canvas(int lines, int columns) : lines(lines), columns(columns) {
    pixels = new char* [lines];
    for (int i = 0; i < lines; i++) {
        pixels[i] = new char[columns]();
    }
    clear();
}

void Canvas::set_pixel(int x, int y, char value) {
	if (x > 0 && x < lines && y>0 && y < columns)
		pixels[x][y] = value;
}

void Canvas::set_pixels(int count, ...) {
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++) {
		int x = va_arg(args, int);
		int y = va_arg(args, int);
		char value = va_arg(args, char);
		set_pixel(x, y, value);
	}
	va_end(args);
}

void Canvas::print() const {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            cout << pixels[i][j];
        }
        cout << endl;
    }
}

void Canvas::clear() {
    if (!pixels) return;

    for (int i = 0; i < lines; i++) {
        if (!pixels[i]) continue;
        for (int j = 0; j < columns; j++) {
            pixels[i][j] = ' ';
        }
    }
}