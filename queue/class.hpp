#pragma once
#ifndef __CLASSES_HPP__
#define __CLASSES_HPP__
#include <iostream>

template<class T>
class Queue
{
public:
    virtual ~Queue() {}
    virtual void enQueue(const T& element) = 0;
    virtual T deQueue() = 0;
    virtual bool isEmpty() = 0;
};

template<class T>
class QueueRing: public Queue<T>
{
public:
    

private:
    T* array_;
    std::size_t head_;
    std::size_t tail_;
    std::size_t size_;
};

#endif // !__CLASSES_HPP