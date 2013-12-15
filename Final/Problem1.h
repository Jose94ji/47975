#ifndef PROBLEM1_H
#define PROBLEM1_H

class Prob1Random

{

private:

int *set; //The set of numbers to draw random numbers from

int nset; //The number of variables in the sequence

long int *freq; //Frequency of all the random numbers returned

long int numRand; //The total number of times the random number function is called

public:

Prob1Random(const int ,int *,long int *); //Constructor

int randFromSet(void); //Returns a random number from the set

long int *getFreq(void) const; //Returns the frequency histogram

int *getSet(void) const; //Returns the set used

long int getNumRand(void) const; //Gets the number of times randFromSet has been called


};

//Variables
Prob1Random:: Prob1Random(const int c, int * ar,long int * fr)

{


set=ar;

nset=c;

freq=fr;

}

//Create set o nums
int Prob1Random::randFromSet(void)

{

int i = rand() % (nset);

freq[i]++;

numRand++;

return set[i];

}

//Finds frequency
long int *Prob1Random::getFreq(void) const

{

return freq;

}

//Gets the set
int *Prob1Random::getSet(void) const

{

return set;

}

//Get random amount of numbers
long int Prob1Random::getNumRand(void) const

{

return 100000;

}


#endif