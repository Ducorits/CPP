#include "Span.hpp"
#include <climits>

Span::Span(unsigned int n) : max_n_(n) {}

Span::Span(const Span &other) : max_n_(other.max_n_) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
		max_n_ = other.max_n_;
	return *this;
}

Span::~Span() {}

void Span::addNumber(unsigned int num)
{
	if (numbers_.size() < max_n_)
	{
		numbers_.push_back(num);
		sorted_numbers_.insert(num);
	}
	else
		throw(std::exception());
}

unsigned int Span::shortestSpan()
{
	if (numbers_.size() < 2)
	{
		throw NoSpanException();
	}
	unsigned int shortest_span = INT_MAX;
	for (auto it = sorted_numbers_.begin(); std::next(it) != sorted_numbers_.end(); it++)
	{
		auto it2 = it;
		it2++;
		if (abs(*it - *it2) < shortest_span)
			shortest_span = abs(*it - *it2);
	}
	return shortest_span;
}

unsigned int Span::longestSpan()
{
	if (numbers_.size() < 2)
	{
		throw NoSpanException();
	}
	unsigned int span;

	auto min = sorted_numbers_.begin();
	auto max = sorted_numbers_.end();
	span = *max - *min;
	return span;
}

void Span::print()
{
	for (auto it = numbers_.begin(); it != numbers_.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}
