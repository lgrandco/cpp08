#include "Span.hpp"

Span::Span() : _capacity(100), _longest_span(-1), _shortest_span(-1), is_ordered(false) {
    print_color("Default construcor called, span of size 100 created");
    _content.reserve(100);
}

Span::Span(unsigned int n)
    : _capacity(n), _longest_span(-1), _shortest_span(-1), is_ordered(false) {
    _content.reserve(n);
};

Span::Span(const Span& cpy) : _capacity(cpy._capacity), _content(cpy._content) {
    _longest_span = cpy._longest_span;
    _shortest_span = cpy._shortest_span;
    is_ordered = cpy.is_ordered;
};

Span& Span::operator=(const Span& cpy) {
    _capacity = cpy._capacity;
    _content = cpy._content;
    _longest_span = cpy._longest_span;
    _shortest_span = cpy._shortest_span;
    is_ordered = cpy.is_ordered;
    return *this;
}

Span::~Span() { _content.clear(); };

void Span::addNumber(int n) {
    if (_content.size() >= _capacity)
        throw std::length_error("could not add number: max size of span reached");
    _content.push_back(n);
    _longest_span = -1;
    _shortest_span = -1;
};

long int Span::shortestSpan() {
    if (_content.size() < 2) throw std::logic_error("not enough values to get shortest_span");
    if (_shortest_span != -1) return _shortest_span;
    std::sort(_content.begin(), _content.end());
    long _min = -1;
    int last;

    std::vector<int>::iterator it = _content.begin();
    std::vector<int>::iterator end = _content.end();
    for (; it != end; ++it) {
        _min = _min == -1 ? LONG_MAX : std::min(_min, std::abs(static_cast<long>(*it) - last));
        last = *it;
    }
    is_ordered = 1;
    _shortest_span = _min;
    return _shortest_span;
}

long int Span::longestSpan() {
    if (_content.size() < 2) throw std::logic_error("not enough values to get longest_span");
    if (_longest_span == -1)
        _longest_span = is_ordered ? _content.back() - *_content.begin()
                                   : *std::max_element(_content.begin(), _content.end()) -
                                         *std::min_element(_content.begin(), _content.end());
    return _longest_span;
};

// add from a(included) to b(not included)
void Span::addSequence(int a, int b) {
    if (_content.size() + (static_cast<long>(b) - a) > _capacity)
        throw std::length_error("could not add sequence: max size of span reached");
    for (; a < b; ++a) { _content.push_back(a); }
    _longest_span = -1;
    _shortest_span = -1;
}

std::ostream& operator<<(std::ostream& out, Span& span) {
    try {
        return out << get_color() << "shortest span of this span is " << span.shortestSpan()
                   << " and its longest span is " << span.longestSpan() << ANSI_RESET;
    } catch (const std::exception& e) {
        return out << get_color() << "not enough elements to get shortest and longest span"
                   << ANSI_RESET;
    }
}
