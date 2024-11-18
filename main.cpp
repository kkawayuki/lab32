// COMSC-210 | lab 32 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
#include <deque> //std::deque
#include <array> //std::array
#include "Car.h" //user-defined class
#include <random>
#include <time.h>
using namespace std;

//function prototypes
void runDay(deque<Car>&);
void carLeaves(deque<Car>&);
void carJoins(deque<Car>&);
void printAll(deque<Car>);

/************************************************
 * Function: Main
 ************************************************/
int main()
{
    srand(time(0)); //seed random
    const int SIZE = 2; 
    deque<Car> tollBooth (SIZE); //declare dequeue with intial size 2

    //there are now 4 toll booths (dequeues)
    //add more lanes
    deque<Car>lanes[4]; 

    //cout initial
    cout << "Initial queue:\n"; 
    printAll(tollBooth);

    for(int i = 1; tollBooth.size() != 0; i++)
    {
        cout << "Time: " << i << " Operation: ";
        runDay(tollBooth); 

        cout << "Queue:\n"; 
        printAll(tollBooth);
    }
}

/************************************************
 * Function: Handles the processes for one "Time"
 * loop of the deque
 *
 * Parameters: &tollBooth, as it calls other functions
 * that push/pop Car objects from the deque
 ************************************************/
void runDay(deque<Car>&tollBooth)
{
    int rand1 = (rand()%100)+1; //random variable deciding addition/payment
    if(rand1 <= 55)
    {
        cout << "Car paid: ";
        tollBooth[0].print(); 
        carLeaves(tollBooth);
    }
    else //the other 45%
    {
        cout << "Joined lane: ";
        carJoins(tollBooth);
        tollBooth[tollBooth.size()-1].print(); //print the last car to enter deque


        
    }
}

/************************************************
 * Function: Simply removes the frontmost car in 
 * line
 * Parameters: &tollBooth, as a modification to the 
 * original deque is made.
 ************************************************/
void carLeaves(deque<Car>&tollBooth)
{
    tollBooth.pop_front();
}

/************************************************
 * Function: Adds a new car to the deque
 *
 * Parameters: &tollBooth, as a modification to the 
 * original deque is made.
 ************************************************/
void carJoins(deque<Car>&tollBooth)
{
    Car *temp = new Car(); //use default constructor 
    tollBooth.push_back(*temp); 
}

/************************************************
 * Function: Adds a new car to the deque
 *
 * Parameters: tollBooth, passed by value, as no 
 * modificaiton to the original deque needs to be
 * made, helps guard against accidental changes. 
 ************************************************/
void printAll(deque<Car>tollBooth)
{
    for(int i = 0; i != tollBooth.size(); i++)
    {
        cout << '\t'; //formatting
        tollBooth[i].print();
    }
    if(tollBooth.size() == 0) //handles case of empty deque
    {
        cout << "\tEmpty";
    }
    cout << "\n";
}