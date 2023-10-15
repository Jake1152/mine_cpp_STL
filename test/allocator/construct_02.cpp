#include <iostream>
#include <memory>

struct A {
  int size;
  int* arr;

  A(void) : size(0), arr(NULL) {}

  A(int size) : size(size), arr(new int[size]) {}

  A(const A& other) : size(other.size), arr(new int[size]) {
    for (int i = 0; i < size; ++i)
      this->arr[i] = other.arr[i];
  }

  A& operator=(const A& other) {
    if (this->size < other.size) {
      delete[] this->arr;
      this->arr = new int[other.size];
    }
    this->size = other.size;
    for (int i = 0; i < size; ++i)
      this->arr[i] = other.arr[i];
    return (*this);
  }

  ~A(void) { delete[] this->arr; }
};

int
main(void) {
  A a(10);

  for (int i = 0; i < 10; ++i)
    a.arr[i] = i * i;

  std::allocator<A> alloc;
  A* ptr = alloc.allocate(1);

//   *ptr = a;

  alloc.construct(ptr, a);

  for (int i = 0; i < 10; ++i)
    std::cout << ptr->arr[i] << " ";
  std::cout << std::endl;

  // alloc.destroy(ptr);

  alloc.deallocate(ptr, 1);
  return (0);
}