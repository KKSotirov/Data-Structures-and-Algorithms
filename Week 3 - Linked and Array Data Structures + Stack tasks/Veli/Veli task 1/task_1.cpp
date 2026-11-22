#include <iostream>
#include "array_stack.hpp"
#include <cstring>
#include <cstddef>

bool isValid(const std::string &str)
{
    ArrayStack<char> myStack;
    for (std::size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            myStack.push(str[i]);

        else
        {
            if (myStack.empty())
                return false;

            if (str[i] == ')' && myStack.top() == '(' ||
                str[i] == ']' && myStack.top() == '[' ||
                str[i] == '}' && myStack.top() == '{')
                myStack.pop();
            else
                return false;
        }
        return myStack.empty();
    }
}