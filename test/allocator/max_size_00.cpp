#include <iostream>
#include <memory>
#include <vector>
#include <deque>
#include <set>

int main()
{
    int n;
    std::allocator<int> alloc;
    std::set<int> vec_int;
    // std::vector<int> vec_int;
    int *ptr;
    
    // n = 42;
    // ptr = (int *)alloc.allocate(n);
    // for (int i = 0; i < n; i++)
    //     alloc.construct(ptr + i, i);
    // vec_int.push_back(42);
    // vec_int.push_back(22);
    // for (auto iter = vec_int.begin(); iter != vec_int.end(); iter++)
    //     std::cout << *iter << std::endl;
    std::cout << "vec_int.max_size() : " << vec_int.max_size() << std::endl;
    // for (int i = 0; i < n; i++)
    // {
    //     std::cout << "*(ptr + i) : " << *(ptr + i) << " |||\t";
    //     std::cout << "alloc.address(*(ptr + i)) : " << alloc.address(*(ptr + i)) << std::endl;
    // }
    alloc.destroy(ptr);
    alloc.deallocate(ptr, n);
    return (0);
}