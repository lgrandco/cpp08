#ifndef SPAN_HPP
#define SPAN_HPP
#include "colors.hpp"
#include <algorithm>
#include <climits>
#include <limits>
#include <vector>

class Span {
private:
    unsigned int _capacity;
    std::vector<int> _content;
    long int _longest_span;
    long int _shortest_span;
    bool is_ordered;

public:
    Span(/* args */);
    Span(const Span& cpy);
    Span& operator=(const Span& cpy);
    ~Span();
    Span(unsigned int n);
    void addNumber(int n);
    void addSequence(int a, int b);
    long int shortestSpan();
    long int longestSpan();
};

std::ostream& operator<<(std::ostream& out, Span& span);

#endif // !SPAN_HPP
