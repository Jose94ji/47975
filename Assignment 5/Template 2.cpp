/*Jose Jimenez
11/25/2013
Finding absolute value
gaddis ch16 number 4*/

//Libraries
#include <iostream>

using namespace std;

//Create template function
template <class T>
T findAbs(T a)
{
	//Return the abs value
	if(a<0){
		return -a;}
	else{
		return a;}

}

//Main starts here
int main()
{
	//Declare the variables
	int x;
	cout << "Please enter a any number you would like to find the absolute value of" << endl;
	//Input number
	cin >> x;
	//Call function and outout the absolute value.
	cout << "The absolute value is " << findAbs(x);
	cout << endl;

	//Program ends here
	system("PAUSE");
		return 1;
}

