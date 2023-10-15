#include <iostream>
#include <vector>
#include "../include/vector.hpp"

int _ratio = 10000;

template <typename T>
ft::vector<int> resize_test(ft::vector<T> vector) {
    ft::vector<int> v;
    // vector.assign(9900 * _ratio, 1);
    vector.resize(5000 * _ratio);
    vector.reserve(5000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(7000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(15300 * _ratio, T());
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    v.push_back(vector[65]);;
    return v;
}

int main(void)
{
	ft::vector<int> v;
	ft::vector<int> ret = resize_test(v);
	std::cout << ret[0] << std::endl;
	std::cout << ret[1] << std::endl;
	std::cout << ret[2] << std::endl;
	std::cout << ret[3] << std::endl;
	std::cout << ret[4] << std::endl;
	std::cout << ret[5] << std::endl;
	std::cout << ret[6] << std::endl;
	return (0);
}