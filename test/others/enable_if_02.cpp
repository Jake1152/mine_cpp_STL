// typedef typename is_integral<_InputIterator>::type _Integral;
// _M_assign_dispatch(__first, __last, _Integral());


// template<class _InputIterator>
// void assign(_InputIterator __first, _InputIterator __last) {
//   typedef typename is_integral<_InputIterator>::type _Integral;
//   _M_assign_dispatch(__first, __last, _Integral());
// }


// template<class _InputIterator>
// void assign(_InputIterator __first, _InputIterator __last) {
//   _M_assign_dispatch(__first, __last, false_type());
// }


// enable_if example: two ways of using enable_if
#include <iostream>
#include <type_traits>
#include <string>

// 1. the return type (bool) is only valid if T is an integral type:
template <class T>
// typename std::enable_if<std::is_integral<T>::value, char>::type  is_odd (T i)          => i is odd: 
// typename std::enable_if<std::is_integral<T>::value, int>::type  is_odd (T i)           => i is odd: 1
// typename std::enable_if<std::is_integral<T>::value, float>::type  is_odd (T i)         => i is odd: 1
// typename std::enable_if<std::is_integral<T>::value, std::string>::type  is_odd (T i)   => i is odd: 1
typename std::enable_if<std::is_integral<T>::value, bool>::type  is_odd (T i)           //=> i is odd: true
{
  return float(3.14);
}

// 2. the second template argument is only valid if T is an integral type:
template < class T,
           class = typename std::enable_if<std::is_integral<T>::value>::type>
bool is_even (T i) {return !bool(i%2);}

int main() {

  short int i = 1;    // code does not compile if type of i is not integral

  std::cout << std::boolalpha;
  std::cout << "i is odd: " << is_odd(i) << std::endl;
  std::cout << "i is even: " << is_even(i) << std::endl;

  return 0;
}


