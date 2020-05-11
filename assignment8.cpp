//Program for exception handlng 
// Roll No:-16
#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
class info
{
 int age,income,vehicle;
 char city[25];
 public:
 	void get()
 	{
 	   cout<<"\nEnter your age:";
 	   label:cin>>age;
 	   try
 	   {
 	      if(age<18 || age>55)
 	      {
 	         throw(age);
 	      }
 	   }
 	   catch(...)
 	   {	
 	         cout<<"\t\t!!! Error !!!\n!!! Age should be between 18 to 55 !!!\nEnter again:-";
 	   	goto label;
 	   }
 	   cout<<"Enter your income:";
 	   inco:cin>>income;
 	   try
 	   {
 	      if(income<50000 || income>100000)
 	      {
 	         throw(income);
 	      }
 	   }
 	   catch(...)
 	   {	
 	         cout<<"\t\t!!! Error !!!\n!!! Income should be between Rs.50,000 - Rs.1,00,000/- !!!\nEnter again:-";
 	   	goto inco;
 	   }
 	   cout<<"Enter your city:";
 	   cin.ignore();
 	   ci:cin.getline(city,25);
 	   for(int i=0;i<strlen(city);i++)
 	   {
 	   	if(city[i]>='a' && city[i]<='z')
 	   	{
 	   		city[i]=city[i]-32;
 	   	}
 	   }
 	   try
 	   {
 	      if(strcmp("PUNE",city)!=0 && strcmp("BANGLORE",city)!=0 && strcmp("MUMBAI",city) && strcmp("CHENNAI",city))
 	      {
 	         throw(city);
 	      }
 	   }
 	   catch(...)
 	   {	
 	         cout<<"\t\t!!! Error !!!\nEnter again:-";
 	   	goto ci;
 	   }
 	   cout<<"Enter your vehicle type(e.g 4,2,etc.):";
 	   veh:cin>>vehicle;
 	   try
 	   {
 	      if(vehicle!=4)
 	      {
 	         throw(age);
 	      }
 	   }
 	   catch(...)
 	   {	
 	         cout<<"\t\t!!! Error !!!\n!!! Vehicle must be 4 wheeler !!!\nEnter again:-";
 	   	goto veh;
 	   }
 	}
 	void display()
 	{
 	  cout<<"\nAge      :-\t"<<age;
 	  cout<<"\nIncome :-\tRs."<<income<<"/-";
 	  cout<<"\nCity      :-\t"<<city;
 	  cout<<"\nVehicle :-\t"<<vehicle<<" wheeler";
 	}
};
int main()
{
  info i;
  i.get();
  i.display();
}

/*
Output:-

Enter your age:-  15

Exception cought: Age is not in range
Please again enter your age

Enter your age:-  20


Enter your monthly income:- 15000

Exception cought: Income is not in range
Please again enter your monthly income

Enter your monthly income:- 75000


 Enter your city name:-  Nashik

Exception cought: City is not valid
Please again enter your city name

 Enter your city name:-  Mumbai

Your city is :-Mumbai

You have 4 wheeler whehicle(Y/N): Y

Congrates you have 4 wheeler car*/
