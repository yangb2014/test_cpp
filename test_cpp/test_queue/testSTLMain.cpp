/*
 * testSTLMain.cpp
 *
 *  main
 */

#include <iostream>

#include <execinfo.h>
#include <unistd.h>

#include "testGlobal.h"

#include "testSTL.h"
#include "testSMS.h"
#include "testLeak.h"
#include "testString.h"


// 诊断
int g_debugMemLevel = 0;

// 打印调用栈
void print_stacktrace()
{
    int size = 16;
    void * array[16];
    int stack_num = backtrace(array, size);
    char ** stacktrace = backtrace_symbols(array, stack_num);

    cout << "========================================" << endl;
    cout << "print_stacktrace(): " << endl;
    for (int i = 0; i < stack_num; ++i)
    {
        cout << stacktrace[i] << endl;
    }
    cout << "----------------------------------------" << endl;
    free(stacktrace);
}

// 打印内存使用
int print_memuse()
{
    cout << "========================================" << endl;
    cout << "print_memuse(): " << endl;

    char cCmdLine[128];
    sprintf(cCmdLine, " cat /proc/%d/status &", getpid());
    cout << "process " << cCmdLine << endl;
    system(cCmdLine);

    cout << "----------------------------------------" << endl;
    return 0;
}


// main
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;

    //print_stacktrace();

    // test stl swap
    //test_swap();

    // test sms class
    //test_sms();

    // test mem manage of stl
    //test_frag();

    //test_SMSDeque_leak();
    //test_SMSDeque_frag();

    test_string();

    cout << "test end, bye!" << endl;
    return 0;
}

