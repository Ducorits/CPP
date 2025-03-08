
#include <iostream>
#include <list>
#include <vector>
#include <easyfind.hpp>

void test_list(float num) {
	std::list<float> float_list;
	for (int i = 1; i < num ; i++)
		float_list.push_back(i);

	std::cout << "Looking for 5 inside float list" << std::endl;
	auto it = easyfind(float_list, 5);
	std::cout << "Found: " << *it << std::endl;

	std::cout << "Looking for 10 inside float list" << std::endl;
	it = easyfind(float_list, 10);
	std::cout << "Found: " << *it << std::endl;

	std::cout << "Looking for 15 inside float list" << std::endl;
	it = easyfind(float_list, 15);
	std::cout << "Found: " << *it << std::endl;
}

void test_vector(int num) {
	std::vector<int> int_vec;
	for (int i = 1; i < num ; i++)
		int_vec.push_back(i);

	std::cout << "Looking for 5 inside int vector" << std::endl;
	auto it = easyfind(int_vec, 5);
	std::cout << "Found: " << *it << std::endl;


	std::cout << "Looking for 10 inside int vector" << std::endl;
	it = easyfind(int_vec, 10);
	std::cout << "Found: " << *it << std::endl;

	std::cout << "Looking for 15 inside int vector" << std::endl;
	it = easyfind(int_vec, 15);
	std::cout << "Found: " << *it << std::endl;
}

int main()
{
	try {
		test_vector(20);
		test_vector(10);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try {
		test_list(20);
		test_list(10);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}