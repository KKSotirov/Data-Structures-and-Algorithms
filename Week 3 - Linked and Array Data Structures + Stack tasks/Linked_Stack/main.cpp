#include <iostream>
#include "linked_stack.hpp"

int main()
{
    LinkedStack<int> list;
    list.push(73);
    list.push(33);
    std::cout << "Top of stack = " << list.top() << "\n";
    list.pop();
    list.push(1000);
    std::cout << "Top of stack = " << list.top() << "\n";
    std::cout << "Stack is empty? " << list.empty() << "\n";
    std::cout << "Stack size = " << list.size() << "\n";
    list.clear();
    std::cout << "Stack is empty? " << list.empty() << "\n";

    return 0;
}