#include <iostream>
#include <regex>
#include <vector>
#include <deque>

void binaryInsert(std::vector<int> &sorted_vec, int value)
{
	auto pos = std::lower_bound(sorted_vec.begin(), sorted_vec.end(), value);
	sorted_vec.insert(pos, value);
}

void fordJohnsonSort(std::vector<int> &vec)
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

	fordJohnsonSort(winners);

	for (int value : losers)
	{
		binaryInsert(winners, value);
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

	fordJohnsonSort(vec);

	for (auto value : vec)
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