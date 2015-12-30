/*
 * testMain.cpp
 *
 *  main
 */

#include <iostream>

#include <execinfo.h>
#include <unistd.h>


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


//#define DBG_NEW_OP
#ifdef DBG_NEW_OP
// 重载new
void *operator new(size_t size)
{
    void *p = malloc(size);
    if (g_debugMemLevel >= 1)
        cout << ">>>>>>>> new size," << dec << size << ",p:" << hex << p << endl;
    if (g_debugMemLevel >= 2)
        print_stacktrace();
    return p;
    //return malloc(size);
}
// 重载delete
void operator delete(void *p)
{
    if (g_debugMemLevel >= 1)
        cout << ">>>>>>>> delete, ,p:" << hex << p << endl;
    if (g_debugMemLevel >= 2)
        print_stacktrace();
    free(p);
}
#endif


//#define DBG_NEW_OP2
#ifdef DBG_NEW_OP2  
void * operator new(unsigned int size, const char *file, int line)  
{  
    // 下面两种方法可以达到同样的效果，但下面一种比较好  
    // 因为用下面一种可以保持原有的申请方式一样  
    //void * p = malloc(size);  
    void * p = operator new(size);  
    if (g_debugMemLevel >= 1)
        cout << ">>>>>>>> new " << hex << p << ", size:" << dec << size << ", file:" << file << ", line:" << dec << line << endl;
    if (g_debugMemLevel >= 2)
        print_stacktrace();
    return p;  
}  
void operator delete(void * p)  
{  
    if (g_debugMemLevel >= 1)
        cout << ">>>>>>>> delete p:" << hex << (long)p << endl;
    if (g_debugMemLevel >= 2)
        print_stacktrace();
    free(p);  
}  
void operator delete [] (void * p)  
{  
    if (g_debugMemLevel >= 1)
        cout << ">>>>>>>> delete [] p:" << hex << (long)p << endl;
    if (g_debugMemLevel >= 2)
        print_stacktrace();
    free(p);  
}  
void operator delete(void * p, const char *file, int line)  
{  
    if (g_debugMemLevel >= 1)
        cout << ">>>>>>>> delete p:" << hex << (long)p << ", file:" << file << ", line:" << dec << line << endl;
    if (g_debugMemLevel >= 2)
        print_stacktrace();
    free(p);  
}  
void operator delete [] (void * p, const char *file, int line)  
{  
    if (g_debugMemLevel >= 1)
        cout << ">>>>>>>> delete [] p:" << hex << (long)p << ", file:" << file << ", line:" << dec << line << endl;
    if (g_debugMemLevel >= 2)
        print_stacktrace();
    free(p);  
}  
#define new new(__FILE__, __LINE__)  
#endif


// main
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;


    cout << "test end, bye!" << endl;
    return 0;
}

