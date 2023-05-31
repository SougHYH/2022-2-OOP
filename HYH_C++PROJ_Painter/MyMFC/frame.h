#pragma once
#include "Windows.h"
#include <string>
#include <list>
#include "Misc.h"
#include "Container.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
class ToolBar;
class Panel;
class Frame : public Container
{
protected:
	// Window ���α׷����� ���� �⺻ �������̴�. �ǵ帮�� �ʴ´�.
	HINSTANCE hInst_;
	HWND hWnd_;	 // ���� �ڵ��� �����صд�.
	HDC hDC_;    // �� ������ �־�� �׸��� �׸� �� �ִ�.
	
public:
	Frame();
	Frame(std::string, int, int);
	void invalidate();
	HDC getHDC();
	virtual void run();
};