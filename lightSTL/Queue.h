#pragma once
template<typename DATA>
class Queue
{
	unsigned m_nSize;
	unsigned m_nTail;
	unsigned m_nHead;
	DATA *m_pData;
public:
	Queue(int nSize = 8):m_nSize(nSize), m_nHead(0), m_nTail(0)
	{
		m_pData = new DATA[m_nSize];
	}
	~Queue()
	{
		delete[]m_pData;
	}
	unsigned GetSize() const
	{
		return m_nSize;
	}
	unsigned GetCount() const
	{
		return m_nTail - m_nHead;
	}
	bool IsEmpty()
	{
		if (m_nTail != m_nHead)
			return false;
		m_nHead = m_nTail = 0;
		return true;
	}
	bool IsFull()
	{
		return  m_nTail - m_nHead == m_nSize;
	}
	void EnQueue(const DATA &data);
	void DeQueue(DATA &data);
};

template<typename DATA>
void Queue<DATA>::EnQueue(const DATA &data)
{
	if (IsFull())
		return;
	m_pData[m_nTail%m_nSize] = data;
	m_nTail++;
}

template<typename DATA>
void Queue<DATA>::DeQueue(DATA &data)
{
	if (IsEmpty())
		return;
	data = m_pData[m_nHead%m_nSize];
	m_nHead++;
}
