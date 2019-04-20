#include "forward_list.h"

template<typename TValue>
size_t List<TValue>::size()const {
	return m_size;
}

template<typename TValue>
bool List<TValue>::empty()const {
	return (m_size == 0);
}

template<typename TValue>
void List<TValue>::insert(const TValue& value, Iterator pos) {
	if (pos == begin()) {
		push_front(value);
		return;
	}
	else if (pos == end()) {
		push_back(value);
		return;
	}
	pointer_type newNode = new value_type(value, pos.m_node_ptr->m_next);
	m_size++;
	if (pos.m_node_ptr == m_tail) {
		m_tail = newNode;
	}
	pos.m_node_ptr->m_next = newNode;
}

template<typename TValue>
void List<TValue>::erase(Iterator pos) {
	if (pos == begin()) {
		pop_front();
	}
	else {
		pointer_type tmp = pos.m_node_ptr->m_next;
		pos.m_node_ptr->m_next = pos.m_node_ptr->m_next->m_next;
		if (tmp = m_tail) {
			m_tail = pos.m_node_ptr;
		}
		m_size--;
		delete tmp;
	}
}

template<typename TValue>
typename List<TValue>::Iterator List<TValue>::begin() {
	assert(m_head != nullptr);
	return List<TValue>::Iterator(m_head);
}

template<typename TValue>
typename List<TValue>::Iterator List<TValue>::end() {
	return List<TValue>::Iterator(m_tail + 1);
}

template<typename TValue>
void List<TValue>::push_back(const TValue& value) {
	pointer_type newNode = new value_type(value, nullptr);
	m_tail->m_next = newNode;
	m_tail = newNode;
	m_size++;
}

template<typename TValue>
void List<TValue>::push_front(const TValue& value) {
	pointer_type newNode = new value_type(value, m_head);
	if (m_size == 0)
		m_tail = newNode;
	m_head = newNode;
	m_size++;
}

template<typename TValue>
void List<TValue>::pop_front() {
	pointer_type tmp = m_head;
	m_head = m_head->m_next;
	m_size--;
	delete tmp;
}

////////////////////////////////////////////////////////////////////////

template <typename TValue>
typename List<TValue>::Iterator& List<TValue>::Iterator::operator=(const List<TValue>::Iterator& other) {
	if (this == &other)
		return *this;
	m_node_ptr = other.m_node_ptr;
	return *this;
}
template <typename TValue>
typename List<TValue>::Iterator& List<TValue>::Iterator::operator++() {
	m_node_ptr = m_node_ptr->m_next;
	return this;
}

template <typename TValue>
typename List<TValue>::Iterator List<TValue>::Iterator::operator++(int) {
	List<TValue>::Iterator tmp = *this;
	m_node_ptr = m_node_ptr->m_next;
	return tmp;
}

template <typename TValue>
bool List<TValue>::Iterator::operator==(Iterator other)const {
	return (m_node_ptr->m_value == other.m_node_ptr->m_value);
}
template <typename TValue>
bool List<TValue>::Iterator::operator!=(Iterator other)const {
	return !(*this == other);
}
template <typename TValue>
TValue& List<TValue>::Iterator::operator*()const {
	return m_node_ptr->m_value;
}
