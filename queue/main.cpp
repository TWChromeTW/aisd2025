#include "class.hpp"
#include <iostream>

int main()
{
    // QueueRing<int> queue(10);

    // queue.enQueue(15);
    // queue.enQueue(6);
    // queue.enQueue(9);
    // queue.enQueue(8);
    // queue.enQueue(4);

    // std:: cout << queue;

    // queue.enQueue(17);
    // queue.enQueue(3);
    // queue.enQueue(5);

    // std:: cout << queue;

    // queue.deQueue();

    // std:: cout << queue;

    QueueRing<int> queue(5);

    queue.enQueue(5);
    queue.enQueue(3);
    queue.enQueue(10);
    queue.enQueue(53);
    queue.enQueue(25);

    std::cout << "First: \n";

    std::cout << queue << '\n';

    std::cout << queue.deQueue() << '\n';

    std:: cout << queue;

    queue.enQueue(100);
    // queue.enQueue(101);

    std::cout << queue;

    return 0;
}