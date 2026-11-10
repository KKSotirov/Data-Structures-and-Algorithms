#include <iostream>
#include <vector>
#include <stdexcept>

void printUniqueCombinations(const std::vector<std::string> &elements, const int k, int start, std::vector<std::string> &curr)
{

    // 1. Recursion base
    if (static_cast<int>(curr.size()) == k)
    {
        std::cout << "[";

        for (auto &x : curr)
            std::cout << x << "   "; // printing combination in [] brackets

        std::cout << "]  ";

        static int printed = 0;
        printed++; // calculating positions by keeping max 8 printed at each row

        if (printed % 8 == 0)
            std::cout << '\n';

        return;
    }

    // 2. Else -> generate a combination
    for (int i = start; i < static_cast<int>(elements.size()); i++)
    {
        curr.push_back(elements[i]);                       // we add the curr number
        printUniqueCombinations(elements, k, i + 1, curr); // call recursively with i+1 so we have no repition

        curr.pop_back(); // pop back, so we generate with next i
    }
}

int main()
{
    int k = 3;
    std::vector<std::string> elements = {"Cyber Dragon Core", "Cyberdark Claw", "Cyberdark Chimera"
                                                                                "Cyberdark Realm",
                                         "Cybernetic Horizon", "Cyber Dragon The Luminous Mech Dragon"};

    std::vector<std::string> curr;
    std::cout << "Printing all possible combinations without repetition! \n";
    printUniqueCombinations(elements, k, 1, curr);
    std::cout << "\n";

    return 0;
}