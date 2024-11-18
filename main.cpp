// COMSC-210 | lab 32 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
#include <deque> //std::deque
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
    deque<Car> myDeque (SIZE); //declare dequeue with intial size 2

    //cout initial
    cout << "Initial queue:\n"; 
    printAll(myDeque);

    for(int i = 1; myDeque.size() != 0; i++)
    {
        cout << "Time: " << i << " Operation: ";
        runDay(myDeque); 

        cout << "Queue:\n"; 
        printAll(myDeque);
    }
}

/************************************************
 * Function: Handles the processes for one "Time"
 * loop of the deque
 *
 * Parameters: &myDeque, as it calls other functions
 * that push/pop Car objects from the deque
 ************************************************/
void runDay(deque<Car>&myDeque)
{
    int rand1 = (rand()%100)+1; //random variable deciding addition/payment
    if(rand1 <= 55)
    {
        cout << "Car paid: ";
        myDeque[0].print(); 
        carLeaves(myDeque);
    }
    else //the other 45%
    {
        cout << "Joined lane: ";
        carJoins(myDeque);
        myDeque[myDeque.size()-1].print(); //print the last car to enter deque


        
    }
}

/************************************************
 * Function: Simply removes the frontmost car in 
 * line
 * Parameters: &myDeque, as a modification to the 
 * original deque is made.
 ************************************************/
void carLeaves(deque<Car>&myDeque)
{
    myDeque.pop_front();
}

/************************************************
 * Function: Adds a new car to the deque
 *
 * Parameters: &myDeque, as a modification to the 
 * original deque is made.
 ************************************************/
void carJoins(deque<Car>&myDeque)
{
    Car *temp = new Car(); //use default constructor 
    myDeque.push_back(*temp); 
}

/************************************************
 * Function: Adds a new car to the deque
 *
 * Parameters: myDeque, passed by value, as no 
 * modificaiton to the original deque needs to be
 * made, helps guard against accidental changes. 
 ************************************************/
void printAll(deque<Car>myDeque)
{
    for(int i = 0; i != myDeque.size(); i++)
    {
        cout << '\t'; //formatting
        myDeque[i].print();
    }
    if(myDeque.size() == 0) //handles case of empty deque
    {
        cout << "\tEmpty";
    }
    cout << "\n";
}