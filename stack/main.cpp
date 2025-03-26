#include "class.hpp"
#include <iostream>

int main()
{
    StackVector<int> test;
    int tmp;

    std::cout << test.isEmpty() << std::endl;
    test.push(5);
    std::cout << test.isEmpty() << std::endl;
    tmp = test.pop();
    std::cout << test.isEmpty() << std::endl;

    std::cout << tmp;

    return 0;
}