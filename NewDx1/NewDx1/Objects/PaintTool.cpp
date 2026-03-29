#include "Framework.h"

PaintTool::PaintTool(HWND hWnd)
{
	hdc = GetDC(hWnd);
}

PaintTool::~PaintTool()
{
}

void PaintTool::OnMouseMove(LPARAM lParam)
{

	if (!isMouseDown)
	{
		return;
	}

	curMousePos.x = LOWORD(lParam);
	curMousePos.y = HIWORD(lParam);

	MoveToEx(hdc, prevMousePos.x, prevMousePos.y, nullptr);
	LineTo(hdc, curMousePos.x, curMousePos.y);

	prevMousePos = curMousePos;
	
}

void PaintTool::OnLButtonDown(LPARAM lParam)
{
	prevMousePos.x = LOWORD(lParam);
	prevMousePos.y = HIWORD(lParam);
	isMouseDown = true;
}

void PaintTool::OnLButtonUp(LPARAM lParam)
{
	isMouseDown = false;
}
