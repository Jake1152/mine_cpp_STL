#include <iostream>
#include <type_traits>
#include <string>

template <class InputIterator>
void    assign(InputIterator it1, InputIterator it2, typename std::enable_if<!(std::is_integral<InputIterator>::value), InputIterator>::type * = NULL)
{
    std::cout << "hello!" << std::endl;
}

int main() {
    std::string str("asdfasfd");
    assign<std::string>(str, str, &str);
}