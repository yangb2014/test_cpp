/*
 * SMSQueue.h
 *
 *  define of SMSQueue
 */

#ifndef SMS_QUEUE_H
#define SMS_QUEUE_H

#include <queue>
#include <map>

using namespace std;


template <class T1, class T2>
class SMSQueue
{
private:
	//ost::ThreadLock m_MapLock;
	map<T1, queue<T2> > m_Map;

public:
	bool empty(T1& key)
	{
		//m_MapLock.readLock();
		bool bIsEmpty = (m_Map[key]).empty();
		//m_MapLock.unlock();
		return bIsEmpty;
	}

	//输入数据
	int push(T1 key, T2& elem)
	{
		//m_MapLock.writeLock();
		(m_Map[key]).push(elem);
		//m_MapLock.unlock();
		return 0;
	}

	//得到数据
	int pop(T1 key, T2& elem)
	{
		//m_MapLock.writeLock();
		if ((m_Map[key]).empty())
		{
			//m_MapLock.unlock();
			return -1;
		}

		elem = (m_Map[key]).front();
		(m_Map[key]).pop();

		//m_MapLock.unlock();

		return 0;
	}

	int any(T2& elem)
	{
		//m_MapLock.writeLock();
		typename map<T1, queue<T2> >::iterator iter = m_Map.begin();
		for(; iter != m_Map.end(); ++iter)
		{
			if (!(iter->second.empty()))
			{
				elem = iter->second.front();
				iter->second.pop();
				break;
			}
		}
		if(iter == m_Map.end())
		{
			//m_MapLock.unlock();
			return -1;
		}
		//m_MapLock.unlock();

		return 0;
	}

	int size(T1& key)
	{
		//m_MapLock.readLock();
		int size = (m_Map[key]).size();
		//m_MapLock.unlock();

		return size;
	}
};


#endif

