// reverse_iterator::operator+= example
#include <iostream>     // std::cout
#include <iterator>     // std::reverse_iterator
#include <vector>       // std::vector
#include "../iterator.hpp"     // std::reverse_iterator

int main () {
  std::vector<int> myvector;
  for (int i=0; i<2; i++)
    myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

  typedef std::vector<int>::iterator iter_type;

  ft::reverse_iterator<iter_type> rev_iterator(myvector.rbegin());

  rev_iterator += 2;

  std::cout << "The third element from the end is: " << *rev_iterator << '\n';

  return 0;
}