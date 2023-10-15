#include <iostream>
#include <vector>
#include "../../include/vector.hpp"

int main()
{
	ft::vector<long long> vec(5);
	// std::cout << "back() :: " << vec.back() << std::endl;	
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30); 
	vec.push_back(40);

	for (std::vector<long long>::size_type i = 0; i < vec.size(); i++)
		std::cout << "vec " << i + 1 << "'th element :: " << vec[i] << std::endl;

	vec.pop_back();
	// int arr[4] = {10, 20, 30, 40};
	// *(arr + 2) == arr[2] == 30;
	// *(itr + 2) == vec[2] == 30;

	std::cout << "back() :: " << vec.back() << std::endl;	

	std::vector<long long>::iterator itr = vec.begin() + 2;
	std::cout << "3번째 원소 :: " << *itr << std::endl;	
	std::vector<long long>::iterator iter = (vec.begin() + 2);
	*iter = 4242;
	std::cout << "3번째 원소 :: " << *itr << std::endl;

	std::vector<long long>::iterator itr_end = vec.end();
	std::cout << "end() :: " << *itr_end << std::endl;	
	std::cout << "end() address using base() :: " << itr_end.base() << std::endl;
	std::cout << "--end() :: " << *(--itr_end) << std::endl;	
	std::cout << "--end() address using base() :: " << (--itr_end).base() << std::endl;

	for (std::vector<long long>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		std::cout << *itr << std::endl;

	std::cout << "size() : " << vec.size() << std::endl;
	std::cout << "capacitiy() : " << vec.capacity() << std::endl;
	return (0);
}