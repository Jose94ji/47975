//Jose Jimenez
//Date
//Game project
// 10/27/2013 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;

//Declare struct
struct Enemy{
int health;
string name;
};

struct Character{
	string name;
	int age;
};

//Function prototypes
void intro();
void create(Character &);
void stage1(Character);
void ldoor();
void rdoor(Enemy &);



int main()
{
	int size;
	cout << "How many times do you want to play the game?"  << endl;
	cout << "Twice is reccomended, but play as much as you want!" << endl;
	cin >> size;
	//Allocate the array
	int *p = new int[size];
	//Begin loop
	for (int i =0; i<size; i++){

	Character hero;
	//Function calls
	intro();
	cout << endl;
	cout << endl;
	create(hero);

	stage1(hero);}
	string w;
	cout << "Enter any key to exit the game";

	//Delete allocated memory
	delete [] p;
	//Program ends here
	cin.ignore(); 
	getline(cin, w);
	return 0;
}

void intro()
{
	//Read into file
	ifstream intro;
	intro.open("Intro.txt");
	

	if(!intro.is_open()){
		exit(EXIT_FAILURE);}

	string intro2;

	while(!intro.eof()){
		cout << intro2 << " ";
		intro >> intro2;
	}
	//Close file
		intro.close();
	

	
}

//Creates the users character
void create(Character &b)
{

	cout << "Now that you ready to begin your journey lets create your hero!" << endl;
	cout << "Please enter the name of your hero - " ;
	//User input
	cin.ignore(); 
	getline(cin,b.name);
	cout << endl; 

	cout << "Now how old is your hero? - ";
	cin >> b.age;


	cout << endl;
	if(b.age<21){
		cout << "Oh still a minor are we? Well no matter, your never to young to become a hero!" << endl;
	}

	else{
		cout << endl;
		cout << "Aren't you a bit to old to be a hero? hmmmm.....well no matter, lets go anyways!" << endl;
	}
}

void stage1(Character hero)
{
	//call structure
	Enemy dragon;

	string door;
	string x;

	cout << endl;
	cout << "To continue hit enter" << endl;
	cin.ignore(); 
	getline(cin, x);

	cout << "So " << hero.name << " should we take the left or right door?" << endl << endl;
	cout << "Behind one lies a monster and the other a puzzle" << endl << endl;
	cout << "!!!Remember all decisions may affect the games outcome!!!" << endl << endl;
	cout << "Enter 1 to go through the left and 2 for the right." << endl;

	cin >> door;                     

	while(door != "1" && door !="2")
	{
		
		cout << "ummm please enter 1 or 2, try again." << endl;
		cin >> door;
	}
	if(door == "1"){
		ldoor();}
	else{ 
	
		rdoor(dragon);
	}

}

//Function for the left door
void ldoor()
{
	string rid1;

	cout << endl;
	cout << "Look at the ceiling their is writing on the wall. " << endl;
	cout << "What does it say?" << endl << endl;
	cout << "SOLVE THE RIDLLES AND THE DOOR WILL UNLOCK" << endl << endl;;
	cout << "Riddle 1: Mary's father has 4 children;"
		 << "three are named Nana, Nene, and Nini. So what is is the 4th child's name?"<< endl;

	//The answer to the riddle is Mary
	cin >> rid1;

	//input validation;
	 while(rid1 != "Mary")
	 {
		 cout << endl;
		 cout << "BEEP! that is incorrect please try again" << endl;
		 cout << "Remember capitalization counts." << endl;
		 cin >> rid1;
		 cout << endl;
	 }

	 cout << "Ding dong that is correct! You win! " << endl << endl;
	 cout << endl;
}

//Function for the right door
void rdoor(Enemy &d)
{
	int ability = 0;
	//Access the enemy structure
	d.health = 100;
	d.name = "Red dragon";

	int health = 100;
	int i=0;

	cout << "The " << d.name << " has appeared!" << endl;
	cout << "Looks like we have no choice but to fight it. " << endl;

	//Continue fidht until dragon dies
	 while(d.health>0)
	 {
		 

		 cout << "What attack should we use?" << endl << endl;
		 cout << "Enter the number corresponding to the attack" << endl;
		 
		
		 cout << "1. Fireball"  << endl
			  << "2. Water shot" << endl
			  << "3.Heal" << endl
			  << "4.Hurricane" << endl;
		 cout << endl;

		  cin >> ability;

		  if(ability == 1)
		  {
			  cout << "You attacked with fireball" << endl;
			  d.health -= 25;

		  }

		  else if(ability == 2)
		  {
			   cout << "You attacked with Water Shot" << endl;
			   d.health -= 20;
		  }

		    else if(ability == 3)
		  {
			   cout << "You healed yourself" << endl;
			   health += 20;
		  }
		    else 
		  {
			   cout << "You attacked with Hurricane" << endl;
			   d.health -= 30;

		  }

			
	 cout << "The enemy now has " << d.health <<  " HP" << endl << endl;
	 if(d.health <= 0)
		 {
			 break;
		 }
	
	 if(i==0)
	 {
		 cout << "The enemy used slash!" << endl;
		 health -= 10;
		  cout <<"Your HP is now at " << health << endl << endl;
		i++;
	 }

	 else if(i==1)
	 {
	   cout <<"The enemy used firebreath!" << endl << endl;
	   health -= 15;
	   cout <<"Your HP is now at " << health << endl << endl; 
		i++;
	 }
	 else if(i==2)
	 {
	   cout <<"The enemy used Wind attack!" << endl << endl;
	   health -= 5;
	   cout <<"Your HP is now at " << health << endl << endl;
	i++;
	 }
	 else 
	 {
	   cout <<"The enemy used fire tornado!" << endl << endl;
	   health -= 15;
	   cout <<"Your HP is now at " << health << endl << endl;
	   i--;
	 }

	

	 }

	 cout << "You have slain the Red dragon and have emerged victorious" << endl;
}