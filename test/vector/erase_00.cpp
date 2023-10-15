#include <vector>
#include <iostream>
#include "../../include/vector.hpp"
 
template <typename T>
void print_container(const T& c) 
{
    // for (iterator iter = c.begin(); iter != c.end(); iter++)
    for (size_t idx = 0; idx < c.size(); idx++)
        std::cout << c[idx] << " ";
    std::cout << '\n';
}
/*
    - empty
    - end()
    별도의 예외처리는 없는 듯 하다.

*/

int main( )
{
    std::vector<int> c;

    for (int i=0; i<10; i++)
        c.push_back(i);
    for (size_t idx = 0; idx < c.size(); idx++)
        std::cout << c[idx] << " ";
    std::cout << '\n';
    c.erase(c.end() + 2, c.begin());
    return (0);
}
    // c.erase(c.begin(), c.end());
    // c.erase(c.begin() + 2, c.begin() + 5); // abort
    // print_container(c);
 

    // std::cout << "c.begin().base() : " << c.begin().base() << std::endl;
    // std::cout << "c.end().base() : " << c.end().base() << std::endl;
    // // Erase all even numbers
    // std::vector<int>::iterator it;
    // for (it = c.begin(); it != c.end();)
    // {
    //     // std::cout << "c.end().base() : " << c.end().base() << std::endl;
    //     // std::cout << "it.base() : " << it.base() << std::endl;
    //     // std::cout << "*it : " << *it << std::endl;
    //     if (*it % 2 == 0)
    //     {
    //         std::cout << "*it : " << *it << std::endl;
    //         it = c.erase(it);
    //     }
    //     else
    //         ++it;
    // }
    // std::cout << "after for loop c.end().base() : " << c.end().base() << std::endl;
    // std::cout << "it.base() : " << it.base() << std::endl;
    // print_container(c);
    // std::cout << "c.size() : " << c.size() << std::endl;
    // // c.erase(c.begin());
    // print_container(c);
    // std::cout << "c.size() : " << c.size() << std::endl;
    // std::cout << "c.capacity() : " << c.capacity() << std::endl;
// }
