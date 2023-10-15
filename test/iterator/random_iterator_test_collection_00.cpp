#include <iostream>
#include <iterator>
#include <vector>
#include "../../include/iterator.hpp"

typedef std::vector<int>::iterator iter_type;

template<typename T>
void    std_print(const typename std::vector<T>::iterator& random_iter_begin, const typename std::vector<T>::iterator& random_iter_end)
{
    std::cout << "std myvector:";
    for (typename std::vector<T>::iterator it = random_iter_begin.base(); it != random_iter_end.base(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

template<typename T>
void    ft_print(const typename ft::random_access_iterator<T>& rev_end, const typename ft::random_access_iterator<T>& rev_begin)
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

    iter_type                                std_default_random_access_iterator;
    ft::random_access_iterator<iter_type>    ft_default_random_access_iterator;

    // std_default_random_access_iterator = myvector.rbegin() + 3;
    // ft_default_random_access_iterator = myvector.rbegin() + 3;
    // std::cout << "*std_default_random_access_iterator : " << *std_default_random_access_iterator << std::endl;
    // std::cout << "*ft_default_random_access_iterator : " << *ft_default_random_access_iterator << std::endl;

    iter_type   std_begin (myvector.begin());
    iter_type   std_end (myvector.end());

    ft::random_access_iterator<iter_type> ft_begin (myvector.begin());
    ft::random_access_iterator<iter_type> ft_end (myvector.end());

    std::cout << "------------- base() -------------"<< std::endl;
    std::cout << "*(std_begin.base()) : " << *(std_begin.base()) << std::endl;
    std::cout << "*(std_end.base()) : " << *(std_end.base()) << std::endl;
    std::cout << "*(ft_begin.base()) : " << *(ft_begin.base()) << std::endl;
    std::cout << "*(ft_begin.base()) : " << *(ft_end.base()) << std::endl;
    std::cout << std::endl;

    std::cout << "------------- operator*() -------------"<< std::endl;
    std::cout << "*std_begin : " << *std_begin << std::endl;
    std::cout << "*std_end : " << *std_end << std::endl;
    std::cout << "*ft_begin : " << *ft_begin << std::endl;
    std::cout << "*ft_end : " << *ft_end << std::endl;
    std::cout << std::endl;

    std::cout << "------------- operator+() -------------"<< std::endl;
    std::cout << "*std_begin+(1) : " << *(std_begin+(1)) << std::endl;
    std::cout << "*ft_begin+(1) : " << *(ft_begin+(1)) << std::endl;
    std::cout << std::endl;

    std::cout << "------------- operator++() -------------"<< std::endl;
    std::cout << "*++std_begin : " << *(++std_begin) << std::endl;
    std::cout << "*++ft_begin : " << *(++ft_begin) << std::endl;
    std::cout << "*std_begin : " << *std_begin << std::endl;
    std::cout << "*ft_begin : " << *ft_begin << std::endl;
    std::cout << std::endl;

    std::cout << "------------- operator++(int) -------------"<< std::endl;
    std::cout << "*std_begin++ : " << *(std_begin++) << std::endl;
    std::cout << "*ft_begin++ : " << *(ft_begin++) << std::endl;
    std::cout << "*std_begin : " << *std_begin << std::endl;
    std::cout << "*ft_begin : " << *ft_begin << std::endl;
    std::cout << std::endl;

    std::cout << "------------- operator+=() -------------"<< std::endl;
    std::cout << "*std_begin+=(1) : " << *(std_begin+=(1)) << std::endl;
    std::cout << "*ft_begin+=(1) : " << *(ft_begin+=(1)) << std::endl;
    std::cout << "*std_begin : " << *std_begin << std::endl;
    std::cout << "*ft_begin : " << *ft_begin << std::endl;
    std::cout << std::endl;

    std::cout << "------------- operator-() -------------"<< std::endl;
    std::cout << "*std_begin-(1) : " << *(std_begin-(1)) << std::endl;
    std::cout << "*ft_begin-(1) : " << *(ft_begin-(1)) << std::endl;
    std::cout << "*std_begin : " << *std_begin << std::endl;
    std::cout << "*ft_begin : " << *ft_begin << std::endl;
    std::cout << std::endl;

    std::cout << "------------- operator--() -------------"<< std::endl;
    std::cout << "*--std_begin : " << *(--std_begin) << std::endl;
    std::cout << "*--ft_begin : " << *(--ft_begin) << std::endl;
    std::cout << "*std_begin : " << *std_begin << std::endl;
    std::cout << "*ft_begin : " << *ft_begin << std::endl;
    std::cout << std::endl;

    std::cout << "------------- operator--(int) -------------"<< std::endl;
    std::cout << "*std_begin-- : " << *(std_begin--) << std::endl;
    std::cout << "*ft_begin-- : " << *(ft_begin--) << std::endl;
    std::cout << "*std_begin : " << *std_begin << std::endl;
    std::cout << "*ft_begin : " << *ft_begin << std::endl;
    std::cout << std::endl;

    std::cout << "------------- operator-=() -------------"<< std::endl;
    std::cout << "*std_begin-=(1) : " << *(std_begin-=(1)) << std::endl;
    std::cout << "*ft_begin-=(1) : " << *(ft_begin-=(1)) << std::endl;
    std::cout << "*std_begin : " << *std_begin << std::endl;
    std::cout << "*ft_begin : " << *ft_begin << std::endl;
    std::cout << std::endl;

    std::cout << "------------- operator[]() -------------"<< std::endl;
    std::cout << "std_begin[0] : " << std_begin[0] << std::endl;
    std::cout << "ft_begin[0] : " << ft_begin[0] << std::endl;
    std::cout << "std_begin[1] : " << std_begin[1] << std::endl;
    std::cout << "ft_begin[1] : " << ft_begin[1] << std::endl;
    std::cout << "std_begin[2] : " << std_begin[2] << std::endl;
    std::cout << "ft_begin[2] : " << ft_begin[2] << std::endl;
    std::cout << std::endl;

    std::cout << "------------- operator-() -------------"<< std::endl;
    std::cout << "*std_begin : " << *std_begin << std::endl;
    std::cout << "*std_end : " << *std_end << std::endl;
    std::cout << "*ft_begin : " << *ft_begin << std::endl;
    std::cout << "*ft_end : " << *ft_end << std::endl;
    std::cout << "(std_end - std_begin) has " << (std_end - std_begin) << " elements.\n";
    std::cout << "(ft_end - ft_begin)  has " << (ft_end - ft_begin) << " elements.\n";
    std::cout << std::endl;

    std::cout << "------------- operator+() -------------"<< std::endl;
    std::cout << "*(std_begin + 3) has " << *(std_begin + 3) << " elements.\n";
    std::cout << "*(ft_begin + 3) has " << *(ft_begin + 3) << " elements.\n";
    std::cout << std::endl;


    // std::cout << "------------- operator->() -------------"<< std::endl;
    // std::cout << "std_begin-> : " << std_begin->() << std::endl;
    // std::cout << "*ft_begin : " << *ft_begin << std::endl;
    // std::cout << std::endl;

    // std_print(std_begin, std_end);
    std::cout << "std myvector:";
    for (typename std::vector<int>::iterator it = std_begin; it != std_end; ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    ft_print(ft_begin, ft_end);

    return 0;
}
