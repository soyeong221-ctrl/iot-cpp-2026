// Ch1-5. 이름공간

#include <iostream>

namespace BestComImpl {
	void SimpleFunc(void);
}

namespace BestComImpl {
	void PrettyFunc(void);
}

namespace ProgComImpl {
	void SimpleFunc(void);
}

int main() {
	BestComImpl::SimpleFunc();
	return 0;
}

void BestComImpl::SimpleFunc(void) {

	std::cout << "BestCom이 정의한 함수" << std::endl;
	PrettyFunc();
	ProgComImpl::SimpleFunc();
}

void BestComImpl::PrettyFunc(void) {
std::cout<<"So pretty!"<<std::endl;
}

void ProgComImpl::SimpleFunc(void) {
	std::cout << "ProgCom이 정의한 함수" << std::endl;
}

