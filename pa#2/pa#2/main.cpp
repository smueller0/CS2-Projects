//
//
// Author: Sarah Mueller
// Collaborators: Nicole Hernandez, Pamola Resendiz
// Date: 2/11/2021
// Assignment Number: 2
// CS 2308 Spring 2021
//
// This program displays a menu and asks the user to make a
// selection. A do-while loop repeats the program until the
// user selects item 4 from the menu

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct Movie
{
    int id;
    string name;
    string releaseDate;
    double rating;
};

void readMovies(ifstream& in, Movie movies[], int& size);
void displayMovies(Movie movies[], int SIZE);
void displayHeader();
void sortByDateRating(Movie movies[], int SIZE);
void sortById(Movie movies[], const int SIZE);
int linearSearchByName(Movie movies[], int SIZE, string targetName);
int binarySearchById(Movie movies[], int SIZE, int targetId);


int main()
{
    int size = 100,
        SIZE = 0,
        position = 0,
        choice,
        index,
        targetId;
    string targetName;
    
    ifstream in;
    in.open("movies.txt");
    
    Movie movies[size];
    
    readMovies(in, movies, size);
    
    do
    {
        cout << "\nMenu\n"
             << "1. Display movies sorted by id\n"
             << "2. Display movies sorted by release date, then rating\n"
             << "3. Lookup a release date given a name\n"
             << "4. Lookup a movie by id\n"
             << "5. Quit the Program\n"
             << "Enter your choice:\n";
        cin >> choice;
        
        while (choice < 1 || choice > 5)
        {
           cout << "Please enter 1, 2, 3, 4, or 5:\n";
           cin >> choice;
        }
        
        if (choice != 5)
        {
            switch (choice)
            {
               case 1:
                    SIZE = size;
                    sortById(movies, SIZE);
                    displayMovies(movies, SIZE);
                   break;
               case 2:
                    SIZE = size;
                    sortByDateRating(movies, SIZE);
                    displayMovies(movies, SIZE);
                   break;
               case 3:
                    SIZE = size;
                    
                    cout << "Please enter a movie name:\n";
                    cin >> ws;
                    getline(cin, targetName);
                    
                    index = linearSearchByName(movies, SIZE, targetName);
                    
                    if (index == -1)
                    {
                        cout << "No movie found with name: " << targetName
                             << endl;
                    }
                    else
                    {
                        cout << "Release date of '" << movies[index].name << "' is "
                             << movies[index].releaseDate << endl;
                    }
                    break;
                case 4:
                    SIZE = size;
                    
                    cout << "Please enter a movie id:\n";
                    cin >> targetId;
                    
                    position = binarySearchById(movies, SIZE, targetId);
                    
                    if (position == -1)
                    {
                        cout << "No movie found with id: " << targetId
                             << endl;
                    }
                    else
                    {
                        displayHeader();
                        cout << left << fixed << setprecision(1)
                             << setw(3) << movies[position].id
                             << setw(26) << movies[position].name
                             << setw(12) << movies[position].releaseDate
                             << movies[position].rating
                             << endl;
                    }
                    break;
            }
        }
    } while (choice != 5);
    
    in.close();
    
    cout << "Exiting the program...\n";
    
    return 0;
}

//***********************************************************
// readMovies: reads the movies from the input file
// in the input file
// movies the array of movie structs
// size the number of movies in array
//***********************************************************
void readMovies(ifstream& in, Movie movies[], int& size)
{
    int count = 0;
    
    if (!in)
        cout << "Error opening file";
    else
    {
        while (in >> movies[count].id)
        {
            in >> ws;
            getline(in, movies[count].name);
            in >> movies[count].releaseDate;
            in >> movies[count].rating;
            
            count++;
            size = count;
        }
    }
}

//***********************************************************
// displayMovies: reads the movies from the input file
// movies the array of movie structs
// size the number of movies in array
//***********************************************************
void displayMovies(Movie movies[], int SIZE)
{
    displayHeader();
    for (int i = 0; i < SIZE; i++)
    {
        cout << left << fixed << setprecision(1)
             << setw(3) << movies[i].id
             << setw(26) << movies[i].name
             << setw(12) << movies[i].releaseDate
             << movies[i].rating << endl;
    }
}

//***********************************************************
// displayHeader: prints the header for the movies
//***********************************************************
void displayHeader()
{
    cout << left
         << setw(3) << "ID"
         << setw(26) << "Name"
         << setw(12) << "Date"
         << "Rating"
         << endl;
}

//***********************************************************
// sortByDateRating: sorts the movies by date then rating
// movies the array of movie structs
// size the number of movies in array
//***********************************************************
void sortByDateRating(Movie movies[], int SIZE)
{
    bool swap;
    Movie temp;

    do
    {
       swap = false;
       for (int count = 0; count < (SIZE - 1); count++)
       {
          if (movies[count].releaseDate > movies[count + 1].releaseDate)
          {
             temp = movies[count];
             movies[count] = movies[count + 1];
             movies[count + 1] = temp;
             swap = true;
          }
          else if (movies[count].releaseDate == movies[count + 1].releaseDate)
          {
              if (movies[count].rating < movies[count + 1].rating)
              {
                  temp = movies[count];
                  movies[count] = movies[count + 1];
                  movies[count + 1] = temp;
                  swap = true;
              }
          }
       }
    } while (swap);
}

//***********************************************************
// sortById: sorts the movies by id number
// movies the array of movie structs
// size the number of movies in array
//***********************************************************
void sortById(Movie movies[], const int SIZE)
{
    bool swap;
    Movie temp;

    do
    {
       swap = false;
       for (int count = 0; count < (SIZE - 1); count++)
       {
          if (movies[count].id > movies[count + 1].id)
          {
              temp = movies[count];
              movies[count] = movies[count + 1];
              movies[count + 1] = temp;
              swap = true;
          }
       }
    } while (swap);
}

//***********************************************************
// linearSearchByName: linear search for movies by name
// movies the array of movie structs
// size the number of movies in array
// string name of movie being searched for
//***********************************************************
int linearSearchByName(Movie movies[], int SIZE, string targetName)
{
    int position = -1;
    
    for (int i = 0; i < SIZE; i++)
    {
        if (movies[i].name == targetName)
        {
           return i;
        }
    }
    return position;
}

//***********************************************************
// binarySearchById: binary search for movies by id
// movies the array of movie structs
// size the number of movies in array
// int id of movie being searched for
//***********************************************************
int binarySearchById(Movie movies[], int SIZE, int targetId)
{
    sortById(movies, SIZE);
    
    int first = 0,
        last = SIZE - 1,
        middle,
        position = -1;
    bool found = false;

    while (!found && first <= last)
    {
       middle = (first + last) / 2;
       if (movies[middle].id == targetId)
       {
          found = true;
          position = middle;
       }
       else if (movies[middle].id > targetId)
          last = middle - 1;
       else
          first = middle + 1;
    }
    return position;
}
