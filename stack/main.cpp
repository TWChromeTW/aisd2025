#include "class.hpp"
#include <iostream>

int main()
{
    StackVector<int> test;
    int tmp;

    std::cout << "isEmpty: " << test.isEmpty() << std::endl;
    test.push(5);
    test.push(20);
    test.push(15);
    test.push(500);
    test.push(550);
    test.push(10);
    std::cout << test;
    std::cout << "isEmpty: " <<test.isEmpty() << std::endl;
    tmp = test.pop();
    std::cout << "isEmpty: " << test.isEmpty() << std::endl;

    std::cout << tmp << std::endl;

    return 0;
}