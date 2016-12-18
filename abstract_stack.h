
#ifndef _ABSTRACT_STACK_H_
#define _ABSTRACT_STACK_H_

template <typename T>
class AbstractStack
{
public:

  // push an item of type T into the stack
  // my throw std::bad_alloc on failure
  virtual void push(const T& item) = 0;

  // pop (remove) the top item from the stack
  virtual void pop() = 0;

  // return item at the top of the stack
  virtual const T& top() = 0;

  // returns true if the stack is empty
  virtual bool isempty() = 0;
};


#endif // _ABSTRACT_STACK_H_