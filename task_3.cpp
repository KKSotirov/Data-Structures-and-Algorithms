#include <iostream>
#include <vector>
#include <string>

void push(std::vector<int> &v, const int num)
{
    v.push_back(num);
}

void insertAt(std::vector<int> &v, size_t index, int num)
{
    if (index > v.size())
    {
        std::cout << "Invalid index!\n";
        return;
    }

    v.push_back(0);

    for (size_t i = v.size() - 1; i > index; --i)
        v[i] = v[i - 1];

    v[index] = num;
}

void eraseAt(std::vector<int> &v, size_t index)
{
    if (index >= v.size())
    {
        std::cout << "Invalid index!\n";
        return;
    }

    for (size_t i = index; i < v.size() - 1; i++)
    {
        v[i] = v[i + 1];
    }
    v.pop_back();
}

void reverseArray(std::vector<int> &v)
{
    int temp;
    for (size_t i = 0; i < v.size() / 2; ++i)
    {
        temp = v[v.size() - i - 1];
        v[v.size() - i - 1] = v[i];
        v[i] = temp;
    }
}

int findFirst(const std::vector<int> &v, const int num)
{
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (*it == num)
            return (it - v.begin());
    }
    return -1;
}

void print(const std::vector<int> &v)
{
    std::cout << "Printing vector array: \n";
    for (const auto &x : v)
        std::cout << x << ", ";
    std::cout << "\n";
}

int main()
{
    std::vector<int> vect = {3, 7, 12};
    std::string command;

    while (std::cin >> command)
    {
        if (command == "PUSH")
        {
            int x;
            std::cout << "Please enter number to insert at end of vector array: \n";
            std::cin >> x;
            push(vect, x);
        }

        else if (command == "INSERT")
        {
            int x;
            size_t index;
            std::cout << "Please enter number to insert at end of vector array: \n";
            std::cin >> x;
            std::cout << "Please enter index at which to insert " << x << ": \n";
            std::cin >> index;
            insertAt(vect, index, x);
        }

        else if (command == "ERASE")
        {
            size_t index;
            std::cout << "Please enter index which's element to erase: \n";
            std::cin >> index;
            eraseAt(vect, index);
        }

        else if (command == "REVERSE")
        {
            reverseArray(vect);
            std::cout << "Array has been reversed! \n";
        }

        else if (command == "FIND")
        {
            int x;
            std::cout << "Please enter seeked number: \n";
            std::cin >> x;
            int result = findFirst(vect, x);
            if (result == -1)
                std::cout << "Number was not found in vector array! \n";
            else
                std::cout << "Number was found at index: " << result << "! \n";
        }

        else if (command == "PRINT")
        {
            print(vect);
        }

        else if (command == "EXIT")
            break;
    }

    return 0;
}