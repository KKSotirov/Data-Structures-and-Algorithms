#include <iostream>
#include <cassert>
#include "array_stack.hpp"

int main()
{
    ArrayStack<int> stack;

    assert(stack.empty());

    stack.push(10);
    stack.push(20);
    stack.push(30);

    assert(stack.size() == 3);
    assert(stack.top() == 30);

    stack.pop();

    assert(stack.top() == 20);
    assert(stack.size() == 2);

    stack.pop();
    stack.pop();

    assert(stack.empty());

    std::cout << "All tests passed!\n";
}