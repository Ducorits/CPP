#pragma once
#include <stdlib.h>
#include <vector>
#include <exception>
#include <iostream>
#include <sstream>
#include <iterator>
#include <set>

class Span
{
public:
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int number);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	void print();

	class OverMaxSizeException : public std::exception
	{
	public:
		const char *what() const noexcept override
		{
			return "Spans max size exceeded";
		};
	};

	class NoSpanException : public std::exception
	{
	public:
		const char *what() const noexcept override
		{
			return "Not enough numbers to calculate span (At least 2 required).";
		};
	};

	template <typename Iterator>
	void AddRange(Iterator begin, Iterator end)
	{
		int distance;

		distance = std::distance(begin, end);
		if (distance < 0)
			throw std::range_error("Range Error: Range has negative distance");
		if (distance + this->numbers_.size() > max_n_)
			throw std::range_error("Range Error: Range too big for span");
		for (; begin != end; begin++)
		{
			this->numbers_.push_back(*begin);
			this->sorted_numbers_.insert(*begin);
		}
	}

private:
	unsigned int max_n_;
	std::vector<int> numbers_;
	std::multiset<int> sorted_numbers_;
};