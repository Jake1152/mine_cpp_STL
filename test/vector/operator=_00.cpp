#include <iostream>
#include <vector>
#include <iterator>

template <typename T>
void print_container(const std::vector<T>& c) 
{
    for (T i : c)
        std::cout << i << " ";
    std::cout << '\n';
}

int main()
{
    // # case1
    std::vector<int> vec_int(5, 42);
    print_container(vec_int);

    // template <class InputIterator, class ForwardIterator>
    // ForwardIterator uninitialized_copy ( InputIterator first, InputIterator last, ForwardIterator result );
    std::vector<int> result(5);
    std::vector<int>::iterator last;
    last = std::uninitialized_copy ( vec_int.begin(), vec_int.end(), result.begin() );
    
    std::cout << "last.base() : " << last.base() << std::endl;
    std::cout << "vec_int.end().base() : " << vec_int.end().base() << std::endl;
    std::cout << "result.end().base() : " << result.end().base() << std::endl;
    // std::cout << "result.begin().base() : " << result.begin().base() << std::endl;
    print_container(vec_int);
    print_container(result);


    // std::vector<int> cpy_oper_vec = vec_int;
    // print_container(cpy_oper_vec);
    // std::cout << "vec_int.begin().base() : " << vec_int.begin().base() << std::endl;
    // std::cout << "result.begin().base() : " << result.begin().base() << std::endl;
    // std::cout << vec_int.at(std::vector<int>::const_reference()) << std::endl;
    // std::cout << vec_int[6] << std::endl;
    
    // # case2
    // std::vector<std::string> u = {"1", "2", "3"};
    // std::vector<std::string> v = {"4", "5", "6"};
    // std::vector<int> u = {1,2,3};
    // std::vector<int> v = {4,5,6};
    
    // print_container(u);
    // print_container(v);
    // What happens to the original elements in v?
    // std::uninitialized_copy(u.begin(), u.end(), v.begin());
    // print_container(u);
    // print_container(v);


    return (0);
}