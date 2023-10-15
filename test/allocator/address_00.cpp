#include <iostream>
#include <memory>

int main()
{
    int n;
    std::allocator<int> alloc;
    int *ptr;
    
    n = 42;
    ptr = (int *)alloc.allocate(n);
    for (int i = 0; i < n; i++)
        alloc.construct(ptr + i, i);
    
    for (int i = 0; i < n; i++)
    {
        std::cout << "*(ptr + i) : " << *(ptr + i) << " |||\t";
        std::cout << "alloc.address(*(ptr + i)) : " << alloc.address(*(ptr + i)) << std::endl;
    }
    alloc.destroy(ptr);
    alloc.deallocate(ptr, n);
    return (0);
}