#include "framework.h"
#include "ellipse_shape.h"

void EllipseShape::Show(HDC hdc) {
	HBRUSH hBrush, hBrushOld;
	colorfill = RGB(0, 255, 255);
	hBrush = (HBRUSH)CreateSolidBrush(colorfill);
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
	
	Ellipse(hdc, xs1, ys1, xs2, ys2);
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}