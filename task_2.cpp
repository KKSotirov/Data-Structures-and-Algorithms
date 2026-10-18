#include <iostream>
#include <vector>

void printPrices(const std::vector<double> &prices)
{
    std::cout << "Printing prices: \n";
    for (const auto &it : prices)
    {
        std::cout << it << ", ";
    }
    std::cout << "\n";
}

int main()
{
    std::vector<double> stockPrices;
    stockPrices.push_back(203.7);
    stockPrices.push_back(300.5);
    stockPrices.push_back(128.3);
    stockPrices.push_back(1600);

    double max = stockPrices[0];
    for (auto it = stockPrices.begin(); it != stockPrices.end(); ++it)
    {
        if (*it > max)
            max = *it;
    }
    std::cout << "The highest priced stock is: " << max << "\n";

    // Removing an element
    stockPrices.pop_back();
    std::cout << "Size after pop back = " << stockPrices.size() << "\n";

    // Printing (after removing last element)
    printPrices(stockPrices);

    return 0;
}