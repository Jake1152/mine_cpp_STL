// erasing from map
#include <iostream>
#include <map>
#include "../../include/map.hpp"


// void inorder(const ft::map<char,int>::iterator& cur_node)
// {
//   if (cur_node == NULL)
//     return ;
//   inorder(cur_node->_left);
//   std::cout << cur_node->_value.first << " ";
//   inorder(cur_node->_right);
// }


int main ()
{
  ft::map<char,int> mymap;
  ft::map<char,int>::iterator it;
  ft::map<char,int>::iterator ret_erase_it;

  // insert some values:
  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;
  mymap['A']=42;

  for (auto it = mymap.begin() ; it != mymap.end() ; ++it)
  {
     std::cout << it->first << " " << it->second << '\n';
  }
  std::cout << '\n';
  it = mymap.find ('b');
  std::cout << "it->second : " << it->second << std::endl;
  // for ()
  mymap.erase (it, ++it);    // erasing by range

  // it = mymap.find('b');
  // ret_erase_it = mymap.erase (it);                   // erasing by iterator
  // // std::cout << "ret_erase_it->first : " << ret_erase_it->first << " => " << ret_erase_it->second << '\n';
  // // 삭제 된것을 가리킴, 즉 dangiling
  // size_t ret_erase_val;
  // ret_erase_val = 
  mymap.erase ('A');                  // erasing by key
  // std::cout << "ret_erase_val : " << ret_erase_val << std::endl;
  // std::cout << "ret_erase_it->first : " << ret_erase_it->first << " => " << ret_erase_it->second << '\n';
  // std::cout << "ret_erase_it->first : " << ret_erase_it->first << " => " << ret_erase_it->second << '\n';
  // std::cout << "ret_erase_it->base() : " << ret_erase_it->base() << " => " << ret_erase_it->second << '\n';

  
  // show content:
  // for (it=mymap.begin(); it!=mymap.end(); ++it)
  //   std::cout << it->first << " => " << it->second << '\n';

  return 0;
}