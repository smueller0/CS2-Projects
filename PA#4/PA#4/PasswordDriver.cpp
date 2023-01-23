// File Name: PasswordDriver.cpp
//
// Author: Sarah Mueller
// Collaborators: Paloma Resendiz
// Date: 3/29/2021
// Assignment Number: 4
// CS 2308 Spring 2021
//
// This program will use classes to take a username and password
// and encrypt the password.

#include <iostream>
#include <fstream>
using namespace std;
#include "PasswordManager.h"

int main(){
    PasswordManager manager[3];
    string username, oldPassword, newPassword,
    arrayUser, arrayPass;
    int x = 0;
    bool passUser = false;
    ifstream fin;
    fin.open("passwords.txt");
    
    if(!fin){
        cout << "Input file failed to open!\n";
        return 1;
    }
    
    for(int i = 0; i < 3; i++){
        fin >> arrayUser;
        manager[i].setUsername(arrayUser);
        fin >> arrayPass;
        manager[i].setEncryptedPassword(arrayPass);
    }
    cout << "Please enter your netID:\n";
    cin >> username;
    cout << "Please enter your old password:\n";
    cin >> oldPassword;
    cout << "Please enter your new password:\n";
    cin >> newPassword;
    
    for(int i = 0; i < 3; i++){
        if(username == manager[i].getUsername()){
            x = i;
            passUser = true;
        }
    }
    if(passUser == false){
        cout << endl << "NetID is invalid, password not changed.\n" << endl;
    }
    else{
        if(manager[x].authenticate(oldPassword) == false){
            cout << endl << "Old password is incorrect.\n" << endl;
        }
        else{
            if(manager[x].setNewPassword(newPassword) == false){
                cout << endl << "New Password does not meet criteria.\n" << endl;
            }
            else{
                cout << endl << "Password has been changed for netID: " << username << endl << endl;
            }
        }
        
    }
    
    for(int i=0; i < 3; i++){
        cout << manager[i].getUsername() << "  " <<
        manager[i].getEncryptedPassword() << endl;
    }

    fin.close();
    return 0;
}


