/*
IMAGINE A PUBLISHING COMPANY WHICH DOES MARKETING FOR BOOK AND AUDIOCASSETTE VERSIONS. CREATE A CLASS PUBLICATION THAT STORES THE TITLE (A STRING) AND PRICE (TYPE FLOAT) OF A PUBLICATION. FROM THIS CLASS DERIVE TWO CLASSES: BOOK,WHICH ADDS A PAGE COUNT (TYPE INT), AND TAPE, WHICH ADDA A PLAYING TIME IN MINUTES (TYPE FLOAT).
WRITE A PROGRAM THAT INSTANTIATES THE BOOK AND TAPE CLASSES, ALLOWS USER TO ENTER DATA AND DISPLAYS THE DATA MEMBERS. IF AN EXCEPTION IS CAUGHT, REPLACE ALL THE DATA MEMBER VALUES WITH ZERO VALUES.

ROLL NO:- 16
*/
#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
class publication
{
  protected:
     char title[25];
     int price;
     
  public:
     virtual void get()=0; 
     virtual void disp()=0;
};
class book:virtual public publication
{
  protected:
     int p_count,count1=0,fw=15,fw1=16,fw2=37,count2=0;
     
  public:
     void get()
     {
       cout<<"\nEnter the title of book:";
       cin.ignore();
       cin.getline(title,25);
       cout<<"Enter price of book:";
       cin>>price;
       cout<<"Enter page count of book:";
       cin>>p_count;
     }
     void disp()
     {
     	if(strlen(title)<fw)
		 {
		    fw=fw-strlen(title);   
		 }
		 int p=price;
		 while(p)
		 {
		 	p=p/10;
		 	count1++;
		 }
		if(count1<fw1)
		 {
		 	fw1=fw1-count1;
		 }
		 
		 int c=p_count;
		 while(c)
		 {
		 	c=c/10;
		 	count2++;
		 }
		if(count2<fw2)
		 {
		 	fw2=fw2-count2;
		 }
       cout<<"\n|  "<<title<<setw(fw)<<"|  "<<price<<setw(fw1)<<"|  "<<p_count<<setw(fw2)<<"|";
     }
};
class tape:virtual public publication
{
  protected:
     float p_time,c;
     int fw=15,fw1=16,fw2=39,count1=0,count2=0,l;
     char buffer[25];
  public:
     void get()
     {
       cout<<"\nEnter the title of tape:";
       cin.ignore();
       cin.getline(title,25);
       cout<<"Enter price of tape:";
       cin>>price;
       cout<<"Enter playing time of tape:";
       cin>>p_time;
     }
     void disp()
     {
	    if(strlen(title)<fw)
		 {
		    fw=fw-strlen(title);   
		 }
		 int p=price;
		 while(p)
		 {
		 	p=p/10;
		 	count1++;
		 }
		if(count1<fw1)
		 {
		 	fw1=fw1-count1;
		 }
		 /*while(c)
		 {
		 	c=c/10;
		 	count2++;
		 }*/
		 sprintf(buffer,"%f",c);
		 l=strlen(buffer);
		if(l<fw2)
		 {
		 	fw2=fw2-l;
		 }
     cout<<"\n|  "<<title<<setw(fw)<<"|  "<<price<<setw(fw1)<<"|  "<<p_time<<setw(fw2)<<"|";
   }
};
int main()
{
 publication *p[100];
 int j=0,ch;
 do
 {
    cout<<"\n1.Book\n2.Tape\n3.Display\n4.Exit\nEnter choice:";
    cin>>ch;
    cout<<"\n|---------------------------------------------------------------------|";
    switch(ch)
    {
      case 1:
             cout<<"\nBook";
             p[j]=new book();
             p[j]->get();
             j++;
             cout<<"\n|---------------------------------------------------------------------|";
             break;
      case 2:
             cout<<"\nTape";
             p[j]=new tape();
             p[j]->get();
             j++;
             cout<<"\n|---------------------------------------------------------------------|";
             break;
      case 3:
             cout<<"\n"<<setw(50)<<"*******Displaying list:*******";
             int n=j;
             cout<<"\n|---------------------------------------------------------------------|";
             cout<<"\n|  Title"<<setw(15)<<"|  Price"<<setw(35)<<"|  Page count/Playing  Time"<<setw(13)<<"|";
             cout<<"\n|---------------------------------------------------------------------|";
             for(j=0;j<n;j++)
             {
               p[j]->disp();
             }
             exit (0);
    }
    cout<<"\n";
    }while(ch!=3);
}

/*
OUTPUT:-

1.Book
2.Tape
3.Display
4.Exit
Enter choice:1

|---------------------------------------------------------------------|
Book
Enter the title of book:Rise of Shivgami
Enter price of book:226
Enter page count of book:3500

|---------------------------------------------------------------------|

1.Book
2.Tape
3.Display
4.Exit
Enter choice:2

|---------------------------------------------------------------------|
Tape
Enter the title of tape:Kishor Kumar  
Enter price of tape:120
Enter playing time of tape:225.30

|---------------------------------------------------------------------|

1.Book
2.Tape
3.Display
4.Exit
Enter choice:3

|---------------------------------------------------------------------|
                    *******Displaying list:*******
|---------------------------------------------------------------------|
|  Title       |  Price        |  Page count/Playing  Time            |
|---------------------------------------------------------------------|
|  Rise of Shivgami |  226          |  3500                                |
|  Kishor Kumar|  120          |  225.3                              |
*/
