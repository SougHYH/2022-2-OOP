
#include "frame.h"
#include "Calculater.h"
#include <iostream>
#include <exception>

// �ϴ��� ���� ���� 1���� ����Ѵ�.
extern Frame* theFrame ;
int main() {
	try {
		theFrame = new Calculater("��ü1������Ʈ2022", 420 ,540);
		theFrame->run();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
