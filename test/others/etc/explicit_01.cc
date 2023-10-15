#include <iostream>

class A
{
public:
	int num;
	explicit	A(int n): num(n) {};
};

void printA(A a)
{
	std::cout << a.num << std::endl;
}

int main()
{
	int n = 26;
	printA(n); // 동작하게됨
}