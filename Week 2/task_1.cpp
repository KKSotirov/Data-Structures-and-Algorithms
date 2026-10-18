#include <iostream>
#include <vector>

int main()
{
    // Initialization + inserting stocks
    std::vector<double> stockPrices;
    stockPrices.push_back(213.7);
    stockPrices.push_back(300.5);
    stockPrices.push_back(128.3);
    stockPrices.push_back(1600);

    // Standart print
    std::cout << "Printing with indexes \n";
    for (size_t i = 0; i < stockPrices.size(); i++)
    {
        std::cout << stockPrices[i] << "\n";
    }

    //  Calculating Sum
    double total = 0.0;
    for (const auto &x : stockPrices)
        total += x;
    std::cout << "Stocks total = " << total << "\n";

    //  Increasing prices by 10%
    for (auto &x : stockPrices)
        x *= 1.1;

    //  Printing final prices
    std::cout << "Printing with new auto it \n";
    for (auto it = stockPrices.begin(); it != stockPrices.end(); ++it)
        std::cout << *it << "\n";

    return 0;
}