#include <PmergeMe.hpp>
#include <iostream>
#include <vector>
#include <deque>

void print_number(number_t num)
{
	std::cout << num.value << " ";
}

void print_numvec(std::vector<number_t *> &vec)
{
	for (auto value : vec)
	{
		print_number(*value);
	}
	std::cout << std::endl;
}

void update_indexes_vec(std::vector<number_t *> &vec)
{
	int i = 0;
	for (auto value : vec)
	{
		value->index = i;
		i++;
	}
}

void print_numdeq(std::deque<number_t *> &deq)
{
	for (auto value : deq)
	{
		print_number(*value);
	}
	std::cout << std::endl;
}

void update_indexes_deq(std::deque<number_t *> &deq)
{
	int i = 0;
	for (auto value : deq)
	{
		value->index = i;
		i++;
	}
}