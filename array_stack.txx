// implement array_stack methods here

// implement linked_stack methods here

#include "array_stack.h"

template <typename T>
ArrayStack<T>::ArrayStack() : items(nullptr), maxItems(0), itemCount(0)
{}
//Default Constructor

template <typename T>
ArrayStack<T>::~ArrayStack()
{
	if (items != nullptr) delete[] items;
	//Destructor
}
template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T> & x)
{
	itemCount = x.itemCount;
	maxItems = x.maxItems;
	items = maxItems ? new T[maxItems] : nullptr;
	std::copy(x.items, x.items + x.maxItems, items);
	//Copy Constructor
}


template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(ArrayStack<T> x)
{
	swap(*this, x);

	return *this;
}
//swap operator

template <typename T>
void ArrayStack<T>::swap(ArrayStack<T>& x, ArrayStack<T>& y)
{
	std::swap(x.maxItems, y.maxItems);
	std::swap(x.itemCount, y.itemCount);
	std::swap(x.items, y.items);
	//swap function to help copy construcor
}

template <typename T>
void ArrayStack<T>::push(const T& item)
{
	//grow the items array
	if (itemCount == maxItems)
	{
		T * oldItems = items; //get addr of items array
		maxItems = maxItems + 10;
		//Increases max number of values

		items = new T[maxItems]; //doesn't overwrite old array

		for (int i = 0; i < itemCount; i++)
			items[i] = oldItems[i];

		if (oldItems != nullptr)
			delete[] oldItems;
	}

	items[itemCount] = item;
	itemCount += 1;
	//Adds item to the array

}

template <typename T>
void ArrayStack<T>::pop()
{
	//grow the items array
	T * oldItems = items; //get addr of items array
	if (itemCount == 0)
		throw std::range_error("Nothing in stack!");
	//Throws a range error
	else {
		
		items = new T[maxItems-1]; //doesn't overwrite old array

		for (int i = 0; i < maxItems-1; i++)
			items[i] = oldItems[i];

		if (oldItems != nullptr)
			delete[] oldItems;

		--itemCount;
	}
}

template <typename T>
const T& ArrayStack<T>::top()
{
	if (itemCount == 0)
		throw std::range_error("Nothing in stack!");
	else
		return items[itemCount-1];
	//Checks for the top value. If none exists, throws a range error
}

template <typename T>
bool ArrayStack<T>::isempty()
{
	return (itemCount == 0);
	//Checks if the stack is empty
}