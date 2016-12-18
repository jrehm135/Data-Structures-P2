#ifndef _ARRAY_STACK_H_
#define _ARRAY_STACK_H_

#include "abstract_stack.h"
#include <iostream>
#include <utility>
#include <stdexcept>

template <typename T>
class ArrayStack : public AbstractStack<T>
{
public:

	// Constructor
	ArrayStack();

	// Destructor
	~ArrayStack();

	// copy constructor
	ArrayStack(const ArrayStack & x);

	// copy assignment
	ArrayStack& operator=(ArrayStack x);

	//for copy-swap idiom
	void swap(ArrayStack<T>& x, ArrayStack<T>& y);

	// pushes the item into the stack
	void push(const T& item);

	// pop (remove) the top item from the stack
	void pop();

	// return item at the top of the stack
	const T& top();

	// returns true if the stack is empty
	bool isempty();
private:
	T * items;
	long int maxItems;
	long int itemCount;
};
#include "array_stack.txx"
#endif // _ARRAY_STACK_H_