#include <iostream>
#include <vector>

int main()
{
    size_t  alloc_size;

    alloc_size = 5;
    std::vector<int> vec_int(alloc_size, 42);

    std::cout << "capacity : " << vec_int.capacity() << std::endl;
    std::cout << "size : " << vec_int.size() << std::endl;
    for (size_t i = 0; i < vec_int.size(); i++)
        std::cout << vec_int.at(i) << " ";
    std::cout << std::endl;
    vec_int.clear();
    std::cout << "=== after clear ===" << std::endl;
    std::cout << "capacity : " << vec_int.capacity() << std::endl;
    std::cout << "size : " << vec_int.size() << std::endl;
    for (size_t i = 0; i < alloc_size; i++)
        std::cout << vec_int[i] << " ";
    std::cout << std::endl;

    vec_int.resize(alloc_size * alloc_size);
    std::cout << "=== after resize ===" << std::endl;
    std::cout << "capacity : " << vec_int.capacity() << std::endl;
    std::cout << "size : " << vec_int.size() << std::endl;
    for (size_t i = 0; i < vec_int.size(); i++)
        std::cout << vec_int[i] << " ";
    std::cout << std::endl;
    return (0);
}