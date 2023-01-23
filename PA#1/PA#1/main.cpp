// File Name: PA#!.cpp
//
// Author: Sarah Mueller
// Collaborators: None
// Date: 1/29/2021
// Assignment Number: 1
// CS 2308 Spring 2021
//
// This program will display an struct array, allow the user to change the file size and
// display an updated version of the array. Then when program is ended it will display
// total file size and largest average.
//  main.cpp
//  PA#1
//
//  Created by Sarah Mueller on 1/29/21.
//  Copyright © 2021 Sarah Mueller. All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;

    struct FolderSize{
    string name;   //folder name
    int numFiles;  //number of files in folder
    double size;   //folder size
};

void displayFolders(FolderSize folders[ ]);
int folderIncrement(FolderSize folders[ ]);
float totalSize(FolderSize folders[ ]);
string highestAvg(FolderSize folders[ ]);

int main() {
    
        FolderSize folders[10] = {
        {"Documents", 5, 12.38},
        {"Downloads", 11, 17.22},
        {"Pictures", 27, 30.26},
        {"Videos", 6, 22.75},
        {"Projects", 3, 7.94},
        {"Labs", 6, 1.44},
        {"Music", 45, 102.73},
        {"Favorites", 4, 2.10},
        {"Contacts", 35, 3.51},
        {"Miscellaneous", 1, 2.23}
    };
    
    do{
        displayFolders(folders);
    }
    while(folderIncrement(folders) > 0);
    
    
    cout << fixed << setprecision(2);
    cout << "Total size of all folders: " << totalSize(folders) << endl;
    cout << "Folder with the largest average file size: " << highestAvg(folders) << endl;
    return 0;
}

//*****************************************************************
// function name : display the folder titles and array
//
// folders is the array containing all the folders info
// no returns
//*****************************************************************


    void displayFolders(FolderSize folders[ ]) {
        cout << left
        << setw(3) << "N"
        << setw(15) << "Name"
        << setw(10) << "Num files"
        << setw(10) << "Size(Mb)"
        << endl;
        
        for (int i = 0; i < 10; i++) {
            cout << fixed << setprecision(2);
            cout << left
            << setw(3) << i+1
            << setw(15) << folders[i].name
            << setw(10) << folders[i].numFiles
            << setw(10) << folders[i].size
            << endl;
        }
    }
//****************************************************************
// function name : input the folder number, and size and increment
// the files
//
// folders is the array containing all the folders info
// returns the folder number
//****************************************************************

int folderIncrement(FolderSize folders[ ]){
    int folderNum;
    double sizeInc;
    
    cout << "Enter the folder number (0 to quit):" << endl;
    cin >> folderNum;
    if(folderNum > 0 && folderNum < 11){
    cout << "Enter the file size:" << endl;
    cin >> sizeInc;
    
    folders[folderNum - 1].numFiles++;
    folders[folderNum - 1].size += sizeInc;
    }
    else if(folderNum > 10){
        cout << "Invalid folder number" << endl;
    }
    else {
        
    }
    return folderNum;
}
//*****************************************************************
// function name : to detemine the total size of all the files
//
// folders is the array containing all the folders info
// returns the total size of all the files
//*****************************************************************
 
float totalSize(FolderSize folders[ ]){
    float total = 0;
    
    for(int i = 0; i < 10; i++){
        total = total + folders[i].size;
    }
    
    return total;
}
//*****************************************************************
// function name : to determine the name of thw folder with the
// highest average file size
//
// folders is the array conatining all the folders info
// returns the name of the folder with the highest average
//*****************************************************************
string highestAvg(FolderSize folders[ ]){
    string highest = folders[0].name;
    float average = folders[0].size / folders[0].numFiles;
    for(int i = 1; i < 10; i++){
        if(average < (folders[i].size / folders[i].numFiles)){
            average = folders[i].size / folders[i].numFiles;
            highest = folders[i].name;
        }
    }
    return highest;
}
