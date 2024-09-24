#pragma once

#include <string>
#include <iostream>

// Print the thing!
template <typename T>
void	print(T & thing)
{
	std::cout << thing << std::endl;
}

template <typename T>
void add(T & num)
{
	num++;
}

template <typename T>
void sub(T & num)
{
	num--;
}

template <typename T, typename F>
void	iter(T *array, size_t length, F func)
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}