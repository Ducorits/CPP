#include <iter.hpp>

int main(void)
{
	int iarr[3] = {1, 5, 13};
	float farr[5] = {1.54, 12.3, 13, 7.5, 100.3};

	std::cout << "Int array:" << std::endl;
	iter(iarr, 3, print<int &>);
	std::cout << "adding 1 to whole array" << std::endl;
	iter(iarr, 3, add<int &>);
	std::cout << "Addition result" << std::endl;
	iter(iarr, 3, print<int &>);

	std::cout << "float array:" << std::endl;
	iter(farr, 5, print<float &>);
	std::cout << "subtracting from whole array..." << std::endl;
	iter(farr, 5, sub<float &>);
	std::cout << "Subtraction result:" << std::endl;
	iter(farr, 5, print<float &>);

	return (0);
}