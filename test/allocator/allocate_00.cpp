#include <iostream>
#include <memory>

int main()
{
	int n = 42;
	// int *ptr = std::allocate<int>(std::allocator<int>(), n);
    std::allocator<int> alloc;
    int *ptr = alloc.allocate(n);

	for (int i = 0; i < n; i++)
        alloc.construct(ptr + i, i);
		// ptr[i] = i;

	for (int i = 0; i < n; i++)
		std::cout << ptr[i] << " ";
	std::cout << std::endl;

    alloc.destroy(ptr); // call destructor
    alloc.deallocate(ptr, n);
	// std::allocator<int>().deallocate(ptr, n);

	return 0;
}