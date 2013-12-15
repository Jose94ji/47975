//Jose Jimenez
//Final
//12/14/2013

//Did not finish number 2!!

//Library includes Here!!!
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cmath>
#include <iostream>
#include "Problem1.h"
#include "Problem3.h"
#include "Problem4.h"
#include "Problem5.h"

using namespace std;

//Global Constants Here!!!

//Function Prototypes Here!!!
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for the Final"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6 which is extra credit"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){

	 cout<<"In problem # 1"<<endl<<endl;
	srand (time(NULL));

int n=5;

int rndseq[]={16,34,57,79,122};

long int fr[]={0,0,0,0,0};

long int ntimes=100000;

Prob1Random a(n,rndseq,fr);

for(int i=1;i<=ntimes;i++)

{

a.randFromSet();

}

long int *x=a.getFreq();

int *y=a.getSet();

for(int i=0;i<n;i++)

{

cout<<(y[i])<<" occured "<<x[i]<<" times"<<endl;

}


cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;

cout << endl << endl;
       
}

void problem2(){
        cout<<"In problem # 2"<<endl<<endl;

		cout << " I wan not able to complete this one but began the member functions for partial credit" << endl;
		cout << endl << endl;
}

void problem3(){


int rows=5;

int cols=6;

Prob3TableInherited<int> tab("Problem3.txt",rows,cols);

const int *naugT=tab.getTable();

for(int i=0;i<rows;i++)

{

for(int j=0;j<cols;j++)

{

cout<<naugT[i*cols+j]<<" ";

}

cout<<endl;

}

cout<<endl;

const int *augT=tab.getAugTable();

for(int i=0;i<=rows;i++)

{

for(int j=0;j<=cols;j++)

{

cout<<augT[i*(cols+1)+j]<<" ";

}

cout<<endl;


}
cout << endl << endl;
}
void problem4(){
	cout<<"In problem # 4"<<endl<<endl;

	saveAccount mine(-300);

for(int i=1;i<=10;i++)
{
mine.Transaction((float)(rand()%500)*(rand()%3-1));
}
mine.toString();
cout<<"Balance after 7 years given 10% interest = "
<<mine.Total((float)(0.10),7)<<endl;
cout << endl << endl;
        
}

void problem5(){
	
        cout<<"In problem # 5"<<endl<<endl;

	Employee Mark("Mark", "Boss", 215.50);
Mark.setHoursWorked(-3);
Mark.toString();
Mark.CalculatePay(Mark.setHourlyRate(20.0),Mark.setHoursWorked(25));
Mark.toString();
Mark.CalculatePay(Mark.setHourlyRate(40.0),Mark.setHoursWorked(25));
Mark.toString();
Mark.CalculatePay(Mark.setHourlyRate(60.0),Mark.setHoursWorked(25));
Mark.toString();
Employee Mary("Mary","VP",50.0);
Mary.toString();
Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(40));
Mary.toString();
Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(50));
Mary.toString();
Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(60));
Mary.toString();
}

// 1) The constructor inputs the Name, Job Title and Hourly rate of the employee.
Employee::Employee(char name[], char job_title[], float hourly_rate)
{
strcpy(MyName,name);
strcpy(JobTitle,job_title);
setHourlyRate(hourly_rate);
// 2) All other properties are initialized to zero in the constructor.
HoursWorked = 0;
GrossPay = 0;
NetPay = 0;
}

//3) The Tax utility routine calculates the tax based on
//1 for GrossPay < 500,
//2 for GrossPay<1000 but greater than 500, and
//3 for anything above 1000.
double Employee::Tax(float gross_pay) //Utility Procedure
{
if(gross_pay<=500)
return .1;
else if(gross_pay>500 && gross_pay<=1000)
return 0.2;
else
return .3;
}

// 4) The Set procedures simply write and return the obvious properties.
int Employee::setHoursWorked(int no_of_hours_worked) //Procedure
{
if(no_of_hours_worked>0 && no_of_hours_worked<84)
HoursWorked = no_of_hours_worked;
else
{
cout <<"Unacceptable Hours Worked " << endl;
HoursWorked = 0;
}
return HoursWorked;
}

float Employee::setHourlyRate(float hourly_rate) //Procedure
{
if(hourly_rate>0 && hourly_rate<200)
HourlyRate = hourly_rate;
else
{
HourlyRate = 0;
cout <<"Unacceptable Hourly Rate" << endl;
}

return HourlyRate;
}

//5) The toString procedure prints all the properties.
void Employee::toString() //Procedure
{
cout <<"Name = "<<MyName << " Job Title = "<< JobTitle << endl;
cout <<"Hourly Rate = " << HourlyRate<<" Hours Worked = " <<
HoursWorked <<" Gross Pay = " << GrossPay <<" Net Pay = " << NetPay << endl;
}

// 6) The getGrossPay procedure calculates straight time for hours worked < 40, time and 1/2 for hours worked < 50 but greater than
// 40, double time for all hours above 50. The inputs to this routine are the hourly rate and the hours worked.
float Employee::getGrossPay(float hourly_rate, int no_of_hours_worked) //Procedure
{
GrossPay = 0;
if(no_of_hours_worked<40)
GrossPay = no_of_hours_worked*hourly_rate;
else if(no_of_hours_worked>=40 && no_of_hours_worked<=50)
GrossPay = no_of_hours_worked*hourly_rate*1.5;
else if(no_of_hours_worked>50)
GrossPay = no_of_hours_worked*hourly_rate*2;
return GrossPay;
}

//7) The net pay routine returns the gross pay subtracting off any taxes. Realize that the Tax procedure is utilized
//but these taxes are progressive rates for income above the cutoff limit as described in 3). Taxes are calculated for
//10% below 500, 20% for amounts between 500 and 1000 and finally anything above 1000 is calculated at the 30% rate.
float Employee::getNetPay(float gross_pay) //Procedure
{
NetPay = gross_pay-gross_pay*Tax(gross_pay);
return NetPay;
}

// 8) The Hoursworked must be > 0 and < 84
// 9) The Hourlyrate must be > 0 and < 200
// 10) The calculate pay routine returns the net pay. return getNetPay(getGrossPay(setHourlyRate(x),setHoursWorked(y)));
float Employee::CalculatePay(float x, int y) //Procedure
{
return getNetPay(getGrossPay(setHourlyRate(x),setHoursWorked(y)));
cout << endl << endl;

}

void problem6(){

	cout << "If their was anything i could do to improve my code would be to finish problem 2" << endl;
	cout << "Also probably should have commented more." << endl;
        cout<<"In problem # 6"<<endl<<endl;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}