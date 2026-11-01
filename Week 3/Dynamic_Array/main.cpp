#include <iostream>
#include "dynamic_array.hpp"

int main()
{
    DynamicArray<char> arr1{};
    arr1.push_back('S');
    arr1.push_back('O');
    arr1.push_back('S');

    arr1.insert(2, '!');

    return 0;
}