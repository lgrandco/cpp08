#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include "colors.hpp"
#include <algorithm>
#include <deque>
#include <list>
#include <vector>

// returng a reference to an int so that it is a bit different than find
template < typename T>
int& easyfind(T& cont, int n) {
    typename T::iterator ret = std::find(cont.begin(), cont.end(), n);
    if (ret == cont.end()) throw std::runtime_error("Value not found");
    return *ret;
}

#endif // !EASYFIND_HPP
