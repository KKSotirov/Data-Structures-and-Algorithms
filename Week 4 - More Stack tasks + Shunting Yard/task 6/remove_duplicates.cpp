#include <iostream>
#include <stack>
#include <algorithm>

std::string removeDuplicates(const std::string &str)
{
    std::stack<char> s;
    for (auto i = str.begin(); i != str.end(); ++i)
    {
        if (s.empty())
            s.push(*i);

        else
        {
            if (s.top() == *i)
                s.pop();

            else
                s.push(*i);
        }
    }

    std::string result;
    while (!s.empty())
    {
        result.push_back(s.top());
        s.pop();
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main()
{
    std::cout << removeDuplicates("CCybeer DrraAgon");

    return 0;
}