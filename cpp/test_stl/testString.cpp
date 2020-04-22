/*
 * testString.cpp
 *
 *  test code of string
 */

#include <iostream>

#include "testGlobal.h"
#include "testString.h"


// test string api
int test_string()
{
    std::cout << ">>>>test string now: " << endl;

    string src("TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT");

    for (int i = 0; i< 1000000; i++)
    {
        src = src.substr();
    }

    std::cout << "test string end. " << endl;
    return 0;
}

