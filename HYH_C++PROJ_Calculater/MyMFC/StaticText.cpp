#include "StaticText.h"
#include <string>

StaticText::StaticText() : Component()
{
	setSize(400, 100);
	staticText_ = "";
}

void StaticText::repaint(HDC dc)
{
	Rectangle(dc, posx, posy, posx + width_, posy + height_);
	TextOutA(dc, posx + 10, posy + height_ / 2,staticText_.c_str(),staticText_.size());
}

void StaticText::addText(string s)
{
	staticText_ = staticText_ + s;
}


void StaticText::setText(string text)
{
	staticText_ = text;
}
