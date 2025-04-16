#include <iostream>
#include <regex>
#include <vector>
#include <deque>

// void deqBinaryInsert(std::deque<int> &sorted_deq, int value)
// {
// }

// void deqFordJohnsonSort(std::deque<int> &deq)
// {
// }

// void vecBinaryInsert(std::vector<int> &sorted_vec, int value)
// {
// }

void print_vec(std::vector<int> &vec)
{
	for (auto value : vec)
	{
		std::cout << value << " ";
	}
	std::cout << std::endl;
}

void vecFordJohnsonSort(std::vector<int> &vec, int offset)
{
	size_t i = offset;
	size_t index_offset;
	size_t i2;
	size_t sectionSize = vec.size() - offset;

	if (sectionSize < 2)
		return;

	print_vec(vec);

	if (sectionSize % 2 == 0)
		i2 = offset + (sectionSize / 2);
	else
		i2 = offset + (sectionSize / 2 + 1);

	index_offset = i2;

	while (i < sectionSize / 2)
	{
		int tmp;

		if (vec[i] > vec[i2])
		{
			tmp = vec[i];
			vec[i] = vec[i2];
			vec[i2] = tmp;
		}
		i++;
		i2++;
	}
	if (sectionSize > 1)
		vecFordJohnsonSort(vec, offset + index_offset);
}

int PmergeMe(char **argv)
{
	std::vector<int> vec;
	std::deque<int> deq;

	std::regex pattern(R"(^[0-9]+$)");

	std::smatch match;
	std::string argument;
	for (int i = 1; argv[i]; i++)
	{
		argument = argv[i];
		if (std::regex_match(argument, match, pattern))
		{
			int num = std::stoi(argument);
			vec.push_back(num);
			deq.push_back(num);
		}
		else
		{
			std::cerr << "Error: Invalid argument!" << std::endl;
			return (1);
		}
	}

	vecFordJohnsonSort(vec, 0);
	// deqFordJohnsonSort(deq);

	std::cout << "Vector:" << std::endl;
	print_vec(vec);

	// std::cout << "Deque:" << std::endl;
	// for (auto value : deq)
	// {
	// 	std::cout << value << " ";
	// }
	// std::cout << std::endl;

	return 0;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	else
	{
		return (PmergeMe(argv));
	}
}
