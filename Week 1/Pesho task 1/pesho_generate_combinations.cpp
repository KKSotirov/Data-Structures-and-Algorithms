#include <iostream>
#include <vector>
#include <stdexcept>

bool contains(const std::vector<int> &numbs, const int number)
{
    for (size_t i = 0; i < numbs.size(); i++)
    {
        if (numbs[i] == number)
            return true;
    }
    return false;
}

void printUniqueCombinations(const int n, const int k, const int &curr, std::vector<int> numbs)
{

    // 1. Recursion base
    if (static_cast<int>(numbs.size()) == k)
    {
        std::cout << "[";

        for (int x : numbs)
            std::cout << x << " "; // printing number in [] brackets

        std::cout << "]  ";

        static int printed = 0;
        printed++; // calculating positions by keeping max 8 printed at each row

        if (printed % 8 == 0)
            std::cout << '\n';

        return;
    }

    // 2. Else -> generate a combination
    for (int i = curr; i <= n; i++)
    {
        numbs.push_back(i);                          // we add the curr number
        printUniqueCombinations(n, k, i + 1, numbs); // call recursively with i+1 so we have no repition
        // By always constructing numbers whose next numbers are higher than the previous, we successfully generate all combinations, without duplicating -> (for combinations 123 and 312 are the same thing)

        numbs.pop_back(); // pop back, so we generate with next i
    }
}

void printCombinations(const int n, const int k, const int &curr, std::vector<int> numbs)
{

    // 1. Recursion base
    if (static_cast<int>(numbs.size()) == k)
    {
        std::cout << "[";

        for (int x : numbs)
            std::cout << x << " ";

        std::cout << "]  ";

        static int printed = 0;
        printed++;

        if (printed % 8 == 0)
            std::cout << '\n';

        return;
    }

    // 2. Else -> generate a combination
    for (int i = curr; i <= n; i++)
    {
        numbs.push_back(i);
        printCombinations(n, k, i, numbs); // Here we allow duplicating numbers -> we pass i

        numbs.pop_back();
    }
}

void printVariations(const int n, const int k, std::vector<int> &numbs)
{

    // 1. Recursive base
    if (static_cast<int>(numbs.size()) == k)
    {
        std::cout << "[";

        for (int x : numbs)
            std::cout << x << " ";

        std::cout << "]  ";

        static int printed = 0;
        printed++;

        if (printed % 8 == 0)
            std::cout << '\n';

        return;
    }

    // 2. Else -> Generate variations
    for (int i = 1; i <= n; i++)
    {
        numbs.push_back(i);
        printVariations(n, k, numbs);

        numbs.pop_back();
    }
}

void printUniqueVariations(const int n, const int k, std::vector<int> &numbs)
{

    // 1. Recursive base
    if (static_cast<int>(numbs.size()) == k)
    {
        std::cout << "[";

        for (int x : numbs)
            std::cout << x << " ";

        std::cout << "]  ";

        static int printed = 0;
        printed++;

        if (printed % 8 == 0)
            std::cout << '\n';

        return;
    }

    // 2. Else -> Generate unique variations
    for (int i = 1; i <= n; i++)
    {
        if (!contains(numbs, i))
        {
            numbs.push_back(i);
            printUniqueVariations(n, k, numbs);

            numbs.pop_back();
        }
    }
}

void printUniquePermutations(const int n, std::vector<int> &numbs)
{
    printUniqueVariations(n, n, numbs);
}

void printPermutations(const int n, std::vector<int> &numbs)
{
    printVariations(n, n, numbs);
}

int main()
{
    int n, k;
    std::cout << "Please enter n and k \n";
    std::cin >> n >> k;

    if (n < k)
        throw std::invalid_argument("k cannot be larger than n !");

    std::vector<int> numbs;
    std::cout << "Printing all possible combinations " << k << " from " << n << " without repetition! \n";
    printUniqueCombinations(n, k, 1, numbs);
    std::cout << "\n";

    std::cout << "Printing all possible combinations " << k << " from " << n << " with repetition! \n";
    printCombinations(n, k, 1, numbs);
    std::cout << "\n";

    std::cout << "Printing all possible variations " << k << " from " << n << " without repetition! \n";
    printUniqueVariations(n, k, numbs);
    std::cout << "\n";

    std::cout << "Printing all possible variations " << k << " from " << n << " with repetition! \n";
    printVariations(n, k, numbs);
    std::cout << "\n";

    std::cout << "Printing all possible permutations " << k << " from " << n << " without repetition! \n";
    printUniquePermutations(n, numbs);
    std::cout << "\n";

    std::cout << "Printing all possible permutations " << k << " from " << n << " with repetition! \n";
    printPermutations(n, numbs);
    std::cout << "\n";

    return 0;
}