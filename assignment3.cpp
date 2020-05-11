/*
IMPLEMENT A CLASS COMPLEX WHICH REPRESENTS THE COMPLEX NUMBER DATA TYPE. IMPLEMENT THE FOLLOWING OPERATIONS:
1. CONSTRUCTOR(INCLUDING A DEFAULT CONSTRUCTOR WHICH CREATES THE COMPLEX NUMBER 0+0I).
2. OVERLOAD OPERATOR + TO ADD TWO COMPLEX NUMBERS.
3. OVERLOAD OPERATOR * TO MULTIPLY TWO COMPLEX NUMBERS.
4. OVERLOAD OPERATOR << AND >> TO PRINT AND READ COMPLEX NUMBERS.

ROLL NO:- 16
*/
#include<iostream>
using namespace std;
class complex
{
  public:
  float real,img;
  complex operator +(complex ob)
  {
    complex temp;
    temp.real=real+ob.real;
    temp.img=img+ob.img;
    return temp;
  }
  complex operator -(complex ob)
  {
    complex temp;
    temp.real=real-ob.real;
    temp.img=img-ob.img;
    return temp;
  }
  complex operator *(complex ob)
  {
    complex temp;
    temp.real=(real*ob.real)-(img*ob.img);
    temp.img=(ob.real*img)+(real*ob.img);
    return temp;
  }
  complex operator /(complex ob)
  {
    complex temp;
    temp.real=((real*ob.real)+(img*ob.img))/((ob.real*ob.real)+(ob.img*ob.img));
    temp.img=((real*ob.img)-(ob.real*img))/((ob.real*ob.real)+(ob.img*ob.img));
    return temp;
  }
  friend istream &operator >>(istream &in,complex &c);
  friend ostream &operator <<(ostream &out,complex &c);
};
istream &operator >>(istream &in,complex &c)
{
 cout<<"Enter real part of complex no:";
 in>>c.real;
 cout<<"Enter img part of complex no.:";
 in>>c.img;
}
ostream &operator <<(ostream &out,complex &c)
{
 cout<<"Complex no. is :(";
 out<<c.real<<")+("<<c.img<<")i";
}
int main()
{
  int ch,v;
  complex c1,c2,c3;
  do
   {
    cin>>c1;
    cin>>c2;
    cout<<"\n1.Addition\t\t2.Substraction\n3.Multiplication\t4.Division\n5.Exit\nEnter your choice:";
    cin>>ch;
  switch(ch)
    {
     case 1:
       c3=c1+c2;
       cout<<"\nAddition of ";
       cout<<c3;
     break;
     case 2:
       c3=c1-c2;
       cout<<"\nSubstraction of ";
       cout<<c3;
     break;
     case 3:
       c3=c1*c2;
       cout<<"\nMultiplication of ";
       cout<<c3;
     break;
     case 4:
       c3=c1/c2;
       cout<<"\nDivision of ";
       cout<<c3;
     break;
     case 5:
       exit (0);
     default:
       cout<<"\nPlease enter valid choice";
    }
   cout<<"\nPress 1 to continue\nPress 0 to exit\n";
   cin>>v;
  }while(v!=0);
}
/*
OUTPUT:-

Enter real part of complex no:4
Enter img part of complex no.:2
Enter real part of complex no:5
Enter img part of complex no.:6

1.Addition		2.Substraction
3.Multiplication	4.Division
5.Exit
Enter your choice:1

Addition of Complex no. is :(9)+(8)i
Press 1 to continue
Press 0 to exit
1
Enter real part of complex no:7
Enter img part of complex no.:8
Enter real part of complex no:9
Enter img part of complex no.:5

1.Addition		2.Substraction
3.Multiplication	4.Division
5.Exit
Enter your choice:2

Substraction of Complex no. is :(-2)+(3)i
Press 1 to continue
Press 0 to exit
1
Enter real part of complex no:5
Enter img part of complex no.:1
Enter real part of complex no:3
Enter img part of complex no.:2

1.Addition		2.Substraction
3.Multiplication	4.Division
5.Exit
Enter your choice:3

Multiplication of Complex no. is :(13)+(13)i
Press 1 to continue
Press 0 to exit
1
Enter real part of complex no:7
Enter img part of complex no.:4
Enter real part of complex no:6
Enter img part of complex no.:2

1.Addition		2.Substraction
3.Multiplication	4.Division
5.Exit
Enter your choice:4

Division of Complex no. is :(1.25)+(-0.25)i
Press 1 to continue
Press 0 to exit
1
Enter real part of complex no:5
Enter img part of complex no.:8
Enter real part of complex no:4
Enter img part of complex no.:6

1.Addition		2.Substraction
3.Multiplication	4.Division
5.Exit
Enter your choice:5

*/
