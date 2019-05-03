#include <iostream>
#include <memory>

#define log(a) std::cout << a << std::endl

#include "_list.h"

#include<vector>

int main()
{
    setbuf(stdout, NULL);
    List<int> l = List<int>();
    std::cout << l;

    l.append(3);
    std::cout << l;
    
    l.add(2);
    std::cout << l;

//    List<int> l2 = l;

    l.append(4);
    l.append(5);
    l.add(1);
    std::cout << l;
//    std::cout << l2;

    auto a = l.begin();
    std::cout << a << std::endl;
    ++a;
    std::cout << a << std::endl;
    a++;
    *a = 7;
    std::cout << l;
    std::cout << a << std::endl;

    a++;

    for (auto &i : l)
    {
        i = 0;
    }
    std::cout << l;

    try
    {
        std::cout << *a << std::endl;
    }
    catch (LinkedListElementDoesntExistException const& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        a++;
    }
    catch (LinkedListOutOfBoundsException const& e)
    {
        std::cout << e.what() << std::endl;
    }

    List<int> l3{1, 2, 3, 6, 1};
    std::cout << l3;

    return 0;
}
