/*
 * testSMS.cpp
 *
 *  test code of SMSxxx
 */

#include <iostream>

#include "testGlobal.h"
#include "testSMS.h"


// test SMSVector
int test_SMSVector()
{
    cout << ">>>>test SMSVector now: " << endl;

    const int test_count = 1000000;
    SMSVector<string, MTSMS> foo, bar;
    string device("string");
    MTSMS mtSMS;
    memset(&mtSMS, 0, sizeof(mtSMS));

    // push
    for (int i = 1; i <= test_count; i++)
    {
        sprintf(mtSMS.moRecordID, "%d", i);
        foo.push(device, mtSMS);
    }
    cout << "before pop: " << endl;
    cout << "size of foo[itouch] " << foo.size(device) << endl;
    cout << "size of bar[itouch] " << bar.size(device) << endl;

    // pop
    for (int i = 1; i <= test_count - 1; i++)
    {
        foo.pop(device, mtSMS);
    }
    cout << "after pop: " << endl;
    cout << "size of foo[itouch] " << foo.size(device) << endl;
    cout << "size of bar[itouch] " << bar.size(device) << endl;

    // swap
    foo.swap(device);
    bar.swap(device);
    cout << "after swap: " << endl;
    cout << "size of foo[itouch] " << foo.size(device) << endl;
    cout << "size of bar[itouch] " << bar.size(device) << endl;

    cout << "test SMSVector end! " << endl;
    return 0;
}

// test SMSList
int test_SMSList()
{
    cout << ">>>>test SMSList now: " << endl;

    const int test_count = 1000000;
    SMSList<string, MTSMS> foo, bar;
    string device("string");
    MTSMS mtSMS;
    memset(&mtSMS, 0, sizeof(mtSMS));

    // push
    for (int i = 1; i <= test_count; i++)
    {
        sprintf(mtSMS.moRecordID, "%d", i);
        foo.push(device, mtSMS);
    }
    cout << "before pop: " << endl;
    cout << "size of foo[itouch] " << foo.size(device) << endl;
    cout << "size of bar[itouch] " << bar.size(device) << endl;

    // pop
    for (int i = 1; i <= test_count - 1; i++)
    {
        foo.pop(device, mtSMS);
    }
    cout << "after pop: " << endl;
    cout << "size of foo[itouch] " << foo.size(device) << endl;
    cout << "size of bar[itouch] " << bar.size(device) << endl;

    // swap
    foo.swap(device);
    bar.swap(device);
    cout << "after swap: " << endl;
    cout << "size of foo[itouch] " << foo.size(device) << endl;
    cout << "size of bar[itouch] " << bar.size(device) << endl;

    cout << "test SMSList end! " << endl;
    return 0;
}

// test SMSQueue
int test_SMSQueue()
{
    cout << ">>>>test SMSQueue now: " << endl;

    const int test_count = 1000000;
    SMSQueue<string, MTSMS> foo, bar;
    string device("string");
    MTSMS mtSMS;
    memset(&mtSMS, 0, sizeof(mtSMS));

    // push
    for (int i = 1; i <= test_count; i++)
    {
        sprintf(mtSMS.moRecordID, "%d", i);
        foo.push(device, mtSMS);
    }
    cout << "before pop: " << endl;
    cout << "size of foo[itouch] " << foo.size(device) << endl;
    cout << "size of bar[itouch] " << bar.size(device) << endl;

    // pop
    for (int i = 1; i <= test_count - 1; i++)
    {
        foo.pop(device, mtSMS);
    }
    cout << "after pop: " << endl;
    cout << "size of foo[itouch] " << foo.size(device) << endl;
    cout << "size of bar[itouch] " << bar.size(device) << endl;

    cout << "test SMSQueue end! " << endl;
    return 0;
}

// test SMSDeque
int test_SMSDeque()
{
    cout << ">>>>test SMSDeque now: " << endl;

    const int test_count = 1000000;
    SMSDeque<string, MTSMS> foo, bar;
    string device("string");
    MTSMS mtSMS;
    memset(&mtSMS, 0, sizeof(mtSMS));

    // push
    for (int i = 1; i <= test_count; i++)
    {
        sprintf(mtSMS.moRecordID, "%d", i);
        foo.push(device, mtSMS);
    }
    cout << "before pop: " << endl;
    cout << "size of foo[itouch] " << foo.size(device) << endl;
    cout << "size of bar[itouch] " << bar.size(device) << endl;

    // pop
    for (int i = 1; i <= test_count - 1; i++)
    {
        foo.pop(device, mtSMS);
    }
    cout << "after pop: " << endl;
    cout << "size of foo[itouch] " << foo.size(device) << endl;
    cout << "size of bar[itouch] " << bar.size(device) << endl;

    // swap
    foo.swap(device);
    bar.swap(device);
    cout << "after swap: " << endl;
    cout << "size of foo[itouch] " << foo.size(device) << endl;
    cout << "size of bar[itouch] " << bar.size(device) << endl;

    // clear
    foo.clear(device);
    cout << "after clear: " << endl;
    cout << "size of foo[itouch] " << foo.size(device) << endl;

    cout << "test SMSDeque end! " << endl;
    return 0;
}

// test sms class
int test_sms()
{
    test_SMSVector();
    test_SMSList();
    test_SMSQueue();
    test_SMSDeque();

    return 0;
}


