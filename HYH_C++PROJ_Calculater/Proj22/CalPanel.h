#pragma once
#include "Panel.h"
#include "ActionListener.h"

#define NUM_1 1
#define NUM_2 2
#define NUM_3 3
#define NUM_4 4
#define NUM_5 5
#define NUM_6 6
#define NUM_7 7
#define NUM_8 8
#define NUM_9 9
#define NUM_0 0

#define OP_PLUS 10
#define OP_MINUS 11
#define OP_STAR 12
#define OP_SLASH 13
#define OP_EQUAL 14
#define OP_CANCEL 15

class Calculater;
class StaticText;
class CalPanel : public Panel, public ActionListener
{
public:
	CalPanel();
	void actionPerformed(ActionEvent) override;
	void repaint(HDC) override;
	void addComponent(Component*) override;
	void setFrame(Calculater*);
	void setBtnPos(Component*);
	void setStaticText(StaticText*);
	void calculateValue();

protected:
	int value_;
	list<int> index_;
	Calculater* cal_;
	StaticText* st_;
	static int numBtn;
	static const int btnSize = 100;
};

