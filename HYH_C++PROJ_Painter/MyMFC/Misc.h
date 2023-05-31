#pragma once
#include "Windows.h"

// ȭ����� ���� ��Ÿ���� Ŭ����.
class MPoint {
public:
	int x_, y_;
	MPoint(int x, int y);
	MPoint();
};

// �̺�Ʈ�� Ŭ����ȭ �Ѵ�.
class MEvent {
private:
	UINT msg_;
	WPARAM wParam_;
	LPARAM lParam_;
public:
	MEvent(UINT msg, WPARAM wParam, LPARAM lParam);
	bool isLButtonDownEvent();
	bool isLButtonUpEvent();
	bool isRButtonDownEvent();
	bool isRButtonUpEvent();

	bool isCtrlKeyDown();
	bool isShiftKeyDown();
	int getX();
	int getY();
	MPoint getPoint();
};

class Frame;
class AbstractButton;
class ActionEvent : public MEvent
{
public:
	ActionEvent(UINT msg, WPARAM wParam, LPARAM lParam, Frame*);
	void setEventBtnType(AbstractButton*);
	AbstractButton* getSource();
	Frame* getFrame();
private:
	AbstractButton* button_;
	Frame* frame_;
};
