// map::insert (C++98)
#include <iostream>
#include <map>
// #include "../../include/utility.hpp"
int main ()
{
  std::map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( std::pair<char,int>('a',100) );
  mymap.insert ( std::pair<char,int>('z',200) );
  mymap.insert ( std::make_pair<char,int>('a',100) );
  std::pair<std::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( std::pair<char,int>('z',500) );
  
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
    std::cout << " ret.first->first " << ret.first->first << '\n';
  }

  // second insert function version (with hint position):
  // iter_ret
  std::map<char,int>::iterator it = mymap.begin();
  std::map<char,int>::iterator ret_it;
  ret_it = mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
  // std::cout << "*ret_it : " << ret_it << std::endl; 
  ret_it = mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
  std::cout << "ret_it : " << ret_it << std::endl;

  // third insert function version (range insertion):
  std::map<char,int> anothermap;
  anothermap.insert(mymap.begin(),mymap.find('c'));

  // showing contents:
  std::cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}