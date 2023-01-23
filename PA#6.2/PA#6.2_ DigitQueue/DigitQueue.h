// Class Declaration for a DigitQueue, which uses an int to store digits
//   in a Queue ADT.

class DigitQueue {
private:
    int queue;    //the queue, container of the elements
    int size;     //the number of elements currently in the queue
public:
    DigitQueue();
    void enqueue(int);  // int must be a single digit. Use assert to check
    int dequeue();
    bool isEmpty();
    void print();
};


