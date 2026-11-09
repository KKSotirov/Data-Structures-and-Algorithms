#include <iostream>
#include <vector>

void naPeshoKomboto(const int n, const int k, const int &curr, std::vector<int> numbs)
{
    // 1. Recursion base
    if (numbs.size() >= k)
    {
        for (int x : numbs)
            std::cout << x << " ";
        std::cout << ", ";
        return;
    }

    // 2. Else -> generate a combination
    for (size_t i = curr; i <= n; i++)
    {
        numbs.push_back(i);                 // we add the curr number
        naPeshoKomboto(n, k, i + 1, numbs); // call recursively with i+1 so we have no repition
        // By always constructing numbers whose next numbers are higher than the previous, we successfully generate all combinations, without duplicating -> (for combinations 123 and 312 are the same thing)

        numbs.pop_back(); // pop back, so we generate with next i
    }
}