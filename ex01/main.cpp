#include "Span.hpp"

int main() {
    Span test(50);
    test.addNumber(124423443);
    test.addNumber(124);

    test.addNumber(2);
    test.addNumber(-3);
    test.addNumber(1234);

    test.addNumber(-1);
    test.addNumber(6);

    std::cout << test << std::endl;

    Span test_sequence(10000);
    try {
        test_sequence.addSequence(10, 10011);
    } catch (std::exception& e) { print_color(e.what(), std::cerr); }
    test_sequence.addSequence(10, 10009);
    try {
        test_sequence.addNumber(432);
    } catch (std::exception& e) { print_color(e.what(), std::cerr); }
    try {
        test_sequence.addNumber(433);
    } catch (std::exception& e) { print_color(e.what(), std::cerr); }
    std::cout << test_sequence << std::endl;
}
