// vector assign
#include <iostream>
#include <vector>
#include "../../include/vector.hpp"

int main ()
{
    ft::vector<int> first(5);
    ft::vector<int> second;
    ft::vector<int> third;

    // first.assign (2147483647,100);             // posivtive int max  ints with a value of 100
    first.assign (5,22);             // 7 ints with a value of 100
    // first.assign (-1,100);             // Abort
    std::cout << "first.size() : " << first.size() << std::endl;
    for (int idx = 0; idx < first.size(); idx++)
        std::cout << first[idx] << " ";
    std::cout << std::endl;
    std::cout << "first.capacity() : " << first.capacity() << std::endl;
    // first.assign (33,42);             // 7 ints with a value of 100
    std::cout << "first.capacity() : " << first.capacity() << std::endl;
    std::cout << "first[3] : " << first[3] << std::endl;

    for (int idx = 0; idx < first.size(); idx++)
        std::cout << first.at(idx) << " ";
    std::cout << std::endl;

    ft::vector<int>::iterator it;
    it=first.begin()+1;

    second.assign (it,first.end() + 1 ); // the 5 central values of first
    for (int idx = 0; idx < second.size(); idx++)
        std::cout << second.at(idx) << " ";
    std::cout << std::endl;

    int myints[] = {1776,7,4};
    third.assign (myints,myints+3);   // assigning from array.

    std::cout << "Size of first: " << int (first.size()) << '\n';
    std::cout << "Size of second: " << int (second.size()) << '\n';
    std::cout << "Size of third: " << int (third.size()) << '\n';
    return 0;
}