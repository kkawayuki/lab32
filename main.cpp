// COMSC-210 | lab 33 | Kent Kawashima
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
void carLeaves(deque<Car> *lanes, int arrIndex);
void carJoins(deque<Car> *lanes, int arrIndex);
void printAll(deque<Car> *lanes, bool);
void carShifts(deque<Car> *lanes, int arrIndex);

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
    printAll(lanes, true);

    // 20 runs
    const int days = 3;
    for (int i = 0; i < days; i++)
    {
        cout << "Time: " << i + 1 << '\n'; // +1 for clarity on user side
        runDay(lanes);

        // queue at end
        printAll(lanes, false);
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

        if (rand1 <= PAY) // pay case
        {
            cout << "Lane: " << i + 1 << " Paid: ";
            lanes[i].front().print();
            carLeaves(lanes, i);
        }
        else if (rand1 <= PAY + JOIN) // join
        {
            cout << "Lane: " << i + 1 << " Joined: ";
            carJoins(lanes, i);
            lanes[i].back().print();
        }
        else if (rand1 <= PAY + JOIN + SHIFT) // shift lanes (could also use an else statement)
        {
            cout << "Lane: " << i + 1 << " Switched: ";
            lanes[i].back().print(); // because rear car switches
            carShifts(lanes, i);
        }
    }
}

/************************************************
 * Function: Simulates a car leaving (having paid)
 * from the line
 *
 * Parameters:
 * *lanes, pointer to the array of lanes
 * arrIndex, the variable corresponding to the
 * specific array index to operate on
 ************************************************/
void carLeaves(deque<Car> *lanes, int arrIndex)
{
    lanes[arrIndex].pop_front();
}

/************************************************
 * Function: Adds a new car to the array of
 * deques
 *
 * Parameters:
 * *lanes, pointer to the array of lanes
 * arrIndex, the variable corresponding to the
 * specific array index to operate on
 ************************************************/
void carJoins(deque<Car> *lanes, int arrIndex)
{
    Car *temp = new Car();
    lanes[arrIndex].push_front(*temp);
}

/************************************************
 * Function: Prints out all the values for
 * each lane in the array
 *
 * Parameters:
 * *lanes, pointer to the array of lanes
 ************************************************/
void printAll(deque<Car> *lanes, bool first)
{

    for (int i = 0; i < LANES; i++) // for each array index
    {
        if (first)
            cout << "Lane " << i + 1 << ":\n";
        else
            cout << "Lane " << i + 1 << " Queue:\n";
        if (lanes[i].empty()) // handles case of empty deque
        {
            cout << "\tEmpty";
        }
        else
        {
            for (int j = 0; j < lanes[i].size(); j++) // for each element
            {
                cout << '\t'; // formatting
                lanes[i][j].print();
            }
        }
    }
    cout << "\n";
}

/************************************************
 * Function: Move a car from the back of the
 * current line to a random line
 *
 * Parameters:
 * *lanes, pointer to the array of lanes
 * arrIndex, the variable corresponding to the
 * specific array index to operate on
 ************************************************/
void carShifts(deque<Car> *lanes, int arrIndex)
{
    if (!lanes[arrIndex].empty())
    {
        // logic for car shifting lanes
        Car temp = lanes[arrIndex].back(); // make copy
        lanes[arrIndex].pop_back();        // remove actual back

        int r = rand() % 4;
        while (r == arrIndex)
        {
            r = rand() % 4; // generate random index
        }
        lanes[r].push_back(temp); // add to randomly selected array index
    }
}