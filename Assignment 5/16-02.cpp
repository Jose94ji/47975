/*
Jose Jimenez
11/25/2013
Convert mil time with exceptions
gaddis chapter 16 num 2
*/

//Libraries
#include <iostream>

 using namespace std;

 //Classes
 class Time
 {protected:
 int hour;
 int min;
 int sec;
 //Public variables
 public:
 Time(int h, int m, int s)
 {hour=h;
 min=m;
 sec=s;
 }
 int getHour()
 {return hour;
 }
 int getMin()
 {return min;
 }
 int getSec()
 {return sec;
 }
 };

 class MilTime:public Time
 {private:
 int milH;
 int milS;
 public:
 MilTime(int,int);

 void change();
 void setTime(int, int);
 int getHour()
 { return milH;
 }

 int getStandHr()
 { return hour;
 }
 };

 //Menber funstions
 MilTime::MilTime(int h=0,int s=0):Time(0,0,s)
 {if(h<0||h>2359)
 {cout<<"Invalid input-Hours must be between 0 and 2359\n";
 milH=0;
 milS=0;
 }
 //Input validation
 else if(s<0||s>59)
 {cout<<"Invalid input-Seconds must be between 0 and 59\n";
 milS=0;
 }
 else
 {milH=h;
 milS=s;
 }
 change();
 }
 void MilTime::change()

	 //conversion
 {if(milH>1200)
 hour=milH-1200;
 else
 hour=milH;
 hour/=100;
 min=milH%100;
 }
 void MilTime::setTime(int h,int s)
 {milH=h;
 milS=s;
 change();
 }

 //MAIN STARTS HERE
 int main()

 {
	// Declare variables
 int h,m,s;
 MilTime a(1923,12);
 cout<<"initial hour as military time: "<<a.getHour()<<endl;
 cout<<"initial hour as standard time: "<<a.getStandHr()<<endl;

 //User input
 cout<<"Enter new military hours: ";

 //Exceptions
 try{
	 cin>>h;
	if(h >2400 || h<0)
	{
		throw 0;
	}
 }

 catch(int i)
 {
	cout << "You entered an invalid number" << endl;
	system("PAUSE");
	return 1;
 }
 cout<<"Enter new military minutes: ";
 cin>>m;
 cout<<"Enter new military seconds: ";

 //Exceptions
 try{
	 cin >> s;
	 
	 if(s < 0  || s>59)
	 {
		 throw 1;s
	 }}
	 catch(int b){
		 cout << "You entered an invalid number" << endl;
		 system("PAUSE");
		 return 2;
	 }
 //Find time
 a.setTime (h*100+m,s);

 cout<<"changed hour as military time: "<<a.getHour()<<endl;
 cout<<"changed hour as standard time: "<<a.getStandHr()<<endl;

 // Program Ends here
 system("pause");
 return 0;
 } 