#include <iostream>
#include <stack>

std::string reverseString(const std::string &str)
{
    std::stack<char> s;

    for (char c : str)
        s.push(c);

    std::string newStr;
    while (!s.empty())
    {
        newStr.push_back(s.top());
        s.pop();
    }

    return newStr;
}

int main()
{

    std::cout << reverseString("eruliaFAmI");

    return 0;
}