// File Name: PA#6.2.cpp
//
// Author: Sarah Mueller
// Collaborators: Paloma Resendiz
// Date: 4/20/2021
// Assignment Number: 6.2
// CS 2308 Spring 2021
//
// Implement a queue using a integer variable to contain the entire contents of the queue.
#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

#include "DigitQueue.h"
//******************************************************
// Contructor
//******************************************************
DigitQueue::DigitQueue(){
    size = 0;
    queue = 0;
}
//******************************************************
// Enqueue inserts a value at the rear of the queue.
//******************************************************
void DigitQueue::enqueue(int num){
    assert (num / 10 == 0);
    queue = (num * pow(10,size)) + queue;
    size++;
}
//******************************************************
// Dequeue removes the value at the front of the
// queue and returns the value.
//******************************************************
int DigitQueue::dequeue(){
    assert (!isEmpty());
    
    int result = queue % 10;
    queue = queue / 10;
    size--;
    return result;
}
//******************************************************
// isEmpty returns true if the queue is empty,
// otherwise false.
//******************************************************
bool DigitQueue::isEmpty(){
    return (queue == 0);
}
//******************************************************
// print will print out all of the values in the queue
// one at a time.
//******************************************************
void DigitQueue::print(){
    int print = queue;
    int x;
    while(print != 0){
        x = print % 10;
        cout << x << endl;
        print = print / 10;
    }
}
