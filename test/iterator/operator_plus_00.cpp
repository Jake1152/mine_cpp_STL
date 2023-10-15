// reverse_iterator::operator+ example
#include <iostream>     // std::cout
#include <iterator>     // std::reverse_iterator
#include <vector>       // std::vector
#include "../../include/vector.hpp"     // std::reverse_iterator
#include "../../include/iterator.hpp"     // std::reverse_iterator

int main () {
  std::vector<int> myvector;
  for (int i=0; i<10; i++)
    myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

    ft::vector<int> ft_myvector;
    for (int i=0; i<10; i++)
        ft_myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

  typedef std::vector<int>::iterator iter_type;

  std::reverse_iterator<iter_type> std_rev_it;
  ft::reverse_iterator<iter_type> ft_rev_it;

  std_rev_it = myvector.rbegin();
//   ft_rev_it = ft_myvector.end() - 4;

  std::cout << "#std The fourth element from the end is: " << *std_rev_it-(3) << '\n';
//   std::cout << "#ft The fourth element from the end is: " << *ft_rev_it << '\n';

  return 0;
}