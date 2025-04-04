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
#if 1
    //tests of StackVector
    std:: cout << "Tests of StackVector" << '\n';

    StackVector<int> test(2);
    int tmp;

    std::cout << "Push/Pop..." << '\n';

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

    std::cout << "Copy constuct" << '\n';

    StackVector<std::string> first(5);
    first.push("hello world!");
    first.push("lets go work!");
    first.push("pupupu");
    StackVector<std::string> second(first);

    std::cout << "First:" << '\n';
    std::cout << first << '\n';
    std::cout << "Second:" << '\n';
    std::cout << second << '\n';

    std::cout << "Move constuct" << '\n';

    StackVector<std::string> third(std::move(first));
    std::cout << "Third:" << '\n';
    std::cout << third << '\n';
    std::cout << "Empty first?: " << first.isEmpty() << '\n';

    std::cout << "Copy =" << '\n';

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
    std::cout << "checkBalanceBrackets" << '\n';

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
#endif

#if 0
    StackVector<int> stack(3);

    stack.push(1);
    stack.push(2);

    int a, b, c;

    a = stack.pop();
    b = stack.pop();
    c = stack.pop();
#endif

#if 0
    StackVector<int> test(1000000000000000000);
#endif

    return 0;
}
