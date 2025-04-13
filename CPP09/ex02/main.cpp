#include <iostream>
#include <regex>
#include <vector>
#include <deque>

void deqBinaryInsert(std::deque<int> &sorted_deq, int value)
{
	auto pos = std::lower_bound(sorted_deq.begin(), sorted_deq.end(), value);
	sorted_deq.insert(pos, value);
}

void deqFordJohnsonSort(std::deque<int> &deq)
{

	if (deq.size() <= 1)
		return;

	std::deque<int> winners;
	std::deque<int> losers;

	size_t i = 0;
	for (; i + 1 < deq.size(); i += 2)
	{
		if (deq[i] < deq[i + 1])
		{
			winners.push_back(deq[i + 1]);
			losers.push_back(deq[i]);
		}
		else
		{
			winners.push_back(deq[i]);
			losers.push_back(deq[i + 1]);
		}
	}
	if (i < deq.size())
		losers.push_back(deq[i]);

	deqFordJohnsonSort(winners);

	for (int value : losers)
	{
		deqBinaryInsert(winners, value);
	}

	deq = winners;
}

void vecBinaryInsert(std::vector<int> &sorted_vec, int value)
{
	auto pos = std::lower_bound(sorted_vec.begin(), sorted_vec.end(), value);
	sorted_vec.insert(pos, value);
}

void vecFordJohnsonSort(std::vector<int> &vec)
{

	if (vec.size() <= 1)
		return;

	std::vector<int> winners;
	std::vector<int> losers;

	size_t i = 0;
	for (; i + 1 < vec.size(); i += 2)
	{
		if (vec[i] < vec[i + 1])
		{
			winners.push_back(vec[i + 1]);
			losers.push_back(vec[i]);
		}
		else
		{
			winners.push_back(vec[i]);
			losers.push_back(vec[i + 1]);
		}
	}
	if (i < vec.size())
		losers.push_back(vec[i]);

	vecFordJohnsonSort(winners);

	for (int value : losers)
	{
		vecBinaryInsert(winners, value);
	}

	vec = winners;
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

	vecFordJohnsonSort(vec);
	deqFordJohnsonSort(deq);

	std::cout << "Vector:" << std::endl;
	for (auto value : vec)
	{
		std::cout << value << " ";
	}
	std::cout << std::endl;

	std::cout << "Deque:" << std::endl;
	for (auto value : deq)
	{
		std::cout << value << " ";
	}
	std::cout << std::endl;

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