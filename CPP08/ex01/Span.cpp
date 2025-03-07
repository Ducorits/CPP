#include "Span.hpp"
#include <climits>

Span::Span() : max_n_(0) {}

Span::Span(unsigned int n) : max_n_(n) {}

Span::Span(const Span &other) : max_n_(other.max_n_), sorted_numbers_(other.sorted_numbers_) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		max_n_ = other.max_n_;
		sorted_numbers_ = other.sorted_numbers_;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int num)
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
	if (sorted_numbers_.size() < 2)
		throw NoSpanException();

	unsigned int shortest_span = UINT_MAX;
	for (auto it = sorted_numbers_.begin(), next = std::next(it);
			 next != sorted_numbers_.end();
			 ++it, ++next)
	{
		unsigned int diff = static_cast<unsigned int>(std::abs(*next - *it));
		if (diff < shortest_span)
			shortest_span = diff;
	}
	return shortest_span;
}

unsigned int Span::longestSpan()
{
	if (sorted_numbers_.size() < 2)
	{
		throw NoSpanException();
	}

	auto min = *sorted_numbers_.begin();
	auto max = *sorted_numbers_.rbegin();

	return static_cast<unsigned int>(max - min);
}

void Span::print()
{
	for (auto it = numbers_.begin(); it != numbers_.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}
