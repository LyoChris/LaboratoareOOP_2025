#include "Canvas.h"
#include <iostream>
#include <cmath>
using namespace std;

Canvas::Canvas(int width, int height) : width(width), height(height) {
    pixels = new char* [height];
    for (int i = 0; i < height; i++) {
        pixels[i] = new char[width]();
    }
   Clear();
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    int d = 3 - 2 * ray;
    int a = 0;
    int b = ray;

    while (a <= b) {
        SetPoint(x + a, y + b, ch);
        SetPoint(x - a, y + b, ch);
        SetPoint(x + a, y - b, ch);
        SetPoint(x - a, y - b, ch);
        SetPoint(x + b, y + a, ch);
        SetPoint(x - b, y + a, ch);
        SetPoint(x + b, y - a, ch);
        SetPoint(x - b, y - a, ch);

        if (d < 0)
            d += 4 * a + 6;
        else {
            d += 4 * (a - b) + 10;
            b--;
        }
        a++;
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for (int i = -ray; i <= ray; i++) {
        for (int j = -ray; j <= ray; j++) {
            if (i * i + j * j <= ray * ray)
                SetPoint(x + i, y + j, ch);
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int i = left; i <= right;i++) {
        SetPoint(i, top, ch);
        SetPoint(i, bottom, ch);
    }

    for (int j = top; j <= bottom;j++) {
        SetPoint(left, j, ch);
        SetPoint(right, j, ch);
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	for (int i = left; i <= right; i++) {
		for (int j = top; j <= bottom; j++) {
			SetPoint(j, i, ch);
		}
	}
}

void Canvas::SetPoint(int x, int y, char ch){
	if (x >= 0 && x < width && y >= 0 && y < height) {
		pixels[y][x] = ch;
	}
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void Canvas::Print() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << pixels[i][j];
        }
        cout << endl;
    }
}

void Canvas::Clear() {
    if (!pixels) return;  // Prevents a crash if pixels is null

    for (int i = 0; i < height; i++) {
        if (!pixels[i]) continue;  // Skip if row is null
        for (int j = 0; j < width; j++) {
            pixels[i][j] = ' ';
        }
    }
}