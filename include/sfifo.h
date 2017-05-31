/*
 * This abstract data type fifo provides a FIFO queue data structure with a 2 stack implementation.
 */
#ifndef _SFIFO_H
#define _SFIFO_H

#include <stack>

template < typename item_type >
struct sfifo
{
public:
  typedef std::stack< item_type > stack_type;

  stack_type input_stack, output_stack;

  sfifo()
  {

  }

  void push(item_type x)
  {
		input_stack.push(x);
  }

  void pop()
  {
	if(!output_stack.empty())
	{
		output_stack.pop();
	}
	else
	{
		  // output stack is empty so it needs to be refilled
		  while(!input_stack.empty())
		  {
			  output_stack.push(input_stack.top());
			  input_stack.pop();
		  }

		  // if there more some to pop, now pop
		  if(!output_stack.empty())
		  {
			  output_stack.pop();
		  }
	}
  }

  item_type front()
  {
	  if(output_stack.empty())
	  {
		  while(!input_stack.empty())
		  {
			  output_stack.push(input_stack.top());
			  input_stack.pop();
		  }
		  return output_stack.empty() ? item_type() : output_stack.top();
	  }
	  else
	  {
		  return output_stack.top();
	  }
  }
};

#endif
