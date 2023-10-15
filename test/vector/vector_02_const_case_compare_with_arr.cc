#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int arr[5] = {10, 20, 30, 40, 50};

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator iter = v.begin();
    int* p = arr;
    cout << *iter << ", " << *p << endl; // iter는 p처럼 동작

    vector<int>::const_iterator citer = v.begin();
    const int* cp = arr;
    cout << *citer << ", " << *cp << endl; // citer는 cp처럼 동작
    // cout << *(citer++) << endl; //work

    const vector<int>::iterator iter_const = v.begin();
    int* const p_const = arr; //iter_const는 p_const처럼 동작
    cout << *iter_const << ", " << *p_const << endl;
    cout << *(iter_const++) << endl; // expect error

    // const vector<int>::const_iterator citer_const = v.begin();
    // *citer_const = 42;
    // const int* const cp_const = arr; // citer_const는 cp_const처럼 동작
    // cout << *citer_const << ", " << *cp_const << endl;


    const vector<int>::iterator cend_iter_const = v.end();
    std::cout << "cend_iter_const : " << *(cend_iter_const) << std::endl;
    *cend_iter_const = 42;
    const int* const cp_const = arr; // citer_const는 cp_const처럼 동작
    cout << *cend_iter_const << ", " << *cp_const << endl;

    return 0;
}