#include "class.hpp"
#include <iostream>
#include <string>

int main()
{
    StackVector<int> test(2);
    int tmp;

    std::cout << "Push/Pop..." << std::endl;

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

    std::cout << "Copy constuct" << std::endl;

    StackVector<std::string> first(5);
    first.push("hello world!");
    first.push("lets go work!");
    first.push("pupupu");
    StackVector<std::string> second(first);

    std::cout << "First:" << std::endl;
    std::cout << first << std::endl;
    std::cout << "Second:" << std::endl;
    std::cout << second << std::endl;

    std::cout << "Move constuct" << std::endl;

    StackVector<std::string> third(std::move(first));
    std::cout << "Third:" << std::endl;
    std::cout << third << std::endl;
    std::cout << "Empty first?: " << first.isEmpty() << std::endl;

    std::cout << "Copy =" << std::endl;

    StackVector<double> a(10), b;
    a.push(1.5);
    a.push(-6.352);
    a.push(532532.32);
    a.push(0.0);
    a.push(-5.0);

    b = a;

    std:: cout << "a:" << std::endl;
    std:: cout << a << std::endl;

    std:: cout << "b:" << std::endl;
    std:: cout << b << std::endl;

    std::cout << "a is empyt: " << a.isEmpty() << std::endl;
    std::cout << "b is empyt: " << b.isEmpty() << std::endl;

    return 0;
}