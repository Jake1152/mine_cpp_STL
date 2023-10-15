#include <memory>
#include <iostream>

class dummy {
private:
	int _a;
public:
    dummy() { std::cout<<"ctor"<<std::endl;  }
    // dummy(int a) { std::cout<<"ctor"<<std::endl; this->_a = a; }
    ~dummy() { std::cout<<"dtor"<<std::endl; }
    void show() {
        std::cout << " int : " << _a << std::endl;
    }
};

 

int main(void)
{
    std::allocator<dummy> alloc;
    dummy *p = alloc.allocate(sizeof(dummy));
    ::new ((void*)std::addressof(*p)) dummy();

    //  alloc.construct(p, *p);
    p = dummy();
    p->show();
    alloc.destroy(p);
    alloc.deallocate(p, sizeof(dummy));
    p = NULL;
    // system("leaks a.out");
}