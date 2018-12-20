#pragma once
template< class KEY, class ARG_KEY, class VALUE, class ARG_VALUE >//key只能是int
class HashMap
{
	struct SNode
	{
		KEY key;
		VALUE value;
		SNode* pNext;
	};
	SNode* *m_pData;
	int m_nHashSize;
public:
	HashMap(int nHashSize = 17):m_nHashSize(nHashSize)
	{
		int newSize = m_nHashSize + 1;
		m_pData = new SNode*[newSize];
		memset(m_pData, 0, newSize*sizeof(SNode*));
	}
	 ~HashMap()
	{
		RemoveAll();
		delete[]m_pData;
	}
	void SetAt(ARG_KEY key, ARG_VALUE value)
	{
		(*this)[key] = value;
	}
	bool Lookup(ARG_KEY key, VALUE& rValue) const;
	VALUE& operator[](ARG_KEY key);
	bool RemoveKey(ARG_KEY key);
	void RemoveAll();
};

template<class KEY, class ARG_KEY, class VALUE, class ARG_VALUE>
bool HashMap<KEY, ARG_KEY, VALUE, ARG_VALUE>::Lookup(ARG_KEY key, VALUE & rValue) const
{
	SNode* pList = m_pData[key%m_nHashSize];
	while (pList)
	{
		if (pList->key == key)
		{
			rValue = pList->value;
			return true;
		}
		pList = pList->pNext;
	}
	return false;
}

template<class KEY, class ARG_KEY, class VALUE, class ARG_VALUE>
VALUE & HashMap<KEY, ARG_KEY, VALUE, ARG_VALUE>::operator[](ARG_KEY key)
{
	SNode* *p = &m_pData[key%m_nHashSize];
	while (*p)
	{
		if ((*p)->key == key)
			return (*p)->value;
		p = &(*p)->pNext;
	}
	SNode *pNew = new SNode;
	pNew->key = key;
	pNew->value = VALUE();
	pNew->pNext = 0;
	*p = pNew;
	return pNew->value;
}


template<class KEY, class ARG_KEY, class VALUE, class ARG_VALUE>
bool HashMap<KEY, ARG_KEY, VALUE, ARG_VALUE>::RemoveKey(ARG_KEY key)
{
	SNode* *p = &m_pData[key%m_nHashSize];
	while (*p)
	{
		if ((*p)->key == key)
		{
			SNode *q = *p;
			(*p) = (*p)->pNext;
			delete q;
			return true;
		}
		p = &(*p)->pNext;
	}
	return false;
}

template<class KEY, class ARG_KEY, class VALUE, class ARG_VALUE>
void HashMap<KEY, ARG_KEY, VALUE, ARG_VALUE>::RemoveAll()
{
	SNode* *p = m_pData;
	while (*p)
	{
		SNode *q = *p, *t;
		while (q)
		{
			t = q;
			q = q->pNext;
			delete t;
		}
		p++;
	}
}
