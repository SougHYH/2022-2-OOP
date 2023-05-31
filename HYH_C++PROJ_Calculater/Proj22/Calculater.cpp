#include "Calculater.h"
#include "CalPanel.h"
#include "Button.h"
#include "StaticText.h"

Calculater::Calculater() : Calculater("", 500, 400)
{
	//
}
Calculater::Calculater(string title, int width, int height) : Frame(title, width, height)
{
	CalculaterInit();
}

void Calculater::CalculaterInit()
{
	cpl_ = new CalPanel();
	text_ = new StaticText();

	//숫자버튼
	Button* b1 = new Button("1");
	Button* b2 = new Button("2");
	Button* b3 = new Button("3");
	Button* b4 = new Button("4");
	Button* b5 = new Button("5");
	Button* b6 = new Button("6");
	Button* b7 = new Button("7");
	Button* b8 = new Button("8");
	Button* b9 = new Button("9");
	Button* b0 = new Button("0");
	//기호버튼
	Button* t1 = new Button("+");
	Button* t2 = new Button("-");
	Button* t3 = new Button("*");
	Button* t4 = new Button("/");
	Button* t5 = new Button("=");
	Button* t6 = new Button("C"); //초기화 버튼

	b1->setCommand(NUM_1);
	b2->setCommand(NUM_2);
	b3->setCommand(NUM_3);
	b4->setCommand(NUM_4);
	b5->setCommand(NUM_5);
	b6->setCommand(NUM_6);
	b7->setCommand(NUM_7);
	b8->setCommand(NUM_8);
	b9->setCommand(NUM_9);
	b0->setCommand(NUM_0);

	t1->setCommand(OP_PLUS);
	t2->setCommand(OP_MINUS);
	t3->setCommand(OP_STAR);
	t4->setCommand(OP_SLASH);
	t5->setCommand(OP_EQUAL);
	t6->setCommand(OP_CANCEL);

	b1->addActionListener(cpl_);
	b2->addActionListener(cpl_);
	b3->addActionListener(cpl_);
	b4->addActionListener(cpl_);
	b5->addActionListener(cpl_);
	b6->addActionListener(cpl_);
	b7->addActionListener(cpl_);
	b8->addActionListener(cpl_);
	b9->addActionListener(cpl_);
	b0->addActionListener(cpl_);

	t1->addActionListener(cpl_);
	t2->addActionListener(cpl_);
	t3->addActionListener(cpl_);
	t4->addActionListener(cpl_);
	t5->addActionListener(cpl_);
	t6->addActionListener(cpl_);

	cpl_->addComponent(b1);
	cpl_->addComponent(b2);
	cpl_->addComponent(b3);
	cpl_->addComponent(t6);

	cpl_->addComponent(b4);
	cpl_->addComponent(b5);
	cpl_->addComponent(b6);
	cpl_->addComponent(t1);

	cpl_->addComponent(b7);
	cpl_->addComponent(b8);
	cpl_->addComponent(b9);
	cpl_->addComponent(t2);

	cpl_->addComponent(b0);
	cpl_->addComponent(t3);
	cpl_->addComponent(t4);
	cpl_->addComponent(t5);

	this->addComponent(cpl_);
	this->addComponent(text_);

	cpl_->setStaticText(text_);
	cpl_->setFrame(this);
}