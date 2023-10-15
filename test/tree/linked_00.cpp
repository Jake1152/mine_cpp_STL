#include <iostream>
#include <list>

int main()
{
    typedef std::list<int>::iterator    iter_type;

    std::list<int>  int_list;

    int_list.push_back(100);
    int_list.push_back(200);
    int_list.push_back(300);
    int_list.push_back(400);
    int_list.push_back(500);
    for (auto iter = int_list.begin(); iter != int_list.end(); iter++)
        std::cout << *iter << " ";
    std::cout << std::endl;
    std::reverse_iterator<iter_type> rev_iter = int_list.rbegin();

    for (auto iter = rev_iter; iter != int_list.rend(); iter++)
        std::cout << *iter << " ";
    std::cout << std::endl;

    std::cout << "*rev_iter+=(1) : " << *(rev_iter++) << std::endl;

    return (0);
}