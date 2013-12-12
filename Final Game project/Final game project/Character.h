
//Header file

#include <iostream>
#include <string>


using namespace std;


#ifndef CHARACTER_H
#define CHARACTER_H

//Class to create character
class Charact{

public:
	//Default constructor
	Charact();

	//Overload constuctor
	Charact(string, int, float);

	//Destructor
	~Charact();

	//Accessor
	string getName() const;
	// getName returns name of the character

	int getHeight() const;

	float getWeight() const;

	//Mutator
	void setName(string);
	// SetName

	void setHeight(int);

	void setWeight(float);

private:
	//Member variables
	string newName;
	int newHeight;
	float newWeight;



};

#endif