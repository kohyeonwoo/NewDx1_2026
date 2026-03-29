#pragma once

class PaintTool
{

public :

	PaintTool(HWND hWnd);
	~PaintTool();

	void OnMouseMove(LPARAM lParam);
	void OnLButtonDown(LPARAM lParam);
	void OnLButtonUp(LPARAM lParam);

private :

	HDC hdc;

	POINT prevMousePos = {};
	POINT curMousePos = {};

	bool isMouseDown = false;

};