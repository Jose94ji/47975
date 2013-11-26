/* Jose Jimenez
   11/24/2013
   Min and max templates
   Gaddis chapter 16 number 3
   */

#include <iostream>
using namespace std;

//Create template
template <class T>

//Find the minimum
T min(T a, T b, T c)
{
	// return the minimum
	return(a<b?a:b);
}

//Find the maximum and create the template
template <class X>
X max(X c , X d, X e)
{
	//return max
	return(c>d?c:d);
}

//Main ends here
int main(){

	//Declare the variables
	int x,z;
	cout << "Enter your first number" << endl;
	// input first num
	cin >> x;
	cout << "Enter the second number" << endl;
	cin >> z;

	//output
	cout << "The maximum is " << max(x, z) << endl;
	cout << "The minimum is " << min(x,z) << endl;
	//PROGRAM ENDS HERE
	system("pause");
	return 0;
}

