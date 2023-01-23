// File Name: PasswordManager.h
//
// Author: Sarah Mueller
// Collaborators: Paloma Resendiz
// Date: 3/29/2021
// Assignment Number: 4
// CS 2308 Spring 2021
//
// This header file sets the password class.

#include <string>
using namespace std;

class PasswordManager
{
private:
    string username;
    string encryptedPassword;
    bool meetsCriteria(string);
    string encrypt(string);
    
public:
    
    void setUsername(string);
    void setEncryptedPassword(string);
    string getUsername() const;
    string getEncryptedPassword() const;
    
    bool setNewPassword(string);
    bool authenticate(string);
};



