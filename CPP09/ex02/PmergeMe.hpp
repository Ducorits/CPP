#pragma once

typedef struct number_s
{
	int value;
	int index;
	number_s *winner;
	number_s *loser;
} number_t;

void print_number(number_t num);

void print_numvec(std::vector<number_t *> &vec);

void update_indexes_vec(std::vector<number_t *> &vec);

void print_numdeq(std::deque<number_t *> &deq);

void update_indexes_deq(std::deque<number_t *> &deq);
