// Test driver for the DigitQueue class

#include <iostream>
using namespace std;

#include "DigitQueue.h"

int main() {
    DigitQueue que;
    int s;
    
    que.enqueue(2);
    que.enqueue(3);
    que.enqueue(5);
    cout << "print:" << endl;
    que.print();
    cout << "----" << endl;
    s = que.dequeue();
    cout << s << endl;
    s = que.dequeue();
    cout << s << endl;
    que.enqueue(1);
    cout << "print:" << endl;
    que.print();
    cout << "----" << endl;
    s = que.dequeue();
    cout << s << endl;
    if (que.isEmpty())
        cout << "EMPTY" << endl;
    else
        cout << "NOT EMPTY" << endl;
    s = que.dequeue();
    cout << s << endl;
    if (que.isEmpty())
        cout << "EMPTY" << endl;
    else
        cout << "NOT EMPTY" << endl;
    
    
}

//// Expected output:
//print:
//2
//3
//5
//----
//2
//3
//print:
//5
//1
//----
//5
//NOT EMPTY
//1
//EMPTY
