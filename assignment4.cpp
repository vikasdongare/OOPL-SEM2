/*
IMPLEMENT A CLASS CPPARRAY WHICH IS IDENTICAL TO A ONE-DIMENTIONAL C++ ARRAY (i.e., THE INDEX SET IS A SET OF CONSECUTIVE INTEGERS STARTING AT 0) EXCEPT FOR THE FOLLOWING:
1. IT PERFORMS RANGE CHECKING.
2. IT ALLOWS ONE TO BE ASSIGNED TO ANOTHER ARRAY THROUGH THE USE OF THE ASSIGNMENT OPERATOR(E.G. CP1=CP2)
3. IT SUPPORTS A FUNCTION THAT RETURNS THE SIZE OF THE ARRAY.
4. IT ALLOWS THE READING OR PRINTING OF ARRAY THROUGH THE USE OF COUT AND CIN.

ROLL NO:-16
*/
#include<iostream>
using namespace std;
class cpparray
{
  int cp[20],n;
  public:
  friend istream &operator >>(istream &in,cpparray &c);
  friend ostream &operator <<(ostream &out,cpparray &c);
  int size();
  void operator =(cpparray c);
  int &operator [](int subscript);
};

istream &operator >>(istream &in,cpparray &c)
 {
      cout<<"Enter array elements:";
    for(int i=0;i<c.n;i++)
      {
        in>>c.cp[i];
      }
 }
 
ostream &operator <<(ostream &out,cpparray &c)
 {
    cout<<" array is:";
    for(int i=0;i<c.n;i++)
      {
        cout<<"\t";
        out<<c.cp[i];
      }
 }
 
int cpparray :: size()
 {
   cout<<"Enter the size of array:";
   cin>>n;
   return n;
 }
 
void cpparray :: operator = (cpparray c)
 {
   if(n==c.n)
     {
       for(int i=0;i<c.n;i++)
         {
           c.cp[i]=cp[i];
         }
     }
   else
     cout<<"\nCopying of array is not possible";
 }
 
int &cpparray :: operator [](int subscript)
 {
   if(subscript>n)
    {
      cout<<"\nError:Out of range";
      return cp[n-1];
    }
   else if (subscript<0)
    {
      cout<<"\nError:Index should be positive";
      return cp[0];
    }
   else
    {
      return cp[subscript];
    }
 }
 
int main()
{
  cpparray c1,c2;
  int ch,val,i;
  cout<<"\nEnter details of array:\n";
  c1.size();
  cin>>c1;
   cout<<"\n------------------------------------------------------------\n";
  do
  {
    cout<<"\n1.Display array\t\t2.Copying array\n3.Checking array\t4.Exit\nEnter choice:";
    cin>>ch;
     cout<<"\n------------------------------------------------------------\n";
    switch(ch)
    {
      case 1:
        cout<<c1;
      break;
      case 2:
        c2.size();
        c1=c2;
        cout<<"Copied ";
        cout<<c1;
      break;
      case 3:
        cout<<"\nEnter subscript:";
        cin>>i;
        cout<<"Enter value:";
        cin>>val;
        c1[i]=val;
      break;
      case 4:
        exit (0);
      default :
        cout<<"\n!! Enter valid choice !!";
      break;
     }
      cout<<"\n------------------------------------------------------------\n";
   }while(ch<5);
     return 0;
}

/*
OUTPUT

Enter details of array:
Enter the size of array:5
Enter array elements:2
1
4
6
8

------------------------------------------------------------

1.Display array		2.Copying array
3.Checking array	4.Exit
Enter choice:1

------------------------------------------------------------
 array is:	2	1	4	6	8
------------------------------------------------------------

1.Display array		2.Copying array
3.Checking array	4.Exit
Enter choice:2

------------------------------------------------------------
Enter the size of array:5
Copied  array is:	2	1	4	6	8
------------------------------------------------------------

1.Display array		2.Copying array
3.Checking array	4.Exit
Enter choice:3

------------------------------------------------------------

Enter subscript:2
Enter value:4

------------------------------------------------------------

1.Display array		2.Copying array
3.Checking array	4.Exit
Enter choice:1

------------------------------------------------------------
 array is:	2	1	4	6	8
------------------------------------------------------------

1.Display array		2.Copying array
3.Checking array	4.Exit
Enter choice:4

------------------------------------------------------------
*/
