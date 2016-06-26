#include "S:\yjp.h"

std::string a = "Shihong Song", b = "Jiping Yu";

int main(){
	srand(time(0));
	int T = 1000000;
	while(T--)
		if(rand() % 2)
			std::swap(a, b);
	std::cout << a << ", " << b;
}
