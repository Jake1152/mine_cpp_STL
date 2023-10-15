// inserting into a vector
#include <iostream>
#include <vector>
#include "../../include/vector.hpp"
// _M_assign_dispatch(_Integer __n, _Integer __val, __true_type)
// void				init_dispatch(Integral count, Integral value, ft::true_type);
int main ()
{
  ft::vector<int> myvector; //(3, 100);
  ft::vector<int>::iterator it;
  myvector.push_back(100);
  myvector.push_back(200);
  myvector.push_back(300);
  myvector.reserve(10);
  it = myvector.begin();
  myvector.insert ( it , 2, 42 );
  std::cout << "myvector.size() : " << myvector.size() << std::endl;
  std::cout << "myvector.capacity() : " << myvector.capacity() << std::endl;

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  ft::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "anothervector contains:";
  for (it=anothervector.begin(); it<anothervector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}