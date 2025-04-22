#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include "colors.hpp"
#include <algorithm>
#include <climits>
#include <deque>
#include <limits>
#include <list>
#include <stack>
#include <vector>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
private:
public:
    MutantStack(/* args */) : std::stack<T, Container>() {};
    MutantStack(const MutantStack& cpy) : std::stack<T, Container>(cpy) {};
    MutantStack& operator=(const MutantStack& cpy) {
        std::stack<T, Container>::operator=(cpy);
        return *this;
    };
    ~MutantStack() {};

    typedef typename std::stack<T, Container>::container_type::iterator iterator;
    typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
    void swap(MutantStack& src) { std::swap(this->c, src.c); }
};

#endif // !MutantStack_HPP
