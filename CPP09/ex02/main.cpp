#include <iostream>
#include <regex>
#include <vector>
#include <deque>

typedef struct number_s {
	int value;
	int index;
	number_s *winner;
	number_s *loser;
} number_t;

void print_vec(std::vector<int> &vec)
{
	for (auto value : vec)
	{
		std::cout << value << " ";
	}
	std::cout << std::endl;
}

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

void update_indexes(std::vector<number_t *> &vec)
{
	int i = 0;
	for (auto value : vec)
	{
		value->index = i;
		i++;
	}
}

void insert(number_t *num, size_t start_index, size_t end_index, std::vector<number_t *> &vec)
{
	size_t sectionSize = end_index - start_index + 1;
	size_t compare_index = (start_index + end_index) / 2;

	// std::cout << "inserting: " << num->value << " into: ";
	// print_numvec(vec);
	// std::cout << "start_i: " << start_index << " end_i: " << end_index << " comp_i: " << compare_index << std::endl;
	// std::cout << "section size: " << sectionSize << std::endl;
	if (sectionSize == 1)
	{
		auto it = vec.begin() + compare_index;
		vec.insert(it, num);
		update_indexes(vec);
	}
	else if (num->value <= vec[compare_index]->value)
	{
		insert(num, start_index, compare_index, vec);
	}
	else if (num->value > vec[compare_index]->value)
	{
		insert(num, compare_index + 1, end_index, vec);
	}
}

void fordJohnsonSort(std::vector<number_t *> &vec)
{
	std::vector<number_t *> winners;
	size_t i = 0;

	print_numvec(vec);

	for (; i + 1 < vec.size(); i++)
	{
		std::cout << "comparing: " << vec[i]->value << " and " << vec[i + 1]->value << std::endl;
		if (vec[i]->value >= vec[i + 1]->value)
		{
			auto it = vec.begin() + i;
			winners.push_back(vec[i]);
			(*it)->index = winners.size() - 1;
			(*it)->loser = vec[i + 1];
			vec[i + 1]->winner = *it;
			vec.erase(it);
			update_indexes(vec);
		}
		else
		{
			auto it = vec.begin() + i + 1;
			winners.push_back(vec[i + 1]);
			(*it)->index = winners.size() - 1;
			(*it)->loser = vec[i];
			vec[i]->winner = *it;
			vec.erase(it);
			update_indexes(vec);
		}
	}

	std::cout << "winners: " << std::endl;
	print_numvec(winners);
	std::cout << "Rest: " << std::endl;
	print_numvec(vec);

	if (winners.size() > 1)
		fordJohnsonSort(winners);

	// Start insertion. Use jacobsthal sequence. (make binary insert to start)

	// First we grab the loser connected to the winner on the first index.
	auto it_winner = winners.begin();
	auto it_loser = vec.begin() + (*it_winner)->loser->index;
	winners.insert(it_winner, *it_loser);
	vec.erase(it_loser);
	update_indexes(vec);
	update_indexes(winners);

	for (auto value : vec)
	{
		insert(value, 0, winners.size() - 1, winners);
	}
	vec = winners;
}

void vecFordJohnsonSort(std::vector<int> &vec, int offset)
{
	int i = offset;
	int index_offset;
	int i2;
	int sectionSize = vec.size() - offset;

	if (sectionSize < 2)
		return;

	if (sectionSize % 2 == 0)
		i2 = offset + (sectionSize / 2);
	else
		i2 = offset + (sectionSize / 2 + 1);

	index_offset = i2;
	print_vec(vec);
	std::cout << "offset: " << offset << std::endl;
	std::cout << "index_offset: " << index_offset << std::endl;
	std::cout << "SectionSize: " << sectionSize << std::endl;
	std::cout << "i: " << i << std::endl;
	std::cout << "i2: " << i2 << std::endl;

	while (i - offset < sectionSize / 2)
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

	print_vec(vec);
	if (sectionSize > 1)
		vecFordJohnsonSort(vec, index_offset);
}

int PmergeMe(char **argv)
{
	std::vector<int> vec;
	std::deque<int> deq;
	std::vector<number_t *> num_vec;

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

			number_t *nur = new number_t;
			nur->index = num_vec.size() - 1;
			nur->value = num;
			nur->loser = 0;
			nur->winner = 0;
			num_vec.push_back(nur);
		}
		else
		{
			std::cerr << "Error: Invalid argument!" << std::endl;
			return (1);
		}
	}

	fordJohnsonSort(num_vec);

	std::cout << "Vector:" << std::endl;
	print_numvec(num_vec);

	for (auto value : num_vec)
		delete value;

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
