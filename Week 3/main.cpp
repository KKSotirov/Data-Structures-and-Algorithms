#include <iostream>
#include "static_array.h"

int main()
{
    StaticArray<int, 8> arr;
    arr.fill(73);
    if (arr.empty())
        std::cout << "Empty \n";
    else
    {
        std::cout << "Not empty! \n";
        std::cout << "Number of elements:  " << arr.size() << "\n";
    }

    StaticArray<char, 7> str;
    arr.fill('f');
    if (str.empty())
        std::cout << "Empty \n";
    else
    {
        std::cout << "Not empty! \n";
        std::cout << "Number of elements:  " << str.size() << "\n";
    }

    return 0;
}