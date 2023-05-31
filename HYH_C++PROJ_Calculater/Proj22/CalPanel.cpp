#include "CalPanel.h"
#include "Calculater.h"
#include "AbstractButton.h"
#include "StaticText.h"
#include <string>

int CalPanel::numBtn = 0;
CalPanel::CalPanel() : Panel()
{
	value_ = 0;
}

void CalPanel::repaint(HDC dc)
{
	for (auto i : cpn)
	{
		i->repaint(dc);
	}
}

void CalPanel::addComponent(Component* p)
{
	setBtnPos(p);
	Container::addComponent(p);
	numBtn++;
}

void CalPanel::setBtnPos(Component* p)
{
	if (numBtn < 4)
	{
		p->setBound(numBtn * btnSize, btnSize, 0, 0);
	}
	else if (numBtn >= 4 && numBtn < 8)
	{
		p->setBound((numBtn - 4) * btnSize, btnSize*2, 0, 0);
	}
	else if (numBtn >= 8 && numBtn < 12)
	{
		p->setBound((numBtn - 8) * btnSize, btnSize * 3, 0, 0);
	}
	else
	{
		p->setBound((numBtn - 12) * btnSize, btnSize * 4, 0, 0);
	}
}

void CalPanel::actionPerformed(ActionEvent e)
{
	int source = e.getSource()->getCommand();
	if (e.isLButtonUpEvent())
	{
		if (index_.empty())
		{
			st_->setText("");
			st_->repaint(cal_->getHDC());
		}
		OutputDebugStringA(e.getSource()->getName().c_str());
		OutputDebugStringA("\n");
		if (source != OP_EQUAL && source != OP_CANCEL)
		{
			index_.push_back(source);
			st_->addText(e.getSource()->getName().c_str());
		}
		else if(source==OP_EQUAL)
		{
			calculateValue();
			st_->setText(to_string(value_));
			index_.clear();
		}
		else
		{
			value_ = 0;
			index_.clear();
			st_->setText("");
		}
	}
	st_->repaint(cal_->getHDC());
}

void CalPanel::calculateValue()
{
	int indexOP = 0;
	int num1 = 0;
	int num2 = 0;
	for (auto i : index_)
	{
		if (i <= NUM_9)
		{
			if (indexOP == 0)
				num1 = num1 * 10 + i;
			else
				num2 = num2 * 10 + i;
		}
		else if (i == OP_PLUS)
		{
			indexOP = OP_PLUS;
		}
		else if (i == OP_MINUS)
		{
			indexOP = OP_MINUS;
		}
		else if (i == OP_STAR)
		{
			indexOP = OP_STAR;
		}
		else if (i == OP_SLASH)
		{
			indexOP = OP_SLASH;
		}
	}

	if (indexOP == OP_PLUS)
	{
		value_ = num1 + num2;
	}
	else if (indexOP == OP_MINUS)
	{
		value_ = num1 - num2;
	}
	else if (indexOP == OP_STAR)
	{
		value_ = num1 * num2;
	}
	else if (indexOP == OP_SLASH)
	{
		value_ = num1 / num2;
	}
	else
	{
		return;
	}
}

void CalPanel::setFrame(Calculater* c)
{
	cal_ = c;
}

void CalPanel::setStaticText(StaticText* st)
{
	st_ = st;
}