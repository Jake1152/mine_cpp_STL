// operator- on reverse_iterator
#include <iostream>     // std::cout
#include <iterator>     // std::reverse_iterator
#include <vector>       // std::vector
#include "../../include/iterator.hpp"       // std::vector

int main () {
  std::vector<int> myvector;
  for (int i=0; i<10; i++) myvector.push_back(i);

  ft::reverse_iterator<std::vector<int>::iterator> from,until;

  from = myvector.rbegin();
  until = myvector.rend();

  std::cout << "myvector has " << (until-from) << " elements.\n";

  return 0;
}