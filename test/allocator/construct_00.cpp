#include <iostream>
#include <memory>


int main()
{
	// #1 normal version
    // std::allocator<int> alloc;
    // int *ptr = alloc.allocate(1);

	// alloc.construct(ptr, 42);

	// std::cout << *ptr << std::endl;

	// alloc.destroy(ptr);
	// alloc.deallocate(ptr, 1);

	// #2 1D array
	int n = 42;
	std::allocator<int> alloc;
    int *ptr = alloc.allocate(n);

	for (int i = 0; i < n; i++)
		alloc.construct(ptr + i, i);
	alloc.construct(ptr + 22, 44242);
		// ptr[i] = i  // 역시 동작

	std::cout << *ptr << std::endl;
	for (int i = 0; i < n; i++)
		std::cout << ptr[i] << " ";
	std::cout << std::endl;

	// for (int i = 0; i < n; i++)
	// 	alloc.destroy(ptr + i);
	// alloc.destroy(ptr);
	// alloc.deallocate(ptr, 1);
	alloc.deallocate(ptr, n);
	// alloc.deallocate(ptr, n+1);
	
	// atexit(test);
	return 0;
}