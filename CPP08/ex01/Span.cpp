#include "Span.hpp"

Span::Span(unsigned int n) : max_n_(n) {}

Span::Span(const Span &other) : max_n_(other.max_n_) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
		max_n_ = other.max_n_;
	return *this;
}

Span::~Span() {}

void Span::addNumber()
{
}

void Span::shortestSpan()
{
}

void Span::longestSpan()
{
}
