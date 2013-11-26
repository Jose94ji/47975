/*
Jose Jimenez
11/25/2013
Ch 16 num 1
*/



 /*I know that classes are supposed to be placed in header files
  but It was my fault that didnt have time to reformat them and place them for header
  That oes for all of the chapter 15 and 16 assignments
  */
 
#include <iostream>
#include <string>

using namespace std;

 //Create class
 class Date 
 {
 private:
	 //data member variables
 int month; 
 int day; 
 int year;
 public:
	 //member functions
 Date(int m, int d, int y)
 {
 month = m;
 day = d;
 year = y;
 }
 //Destructor
 ~Date()
 { }

 // define functions
 void printDate1()
 {
 cout << this->month << "/" << this->day << "/" << this->year << "\n";
 }
 void printDate2()
 {
 switch(month)
 {
 case 1:
 cout << "January " << day << ", " << year <<"\n";
 break;
 case 2 :
 cout << "February " << day << ", " << year <<"\n";
 break;
 case 3 :
 cout << "March " << day << ", " << year <<"\n";
 break;
 case 4 :
 cout << "April " << day << ", " << year <<"\n";
 break;
 case 5 :
 cout << "May " << day << ", " << year <<"\n";
 break;
 case 6 :
 cout << "June " << day << ", " << year <<"\n";
 break;
 case 7 :
 cout << "July " << day << ", " << year <<"\n";
 break;
 case 8 :
 cout << "August " << day << ", " << year <<"\n";
 break;
 case 9 :
 cout << "September " << day << ", " << year <<"\n";
 break;
 case 10 :
 cout << "October " << day << ", " << year <<"\n";
 break;
 case 11 :
 cout << "November " << day << ", " << year <<"\n";
 break;
 case 12 :
 cout << "December " << day << ", " << year <<"\n";
 break;
 default :
 cout << "error \n";
 break;
 }
 }
 void printDate3()
 {
 switch(month)
 {
 case 1:
 cout << day << " January " << year <<"\n";
 break;
 case 2 :
 cout << day << " February " << year <<"\n";
 break;
 case 3 :
 cout << day << " March " << year <<"\n";
 break;
 case 4 :
 cout << day << " April " << year <<"\n";
 break;
 case 5 :
 cout << day << " May " << year <<"\n";
 break;
 case 6 :
 cout << day << " June " << year <<"\n";
 break;
 case 7 :
 cout << day << " July " <<year <<"\n";
 break;
 case 8 :
 cout << day << " August " << year <<"\n";
 break;
 case 9 :
 cout << day << " September " << year <<"\n";
 break;
 case 10 :
 cout << day << " October " << year <<"\n";
 break;
 case 11 :
 cout << day << " November " << year <<"\n";
 break;
 case 12 :
 cout << day << " December " <<year <<"\n";
 break;
 default :
 cout << "error \n";
 break;
 }
 }
 };

 //Main begins here!
 int main()
 {
	//Declare variables
 int tempMonth = 0 ;
 int tempDay = 0;
 int tempYear = 0;

 try{
	  
 cout << "Input a month 1 through 12 and press enter: \n";
 cin >> tempMonth;
 
 if(tempMonth > 12 || tempMonth < 1){
	 throw 0;
 }
 }
 catch(int x)
 {
	 cout << "Error you entered an invalid month";
		 cout << endl;
	 system("Pause");
	 return 1;
 }
 //Exceptions
 try{
 cout << "Input a Day 1 through 31 and press enter: \n";
 cin >> tempDay;
 
 if(tempDay > 31 || tempDay < 1)
 {
	 throw 0;
 }}
 catch(int x)
 {
	 cout << "Error you entered an invalid day!!!" << endl;
	 system("PAUSE");
	 return 2;
 }

 while(tempYear < 1)
 {
 cout << "Input a Year: \n";
 cin >> tempYear;
 }

 Date *d = new Date(tempMonth,tempDay,tempYear);

 d->printDate1();
 d->printDate2();
 d->printDate3();

 system("Pause");
 return 0;
 }