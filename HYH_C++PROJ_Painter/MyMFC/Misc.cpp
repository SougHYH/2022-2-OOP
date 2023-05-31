#include "Misc.h"

MEvent::MEvent(UINT msg, WPARAM wParam, LPARAM lParam) :
	msg_(msg), wParam_(wParam), lParam_(lParam) 
{
	//  Nothing to do here.
}

ActionEvent::ActionEvent(UINT msg, WPARAM wParam, LPARAM lParam , Frame * frame) : MEvent(msg, wParam, lParam)
{
	frame_ = frame;
}

Frame* ActionEvent::getFrame()
{
	return frame_;
}
void ActionEvent::setEventBtnType(AbstractButton * b)
{
	button_ = b;
}

AbstractButton* ActionEvent::getSource()
{
	return button_;
}


bool MEvent::isLButtonDownEvent() {
	return msg_ == WM_LBUTTONDOWN;
}
bool MEvent::isLButtonUpEvent()
{
	return msg_ == WM_LBUTTONUP;
}
bool MEvent::isRButtonDownEvent()
{
	return msg_ == WM_RBUTTONDOWN;
}
bool MEvent::isRButtonUpEvent()
{
	return msg_ == WM_RBUTTONUP;
}
bool MEvent::isCtrlKeyDown()
{
	return wParam_ & MK_CONTROL;
}
bool MEvent::isShiftKeyDown() 
{
	return wParam_ & MK_SHIFT;
}

int MEvent::getX() //x��ǥ 
{
	return LOWORD(lParam_);
}
int MEvent::getY() //y��ǥ
{
	return HIWORD(lParam_);
}

MPoint MEvent::getPoint() // x,y��ǥ�� MPointŬ������ ����
{
	return MPoint(getX(),getY());
}

MPoint::MPoint(int x, int y): x_(x), y_(y){

}

MPoint::MPoint() : x_(0), y_(0) {

}