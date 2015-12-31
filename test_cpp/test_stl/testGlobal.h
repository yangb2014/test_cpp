/*
 * testGlobal.h
 *
 *  define of Global
 */

#ifndef TEST_GLOBAL_H
#define TEST_GLOBAL_H

using namespace std;

#include "stdio.h"
#include "stdlib.h"
#include "memory.h"

#include <map>


const int NameSize          = 50 ;
const int DateSize          = 18 ; 
const int PhoneSize         = 20 ;     //电话号码长度
const int LinkIDSize        = 20 ;
const int MsgInfoSize       = 257; 
const int StatusIDSize      = 2  ;
const int RecordIDSize      = 18 ;     //记录标识
const int TransSerialID     = 26 ;
const int DeviceCodeSize    = 16 ; 
const int FailedNumberSize  = 4  ; 
const int UssdServiceCodeSize = 5;
const int UssdEncodingSize = 10;
const int UssdResponseSize = 8;


struct MTSMS
{
    void *p;
	char mtRecordID[RecordIDSize];
	char moRecordID[RecordIDSize];
	char phone[PhoneSize];
	char directiveCode[PhoneSize];
	char deviceCode[DeviceCodeSize];
	char linkID[LinkIDSize];
	char sendingDate[DateSize];
	char msgInfo[MsgInfoSize];
	char resultCode[PhoneSize];
	char failedNumber[FailedNumberSize];
	char statusID[StatusIDSize];
	char transSerialID[TransSerialID];
	char sourceTypeId[StatusIDSize];
	char sourceId[NameSize];
	char operatorName[NameSize];
};


void print_stacktrace();
int print_memuse();


#endif

