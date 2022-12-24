#include "ShapeEditor.h"
#include "point_plus_shape.h"
#include "point_plus_editor.h"
#include "Resource.h"

void PointPlusEditor::OnMouseMove(HWND hWnd) {}

void PointPlusEditor::OnLBdown(HWND hWnd)
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xstart = xend = pt.x;
	ystart = xend = pt.y;
}

void PointPlusEditor::OnLBup(HWND hWnd) {
	pcshape[index] = new PointPlusShape;
	pcshape[index]->Set(xstart, ystart, xend, yend);
	index++;
	InvalidateRect(hWnd, NULL, TRUE);
};
