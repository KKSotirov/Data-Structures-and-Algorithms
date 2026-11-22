#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

bool isPossible(std::vector<int> pushed, std::vector<int> popped)
{
    std::stack<int> jasonStatham;
    std::reverse(pushed.begin(), pushed.end());
    std::reverse(popped.begin(), popped.end());

    while (!pushed.empty() && !popped.empty())
    {
        jasonStatham.push(pushed.back());
        pushed.pop_back();

        while (!jasonStatham.empty() && !popped.empty() &&
               jasonStatham.top() == popped.back())
        {
            jasonStatham.pop();
            popped.pop_back();
        }
    }

    return jasonStatham.empty() && popped.empty();
}

int main()
{
    std::vector<int> pushed = {1, 2, 3, 4};
    std::vector<int> popped = {3, 1, 2, 4};
    if (isPossible(pushed, popped))
        std::cout << "The current sequence of pushing and popping is possible! \n";
    else
        std::cout << "The current sequence of pushing and popping is NOT possible! \n";

    return 0;
}