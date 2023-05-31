
#include "frame.h"
#include "Calculater.h"
#include <iostream>
#include <exception>

// 일단은 전역 변수 1개는 사용한다.
extern Frame* theFrame ;
int main() {
	try {
		theFrame = new Calculater("객체1프로젝트2022", 420 ,540);
		theFrame->run();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
