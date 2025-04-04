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
};

template<class T>
class StackVector: public Stack<T>
{
public:
    StackVector(std::size_t size = 100);
    StackVector(const StackVector<T>& src);
    StackVector(StackVector<T>&& src);

    StackVector& operator=(const StackVector<T>& src);
    StackVector& operator=(StackVector<T>&&src);

    virtual ~StackVector();

    void createArray(std::size_t size);

    void push(const T& element) override;
    T pop() override;
    bool isEmpty() override;

    template<class U>
    friend std::ostream& operator<<(std::ostream& out, const StackVector<U>& stack);

    template<class U>
    friend void swap(StackVector<U>& first, StackVector<U>& second);

private:
    T* array_;
    std::size_t top_;
    std::size_t size_;
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

template<class T>
class WrongStackSize: public std::exception
{
public:
    WrongStackSize() : reason_("WrongStackSize") {}
    const char* what() const noexcept override { return reason_.c_str(); }
private:
    const std::string reason_;
};

template<class T>
void StackVector<T>::createArray(std::size_t size)
{
    try
    {
        array_ = new T[size + 1];
    }
    catch(...)
    {
        throw WrongStackSize<T>();
    }

}

template<class T>
StackVector<T>:: StackVector(std::size_t size) :
    top_(0),
    size_(size)
{
    try
    {
        createArray(size);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}

template<class T>
StackVector<T>:: StackVector(StackVector<T>&& src):
    array_(src.array_),
    top_(src.top_),
    size_(src.size_)
{
    src.array_ = nullptr;
    src.top_ = 0;
    src.size_ = 0;
}

template<class T>
StackVector<T>::StackVector(const StackVector<T>& src) :
    top_(src.top_),
    size_(src.size_)
{
    try
    {
        array_ = new T[src.size_ + 1];

        for (std::size_t i = 1; i <= src.size_; ++i)
        {
            array_[i] = src.array_[i];
        }
    }
    catch(...)
    {
        throw WrongStackSize<T>();
    }
}

template<class T>
StackVector<T>& StackVector<T>:: operator=(const StackVector<T>& src)
{
    if (this != &src)
    {
        StackVector<T> tmp(src);
        swap(*this, tmp);
    }

    return *this;
}

template<class T>
StackVector<T>& StackVector<T>:: operator=(StackVector<T>&& src)
{
    if (this != &src) {
        delete[] array_;
        array_ = src.array_;
        size_ = src.size_;
        top_ = src.top_;

        src.array_ = nullptr;
        src.size_ = 0;
        src.top_ = 0;
    }
    return *this;
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

        try
        {
            T* new_array = new T[new_size];

            for (std::size_t i = 1; i <= size_; ++i)
            {
                new_array[i] = array_[i];
            }

            delete[] array_;
            array_ = new_array;
            size_ = new_size -1;
        }
        catch(...)
        {
            throw WrongStackSize<T>();
        }
    }

    array_[++top_] = element;
}

template<class T>
T StackVector<T>::pop()
{
    try
    {
        if (isEmpty())
        {
            throw StackUnderflow<T>();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return array_[top_--];
}

template<class T>
bool StackVector<T>::isEmpty()
{
    return top_ == 0;
}

template<class U>
std::ostream& operator<<(std::ostream& out, const StackVector<U>& stack)
{
    out << "Elemnts of stack:\n";

    for (std::size_t i = 1; i <= stack.top_; ++i)
    {
        out << stack.array_[i] << "\n";
    }

    out << "end of stack\n";

    return out;
}

template<class U>
void swap(StackVector<U>& first, StackVector<U>& second)
{
    std::swap(first.array_, second.array_);
    std::swap(first.size_, second.size_);
    std::swap(first.top_, second.top_);
}

#endif // !__CLASSES_HPP