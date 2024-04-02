/*
	


*/
#include <mutex>	
#include <iostream>


class RWLock
{
public:
	RWLock()
		:m_Readers(0), m_Writers(0), m_Writing(false)
	{}

	// ����
	void acquireReadLock()
	{
		m_Mutex.lock();
		while (m_Writers)
		{
			// wait
			m_Mutex.unlock();
			sleepInvoke();
			m_Mutex.lock();
		}
		++m_Readers;
		m_Mutex.unlock();
	}

	// �ͷŶ���
	void releaseReadLock()
	{
		m_Mutex.lock();
		--m_Readers;
		m_Mutex.unlock();
	}

	// ��ȡд��
	void acquireWriteLock()
	{
		m_Mutex.lock();
		while (m_Readers > 0 || m_Writers > 0)
		{
			m_Mutex.unlock();
			sleepInvoke();
			m_Mutex.lock();
		}
		++m_Writers;
		m_Writing = true;
		m_Mutex.unlock();
	}

	// �ͷ�д��
	void releaseWriteLock()
	{
		m_Mutex.lock();

		m_Writers = 0;
		m_Writing = false;

		m_Mutex.unlock();

	}

private:
	std::mutex m_Mutex;
	int m_Readers;
	int m_Writers;
	bool m_Writing;
};