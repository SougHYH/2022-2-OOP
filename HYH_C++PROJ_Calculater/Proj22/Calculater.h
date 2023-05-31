#pragma once
#include "frame.h"
class CalPanel;
class StaticText;
class Calculater : public Frame
{
public:
	Calculater();
	Calculater(string title, int width, int height);
	void CalculaterInit();

protected:
	CalPanel* cpl_;
	StaticText* text_;
};

