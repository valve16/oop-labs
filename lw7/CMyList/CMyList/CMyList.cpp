#ifndef CMYLIST_IMPL
#define CMYLIST_IMPL
#include "CMyList.h"
#include <iostream>
#include <stdexcept>
#include <iterator>
#include <utility>

template<typename T>
CMyList<T>::CMyList()
	: m_head(nullptr)
	, m_tail(nullptr)
	, m_size(0)
{
};

template<typename T>
CMyList<T>::CMyList(const CMyList& list) 
	: m_head(nullptr)
	, m_tail(nullptr)
	, m_size(0)
{
	try {
		CopyFrom(list);
	}
	catch (...) {
		Clear();
		throw;
	}
};

template<typename T>
CMyList<T>::CMyList(CMyList&& list) noexcept
	: m_head(list.m_head)
	, m_tail(list.m_tail)
	, m_size(list.m_size)
{
	list.m_head = nullptr;
	list.m_tail = nullptr;
	list.m_size = 0;

}

template<typename T>
CMyList<T>& CMyList<T>::operator=(const CMyList& list)
{
	if (this != &list) {
		CMyList temp(list);
		std::swap(m_head, temp.m_head);
		std::swap(m_tail, temp.m_tail);
		std::swap(m_size, temp.m_size);
	}
	return *this;
}

template<typename T>
CMyList<T>& CMyList<T>::operator=(CMyList&& list) noexcept
{
	if (this != &list)
	{
		Clear();
		m_head = list.m_head;
		m_tail = list.m_tail;
		m_size = list.m_size;
		list.m_head = nullptr;
		list.m_tail = nullptr;
		list.m_size = 0;
	}
	return *this;
}

template<typename T>
CMyList<T>::~CMyList() noexcept
{
	Clear();
}

template<typename T>
void CMyList<T>::push_front(const T& value)
{
	Node* newNode = new Node(value);
	newNode->next = m_head;
	if (m_head)
	{
		m_head->prev = newNode;
	}
	else
	{
		m_tail = newNode;
	}
	m_head = newNode;
	++m_size;
}

template<typename T>
void CMyList<T>::push_front(T&& value)
{
	Node* newNode = new Node(std::move(value));
	newNode->next = m_head;
	if (m_head)
	{
		m_head->prev = newNode;
	}
	else
	{
		m_tail = newNode;
	}
	m_head = newNode;
	++m_size;
}

template<typename T>
void CMyList<T>::push_back(const T& value)
{
	Node* newNode = new Node(value);
	newNode->prev = m_tail;
	if (m_tail)
	{
		m_tail->next = newNode;
	}
	else
	{
		m_head = newNode;
	}
	m_tail = newNode;
	++m_size;
}

template<typename T>
void CMyList<T>::push_back(T&& value)
{
	Node* newNode = new Node(std::move(value));
	newNode->prev = m_tail;
	if (m_tail)
	{
		m_tail->next = newNode;
	}
	else
	{
		m_head = newNode;
	}
	m_tail = newNode;
	++m_size;
}

template<typename T>
size_t CMyList<T>::GetSize() const noexcept
{
	return m_size;
}

template<typename T>
void CMyList<T>::Clear() noexcept
{
	while (m_head)
	{
		Node* tmp = m_head;
		m_head = m_head->next;
		delete tmp;
	}
	m_tail = nullptr;
	m_size = 0;
}

template<typename T>
void CMyList<T>::CopyFrom(const CMyList& list)
{
	for (Node* cur = list.m_head; cur != nullptr; cur = cur->next)
	{
		push_back(cur->data);
	}
}

// Iterator methods
template<typename T>
CMyList<T>::CIt::CIt(Node* node) 
	: m_current(node)
{
}

template<typename T>
typename CMyList<T>::CIt::reference  CMyList<T>::CIt::operator*() const
{
	return m_current->data;
}

template<typename T>
typename CMyList<T>::CIt::pointer CMyList<T>::CIt::operator->()
{
	return &(m_current->data);
}

template<typename T>
typename CMyList<T>::CIt& CMyList<T>::CIt::operator++()
{
	m_current = m_current->next;
	return *this;
}

