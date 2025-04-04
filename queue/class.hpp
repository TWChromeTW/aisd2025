#pragma once
#ifndef __CLASSES_HPP__
#define __CLASSES_HPP__
#include <iostream>

template <class T>
class Queue
{
public:
    virtual ~Queue() {};
    virtual void enQueue(const T& element) = 0;
    virtual T deQueue() = 0;
    virtual bool isEmpty() = 0;
};

template <class T>
class QueueRing: public Queue<T>
{
public:
    QueueRing(std::size_t size = 100);
    //другие конструкторы
    //и переопределение операторов

    virtual ~QueueRing();

    void enQueue(const T& element) override;
    T deQueue() override;

    bool isEmpty();
    bool isFull();

    template <class U>
    friend std::ostream& operator<<(std::ostream& out, QueueRing<U>& queue);

private:
    T* array_;
    std::size_t head_; //front
    std::size_t tail_; //rear
    std::size_t size_;
};

template <class T>
QueueRing<T>:: QueueRing(std::size_t size):
    head_(0),
    tail_(0),
    size_(size)
{
    array_ = new T[size_ + 1];
}

template <class T>
QueueRing<T>:: ~QueueRing()
{
    delete[] array_;
}

template <class T>
void QueueRing<T>:: enQueue(const T& element)
{
    if (isFull())
    {
        std::cout << "QueueOverflow" << '\n';
        throw std::runtime_error("Queue overflow");
        //throw QueueOverflow

        return;
    }
    else
    {
        if (head_ == 0) head_ = 1;
        tail_ = (tail_ + 1) % size_;
        array_[tail_] = element;
    }
}

template <class T>
T QueueRing<T>:: deQueue()
{
    if (isEmpty())
    {
        std::cout << "WrongQueueSize" << '\n';
        throw std::runtime_error("Queue underflow");
        //throw WrongQueueSize
    }
    else
    {
        T tmp = array_[head_];

        if (head_ == tail_)
        {
            head_ = 0;
            tail_ = 0;
        }
        else
        {
            head_ = (head_ + 1) % size_;
        }

        return tmp;
    }
}

template <class T>
bool QueueRing<T>::isEmpty()
{
    return head_ == 0;
}

template <class T>
bool QueueRing<T>::isFull()
{
    if (head_ == 0 && tail_ == (size_ - 1)) return true;
    if (head_ == (tail_ + 1)) return true;

    return false;
}

template<class U>
std::ostream& operator<<(std::ostream& out, QueueRing<U>& queue)
{
    out << '\n' << "Elements of QueueRing:" << '\n';

    if (!queue.isEmpty())
    {
        std::size_t i = queue.head_;

        do
        {
            out << queue.array_[i] << '\n';
            i = (i + 1) % queue.size_;
        }
        while (i != (queue.tail_ + 1) % queue.size_);
    }

    return out;
}

#endif // !__CLASSES_HPP