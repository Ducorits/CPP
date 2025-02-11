#pragma once
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <exception>

class NotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Value not found in container.";
    }
};

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    auto it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw NotFoundException();
    }
    return it;
}

#endif // EASYFIND_HPP