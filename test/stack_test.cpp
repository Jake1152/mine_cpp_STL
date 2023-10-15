#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include "stack.hpp"

/*
- check list
모든 기능 테스트
- 생성
    - default
    - copy
- member function
    - empty()
    - size()
    - top()
    - push()
    - pop()
*/

int main()
{
    //Case 1)
    // std::deque<int> mydeque (3,100);          // deque with 3 elements
    // std::vector<int> myvector (2,200);        // vector with 2 elements

    // ft::stack<int> first;                    // empty stack
    // ft::stack<int> second (mydeque);         // stack initialized to copy of deque

    // ft::stack<int,std::vector<int> > third;  // empty stack using vector
    // ft::stack<int,std::vector<int> > fourth (myvector);

    // std::cout << "size of first: " << first.size() << '\n';
    // std::cout << "size of second: " << second.size() << '\n';
    // std::cout << "size of third: " << third.size() << '\n';
    // std::cout << "size of fourth: " << fourth.size() << '\n';
    // std::cout << "------------------" << std::endl;
    
    //Case 2)
    // ft::stack<int>  s1;
    // for(int i = 0; i < 5; i++)
    //     s1.push(i);
    
    // std::cout << "size : " << s1.size() << std::endl;
    // std::cout << "empty : " << s1.empty() << std::endl;

    // while (s1.empty() == false)
    // {
    //     std::cout << s1.top() << std::endl;
    //     s1.pop();
    // }
    // std::cout << "------------------" << std::endl;

    // std::cout << "size : " << s1.size() << std::endl;
    // std::cout << "empty : " << s1.empty() << std::endl;

    //Case 3)
    // std::deque<int>	ctnr;

	// ctnr.push_back(21);
	// ctnr.push_back(42);
	// ctnr.push_back(1337);
	// ctnr.push_back(19);
	// ctnr.push_back(0);
	// ctnr.push_back(183792);

	// std::stack<int>  stck(ctnr);
	// ft::stack<int>	stck2(ctnr);
    
    // Case 4)
    ft::stack<int> A;

	ft::stack<int> B;
	ft::stack<std::string> C;
	A.push(1);
	std::cout << A.size() << std::endl;
	A.push(2);
	A.push(3);
	A.push(4);
	std::cout << A.size() << std::endl;
	std::cout << A.top() << std::endl;
	A.pop();
	std::cout << A.top() << std::endl;

	std::cout << "same? " << (A == B) << std::endl;
	std::cout << "compare? " << (A > B) << std::endl;
	std::cout << "compare? " << (A < B) << std::endl;
	std::cout << "compare? " << (A != B) << std::endl;


    return (0);
}