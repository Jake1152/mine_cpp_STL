// vector::rbegin/rend
#include <iostream>
#include <vector>

int main ()
{
    std::vector<int> myvector;  // 5 default-constructed ints

    int i = 0;
    int alloc_size = 5;

    std::vector<int>::reverse_iterator rit = myvector.rbegin();
    //   for (; rit!= myvector.rend(); ++rit)
    //     *rit = ++i;
    for (int idx = 0; idx < alloc_size; idx++)
        myvector.push_back(idx);
        // std::cout << ' ' << *it; 

    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "myvector reverse:";
    for (std::vector<int>::reverse_iterator it = myvector.rbegin(); it != myvector.rend(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    return 0;
}