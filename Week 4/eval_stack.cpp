#include <iostream>
#include <stack>
#include <cstddef>
#include <cstring>
#include <stdexcept>

int eval(const std::string &s)
{
    std::stack<int> st;
    int curr = 0;

    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(curr);
            curr = 0;
        }

        else if (s[i] == ')')
        {
            if (st.empty())
                throw std::invalid_argument("INVALID STRING!");

            curr = (curr == 0) ? 1 : curr * 2;
            curr += st.top();
            st.pop();
        }

        else
            throw std::invalid_argument("INVALID STRING!");
    }

    if (!st.empty())
        throw std::invalid_argument("INVALID STRING!");

    return curr;
}

int main()
{
    std::string str = "(((())))()(())";
    std::cout << "Evaluation of string is = " << eval(str) << "\n";

    return 0;
}