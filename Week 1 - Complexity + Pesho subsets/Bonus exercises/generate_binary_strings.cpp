#include <iostream>
#include <vector>

void printBinaryStrings(const int n, std::vector<bool> &numbs) // By using bool array, we save mem
{

    // 1. Recursive base
    if (static_cast<int>(numbs.size()) == n)
    {
        std::cout << "{";
        for (auto x : numbs)
            std::cout << x << " ";
        std::cout << "} \n";
        return;
    }

    // 2. Generate all binary strings
    for (int i = 0; i < 2; i++) // we either fill with 0 or with 1   :)
    {

        numbs.push_back(i);
        printBinaryStrings(n, numbs);

        numbs.pop_back();
    }
}

int main()
{
    int n;
    std::vector<bool> numbs;
    std::cout << "Please enter n \n";
    std::cin >> n;

    std::cout << "Printing all binary strings with size n: \n";
    printBinaryStrings(n, numbs);

    return 0;
}