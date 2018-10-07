// CS-3505 Assignment1: C++ Starter
// @version 8.29.2018
// @author Yingjie Lian

// You will write a C++ program in a file EcoSim.cpp that computes the rabbit and fox 
// populations and displays them as an ASCII chart, with each row showing the current 
// rabbit and fox population. Each iteration of the simulation produces a new row (going 
// down) and the x axis shows the scaled populations as described below. Start the chart 
// with a row for the initial rabbit and fox populations, then each iteration of updated 
// populations should be displayed. The last row of the chart should be the final computed 
// populations.

#include <iostream>
using namespace std;

// Declared all needed functions in the front
void updatePopulations(double g, double K, double p, double m, double c, double &numRabbits, double &numFoxes);
void incrementCounter(int*);
void plotCharacterAtPosition(int, char);
void plotPopulations(double, double, double);

// A main function that sets the parameters needed for the update equation, that asks the user 
// for an initial rabbit and fox population and that runs the simulation for 500 steps or until 
// the predator or prey population goes below 1. Store the number of rabbits and foxes as doubles 
// to let the equations work a little more smoothly. If the user enters anything that cannot be 
// converted to a double for an initial population, give a warning message and terminate the program. 
// Use cin as the mechanism for capturing input.
// rabbitGrowth (g): 0.2
// predationRate(p) : 0.002
// foxPreyConversion(c) : 0.6
// foxMortalityRate(m) : 0.2
// carryCapacity(K) : 1000.0
int main()
{
	// Initialize the variables that were given in the instruction
	double numFoxes = 0;
	double numRabbits = 0;
	double rabbitGrowth = 0.2;
	double predationRate = 0.002;
	double foxPreyConversion = 0.6;
	double foxMortalityRate = 0.2;
	double carryCapacity = 1000.0;

	cout << "Please enter the population of Foxes: " << endl;
        if (!(cin >> numFoxes))
        {
            cout << "The value you have entered is invalid. It must be a positive enteger." << endl;
            return 1;
        }

        if (numFoxes <= 0)
	{
		cout << "The value you have entered is invalid. It must be a positive enteger." << endl;
		return 1;
	}

	cout << "Please enter the population of Rabbits: " << endl;
        if (!(cin >> numRabbits))
        {

        }
        if (numRabbits <= 0)
	{
		cout << "The value you have entered is invalid. It must be a positive enteger." << endl;
		return 1;
	}

	int iterations = 0;

	while (iterations < 500 && numRabbits > 0 && numFoxes > 0)
	{
		// Used from instruction: "As some examples, if the scale factor is 0.1"
		plotPopulations(numRabbits, numFoxes, 0.1);
		updatePopulations(rabbitGrowth, predationRate, foxPreyConversion, foxMortalityRate, carryCapacity,
			numRabbits, numFoxes);
		int* pointer = &iterations;
		incrementCounter(pointer);
	}
	return 0;

}

// A population update function that takes in the model parameters and then the number of rabbits and 
// number of foxes with a pass-by-reference style. (This style of function is a good example for why 
// object-oriented programming was developed). Each iteration in the main function should call this 
// update function.
// deltaRabbit = gR(1-R/K) - pRF
// deltaFoxes = cpRF - mF
void updatePopulations(double g, double p, double c, double m, double K,
	double& numRabbits, double& numFoxes) {
	double rabbits = numRabbits;
	double foxes = numFoxes;

	numRabbits = rabbits + (g*rabbits*(1 - (rabbits / K)) - (p*rabbits*foxes));
	numFoxes = foxes + (c*p*rabbits*foxes - m * foxes);
}

// A void helper function plotCharacterAtPosition that takes in an int number and a character and sends 
// to std::cout number-1 spaces followed by the character. Unlike array indexing, the position of the 
// leftmost character on the screen is position 1. If the positioning number is less than 1, just output 
// the character.
void plotCharacterAtPosition(int spaces, char c) {
	string chart = "";

	while (spaces > 1) {
		chart += " ";
		spaces--;
	}
	chart += c;
	cout << chart;
}

// A void charting function plotPopulations that has parameters for the number of rabbits, the number of foxes, 
// and a fractional scale factor in that order. Using the plotCharacterAtPosition function as a helper, it should 
// draw a row of a text chart with an 'F' for foxes and 'r' for rabbits and '*' if the drawing of each would overlap. 
// The characters should be drawn in position floor(num*scale) + 1 from the left margin (with the first space being 
// position 1). As some examples, if the scale factor is 0.1 (which is the scale you should use in your submitted code) :
//	-for a fox population of 10 and a rabbit population of 5, then the output should be
//	rF
//	- for a fox population of 52 and a rabbit population of 27, the output should be
//	r  F
void plotPopulations(double numRabbits, double numFoxes, double scale) {
	string line = "";

        double spacesOfRabbits = numRabbits * scale;
        double spacesOfFoxes = numFoxes * scale;

	// '*' if the drawing of each would overlap which means they had equal amounts
	if (spacesOfRabbits == spacesOfFoxes)
	{
		plotCharacterAtPosition(spacesOfRabbits, '*');
		cout << endl;
	}

	else if (spacesOfRabbits > spacesOfFoxes)
	{
		plotCharacterAtPosition(spacesOfFoxes, 'F');
		spacesOfRabbits -= spacesOfFoxes;

		plotCharacterAtPosition(spacesOfRabbits, 'r');
		cout << endl;
	}

	else
	{
		plotCharacterAtPosition(spacesOfRabbits, 'r');
		spacesOfFoxes -= spacesOfRabbits;

		plotCharacterAtPosition(spacesOfFoxes, 'F');
		cout << endl;
	}
	
}

// A helper function incrementCounter that returns void and has a pointer to an integer parameter. The function 
// should add 1 to the value pointed to by the pointer. You must use this function to update your iteration count 
// in the main function. This is purely busy work to practice passing pointers.
void incrementCounter(int* pointer) {
	*pointer += 1;
}
