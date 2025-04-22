#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack;
    std::cout << get_color() << "Is the stack empty? " << (mstack.empty() ? "Yes" : "No")
              << ANSI_RESET << std::endl;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    MutantStack<int> s2;
    s2.push(-1);
    s2.push(-2);
    s2.push(-3);
    mstack.swap(s2);
    it = mstack.begin();
    ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << get_color() << *it << ANSI_RESET << std::endl;
        ++it;
    }
    std::cout << get_color() << "Is the stack empty? " << (mstack.empty() ? "Yes" : "No")
              << std::endl;
    std::cout << get_color() << "Size of stack is " << mstack.size() << ANSI_RESET << std::endl;
    return 0;
}

// #include "MutantStack.hpp"
// int main() {
//     std::list<int> mstack;
//     mstack.push_back(5);
//     mstack.push_back(17);
//     std::cout << mstack.back() << std::endl;
//     mstack.pop_back();
//     std::cout << mstack.size() << std::endl;
//     mstack.push_back(3);
//     mstack.push_back(5);
//     mstack.push_back(737);
//     //[...]
//     mstack.push_back(0);
//     std::list<int>::iterator it = mstack.begin();
//     std::list<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite) {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     std::list<int> s(mstack);
//     return 0;
// }
