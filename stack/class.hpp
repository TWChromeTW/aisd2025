#pragma once
#ifndef __CLASSES_HPP__
#define __CLASSES_HPP__
#include <iostream>
#include <exception>
#include <string>

template<class T>
class Stack
{
public:
    virtual ~Stack() {}
    virtual void push(const T& element) = 0;
    virtual T pop() = 0;
    virtual bool isEmpty() = 0;

// exception: ##думать думать думать
//     StackUnderflow
};

template<class T>
class StackVector;

template<class T>
std::ostream& operator<<(std::ostream& out, const StackVector<T>& stack);

template<class T>
class StackVector: public Stack<T>
{
public:
    StackVector(std::size_t size = 100);
    // StackVector(const StackVector<T>& src); ##не понял зачем...
    // StackVector(StackVector<T>&& src); ##не понял зачем...

    // StackVector& operator=(const StackVector<T>& src);
    // StackVector& operator=(StackVector<T>&&src);

    virtual ~StackVector();

    void push(const T& element);
    T pop() override;
    bool isEmpty();

    friend std::ostream& operator<< <T>(std::ostream& out, const StackVector<T>& stack);

    // std::size_t getSize() { return size_; };
    // T* getArray() { return array_; };

private:
    T* array_;
    std::size_t top_;
    std::size_t size_;

// exception: ##думать думать думать
//     StackUnderflow
};

template<class T>
class StackUnderflow: public std::exception
{
public:
    StackUnderflow() : reason_("StackUnderflow") {}
    const char* what() const noexcept override { return reason_.c_str(); }

private:
    const std::string reason_;
};

// template<class T>
// class WrongStackSize
// {
// //pass
// };

template<class T>
StackVector<T>:: StackVector(std::size_t size) :
    size_(size),
    top_(0)
{
    try
    {
        array_ = new T[size + 1];
    }
    catch(...)
    {
        std::cout << "bad\n";
        // throw WrongStackSize()
    }

}

template<class T>
StackVector<T>:: ~StackVector()
{
    delete[] array_;
}

template<class T>
void StackVector<T>::push(const T& element)
{
    if (top_ == size_)
    {
        std::size_t new_size = size_*2 + 1;

        T* new_array = new T[new_size];

        // memset(new_array, 0, sizeof(T) * new_size);
        // std::copy(array_, array_ + new_size, new_array);

        try
        {
            std::copy(array_, array_ + new_size, new_array);
        }
        catch(...)
        {
            delete[] new_array;
            throw;
        }

        delete[] array_;

        array_ = new_array;
        size_ = new_size;
    }

    array_[++top_] = element;
}

template<class T>
T StackVector<T>::pop()
{
    if (isEmpty())
    {
        throw StackUnderflow<T>();
    }

    return array_[top_--];
}

template<class T>
bool StackVector<T>::isEmpty()
{
    return top_ == 0;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const StackVector<T>& stack)
{
    out << "Elemnts of stack:\n";

    for (std::size_t i = 0; i < stack.top_; ++i)
    {
        out << stack.array_[i] << "\n";
    }

    out << "end of stack\n";

    return out;
}

#endif // !__CLASSES_HPP