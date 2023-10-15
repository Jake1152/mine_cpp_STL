#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> v;

    v.reserve(2);
    std::cout << v.capacity() << std::endl;
    v.push_back(42);
    v.push_back(234);
    v.push_back(423423);
    v.push_back(234543);
    std::cout << v.capacity() << std::endl;
    v.reserve(42);
    std::cout << v.capacity() << std::endl;
    v.reserve(12);
    std::cout << v.capacity() << std::endl;
    std::cout << "v.max_size() : " << v.max_size() << std::endl;
    // 한번 늘어난 capacity가 줄어드는 것은 불가능

    return (0);
}