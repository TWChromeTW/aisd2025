#include "class.hpp"
#include <iostream>
#include <string>
#include <cstring>

bool checkBalanceBrackets(const char* text, const int maxDeep);

bool checkBalanceBrackets(const char* text, const int maxDeep)
{
    if (!text || maxDeep <= 0)
    {
        return false;
    }

    StackVector<char> tmp(maxDeep);

    const char* ptr = text;
    int nowDeep = 0;

    while (*ptr != '\0')
    {
        if (*ptr == '{' || *ptr == '(' || *ptr == '[')
        {
            if (nowDeep >= maxDeep)
            {
                return false;
            }

            tmp.push(*ptr);
            ++nowDeep;
        }

        if (*ptr == '}' || *ptr == ')' || *ptr == ']')
        {
            if (!tmp.isEmpty())
            {
                char top = tmp.pop();

                if (
                    (*ptr == '}' && top != '{') ||
                    (*ptr == ')' && top != '(') ||
                    (*ptr == ']' && top != '[')
                    )
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }

        ++ptr;
    }

    return tmp.isEmpty();
}

int main()
{
    //tests of StackVector
    std:: cout << "Tests of StackVector" << '\n';

    StackVector<int> test(2);
    int tmp;

    std::cout << "\nPush/Pop..." << '\n';

    std::cout << "isEmpty: " << test.isEmpty() << '\n';
    test.push(5);
    test.push(20);
    test.push(15);
    test.push(500);
    test.push(550);
    test.push(10);
    std::cout << test;
    std::cout << "isEmpty: " <<test.isEmpty() << '\n';
    tmp = test.pop();
    std::cout << "isEmpty: " << test.isEmpty() << '\n';

    std::cout << tmp << '\n';

    std::cout << "\nCopy constuct" << '\n';

    StackVector<std::string> first(5);
    first.push("hello world!");
    first.push("lets go work!");
    first.push("pupupu");
    StackVector<std::string> second(first);

    std::cout << "First:" << '\n';
    std::cout << first << '\n';
    std::cout << "Second:" << '\n';
    std::cout << second << '\n';

    std::cout << "\nMove constuct" << '\n';

    StackVector<std::string> third(std::move(first));
    std::cout << "Third:" << '\n';
    std::cout << third << '\n';
    std::cout << "Empty first?: " << first.isEmpty() << '\n';

    std::cout << "\nCopy =" << '\n';

    StackVector<double> a(10), b;
    a.push(1.5);
    a.push(-6.352);
    a.push(532532.32);
    a.push(0.0);
    a.push(-5.0);

    b = a;

    std:: cout << "a:" << '\n';
    std:: cout << a << '\n';

    std:: cout << "b:" << '\n';
    std:: cout << b << '\n';

    std::cout << "a is empyt: " << a.isEmpty() << '\n';
    std::cout << "b is empyt: " << b.isEmpty() << '\n';

    //checkBalanceBrackets
    std::cout << "\ncheckBalanceBrackets" << '\n';

    struct Node
    {
    public:
        Node(const char* elem, const int deep):
            elem_(elem),
            deep_(deep)
        {}

        const char* getElem() { return elem_; }
        int getDeep() { return deep_; }
    private:
        const char* elem_;
        const int deep_;
    };

    Node arr[6] =
    {
        Node("({[]})", 3), //true
        Node("([{}()][()({{()}})()])", 11), //true
        Node("({[][]}({})]", 3), //false
        Node("({[()]{]({})})", 4), //false
        Node("([]((({]((({{{}}}))()){})[})))[])", 10), //false
        Node("(((())))", 3) //false
    };

    for (std::size_t i = 0; i < 6; ++i)
    {
        std::cout << arr[i].getElem() << " : " << checkBalanceBrackets(arr[i].getElem(), arr[i].getDeep()) << '\n';
    }

    std::cout << "\nTest's of exception's" << '\n';

    std::cout << "\nException for pop (StackUnderflow):" << '\n';

    StackVector<int> stack(3);

    stack.push(1);
    stack.push(2);

    try
    {
        std::cout << "\nPop's:" << '\n';

        std::cout << "First pop: " << stack.pop() << '\n';
        std::cout << "Second pop: " << stack.pop() << '\n';
        std::cout << "Third pop: " << stack.pop() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\nException for big size of stack (WrongStackSize):" << '\n';

    try
    {
        StackVector<int> test_big_size(1000000000000000000);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\nException for many push and big size of stack (WrongStackSize): " << '\n';

    StackVector<int> many_push(10);

    std::size_t const BIG_SIZE = 1000000000000000000;
    std::size_t colvo_operation = 0;

    try
    {
        for (std::size_t i = 0; i <= BIG_SIZE; ++i)
        {
            colvo_operation = i;

            many_push.push(1);
        }
    }
    catch(const std::exception& e)
    {
        std::cout << "Colvo operation before exception: " << colvo_operation << '\n';
        std::cerr << e.what() << '\n';
    }

    return 0;
}
