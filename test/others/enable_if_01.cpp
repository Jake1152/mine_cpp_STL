#include <iostream>
#include <type_traits>
#include "../../include/type_traits.hpp"

template <typename T,
          typename = typename ft::enable_if<ft::is_integral<T>::value>::type>
void test(const T& t) {
  std::cout << "t : " << t << std::endl;
}

int main() {
  test(1);      // int
  test(false);  // bool
  test('c');    // char
}