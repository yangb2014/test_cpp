/*
 * SMSDeque.h
 *
 *  define of SMSDeque
 */

#ifndef SMS_DEQUE_H
#define SMS_DEQUE_H

#include <deque>
#include <map>

using namespace std;


template <class T1, class T2>
class SMSDeque
{
private:
	//ost::ThreadLock m_MapLock;
	map<T1, deque<T2> > m_Map;

public:
	bool empty(T1& key)
	{
		//m_MapLock.readLock();
		bool bIsEmpty = (m_Map[key]).empty();
		//m_MapLock.unlock();
		return bIsEmpty;
	}

	int push(T1 key, T2& elem)
	{
		//m_MapLock.writeLock();
		(m_Map[key]).push_back(elem);
		//m_MapLock.unlock();
		return 0;
	}

	int pop(T1 key, T2& elem)
	{
		//m_MapLock.writeLock();
		if ((m_Map[key]).empty())
		{
			//m_MapLock.unlock();
			return -1;
		}

		elem = (m_Map[key]).front();
		(m_Map[key]).erase((m_Map[key]).begin());

		//m_MapLock.unlock();

		return 0;
	}

	int any(T2& elem)
	{
		//m_MapLock.writeLock();
		typename map<T1, deque<T2> >::iterator iter = m_Map.begin();
		for(; iter != m_Map.end(); ++iter)
		{
			if (!(iter->second.empty()))
			{
				elem = iter->second.front();
				iter->second.erase(iter->second.begin());
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

	int clear(T1& key)
	{
		//m_MapLock.readLock();
		(m_Map[key]).clear();
		//m_MapLock.unlock();

		return 0;
	}

    int swap(T1& key)
    {
		//m_MapLock.readLock();
        //std::deque<T2> tmp = m_Map[key]; (m_Map[key]).swap(tmp);
        std::deque<T2>(m_Map[key]).swap(m_Map[key]);
		//m_MapLock.unlock();

		return 0;
    }

};


#endif

