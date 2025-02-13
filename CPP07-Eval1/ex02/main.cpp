#include <Array.hpp>
#include <iostream>

template <typename T>
void fill_array(Array<T> &arr)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		arr[i] = i;
	}
}

template <typename T>
void print_array(Array<T> arr)
{
	std::cout << "Printing array of size: [" << arr.size() << "]" << std::endl;
	for (size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;
}

int own_test(void)
{
	Array<int> int_arr = Array<int>(30);
	Array<int> int_arr2 = Array<int>(10);
	Array<float> flotarr = Array<float>(50);
	Array<float> floatarr2 = Array<float>(20);

	int *a = new int();

	std::cout << "a: " << *a << std::endl;

	fill_array(int_arr);
	fill_array(int_arr2);
	fill_array(flotarr);
	fill_array(floatarr2);
	std::cout << "print arrays:" << std::endl;
	print_array(int_arr);
	print_array(int_arr2);
	print_array(flotarr);
	print_array(floatarr2);

	int_arr = int_arr2;
	flotarr = floatarr2;
	std::cout << "after copying" << std::endl;
	print_array(int_arr);
	print_array(int_arr2);
	print_array(flotarr);
	print_array(floatarr2);

	try
	{
		int_arr[100];
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}

#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char **)
{
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	// SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete[] mirror; //
	own_test();
	return 0;
}