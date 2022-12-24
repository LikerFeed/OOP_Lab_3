#include "framework.h"
#include "rect_shape.h"

void RectShape::Show(HDC hdc) {

	long xStart = xs2 - (2 * (xs2 - xs1));
	long yStart = ys2 - (2 * (ys2 - ys1));

	MoveToEx(hdc, xStart, yStart, NULL);
	LineTo(hdc, xs2, yStart);
	LineTo(hdc, xs2, ys2);
	LineTo(hdc, xStart, ys2);
	LineTo(hdc, xStart, yStart);
}