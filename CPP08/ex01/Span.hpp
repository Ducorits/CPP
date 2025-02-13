#pragma once
#include <stdlib.h>
#include <vector>

class Span
{
public:
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int number);
	void shortestSpan();
	void longestSpan();

private:
	size_t max_n_;
	std::vector<int> numbers_;
};