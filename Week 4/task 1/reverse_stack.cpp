#include <iostream>
#include <stack>
#include <cstddef>

void reverse(std::stack<int> &s)
{
    std::size_t size = s.size();
    std::stack<int> copy;
    for (size_t i = 0; i < size; i++)
    {
        copy.push(s.top());
        s.pop();
    }
    s = copy;
}

int main()
{
    std::stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    std::cout << "Current TOS = " << s1.top() << "\n";
    reverse(s1);
    std::cout << "Current TOS = " << s1.top() << "\n";
    s1.pop();
    std::cout << "Current TOS = " << s1.top() << "\n";

    return 0;
}