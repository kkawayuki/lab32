// COMSC-210 | lab 32 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
#include <deque> //std::deque
#include "Car.h" //user-defined class
#include <random>
#include <time.h>
using namespace std;

//function prototypes
string runDay(deque<Car>&);
void carLeaves(deque<Car>&);
void carJoins(deque<Car>&);
void printAll(deque<Car>);


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
        cout << "Time: " << i << " " << runDay(myDeque);
        //myDeque[myDeque.size()].print();
        cout << "Queue:\n"; 
        printAll(myDeque);
    }
}

string runDay(deque<Car>&myDeque)
{
    int rand1 = (rand()%100)+1; //random variable deciding addition/payment
    if(rand1 <= 55)
    {
        carLeaves(myDeque);
        return("Joined lane: ");
    }
    else //the other 45%
    {
        carJoins(myDeque);
        return("Car paid: ");
    }
}

void carLeaves(deque<Car>&myDeque)
{
    myDeque.pop_front();
}

void carJoins(deque<Car>&myDeque)
{
    Car *temp = new Car(); //use default constructor 
    myDeque.push_back(*temp); 
}

void printAll(deque<Car>myDeque)
{
    for(int i = 0; i != myDeque.size(); i++)
    {
        cout << '\t'; //formatting
        myDeque[i].print();
    }
    cout << "\n\n";
}