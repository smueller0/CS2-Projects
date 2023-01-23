// Specification file for the IntStack class

class IntStack
{
private:
    const static int STACKSIZE = 100;  // The stack size
    int stackArray[STACKSIZE];  // The stack array
    int top;          // Index to the top of the stack
    
public:
    // Constructor
    IntStack()  {  top = -1;  }  // empty stack
    
    // Stack operations
    void push(int);
    int pop();
    bool isFull() const;
    bool isEmpty() const;
    
    //added for testing purposes
    void display();
};