template<typename T>
typename CMyList<T>::CIt CMyList<T>::CIt::operator++(int)
{
	CIt tmp = *this;
	m_current = m_current->next;
	return tmp;
}

template<typename T>
typename CMyList<T>::CIt& CMyList<T>::CIt::operator--()
{
	m_current = m_current->prev;
	return *this;
}

template<typename T>
typename CMyList<T>::CIt CMyList<T>::CIt::operator--(int)
{
	CIt tmp = *this;
	m_current = m_current->prev;
	return tmp;
}

template<typename T>
typename CMyList<T>::CIt CMyList<T>::begin()
{
	return CIt(m_head);
}

template<typename T>
typename CMyList<T>::CIt CMyList<T>::end()
{
	return CIt(nullptr);
}

// CRevIt methods
template<typename T>
CMyList<T>::CRevIt::CRevIt(Node* node)
	: m_current(node)
{
}

template<typename T>
typename CMyList<T>::CRevIt::reference  CMyList<T>::CRevIt::operator*() const
{
	return m_current->data;
}

template<typename T>
typename CMyList<T>::CRevIt::pointer CMyList<T>::CRevIt::operator->()
{
	return &(m_current->data);
}

template<typename T>
typename CMyList<T>::CRevIt& CMyList<T>::CRevIt::operator++()
{
	m_current = m_current->prev;
	return *this;
}

template<typename T>
typename CMyList<T>::CRevIt  CMyList<T>::CRevIt::operator++(int)
{
	CRevIt tmp = *this;
	m_current = m_current->prev;
	return tmp;
}

template<typename T>
typename CMyList<T>::CRevIt& CMyList<T>::CRevIt::operator--()
{
	m_current = m_current->next;
	return *this;
}

template<typename T>
typename CMyList<T>::CRevIt CMyList<T>::CRevIt::operator--(int)
{
	CRevIt tmp = *this;
	m_current = m_current->next;
	return tmp;
}

template<typename T>
typename CMyList<T>::CRevIt CMyList<T>::rbegin()
{
	return CRevIt(m_tail);
}

template<typename T>
typename CMyList<T>::CRevIt CMyList<T>::rend()
{
	return CRevIt(nullptr);
}

template<typename T>
typename CMyList<T>::CIt CMyList<T>::insert(CIt pos, const T& value)
{
	Node* posNode = pos.getNode();
	Node* newNode = new Node(value);

	if (!posNode)
	{
		push_back(value);
		return CIt(m_tail);
	}

	newNode->next = posNode;
	newNode->prev = posNode->prev;

	if (posNode->prev)
	{
		posNode->prev->next = newNode;
	}
	else
	{
		m_head = newNode;
	}

	posNode->prev = newNode;

	++m_size;
	return CIt(newNode);
}

template<typename T>
typename CMyList<T>::CIt CMyList<T>::insert(CIt pos, T&& value)
{
	Node* posNode = pos.getNode();
	Node* newNode = new Node(std::move(value));
	newNode->next = posNode;
	if (posNode)
	{
		newNode->prev = posNode->prev;
		if (posNode->prev)
		{
			posNode->prev->next = newNode;
		}
		else
		{
			m_head = newNode;
		}
		posNode->prev = newNode;
	}
	else
	{
		newNode->prev = m_tail;
		if (m_tail)
		{
			m_tail->next = newNode;
		}
		else
		{
			m_head = newNode;
		}
		m_tail = newNode;
	}
	++m_size;
	return CIt(newNode);
}

template<typename T>
typename CMyList<T>::CIt CMyList<T>::erase(CIt pos)
{
	Node* posNode = pos.getNode();
	if (!posNode)
	{
		throw std::out_of_range("Invalid iterator position");
	}

	if (posNode->prev)
	{
		posNode->prev->next = posNode->next;
	}
	else
	{
		m_head = posNode->next;
	}

	if (posNode->next)
	{
		posNode->next->prev = posNode->prev;
	}
	else
	{
		m_tail = posNode->prev;
	}

	CIt next(posNode->next);
	delete posNode;
	--m_size;
	return next;
}

#endif 
