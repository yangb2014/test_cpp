/*
 * testLeak.cpp
 *
 *  test code of sms leak
 */

#include <iostream>
#include <string>

#include "testGlobal.h"
#include "testLeak.h"

const std::string sHIGHPRIORITYMTSMS = "HighPriorityMTSMS";
const std::string sLOWERPRIORITYMTSMS = "LowerPriorityMTSMS";

std::map<string,SMSVector<string, MTSMS>*> m_SMSVectorMap;
std::map<string,SMSList<string, MTSMS>*>   m_SMSListMap;
std::map<string,SMSQueue<string, MTSMS>*>  m_SMSQueueMap;
std::map<string,SMSDeque<string, MTSMS>*>  m_SMSDequeMap;


// test SMSDeque leak
int test_SMSDeque_leak()
{
    cout << ">>>>test SMSDeque leak now: " << endl;

    string device("string");
	SMSDeque<std::string, MTSMS>* pHighPriorityMTQueue = new SMSDeque<std::string, MTSMS>;
	SMSDeque<std::string, MTSMS>* pLowerPriorityMTQueue = new SMSDeque<std::string, MTSMS>;
	m_SMSDequeMap.insert(make_pair(sHIGHPRIORITYMTSMS,pHighPriorityMTQueue));
	m_SMSDequeMap.insert(make_pair(sLOWERPRIORITYMTSMS,pLowerPriorityMTQueue));

	MTSMS mtSMS;
    memset(&mtSMS, 0, sizeof(mtSMS));
    // 循环10000次
    //for (int i = 0; i < 10; i++)
    {
        // 先push 1000
        for (int j = 0; j < 100000; j++)
        {
            sprintf(mtSMS.moRecordID, "%d", j);
			m_SMSDequeMap[sHIGHPRIORITYMTSMS]->push(device, mtSMS);
        }
        cout << "push MTSMS end " << endl;

        // 后pop 1000
        for (int j = 0; j < 100000 - 1; j++)
        {
			m_SMSDequeMap[sHIGHPRIORITYMTSMS]->pop(device, mtSMS);
        }
        cout << "pop MTSMS end " << endl;

    }

    // swap
    cout << "before swap size of container is " << m_SMSDequeMap[sHIGHPRIORITYMTSMS]->size(device) << endl;
    m_SMSDequeMap[sHIGHPRIORITYMTSMS]->swap(device);
    cout << "after swap size of container is " << m_SMSDequeMap[sHIGHPRIORITYMTSMS]->size(device) << endl;

    // destory
    cout << "destory now " << endl;
    std::map<string,SMSDeque<string, MTSMS>*>::iterator iter = m_SMSDequeMap.begin();
    for (; iter != m_SMSDequeMap.end(); )
    {
        cout << "destory " << (*iter).first << endl;
        delete (*iter).second;
        (*iter).second = 0;
        m_SMSDequeMap.erase(iter++);
    }

    cout << "test SMSDeque leak end " << endl;
    return 0;
}

