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
void runDay(deque<Car> *lanes);
void carLeaves(deque<Car> &);
void carJoins(deque<Car> &);
void printAll(deque<Car>);

// global variables
const int SIZE = 2, LANES = 4, PAY = 46, JOIN = 39, SHIFT = 15; // includes constants for probabilities

/************************************************
 * Function: Main
 ************************************************/
int main()
{
    srand(time(0)); // seed random

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

    // 20 runs
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
void runDay(deque<Car> *lanes)
{
    // logic for running each of the cars
    for (int i = 0; i < LANES; i++)
    {
        int rand1 = (rand() % 100) + 1; // random variable deciding various operations

        if (rand1 <= PAY) //pay case
        {
            cout << "Car paid: ";
            lanes[i].front().print(); 
            carLeaves(lanes, i);
        }
        else if (rand1 <= PAY + JOIN) // join
        {
            cout << "Joined lane: ";
            carJoins(lanes, i);
            lanes[i].back().print(); 
        }
        else if (rand1 <= PAY + JOIN + SHIFT) //shift lanes (could also use an else statement)
        {
            carShifts(lanes, i); 
        }
    }
}

/************************************************
 * Function: Simply removes the frontmost car in
 * line
 * Parameters: &tollBooth, as a modification to the
 * original deque is made.
 ************************************************/
void carLeaves(deque<Car> *lanes, int arrIndex)
{
    lanes[arrIndex].pop_front(); 
}

/************************************************
 * Function: Adds a new car to the deque
 *
 * Parameters: &tollBooth, as a modification to the
 * original deque is made.
 ************************************************/
void carJoins(deque<Car> *lanes, int arrIndex)
{
    Car *temp = new Car();
    lanes[arrIndex].push_front(*temp); 
}

/************************************************
 * Function: Adds a new car to the deque
 *
 * Parameters: tollBooth, passed by value, as no
 * modificaiton to the original deque needs to be
 * made, helps guard against accidental changes.
 ************************************************/
void printAll(deque<Car> *lanes)
{

    for(int i = 0; i < LANES; i++) //for each array index
    {
        for(int j = 0; j < lanes[i].size()-1; j++) //for each element
        {
            cout << '\t'; // formatting
            lanes[i][j].print(); 
        }
    }
    if (lanes[i].size() == 0) // handles case of empty deque
    {
        cout << "\tEmpty";
    }
    cout << "\n";
}

void carShifts(deque<Car> *lanes, int arrIndex)
{
    //logic for car shifting lanes
}