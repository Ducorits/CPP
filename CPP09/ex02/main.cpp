#include <iostream>
#include <regex>
#include <vector>
#include <deque>
#include <chrono>

typedef struct number_s
{
	int value;
	int index;
	number_s *winner;
	number_s *loser;
} number_t;

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

void insertDeq(number_t *num, size_t start_index, size_t end_index, std::deque<number_t *> &deq)
{
	size_t sectionSize = end_index - start_index + 1;
	size_t compare_index = (start_index + end_index) / 2;

	if (sectionSize == 1)
	{
		auto it = deq.begin() + compare_index;
		deq.insert(it, num);
		update_indexes_deq(deq);
	}
	else if (num->value <= deq[compare_index]->value)
	{
		insertDeq(num, start_index, compare_index, deq);
	}
	else if (num->value > deq[compare_index]->value)
	{
		insertDeq(num, compare_index + 1, end_index, deq);
	}
}

void insertVec(number_t *num, size_t start_index, size_t end_index, std::vector<number_t *> &vec)
{
	size_t sectionSize = end_index - start_index + 1;
	size_t compare_index = (start_index + end_index) / 2;

	if (sectionSize == 1)
	{
		auto it = vec.begin() + compare_index;
		vec.insert(it, num);
		update_indexes_vec(vec);
	}
	else if (num->value <= vec[compare_index]->value)
	{
		insertVec(num, start_index, compare_index, vec);
	}
	else if (num->value > vec[compare_index]->value)
	{
		insertVec(num, compare_index + 1, end_index, vec);
	}
}

void fordJohnsonSortVec(std::vector<number_t *> &vec)
{
	std::vector<number_t *> winners;
	size_t i = 0;

	for (; i + 1 < vec.size(); i++)
	{
		if (vec[i]->value >= vec[i + 1]->value)
		{
			auto it = vec.begin() + i;
			winners.push_back(vec[i]);
			(*it)->index = winners.size() - 1;
			(*it)->loser = vec[i + 1];
			vec[i + 1]->winner = *it;
			vec.erase(it);
			update_indexes_vec(vec);
		}
		else
		{
			auto it = vec.begin() + i + 1;
			winners.push_back(vec[i + 1]);
			(*it)->index = winners.size() - 1;
			(*it)->loser = vec[i];
			vec[i]->winner = *it;
			vec.erase(it);
			update_indexes_vec(vec);
		}
	}

	if (winners.size() > 1)
		fordJohnsonSortVec(winners);
	// Start insertion. Use jacobsthal sequence.

	// First we grab the loser connected to the winner on the first index.
	auto it_winner = winners.begin();
	auto it_loser = vec.begin() + (*it_winner)->loser->index;
	winners.insert(it_winner, *it_loser);
	vec.erase(it_loser);
	update_indexes_vec(vec);
	update_indexes_vec(winners);

	size_t cj = 3;
	size_t pj = 1;
	i = cj - pj - 1;

	while (vec.size() > 0)
	{
		if (i > vec.size() - 1)
			i = vec.size() - 1;
		auto it = vec.begin() + i;
		// If odd one has no winner
		if ((*it)->winner)
			insertVec(*it, 0, (*it)->winner->index, winners);
		else
			insertVec(*it, 0, winners.size() - 1, winners);
		vec.erase(it);
		if (i == 0)
		{
			size_t tmpj;
			tmpj = cj + (pj * 2);
			pj = cj;
			cj = tmpj;
			i = cj - pj - 1;
		}
		else
			i--;
	}
	vec = winners;
}

void fordJohnsonSortDeq(std::deque<number_t *> &deq)
{
	std::deque<number_t *> winners;
	size_t i = 0;

	for (; i + 1 < deq.size(); i++)
	{
		if (deq[i]->value >= deq[i + 1]->value)
		{
			auto it = deq.begin() + i;
			winners.push_back(deq[i]);
			(*it)->index = winners.size() - 1;
			(*it)->loser = deq[i + 1];
			deq[i + 1]->winner = *it;
			deq.erase(it);
			update_indexes_deq(deq);
		}
		else
		{
			auto it = deq.begin() + i + 1;
			winners.push_back(deq[i + 1]);
			(*it)->index = winners.size() - 1;
			(*it)->loser = deq[i];
			deq[i]->winner = *it;
			deq.erase(it);
			update_indexes_deq(deq);
		}
	}

	if (winners.size() > 1)
		fordJohnsonSortDeq(winners);
	// Start insertion. Use jacobsthal sequence.

	// First we grab the loser connected to the winner on the first index.
	auto it_winner = winners.begin();
	auto it_loser = deq.begin() + (*it_winner)->loser->index;
	winners.insert(it_winner, *it_loser);
	deq.erase(it_loser);
	update_indexes_deq(deq);
	update_indexes_deq(winners);

	size_t cj = 3;
	size_t pj = 1;
	i = cj - pj - 1;

	while (deq.size() > 0)
	{
		if (i > deq.size() - 1)
			i = deq.size() - 1;
		auto it = deq.begin() + i;
		// If odd one has no winner
		if ((*it)->winner)
			insertDeq(*it, 0, (*it)->winner->index, winners);
		else
			insertDeq(*it, 0, winners.size() - 1, winners);
		deq.erase(it);
		if (i == 0)
		{
			size_t tmpj;
			tmpj = cj + (pj * 2);
			pj = cj;
			cj = tmpj;
			i = cj - pj - 1;
		}
		else
			i--;
	}
	deq = winners;
}

int PmergeMe(char **argv)
{
	std::deque<number_t *> num_deq;
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

			number_t *numt = new number_t;
			number_t *numpty = new number_t;
			numt->index = num_vec.size() - 1;
			numt->value = num;
			numt->loser = 0;
			numt->winner = 0;
			numpty->index = num_deq.size() - 1;
			numpty->value = num;
			numpty->loser = 0;
			numpty->winner = 0;
			num_vec.push_back(numt);
			num_deq.push_back(numpty);
		}
		else
		{
			std::cerr << "Error: Invalid argument!" << std::endl;
			return (1);
		}
	}

	std::cout << "Before sort:" << std::endl;
	print_numvec(num_vec);

	std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
	fordJohnsonSortVec(num_vec);
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

	std::chrono::high_resolution_clock::time_point begin2 = std::chrono::high_resolution_clock::now();
	fordJohnsonSortDeq(num_deq);
	std::chrono::high_resolution_clock::time_point end2 = std::chrono::high_resolution_clock::now();

	std::cout << "After sort:" << std::endl;
	print_numvec(num_vec);

	// Print timing
	std::chrono::microseconds elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::chrono::microseconds elapsed2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2);

	std::cout << "Time to sort " << num_vec.size() << " elements using std::vector: " << elapsed.count() << " us" << std::endl;
	std::cout << "Time to sort " << num_deq.size() << " elements using std::deque: " << elapsed2.count() << " us" << std::endl;

	for (auto value : num_vec)
		delete value;
	for (auto value : num_deq)
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