// test SMSDeque frag
int test_SMSDeque_frag()
{
    cout << ">>>>test SMSDeque frag now: " << endl;

    string device("string");
	SMSDeque<std::string, MTSMS>* pHighPriorityMTQueue = new SMSDeque<std::string, MTSMS>;
	SMSDeque<std::string, MTSMS>* pLowerPriorityMTQueue = new SMSDeque<std::string, MTSMS>;
	m_SMSDequeMap.insert(make_pair(sHIGHPRIORITYMTSMS,pHighPriorityMTQueue));
	m_SMSDequeMap.insert(make_pair(sLOWERPRIORITYMTSMS,pLowerPriorityMTQueue));

    std::vector<MTSMS*> vec_pointer;

    // 积压短信
    for (int j = 0; j < 100; j++)
    {
		MTSMS* mtSMS = new MTSMS;
        memset(mtSMS, 0, sizeof(MTSMS));
        sprintf(mtSMS->mtRecordID, "%d", 0);
        sprintf(mtSMS->moRecordID, "%d", j);
        mtSMS->p = (void*)mtSMS;
		m_SMSDequeMap[sHIGHPRIORITYMTSMS]->push(device, *mtSMS);
        //cout << "push MTSMS: " << mtSMS->mtRecordID << ", " << mtSMS->moRecordID << ", " << hex << mtSMS->p << endl;
    }
    cout << "push MTSMS end " << 0 << endl;
    cout << "size of container is " << m_SMSDequeMap[sHIGHPRIORITYMTSMS]->size(device) << endl;

    // 循环10000次
    for (int i = 0; i < 10; i++)
    {
        // 先push 1000
        for (int j = 0; j < 10; j++)
        {
    		MTSMS* mtSMS = new MTSMS;
            memset(mtSMS, 0, sizeof(MTSMS));
            sprintf(mtSMS->mtRecordID, "%d", i);
            sprintf(mtSMS->moRecordID, "%d", j);
            mtSMS->p = (void*)mtSMS;
    		m_SMSDequeMap[sHIGHPRIORITYMTSMS]->push(device, *mtSMS);
            //cout << "push MTSMS: " << mtSMS->mtRecordID << ", " << mtSMS->moRecordID << ", " << hex << mtSMS->p << endl;
        }
        //cout << "push MTSMS end " << i << endl;

        // 后pop 1000
        for (int j = 0; j < 10; j++)
        {
			MTSMS sms;
			m_SMSDequeMap[sHIGHPRIORITYMTSMS]->pop(device, sms);
            //cout << "pop MTSMS: " << sms.mtRecordID << ", " << sms.moRecordID << ", " << hex << (long)sms.p << endl;
			//delete (MTSMS*)sms.p;
			vec_pointer.push_back((MTSMS*)sms.p);
			sms.p = (void *)0;
        }
        //cout << "pop MTSMS end " << i << endl;

    }
    cout << "size of container is " << m_SMSDequeMap[sHIGHPRIORITYMTSMS]->size(device) << endl;

    // pop积压短信
    for (int j = 0; j < 100; j++)
    {
		MTSMS sms;
		m_SMSDequeMap[sHIGHPRIORITYMTSMS]->pop(device, sms);
        //cout << "pop MTSMS: " << sms.mtRecordID << ", " << sms.moRecordID << ", " << hex << (long)sms.p << endl;
		//delete (MTSMS*)sms.p;
		vec_pointer.push_back((MTSMS*)sms.p);
		sms.p = (void *)0;
    }
    cout << "pop MTSMS end " << 0 << endl;
    cout << "size of container is " << m_SMSDequeMap[sHIGHPRIORITYMTSMS]->size(device) << endl;

    // swap
    cout << "before swap size of container is " << m_SMSDequeMap[sHIGHPRIORITYMTSMS]->size(device) << endl;
    m_SMSDequeMap[sHIGHPRIORITYMTSMS]->swap(device);
    cout << "after swap size of container is " << m_SMSDequeMap[sHIGHPRIORITYMTSMS]->size(device) << endl;
#if 0
    // free mem
    cout << "size of vec_point is " << vec_pointer.size() << endl;
    std::vector<MTSMS*>::iterator veciter = vec_pointer.begin();
    for (; veciter != vec_pointer.end(); veciter++)
    {
        if (*veciter)
        {
            cout << "delete " << hex << (*veciter) << endl;
            delete (*veciter);
        }
    }
    cout << "before clear, size of vec_point is " << vec_pointer.size() << endl;
    vec_pointer.clear();
    cout << "after clear, size of vec_point is " << vec_pointer.size() << endl;

    // clear
    //cout << "before clear size of container is " << m_SMSDequeMap[sHIGHPRIORITYMTSMS]->size(device) << endl;
    //m_SMSDequeMap[sHIGHPRIORITYMTSMS]->clear(device);
    //cout << "after clear size of container is " << m_SMSDequeMap[sHIGHPRIORITYMTSMS]->size(device) << endl;

    // destory
    cout << "destory now " << endl;
    std::map<string,SMSDeque<string, MTSMS>*>::iterator iter = m_SMSDequeMap.begin();
    for (; iter != m_SMSDequeMap.end(); )
    {
        cout << "destory " << (*iter).first << endl;
        delete (*iter).second;
        (*iter).second = 0;
        m_SMSDequeMap.erase(iter++);
    }
#endif
    cout << "test SMSDeque frag end " << endl;
    return 0;
}

// test sms leak
int test_leak()
{
    return 0;
}

// test malloc frag
int test_frag()
{
    cout << ">>>>test frag now: " << endl;

    void* p[1000];
    
    for (int i = 0; i < 100; i++)
    {
        p[i] = (void*)malloc(128);
        memset(p[i], 'U', 128);
        cout << "malloc size 128, p:" << hex << p[i] << endl;
    }

    free(p[0]);
    p[0] = 0;

    p[0] = (void*)malloc(8);
    cout << "malloc size 8, p:" << hex << p[0] << endl;

    p[100] =  (void*)malloc(128);
    cout << "malloc size 128, p:" << hex << p[100] << endl;


    // free
    for (int i = 0; i < 1000; i++)
    {
        if (p[i] != 0)
        {
            free(p[i]);
        }
    }

    cout << "test frag end " << endl;
    return 0;
}

