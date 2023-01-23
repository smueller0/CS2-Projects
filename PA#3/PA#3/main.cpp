// File Name: PA#3.cpp
//
// Author: Sarah Mueller
// Collaborators: Paloma Resendiz
// Date: 1/29/2021
// Assignment Number: 3
// CS 2308 Spring 2021
//
// This point of this program is to write 4 functions that
// work independently using pointers and dynamic memory
// allocation
#include <iostream>
using namespace std;

void showArray(int* array, int size);
int *duplicateArray (int *arr, int size);
bool isSorted(int *arr, int size);
int sort2withSum (int *x, int *y);
int *grow(int *arr, int size);
int *subArray (int *arr, int start, int length);

int main() {
    int testArr1[8] = {1,2,3,4,5,6,7,8};
    int testArr2[8] = {8,7,6,5,4,3,2,1};
    int testArr3[8] = {1,2,3,5,4,6,7,8};

    //use with sort2withSum
    int a = 8;
    int b = 5;
    
    int testArrayGrow[9] = {1,2,3,4,5,6,7,8,9};
    int expectedArrayGrow[2 * 9] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9};

    int testArraySub[8] = {18, 19, 15, 16, 12, 11, 13, 14};
    const int arrayStartIdx = 3, arrayLength = 4;
    int expectedArraySub[4] = {16, 12, 11, 13};
    
    // isSorted
    cout << "Testing isSorted:\n";
    cout << "test data array 1: " ;
    showArray(testArr1, 8);
    cout << "Expected result: true\n";
    cout << "Actual result:   " << boolalpha <<
    isSorted(testArr1,8) << endl;
    cout << "test data array 2: " ;
    showArray(testArr2, 8);
    cout << "Expected result: false\n";
    cout << "Actual result:   " << boolalpha <<
    isSorted(testArr2, 8) << endl;
    cout << "test data array 3: " ;
    showArray(testArr3, 8);
    cout << "Expected result: false\n";
    cout << "Actual result:   " << boolalpha <<
    isSorted(testArr3, 8) << endl << endl;
    
    // sort2withSum
    cout << "Testing sort2withSum" << endl;
    cout << "test data: a:" << a << " b:" << b << endl;
    int sum = sort2withSum(&a, &b);
    cout << "Expected result: " << sum << "  a: " << a << "  b: "
    << b << endl;
    cout << "Actual results : " << sum << "  a: " << a << "  b: "
    << b << endl;
    a = 2;
    b = 5;
    cout << "test data: a:" << a << " b:" << b << endl;
    int sum2 = sort2withSum(&a, &b);
    cout << "Expected result: " << sum2 << "  a: " << a << "  b: "
    << b << endl;
    cout << "Actual results : " << sum2 << "  a: " << a << "  b: "
    << b << endl << endl;
    
    //grow
    cout << "Testing grow:\n";
    cout << "test data: ";
    showArray(testArrayGrow, 9);
    int *growArray = grow(testArrayGrow, 9);
    cout << "Expected result:";
    showArray(expectedArrayGrow, 18);
    cout << "Actual result:  ";
    showArray(growArray, 18);
    cout << endl;
    
    
    // subArray
    cout << "Testing subArray:" << endl;
    cout << "test data: ";
    showArray(testArraySub, 8);
    cout << "start and length: " << arrayStartIdx << " " <<
    arrayLength << endl;
    int *actualArray= subArray(testArraySub, arrayStartIdx, arrayLength);
    cout << "result:   ";
    showArray(actualArray, arrayLength);
    cout << "expected: ";
    showArray(expectedArraySub, 4);
    delete [] actualArray;
    return 0;
}

//***********************************************************
// showArray: displays the elements of an integer array in one line
//       separated by a space.
// array: an array of ints
// size: the number of ints in the array
//***********************************************************
void showArray (int *array, int size) {
    for (int i=0; i<size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

//***********************************************************
// duplicateArray: creates a new array that contains the elements of the
//      array argument in the same order
// array: an array of ints
// size: the number of ints in the array
// returns a pointer to the new array.
//      If an invalid size is passed the function returns null.
// NOTE: it is the caller's responsibility to delete the returned array
//      when finished with it.
//***********************************************************
int *duplicateArray (int *arr, int size) {
   
   int *newArray;
   if (size <= 0)         //size must be positive
      return NULL;        //NULL is 0, an invalid address

   newArray = new int [size];  //allocate new array

   for (int index = 0; index < size; index++)
      newArray[index] = arr[index];  //copy to new array

   return newArray;
}

//***********************************************************
// isSorted: tests the array to see if it's sorted and will
// return true if it is sorted and false if its not sorted.
// array : and array of ints
// size : number of ints in the array
// returns true or false if sorted or not.
//***********************************************************
bool isSorted(int *array, int size){
    bool answer = true;
    for(int i = 0 ; i < (size-1); i ++){
        if(*(array+i) > *(array+(i+1))){
            answer = false;
        }
    }
    return answer;
}
//***********************************************************
// sort2withSum: sorts 2 numbers and returns the sum of the
// two numbers
// x: an integer number that will switch with y if its larger
// y: an integer number that will switch with x if smaller
// returns the sum of the two inputs
//***********************************************************
int sort2withSum (int *x, int *y) {
    if (*x > *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    return *x + *y;
}
//***********************************************************
// grow: will take the array and size and will duplicate the
// array by duplicating each int twice
// array: the array of int
// size: the size of the array
// returns pointer to the new array
//***********************************************************
int *grow(int arr[], int size){
    int *bigArray;
    bigArray = new int [size*2];
    
    for (int i = 0; i < size; i++){
            *(bigArray+i+i) = *(arr+i);
            *(bigArray+i+i+1) = *(arr+i);
    }
    return bigArray;
}
//***********************************************************
// subArray: take in an array, the start and length values and
// then creates a new array starting at the start value and
// only producing to the length given
// array: the array gievn
// start: the start pointer of the new array
// length: the length of the new array
// returns the new array
//***********************************************************

int *subArray (int *array, int start, int length) {
     int *result = duplicateArray((array + start), length);
     return result;
}
