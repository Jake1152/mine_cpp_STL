// pair<const_iterator,const_iterator>
// equal_range (const key_type& k) const;

// pair<iterator,iterator>
// equal_range (const key_type& k);
// map::equal_range
#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
  ret = mymap.equal_range('b');
//   ret = mymap.find('b');
  std::map<char,int>::iterator it;
  it = mymap.find('b');

  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';

  return 0;
}