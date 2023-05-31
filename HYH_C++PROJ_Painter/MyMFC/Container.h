#pragma once
#include "Component.h"
#include <list>
//Component Ŭ������ ���� Ŭ������ Composit ������ �̿��� Component ��ü ���� �����Ѵ�.
//�̺�Ʈ�� ó�� ���� ����Ѵ�.
class MouseListener;
class Container : public Component
{
public:
	Container();
	Container(string, int, int, int, int);

	bool eventHandler(ActionEvent) override;
	void repaint(HDC) override;

	void addMouseListener(MouseListener* l);
	virtual void addComponent(Component*);


protected:
	list<Component*> cpn;
	list<MouseListener*> mouseListener_;

	int shapeType;
	int checkBoxType;
	bool isChecked;
	bool isGroupKeyDown;
};

