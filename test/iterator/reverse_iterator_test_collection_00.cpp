#include <iostream>
#include <iterator>
#include <vector>
#include "../../include/iterator.hpp"

typedef std::vector<int>::iterator iter_type;

template<typename T>
void    std_print(const typename std::reverse_iterator<T>& rev_end, const typename std::reverse_iterator<T>& rev_begin)
{

    std::cout << "std myvector:";
    for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

template<typename T>
void    ft_print(const typename ft::reverse_iterator<T>& rev_end, const typename ft::reverse_iterator<T>& rev_begin)
{
    std::cout << "ft myvector:";
    for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}


int main () {
    std::vector<int> myvector;
    // iter_type   it(42);

    for (int i=0; i<10; i++)
        myvector.push_back(i);

    std::reverse_iterator<iter_type>    std_default_reverse_iterator;
    ft::reverse_iterator<iter_type>    ft_default_reverse_iterator;

    // std_default_reverse_iterator = myvector.rbegin() + 3;
    // ft_default_reverse_iterator = myvector.rbegin() + 3;
    // std::cout << "*std_default_reverse_iterator : " << *std_default_reverse_iterator << std::endl;
    // std::cout << "*ft_default_reverse_iterator : " << *ft_default_reverse_iterator << std::endl;

    std::reverse_iterator<iter_type> std_rev_begin (myvector.end());
    std::reverse_iterator<iter_type> std_rev_end (myvector.begin());

    ft::reverse_iterator<iter_type> ft_rev_begin (myvector.end());
    ft::reverse_iterator<iter_type> ft_rev_end (myvector.begin());

    std::cout << "------------- base() -------------"<< std::endl;
    std::cout << "*(--std_rev_begin.base()) : " << *(--std_rev_begin.base()) << std::endl;
    std::cout << "*(++std_rev_end.base()) : " << *(++std_rev_end.base()) << std::endl;
    std::cout << "*(--ft_rev_begin.base()) : " << *(--ft_rev_begin.base()) << std::endl;
    std::cout << "*(++ft_rev_begin.base()) : " << *(++ft_rev_end.base()) << std::endl;
    std::cout << std::endl;

    std::cout << "------------- operator*() -------------"<< std::endl;
    std::cout << "*std_rev_begin : " << *std_rev_begin << std::endl;
    std::cout << "*std_rev_end : " << *std_rev_end << std::endl;
    std::cout << "*ft_rev_begin : " << *ft_rev_begin << std::endl;
    std::cout << "*ft_rev_end : " << *ft_rev_end << std::endl;
    std::cout << std::endl;

    std::cout << "------------- operator+() -------------"<< std::endl;
    std::cout << "*std_rev_begin+(1) : " << *(std_rev_begin+(1)) << std::endl;
    std::cout << "*ft_rev_begin+(1) : " << *(ft_rev_begin+(1)) << std::endl;
    std::cout << std::endl;

    std::cout << "------------- operator++() -------------"<< std::endl;
    std::cout << "*++std_rev_begin : " << *(++std_rev_begin) << std::endl;
    std::cout << "*++ft_rev_begin : " << *(++ft_rev_begin) << std::endl;
    std::cout << "*std_rev_begin : " << *std_rev_begin << std::endl;
    std::cout << "*ft_rev_begin : " << *ft_rev_begin << std::endl;
    std::cout << std::endl;

    std::cout << "------------- operator++(int) -------------"<< std::endl;
    std::cout << "*std_rev_begin++ : " << *(std_rev_begin++) << std::endl;
    std::cout << "*ft_rev_begin++ : " << *(ft_rev_begin++) << std::endl;
    std::cout << "*std_rev_begin : " << *std_rev_begin << std::endl;
    std::cout << "*ft_rev_begin : " << *ft_rev_begin << std::endl;
    std::cout << std::endl;

    std::cout << "------------- operator+=() -------------"<< std::endl;
    std::cout << "*std_rev_begin+=(1) : " << *(std_rev_begin+=(1)) << std::endl;
    std::cout << "*ft_rev_begin+=(1) : " << *(ft_rev_begin+=(1)) << std::endl;
    std::cout << "*std_rev_begin : " << *std_rev_begin << std::endl;
    std::cout << "*ft_rev_begin : " << *ft_rev_begin << std::endl;
    std::cout << std::endl;

    std::cout << "------------- operator-() -------------"<< std::endl;
    std::cout << "*std_rev_begin-(1) : " << *(std_rev_begin-(1)) << std::endl;
    std::cout << "*ft_rev_begin-(1) : " << *(ft_rev_begin-(1)) << std::endl;
    std::cout << "*std_rev_begin : " << *std_rev_begin << std::endl;
    std::cout << "*ft_rev_begin : " << *ft_rev_begin << std::endl;
    std::cout << std::endl;

    std::cout << "------------- operator--() -------------"<< std::endl;
    std::cout << "*--std_rev_begin : " << *(--std_rev_begin) << std::endl;
    std::cout << "*--ft_rev_begin : " << *(--ft_rev_begin) << std::endl;
    std::cout << "*std_rev_begin : " << *std_rev_begin << std::endl;
    std::cout << "*ft_rev_begin : " << *ft_rev_begin << std::endl;
    std::cout << std::endl;

    std::cout << "------------- operator--(int) -------------"<< std::endl;
    std::cout << "*std_rev_begin-- : " << *(std_rev_begin--) << std::endl;
    std::cout << "*ft_rev_begin-- : " << *(ft_rev_begin--) << std::endl;
    std::cout << "*std_rev_begin : " << *std_rev_begin << std::endl;
    std::cout << "*ft_rev_begin : " << *ft_rev_begin << std::endl;
    std::cout << std::endl;

    std::cout << "------------- operator-=() -------------"<< std::endl;
    std::cout << "*std_rev_begin-=(1) : " << *(std_rev_begin-=(1)) << std::endl;
    std::cout << "*ft_rev_begin-=(1) : " << *(ft_rev_begin-=(1)) << std::endl;
    std::cout << "*std_rev_begin : " << *std_rev_begin << std::endl;
    std::cout << "*ft_rev_begin : " << *ft_rev_begin << std::endl;
    std::cout << std::endl;

    std::cout << "------------- operator[]() -------------"<< std::endl;
    std::cout << "std_rev_begin[0] : " << std_rev_begin[0] << std::endl;
    std::cout << "ft_rev_begin[0] : " << ft_rev_begin[0] << std::endl;
    std::cout << "std_rev_begin[1] : " << std_rev_begin[1] << std::endl;
    std::cout << "ft_rev_begin[1] : " << ft_rev_begin[1] << std::endl;
    std::cout << "std_rev_begin[2] : " << std_rev_begin[2] << std::endl;
    std::cout << "ft_rev_begin[2] : " << ft_rev_begin[2] << std::endl;
    std::cout << std::endl;

    std::cout << "------------- operator-() -------------"<< std::endl;
    std::cout << "*std_rev_begin : " << *std_rev_begin << std::endl;
    std::cout << "*std_rev_end : " << *std_rev_end << std::endl;
    std::cout << "*ft_rev_begin : " << *ft_rev_begin << std::endl;
    std::cout << "*ft_rev_end : " << *ft_rev_end << std::endl;
    std::cout << "(std_rev_end - std_rev_begin) has " << (std_rev_end - std_rev_begin) << " elements.\n";
    std::cout << "(ft_rev_end - ft_rev_begin)  has " << (ft_rev_end - ft_rev_begin) << " elements.\n";
    std::cout << std::endl;

    std::cout << "------------- operator+() -------------"<< std::endl;
    std::cout << "*(std_rev_begin + 3) has " << *(std_rev_begin + 3) << " elements.\n";
    std::cout << "*(ft_rev_begin + 3) has " << *(ft_rev_begin + 3) << " elements.\n";
    std::cout << std::endl;


    // std::cout << "------------- operator->() -------------"<< std::endl;
    // std::cout << "std_rev_begin-> : " << std_rev_begin->() << std::endl;
    // std::cout << "*ft_rev_begin : " << *ft_rev_begin << std::endl;
    // std::cout << std::endl;

    std_print(std_rev_end, std_rev_begin);
    ft_print(ft_rev_end, ft_rev_begin);

    return 0;
}
