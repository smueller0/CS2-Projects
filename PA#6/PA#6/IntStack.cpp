// Implementation file for the IntStack class

#include <iostream>
#include <cassert>
#include "IntStack.h"
using namespace std;


//*************************************************
// Member function push pushes the argument onto  *
// the stack.                                     *
//*************************************************

void IntStack::push(int num)
{
    assert (!isFull());
    
    top++;
    stackArray [top]  = num;
    
}

//****************************************************
// Member function pop pops the value at the top     *
// of the stack off, and returns it.                 *
//****************************************************

int IntStack::pop()
{
    assert (!isEmpty());
    int result = stackArray[top];
    top--;
    return result;
}

//***************************************************
// Member function isFull returns true if the stack *
// is full, or false otherwise.                     *
//***************************************************

bool IntStack::isFull() const
{
    return (top == STACKSIZE-1);
}

//****************************************************
// Member funciton isEmpty returns true if the stack *
// is empty, or false otherwise.                     *
//****************************************************

bool IntStack::isEmpty() const
{
    return (top == -1);
}


//****************************************************
// display outputs the elements in the stack, bottom *
//   to top.                                         *
//****************************************************

void IntStack::display()
{
    for (int i=0; i<=top; i++)
        cout << stackArray[i] << " ";
    cout << endl;
}
