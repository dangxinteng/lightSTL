#pragma once
template<typename KEY, typename VALUE>
class CMap
{
	struct SNode
	{
		KEY key;
		VALUE value;
		SNode* pLeft, *pRight;
		SNode(KEY key) :key(key), pLeft(nullptr), pRight(nullptr), value({})
		{
		}

		SNode(KEY key,const VALUE& value) :key(key),value(value) ,pLeft(nullptr), pRight(nullptr)
		{
		}
	};
	SNode *m_pRoot;
	void PostOrder(SNode* p);
public:
	void SetAt(KEY key, const VALUE& value)
	{
		(*this)[key] = value;
	}
	bool Lookup(KEY key, VALUE& rValue) const;
	VALUE& operator[](KEY key);
	bool RemoveKey(KEY key);
	void RemoveAll();
	CMap()
	{
		m_pRoot = nullptr;
	}
	~CMap()
	{
		RemoveAll();
	}
};

template<typename KEY, typename VALUE>
inline void CMap<KEY, VALUE>::PostOrder(SNode * p)
{
	if (p->pLeft)
		PostOrder(p->pLeft);
	if (p->pRight)
		PostOrder(p->pRight);
	delete p;
}

template<typename KEY, typename VALUE>
inline bool CMap<KEY, VALUE>::Lookup(KEY key, VALUE & rValue) const
{
	auto p = m_pRoot;
	while (p)
	{
		if (key == p->key)
		{
			rValue = p->value;
			return true;
		}
		if (key < p->key)
			p = p->pLeft;
		else
			p = p->pRight;
	}
	return false;
}

template<typename KEY, typename VALUE>
inline VALUE & CMap<KEY, VALUE>::operator[](KEY key)
{
	auto p = &m_pRoot;
	while (*p)
	{
		if ((*p)->key == key)
			return (*p)->value;
		if (key < (*p)->key)
			p = &(*p)->pLeft;
		else
			p = &(*p)->pRight;
	}
	(*p) = new SNode(key);
	return (*p)->value;
}

template<typename KEY, typename VALUE>
inline bool CMap<KEY, VALUE>::RemoveKey(KEY key)
{
	SNode* *p = &m_pRoot;
	while (*p)
	{
		if ((*p)->key == key)
			break;
		if (key < (*p)->key)
			p = &(*p)->pLeft;
		else
			p = &(*p)->pRight;
	}
	if (!*p)
		return false;
	auto q = *p;
	if ((*p)->pLeft)
	{
		*p = (*p)->pLeft;
		do
			p = &(*p)->pRight;
		while (*p);
		*p = q->pRight;
	}
	else if ((*p)->pRight)
		*p = (*p)->pRight;
	else
		*p = nullptr;
	delete q;
	return true;
}

template<typename KEY, typename VALUE>
inline void CMap<KEY, VALUE>::RemoveAll()
{
	PostOrder(m_pRoot);
	m_pRoot = nullptr;
}

