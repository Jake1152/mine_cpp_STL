#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec_int(5, 42);

    for (int i = 0; i < vec_int.size(); i++)
        std::cout << vec_int.at(i) << " ";

    std::cout << std::endl;
    std::cout << vec_int.at(std::vector<int>::const_reference()) << std::endl;
    // std::cout << vec_int[6] << std::endl;
        
    return (0);
}