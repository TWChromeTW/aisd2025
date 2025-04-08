#include "class.hpp"
#include <iostream>
#include <string>

int main()
{
    std::cout << "TEST OF QUEUERING" << '\n';

    std::cout << "\nCreate, enQueue, deQueue (int)" << '\n';

    QueueRing<int> test1(10);

    std::cout << "enQueue and cout Qeueu" << '\n';

    test1.enQueue(10);
    test1.enQueue(154);
    test1.enQueue(-4548);
    test1.enQueue(645);
    test1.enQueue(15);
    test1.enQueue(91);
    test1.enQueue(546);

    std::cout << test1 << '\n';

    int tmp_for_test1;

    tmp_for_test1 = test1.deQueue();

    std::cout << "deQeueu: " << tmp_for_test1 << " and cout test1" <<'\n';

    std::cout << test1 << '\n';

    std::cout << "'\nConsructor copy and moving" << '\n';

    std::cout << "Constructor copy" << '\n';

    QueueRing<int> test2(test1);

    std::cout << "test1" << test1 <<'\n';
    std::cout << "test2" << test2 << '\n';

    std::cout << "Constructor moving" << '\n';

    QueueRing<int> test3(std::move(test1));

    std::cout << "test1" << test1 << "test1 isEmpty: " << test1.isEmpty() << '\n';
    std::cout << "test2" << test2 << '\n';
    std::cout << "test3" << test3 << '\n';

    std::cout << "\nOperator = (copy)" << '\n';
    test3.deQueue();
    test3.deQueue();

    test1 = test3;

    std::cout << "test1" << test1 << '\n';
    std::cout << "test3" << test3 << '\n';

    std::cout << "\nEXCEPTIONS (string)" << '\n';

    std::cout << "QueueOverflow" << '\n';

    QueueRing<std::string> test4(3);

    test4.enQueue("hello");
    test4.enQueue("world");
    test4.enQueue("chrome");

    std::cout << test4 << '\n';

    std::cout << "Exception:" << '\n';

    try
    {
        test4.enQueue("exception");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\nWrongQueueSize" << '\n';

    test4.deQueue();
    test4.deQueue();

    std::cout << test4 << '\n';

    std::cout << "Exception:" << '\n';

    try
    {
        test4.deQueue();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\nException:" << '\n';

    try
    {
        QueueRing<int> test5(1000000000000000000);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}