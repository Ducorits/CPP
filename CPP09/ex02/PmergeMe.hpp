#pragma once
#include <iostream>
#include <vector>
#include <deque>

typedef struct number_s
{
	int value;
	int index;
	number_s *winner;
	number_s *loser;
} number_t;

template <typename Container = std::vector<number_t *>>
void print_numcon(Container &con)
{
	for (auto value : con)
	{
		std::cout << value->value << " ";
	}
	std::cout << std::endl;
}

template <typename Container = std::vector<number_t *>>
void update_indexes_con(Container &con)
{
	int i = 0;
	for (auto value : con)
	{
		value->index = i;
		i++;
	}
}

template <typename Container = std::vector<number_t *>>
void insertCon(number_t *num, size_t start_index, size_t end_index, Container &con)
{
	size_t sectionSize = end_index - start_index + 1;
	size_t compare_index = (start_index + end_index) / 2;

	if (sectionSize == 1)
	{
		auto it = con.begin() + compare_index;
		con.insert(it, num);
		update_indexes_con<Container>(con);
	}
	else if (num->value <= con[compare_index]->value)
	{
		insertCon<Container>(num, start_index, compare_index, con);
	}
	else if (num->value > con[compare_index]->value)
	{
		insertCon<Container>(num, compare_index + 1, end_index, con);
	}
}

template <typename Container = std::vector<number_t *>>
void fordJohnsonSortCon(Container &vec)
{
	Container winners;
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
			update_indexes_con<Container>(vec);
		}
		else
		{
			auto it = vec.begin() + i + 1;
			winners.push_back(vec[i + 1]);
			(*it)->index = winners.size() - 1;
			(*it)->loser = vec[i];
			vec[i]->winner = *it;
			vec.erase(it);
			update_indexes_con<Container>(vec);
		}
	}

	if (winners.size() > 1)
		fordJohnsonSortCon<Container>(winners);
	// Start insertion. Use jacobsthal sequence.

	// First we grab the loser connected to the winner on the first index.
	auto it_winner = winners.begin();
	auto it_loser = vec.begin() + (*it_winner)->loser->index;
	winners.insert(it_winner, *it_loser);
	vec.erase(it_loser);
	update_indexes_con<Container>(vec);
	update_indexes_con<Container>(winners);

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
			insertCon<Container>(*it, 0, (*it)->winner->index, winners);
		else
			insertCon<Container>(*it, 0, winners.size() - 1, winners);
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