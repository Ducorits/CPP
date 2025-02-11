#pragma once
#include <stdlib.h>

class Span {
	public:
		void addNumber();
		void shortestSpan();
		void longestSpan();
	private:
		size_t max_n_;
};