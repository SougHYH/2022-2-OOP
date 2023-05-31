#include "Container.h"
#include "MouseListener.h"


Container::Container() : Container("", 0, 0, 0, 0)
{
	//
}

Container::Container(string title, int x, int y, int width, int height) : Component(title, 0, 0, width, height)
{
	//
}

//containerq�� ���� ������Ʈ�鿡�� eventhandler�� ȣ�����ش�.
bool Container::eventHandler(ActionEvent e)
{
	for (auto i : cpn)
	{
		if (i->eventHandler(e))
		{
			return true;
		}
	}

	if (includes(e.getPoint()))
	{
		if (e.isLButtonDownEvent() || e.isRButtonDownEvent())
		{
			for (auto i : mouseListener_)
			{
				i->mousePressed(e);
			}
		}
		else if (e.isLButtonUpEvent() || e.isRButtonUpEvent())
		{
			for (auto i : mouseListener_)
			{
				i->mouseReleased(e);
			}
		}
	}
	return false;
}

void Container::addMouseListener(MouseListener *l)
{
	mouseListener_.push_back(l);
}

void Container::repaint(HDC dc) //������Ʈ���� �׷���
{
	for (auto i : cpn)
	{
		i->repaint(dc);
	}
}

void Container::addComponent(Component* p)
{
	cpn.push_back(p);
	p->setContainer(this);
}


