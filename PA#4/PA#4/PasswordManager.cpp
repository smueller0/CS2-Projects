// File Name: PasswordManager.cpp
//
// Author: Sarah Mueller
// Collaborators: Paloma Resendiz
// Date: 3/29/2021
// Assignment Number: 4
// CS 2308 Spring 2021
//
// Password Manager Class
//
#include "PasswordManager.h"

void PasswordManager::setUsername(string usern){
    username = usern;
}
void PasswordManager::setEncryptedPassword(string EncyPass){
    encryptedPassword = EncyPass;
}
string PasswordManager::getUsername() const{
    return username;
}
string PasswordManager::getEncryptedPassword() const{
    return encryptedPassword;
}
string PasswordManager::encrypt(string password){
    int asciiVal;
    char x;
    string newPassword;
    
    for(int i = 0; i < password.length(); i++){
        asciiVal = int(password[i]);
        x = ((asciiVal - 33) + 45) % 94 + 33;
        newPassword += x;
    }
    return newPassword;
}
bool PasswordManager::meetsCriteria(string password){
    bool lowercase = false;
    bool digit = false;
    
    if(password.length() < 9)
        return false;
    if(password[0]=='_')
        return false;
    
    for(int i = 0; i < password.length(); i++){
        if(islower(password[i]))
            lowercase = true;
        if(isdigit(password[i]))
            digit = true;
    }
    if(lowercase && digit)
        return true;
    
        return false;
}
bool PasswordManager::setNewPassword(string password){
    string newPassword;
    bool created = false;
    if (meetsCriteria(password) == true){
        newPassword = encrypt(password);
        created = true;
        setEncryptedPassword(newPassword);
        
    }
    return created;
}
bool PasswordManager::authenticate(string password){
    bool authen = false;
    if(encrypt(password) == getEncryptedPassword()){
        authen = true;
    }
    return authen;
}
