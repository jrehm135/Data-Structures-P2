#ifndef _LINKED_STACK_H_
#define _LINKED_STACK_H_

#include "abstract_stack.h"
#include <iostream>
#include <string>
#include <utility>
#include <stdexcept>

template <typename T>
class LinkedStack: public AbstractStack<T>
{
public:

	// Constructor
	LinkedStack();

	// Destructor
	~LinkedStack();

	// copy constructor
	LinkedStack(const LinkedStack & x);

	// copy assignment
	LinkedStack& operator=(LinkedStack x);

	//for copy-swap idiom
	void swap(LinkedStack<T>& x, LinkedStack<T>& y);

	// pushes an item into the stack
	void push(const T& item);

	// pop (remove) the top item from the stack
	void pop();

	// return item at the top of the stack
	const T& top();

	// returns true if the stack is empty
	bool isempty();
private:
	template<typename U>
	struct Node {
		U data;
		Node<U> * next;
		Node<U> * prev;

		Node() : next(nullptr), prev(nullptr) {};
		Node(const U& d) : data(d), next(nullptr), prev(nullptr) {};
	};

	Node<T> * head;
	std::size_t size;
};
#include "linked_stack.txx"
#endif // _LINKED_STACK_H_