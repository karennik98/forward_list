#pragma once
#include <cassert>
#include <iterator>

template <typename TValue>
class List
{
private:
	template<typename TValue>
	class Node
	{
	public:
		Node(const TValue& value = TValue(), Node<TValue>* next = nullptr) : m_next(next), m_value(value) {}
		Node<TValue>* m_next = nullptr;
		TValue m_value;
	};
public:
	using value_type = Node<TValue>;
	using pointer_type = Node<TValue>*;
	using reference_type = Node<TValue>&;
public:
	using base_iterator  = std::iterator<std::forward_iterator_tag, value_type>;
	class Iterator : public base_iterator
	{
	public:
		Iterator() :m_node_ptr(nullptr) {}
		explicit Iterator(pointer_type) : m_node_ptr(ptr) {}
		Iterator& operator=(const Iterator& other);
		Iterator& operator++();
		Iterator operator++(int);
		bool operator==(Iterator other)const;
		bool operator!=(Iterator other)const;
		TValue& operator*()const;
	private:
		friend class List<TValue>;
		value_type* m_node_ptr;
	};
public:
	virtual bool empty()const;
	virtual size_t size()const;
	virtual void insert(const TValue& data, Iterator pos);
	virtual void push_back(const TValue&);
	virtual void push_front(const TValue&);
	virtual void pop_front();
	virtual void erase(Iterator);
	Iterator begin();
	Iterator end();
private:
	size_t m_size;
	pointer_type m_head;
	pointer_type m_tail;
};

#include "forward_list_impl.hpp"