

#include "Character.h"

Charact::Charact(){
	newHeight = 0;
	newWeight = 0.0;}

	Charact::Charact(string name, int height, float weight){

		newName = name;
		newHeight = height;
		newWeight = weight;


}

	Charact::~Charact(){

	}

	string Charact::getName() const{

		return newName;
	}

	int Charact::getHeight() const{
		return newHeight;

	}

	float Charact::getWeight() const{

		return newWeight;
	}

	void Charact::setName(string name){
		newName = name;
	}

	void Charact::setHeight(int height){
		newHeight = height;

	}

	void Charact::setWeight(float weight)
	{

		newWeight= weight;
	}
