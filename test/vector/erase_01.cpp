// erasing from vector
#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector;

  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) myvector.push_back(i);

  // erase the 6th element
  std::vector<int>::iterator last;
  last = myvector.erase (myvector.begin()+5);
  std::cout << "*last : "  << *last << std::endl;
  std::cout << "last.base() : "  << last.base() << std::endl;

  // erase the first 3 elements:
  last = myvector.erase (myvector.begin(),myvector.begin()+3);
  std::cout << "*last : "  << *last << std::endl;
  std::cout << "last.base() : "  << last.base() << std::endl;

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  return 0;
}