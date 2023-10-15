#include <iostream>
#include <iterator> // for iterators
#include <vector> // for vectors

using namespace std;

int main()
{
    vector<int> ar = { 1,2,3,4,5 };
    // Declaring iterator to a vector
    vector<int>::iterator ptr;

    // Displaying vector elments using begin() and end()
    cout << "The vector elements are : ";
    for (ptr = ar.begin(); ptr < ar.end(); ptr++)
        cout << *ptr << " ";
    cout << endl;
    return 0;
}