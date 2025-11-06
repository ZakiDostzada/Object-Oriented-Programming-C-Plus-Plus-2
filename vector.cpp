//vector.cpp

#include <iostream>
#include <vector>
#include <stdio.h>   // C header for printf (not <cstdio>)

using namespace std;

/**
 * @brief Prints the elements in the vector and their memory locations.
 *
 * @param x Vector of ints to display. (Passed by value, so this prints a copy’s addresses.) 
 */
void printMemVec(vector<int> x)
{
    auto n = x.size();
   // size_t = size(x);
    
    for (size_t i = 0; i < n; ++i)
    {
        cout << "Value: " << x[i] << "\tAt Memory Location: " << &x[i] << '\n';
    }
}

/**
 * @brief Increments all elements in the vector by 10 (in place).
 *
 * @param v Vector of ints to modify. (Passed by reference; the original changes.)
 */
void incVecBy10(vector<int>& v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        v[i] += 10;
    }
}

int main()
{
    const int SIZE = 5;
    vector<int> vec;
    for (int i = 0; i < SIZE; ++i)
    {
        vec.push_back(100 + i);
    }

    printf("Before Increment---------------\n");
    printMemVec(vec);

    incVecBy10(vec);
    printf("After Increment---------------\n");
    printMemVec(vec);

    vec.pop_back();
    printf("After Pop---------------\n");
    printMemVec(vec);

    vec.push_back(101);
    vec.push_back(102);
    printf("After Push---------------\n");
    printMemVec(vec);

    return 0;
}
