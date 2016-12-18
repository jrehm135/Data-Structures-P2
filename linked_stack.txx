// implement linked_stack methods here

#include "linked_stack.h"

template <typename T>
LinkedStack<T>::LinkedStack() : head(nullptr), size(0)
{}

template <typename T>
LinkedStack<T>::~LinkedStack()
{
	while (head != nullptr) {
		Node<T> * temp = head;
		head = head->next;
		delete temp;
	}
}
template <typename T>
LinkedStack<T>::LinkedStack(const LinkedStack<T> & x) : head(nullptr), size(0)
{
	Node<T> * x_curr = x.head;
	Node<T> * this_prev = nullptr;

	while (x_curr != nullptr) {
		Node<T> * this_curr = new Node<T>(x_curr->data);
		this_curr->prev = this_prev;
		if (this_prev != nullptr) this_prev->next = this_curr;
		else head = this_curr;
		this_prev = this_curr;
		x_curr = x_curr->next;
		size += 1;
	}
}


template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(LinkedStack<T> x)
{
	swap(*this, x);
	return *this;
}

template <typename T>
void LinkedStack<T>::swap(LinkedStack<T>& x, LinkedStack<T>& y)
{
	std::swap(x.head, y.head);
	std::swap(x.size, y.size);
}

template <typename T>
void LinkedStack<T>::push(const T& item)
{
	Node<T> * current = head;
	Node<T> * this_curr = new Node<T>(item);
	//creates a new node for the current values
	this_curr->next = nullptr;
	if (current == nullptr)
	{
		this_curr->prev = nullptr;
		head = this_curr;
	}
	//if the stack has nothing, adds item as the first value

	else {
		while (current->next != nullptr) {
			current = current->next;
		}
		this_curr->prev = current;
		current->next = this_curr;
		//iterates until the top value in the stack then implements a new node
	}

	size += 1;
	//adds 1 thing, so size increases by 1
}

template <typename T>
void LinkedStack<T>::pop()
{
	Node<T> * top = head;

	if (size != 0)
	{
		while (top->next != nullptr) {
			top = top->next;
		}
		//iterates to the top of the stack
		if (top == head)
		{
			head = nullptr;
			size -= 1;
		}
		//if there is only one thing in the stack, empties the stack completely
		else {
			Node<T> * newTop = top->prev;
			newTop->next = nullptr;
			delete top;
			size -= 1;
		}
		//if there are multiple things in the array, deletes the top value and sets the previous value to nullptr
	}
	else throw std::range_error("Nothing in stack!");
	//throws a range error if size = 0
}

template <typename T>
const T& LinkedStack<T>::top()
{
	Node<T> * top = head;

	if (size == 0) {
		throw std::range_error("Nothing in stack");
	}

	while (top->next != nullptr) {
		top = top->next;
	}
	return top->data;
	//iterates to the top value and returns it, unless there is nothing in the stack, in which case, it throws a range error

}

template <typename T>
bool LinkedStack<T>::isempty()
{
	if (size == 0)
		return true;
	else
		return false;
	//checks if the stack is empty
}