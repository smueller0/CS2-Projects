// File Name: PA#6.1.cpp
//
// Author: Sarah Mueller
// Collaborators:  Paloma Resendiz
// Date: 4/18/2021
// Assignment Number: 6.1
// CS 2308 Spring 2021
//
// Program will check a file and ensure that the proper
// parentheses, curly braces, and square brackets match
// and are in order.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "IntStack.h"

using namespace std;

int main() {
    int brackets;
    char popped;
    bool match = true;
    string fileName;
    ifstream in;
    IntStack stack;
    cout << "Enter the name of a file to check:" << endl;
    cin >> fileName;
    
    in.open(fileName);
    char codeLine;
    
    while (in >> codeLine){
        if(codeLine == '(' || codeLine == '{' || codeLine == '['){
            brackets = codeLine;
            stack.push(brackets);
        }
        switch(codeLine){
            case ')':
                if(stack.isEmpty()){
                    match = false;
                    cout << "Unmatched )" << endl;
                    break;
                }
                popped = stack.pop();
                if (popped == '{'){
                    cout << "Expected a } but found a )" << endl;
                    match = false;
                }
                else if (popped == '['){
                    cout << "Expected a ] but found a )" << endl;
                    match = false;
                }
                break;
            case '}':
                if(stack.isEmpty()){
                    match = false;
                    cout << "Unmatched }" << endl;
                    break;
                }
                popped = stack.pop();
                if (popped == '('){
                    cout << "Expected a ) but found a }" << endl;
                    match = false;
                }
                else if (popped == '['){
                    cout << "Expected a ] but found a }" << endl;
                    match = false;
                }
            break;
            case ']':
                if(stack.isEmpty()){
                    match = false;
                    cout << "Unmatched ]" << endl;
                    break;
                }
                popped = stack.pop();
                if (popped == '('){
                    cout << "Expected a ) but found a ]" << endl;
                    match = false;
                }
                else if (popped == '{'){
                    cout << "Expected a } but found a ]" << endl;
                    match = false;
                }
            break;
        }
        
    }
    if(!stack.isEmpty()){
        popped = stack.pop();
        if(popped == '('){
            cout << "Missing )" << endl;
            match = false;
        }
        else if(popped == '['){
            cout << "Missing ]" << endl;
            match = false;
        }
        else {
            cout << "Missing }" << endl;
            match = false;
        }
    }
    
    if(stack.isEmpty() && match == true){
        cout << "All brackets match" << endl;
    }
    
}
