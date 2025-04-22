#include "easyfind.hpp"

int main(void) {
    print_color("Testing ex00", std::cout, true, 1);
    std::list<int> lst;
    lst.push_back(34);
    lst.push_back(42);
    int& e = easyfind(lst, 34);
    print_color(
        "Testing lists: 34 should be found in list and then replaced by 2, 100 should throw an "
        "exception",
        std::cout,
        true,
        1
    );
    std::cout << get_color() << *lst.begin() << std::endl;
    e = 2;
    std::cout << get_color() << *lst.begin() << std::endl;
    try {
        easyfind(lst, 100);
    } catch (std::exception& e) { print_color(e.what(), std::cerr); }

    std::vector<int> vec;
    vec.push_back(34);
    vec.push_back(42);
    int& f = easyfind(vec, 34);
    print_sep();
    print_color(
        "Testing vectors: 34 should be found in vector and then replaced by 2, 100 should "
        "throw an "
        "exception",
        std::cout,
        true,
        1
    );
    std::cout << get_color() << *vec.begin() << std::endl;
    f = 2;
    std::cout << get_color() << *vec.begin() << std::endl;
    try {
        easyfind(vec, 100);
    } catch (std::exception& e) { print_color(e.what(), std::cerr); }
    std::deque<int> deq;
    deq.push_back(34);
    deq.push_back(42);
    int& g = easyfind(deq, 34);
    print_sep();
    print_color(
        "Testing deques: 34 should be found in deque and then replaced by 2, 100 should "
        "throw an "
        "exception",
        std::cout,
        true,
        1
    );
    std::cout << get_color() << *deq.begin() << std::endl;
    g = 2;
    std::cout << get_color() << *deq.begin() << std::endl;
    try {
        easyfind(deq, 100);
    } catch (std::exception& e) { print_color(e.what(), std::cerr); }
}
