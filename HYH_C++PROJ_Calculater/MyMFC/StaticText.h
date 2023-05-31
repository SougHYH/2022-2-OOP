#pragma once
#include "Component.h"
class StaticText : public Component
{
public:
	StaticText();
	void setText(string);
	void repaint(HDC) override;
	void addText(string);

protected:
	string staticText_;
};

