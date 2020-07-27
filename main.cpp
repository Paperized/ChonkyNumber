#include <iostream>
#include "src/ChonkyNumber.h"

int main()
{
	ChonkyNumber curr = 100;
	std::cout << curr << " prime? ";
	std::cout << curr.IsPrime() << std::endl;

	std::getchar();
	return 0;
}