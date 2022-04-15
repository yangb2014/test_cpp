/*
 * testLeak.h
 *
 *  define of testLeak
 */

#ifndef TEST_LEAK_H
#define TEST_LEAK_H


#include "SMSVector.h"
#include "SMSList.h"
#include "SMSQueue.h"
#include "SMSDeque.h"


int test_SMSDeque_leak();
int test_SMSDeque_frag();

int test_leak();
int test_frag();


#endif

