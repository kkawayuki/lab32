// COMSC-210 | lab 32 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
#include <deque> //std::deque
#include <array> //std::array
#include "Car.h" //user-defined class
#include <random>
#include <time.h>
using namespace std;

// function prototypes
void runDay(deque<Car>* lanes);
void carLeaves(deque<Car> &);
void carJoins(deque<Car> &);
void printAll(deque<Car>);

/************************************************
 * Function: Main
 ************************************************/
int main()
{
    srand(time(0));                                                 // seed random
    const int SIZE = 2, LANES = 4, PAY = 46, JOIN = 39, SHIFT = 15; // includes constants for probabilities

    // add more lanes
    deque<Car> lanes[LANES];
    for (int i = 0; i < LANES; i++) // populate
    {
        for (int j = 0; j < SIZE; j++)
        {
            Car *temp = new Car;
            lanes[i].push_back(*temp);
        }
    }

    // updated print implementation
    cout << "Initial queue:\n";
    for (int i = 0; i < LANES; i++)
    {
        cout << "Lane " << i + 1 << ":\n";
        printAll(lanes[i]);
    }

    //20 runs 
    for (int i = 0; i < 20; i++)
    {
        cout << "Time: " << i + 1 << " Operation: "; // +1 for clarity on user side
        runDay(lanes);


        cout << "Queue:\n";
        for (int i = 0; i < LANES; i++)
        {
            cout << "Lane " << i + 1 << ":\n";
            printAll(lanes[i]);
        }
    }
}

/************************************************
 * Function: Handles the processes for one "Time"
 * loop of the deque
 *
 * Parameters: &tollBooth, as it calls other functions
 * that push/pop Car objects from the deque
 ************************************************/
void runDay(deque<Car>* lanes)
{
    //logic for running each of the cars 

    int rand1 = (rand() % 100) + 1; // random variable deciding addition/payment
    if (rand1 <= 55)
    {
        cout << "Car paid: ";
        tollBooth[0].print();
        carLeaves(tollBooth);
    }
    else // the other 45%
    {
        cout << "Joined lane: ";
        carJoins(tollBooth);
        tollBooth[tollBooth.size() - 1].print(); // print the last car to enter deque
    }
}

/************************************************
 * Function: Simply removes the frontmost car in
 * line
 * Parameters: &tollBooth, as a modification to the
 * original deque is made.
 ************************************************/
void carLeaves(deque<Car> &tollBooth)
{
    tollBooth.pop_front();
}

/************************************************
 * Function: Adds a new car to the deque
 *
 * Parameters: &tollBooth, as a modification to the
 * original deque is made.
 ************************************************/
void carJoins(deque<Car> &tollBooth)
{
    Car *temp = new Car(); // use default constructor
    tollBooth.push_back(*temp);
}

/************************************************
 * Function: Adds a new car to the deque
 *
 * Parameters: tollBooth, passed by value, as no
 * modificaiton to the original deque needs to be
 * made, helps guard against accidental changes.
 ************************************************/
void printAll(deque<Car> tollBooth)
{
    for (int i = 0; i != tollBooth.size(); i++)
    {
        cout << '\t'; // formatting
        tollBooth[i].print();
    }
    if (tollBooth.size() == 0) // handles case of empty deque
    {
        cout << "\tEmpty";
    }
    cout << "\n";
}