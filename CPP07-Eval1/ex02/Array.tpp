
#include <Array.hpp>

template <typename T>
const char *Array<T>::IndexOutOfBoundsException::what() const throw() {
	return "Index out of bounds.";
}

template <typename T>
Array<T>::Array() {
	_size = 1;
	_ptr = new T[_size];
}

template <typename T>
Array<T>::Array(size_t n) {
	_size = n;
	_ptr = new T[_size];
}

template <typename T>
Array<T>::~Array() {
	delete[] _ptr;
}

template <typename T>
Array<T>::Array(const Array<T> &arr) {
	_ptr = new T[1];
	*this = arr;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &arr) {
	if (this == &arr)
		return (*this);
	delete[] _ptr;
	_size = arr.size();
	_ptr = new T[_size];
	for (size_t i = 0; i < _size; i++)
	{
		_ptr[i] = arr[i];
	}
	return (*this);
}

template <typename T>
T	&Array<T>::operator[](size_t i) const {
	if (i >= _size)
		throw Array<T>::IndexOutOfBoundsException();
	return (_ptr[i]);
}

template <typename T>
size_t	Array<T>::size(void) const {
	return _size;
}
