#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() {
        std::cout << "Constructed MyClass object" << std::endl;
    }
    ~MyClass() {
        std::cout << "Destructed MyClass object" << std::endl;
    }
};

int main() {
    std::allocator<MyClass> allocator;
    MyClass* buffer = allocator.allocate(1);

    *buffer = MyClass();  // Normal assignment
    std::cout << "Object assigned\n" << std::endl;

    allocator.destroy(buffer);  // Destructor not called!
    allocator.deallocate(buffer, 1);
	std::cout << "Object is deallocated\n" << std::endl;

    buffer = allocator.allocate(1);
    allocator.construct(buffer);  // Construct using construct()
    std::cout << "Object constructed" << std::endl;

    allocator.destroy(buffer);  // Destructor called!
    allocator.deallocate(buffer, 1);

    return 0;
}
