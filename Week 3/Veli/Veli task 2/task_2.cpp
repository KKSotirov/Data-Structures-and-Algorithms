#include <iostream>
#include <cstddef>
#include "array_stack.hpp"
#include <cstring>

int evalRPN(DynamicArray<std::string> &tokens)
{
    ArrayStack<int> myStack;

    for (std::size_t i = 0; i < tokens.getSize(); i++)
    {
        if (tokens[i] == "+" || tokens[i] == "-" ||
            tokens[i] == "*" || tokens[i] == "/")
        {

            int right = myStack.top();
            myStack.pop();

            int left = myStack.top();
            myStack.pop();

            int value = 0;

            if (tokens[i] == "+")
                value = (right + left);

            if (tokens[i] == "-")
                value = (left - right);

            if (tokens[i] == "*")
                value = (right * left);

            if (tokens[i] == "/")
                value = (left / right);

            myStack.push(value);
        }
        else
            myStack.push(std::stoi(tokens[i]));
    }
    return myStack.top();
}

int main()
{

    DynamicArray<std::string> tokens;
    // {"10", "75", "5", "/", "+"};
    tokens.push_back("10");
    tokens.push_back("75");
    tokens.push_back("5");
    tokens.push_back("/");
    tokens.push_back("+");

    std::cout << "Evaluation  = " << evalRPN(tokens) << "\n";

    return 0;
}