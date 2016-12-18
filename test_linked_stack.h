#include <string>
#include <cxxtest/TestSuite.h>

#include "linked_stack.h"

#include <cstdlib>
#include <stack>

template class LinkedStack<int>;

class LinkedStackTests : public CxxTest::TestSuite
{
public:
   void testTODO( void )
   {
	   LinkedStack<int> c;
	   TS_ASSERT(c.isempty() == true);
	   c.push(5);
	   TS_ASSERT(c.isempty() == false);
	   TS_ASSERT(c.top() == 5);
	   c.pop();
	   TS_ASSERT(c.isempty() == true);
	   c.push(4);
	   c.push(6);
	   TS_ASSERT(c.isempty() == false);
	   TS_ASSERT(c.top() == 6);
	   c.pop();
	   TS_ASSERT(c.top() == 4);
	   c.pop();
	   TS_ASSERT_THROWS(c.pop(), std::range_error);
	   TS_ASSERT_THROWS(c.top(), std::range_error);
	   c.push(2);
	   LinkedStack<int> d(c);
	   TS_ASSERT(d.top() == 2);
	   TS_ASSERT(d.isempty() == false);
	   LinkedStack<int> e;
	   LinkedStack<int> f;
	   e.push(5);
	   f = e;
	   TS_ASSERT(e.top() == 5);
	   TS_ASSERT(f.top() == 5);
	   f.pop();
   }
};
