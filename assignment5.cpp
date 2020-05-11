/*
CREATE EMPLOYEE BIO-DATA USING FOLLOWING CLASSES
1) PERSONAL RECORD
2) PROFESIONAL RECORD
3) ACADEMIC RECORD
ASSUME APPROPRIATE DATA MEMBERS AND MEMBER FUNCTION TO ACCEPT REQUIRED DATA & PRINT BIO-DATA. CREATE BIO-DATA USING MULTIPLE INHERITANCE USING C++.

ROLL NO:- 16
*/
#include<iostream>
#include<string.h>
using namespace std;
class personal
{
	protected:
		char name[25];
		char dob[20];
		char tele[10];
		
		
	public:
		void get_personal()
		{
			cout<<"\nEnter your personal details:-\nName:-";
			cin.getline(name,25);
			cout<<"Date of Birth:";
			cin>>dob;
			tel:cout<<"Telephone no.:-";
			cin>>tele;
			if(strlen(tele)!=10)
			 {
			   cout<<"!!Enter valid telephone no.!!\n       !!Try again!!\n";
			   goto tel;
			 }
		}
};
class professional
{
	protected:
		int salary;
		float pf;
		char id[10];
	
    public:
    	void get_professional()
    	{
    		cout<<"\nEnter your professional details:-\nId:-";
    		cin>>id;
    		cout<<"Salary:-";
    		cin>>salary;
    		cout<<"Pf:-";
    		cin>>pf;
		}
};
class academic
{
	protected:
		float marks10,marks12;
		
	public:
		void get_academic()
		{
			cout<<"\nEnter your academic details:-\n";
			m10:cout<<"SSC marks:-";
			cin>>marks10;
			if(marks10>100 || marks10<0)
			 {
			   cout<<"!!Enter valid Marks!!\n     !!Try again!!\n";
			   goto m10;
			 }
			m12:cout<<"HSC marks:-";
			cin>>marks12;
			if(marks12>100 || marks12<0)
			 {
			   cout<<"!!Enter valid Marks!!\n       !!Try again!!\n";
			   goto m12;
			 }
		}
};
class biodata:public personal,public professional,public academic
{
	public:
		void display()
		{
			cout<<"\n****************************************!!! BIODATA !!!**********************************";
			cout<<"\n-----------------------------------------------------------------------------------------";
			cout<<"\nPersonal details";
			cout<<"\nName          :- "<<name;
			cout<<"\nDate Of Birth :- "<<dob;
			cout<<"\nTelephone     :- "<<tele;
			cout<<"\n-----------------------------------------------------------------------------------------";
			cout<<"\nProfessional Details";
			cout<<"\nEmployee Id   :- "<<id;
			cout<<"\nSalary        :- "<<salary;
			cout<<"\nPf            :- "<<pf;
		    cout<<"\n-----------------------------------------------------------------------------------------";
		    cout<<"\nAcademic Details";
		    cout<<"\n10th Marks    :- "<<marks10;
		    cout<<"\n12th Marks    :- "<<marks12;
		    cout<<"\n-----------------------------------------------------------------------------------------";
		    cout<<"\n                                        !!!THANK YOU!!!\n";
		}
};
int main()
{
	biodata b;
	b.get_personal();
	b.get_professional();
	b.get_academic();
	b.display();
	return 0;
}

/*
OUPUT:-

Enter your personal details:-
Name:-Vikas
Date of Birth:13/08/2000
Telephone no.:-9975093783

Enter your professional details:-
Id:-151
Salary:-45000
Pf:-7.8

Enter your academic details:-
SSC marks:-91.00
HSC marks:-84.62

****************************************!!! BIODATA !!!**********************************
-----------------------------------------------------------------------------------------
Personal details
Name          :- Vikas
Date Of Birth :- 13/08/2000
Telephone     :- 9975093783
-----------------------------------------------------------------------------------------
Professional Details
Employee Id   :- 151
Salary        :- 45000
Pf            :- 7.8
-----------------------------------------------------------------------------------------
Academic Details
10th Marks    :- 91
12th Marks    :- 84.62
-----------------------------------------------------------------------------------------
*/
