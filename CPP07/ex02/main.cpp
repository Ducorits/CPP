#include <Array.hpp>
#include <iostream>

template <typename T>
void	fill_array(Array<T> &arr)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		arr[i] = i;
	}
}


template <typename T>
void	print_array(Array<T> arr)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;
}

int main( void ) {
	Array<int> int_arr = Array<int>(30);
	Array<int> int_arr2 = Array<int>(10);
	Array<float> flotarr = Array<float>(50);
	Array<float> floatarr2 = Array<float>(20);

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