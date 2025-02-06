#pragma once
#include <stdlib.h>
#include <stdexcept>

template <typename T>
class Array {
	public:
		Array();
		Array(size_t n);
		~Array();

		Array(const Array &arr);

		Array &operator=(const Array &arr);

		T	&operator[](size_t index) const;

		size_t size(void) const;
		class IndexOutOfBoundsException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};



	private:
		T		*_ptr;
		size_t	_size;
};

#include "Array.tpp"