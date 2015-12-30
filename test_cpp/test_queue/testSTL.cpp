/*
 * testSTL.cpp
 *
 *  test code of stl api
 */

#include <iostream>

#include "testGlobal.h"
#include "testSTL.h"


// test vector swap
int test_vector_swap()
{
    cout << ">>>>test vector swap now: " << endl;

    std::vector<int> foo(3,100);   // three ints with a value of 100
    std::vector<int> bar(5,200);   // five ints with a value of 200
    cout << "before swap: " << endl;
    cout << "size of foo " << foo.size() << endl;
    cout << "size of bar " << bar.size() << endl;

    foo.swap(bar);
    cout << "after swap: " << endl;
    cout << "size of foo " << foo.size() << endl;
    cout << "size of bar " << bar.size() << endl;

    cout << "test vector end! " << endl;
    return 0;
}

// test list swap
int test_list_swap()
{
    cout << ">>>>test list swap now: " << endl;

    std::list<int> foo(3,100);   // three ints with a value of 100
    std::list<int> bar(5,200);  // five ints with a value of 200
    cout << "before swap: " << endl;
    cout << "size of foo " << foo.size() << endl;
    cout << "size of bar " << bar.size() << endl;

    foo.swap(bar);
    cout << "after swap: " << endl;
    cout << "size of foo " << foo.size() << endl;
    cout << "size of bar " << bar.size() << endl;

    cout << "test list end! " << endl;
    return 0;
}

// test queue swap
int test_queue_swap()
{
    cout << ">>>>test queue swap now: " << endl;
    cout << "queue not support swap before c11 " << endl;

    return 0;
}

// test deque swap
int test_deque_swap()
{
    cout << ">>>>test deque swap now: " << endl;

    std::deque<int> foo(3,100);   // three ints with a value of 100
    std::deque<int> bar(5,200);   // five ints with a value of 200
    cout << "before swap: " << endl;
    cout << "size of foo " << foo.size() << endl;
    cout << "size of bar " << bar.size() << endl;

    foo.swap(bar);
    cout << "after swap: " << endl;
    cout << "size of foo " << foo.size() << endl;
    cout << "size of bar " << bar.size() << endl;

    bar.clear();
    cout << "after clear: " << endl;
    cout << "size of bar " << bar.size() << endl;

    {
        std::deque<int>(bar).swap(bar);
        cout << "after swap: " << endl;
        cout << "size of bar " << bar.size() << endl;
    }

    cout << "test deque end! " << endl;
    return 0;
}

// test stl swap
int test_swap()
{
    test_vector_swap();
    test_list_swap();
    test_queue_swap();
    test_deque_swap();

    return 0;
}

// test deque max_size
int test_deque_maxsize()
{
    cout << ">>>>test deque max_size now: " << endl;

    unsigned int i, j;
    std::deque<int> foo(3,100);   // three ints with a value of 100

    i = foo.size();
    j = foo.max_size();
    std::cout << "the size of deque is " << i << endl;
    std::cout << "the max_size of deque is " << j << endl;

    cout << "test deque end! " << endl;
    return 0;
}

// test stl api
int test_stl()
{
    std::cout << ">>>>test stl api now: " << endl;

    return 0;
}

