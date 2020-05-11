
//program for using STL to add binary number; use STL stack
//Roll N0:-16
#include<iostream>
#include<stack>
using namespace std;

    stack<int> read()
    {
     stack<int>s;
      char num[10];
      A:
       cout<<"\n\n\tEnter binary number :- ";
       cin>>num;
       for(int i=0;num[i]!='\0';i++)
       {
            if(num[i]=='1')
            {
                s.push(1);
            }
           else  if(num[i]=='0')
            {
                s.push(0);
            }
            else
            {
             cout<<"\n\tIt is not binary number";
             goto A;
             }
       }
       return s;
       }
    void display(stack<int >s)
    {
      
       cout<<"\n\tAddition of binary number is :-  ";
       while(!s.empty())
       {
          cout<<s.top();
          s.pop();
       }
    }
    stack<int> addition(stack<int >s1,stack<int >s2)
    {
      stack<int>s;
        int sum=0,carry=0,bit1=0,bit2=0;
     while(!s1.empty()||!s2.empty())
     {
        if(!s1.empty())
        {
           bit1=s1.top();
           s1.pop();
        }
         if(!s2.empty())
        {
           bit2=s2.top();
           s2.pop();
        }
        sum=(bit1+bit2+carry)%2;
        carry=(bit1+bit2+carry)/2;
         s.push(sum);
     }
     if(carry==1)
     {
         s.push(1);
     }
     return s;
}

int main()
{
   stack<int >s1,s2,s3;
   s1=read();
   s2=read();
   s3=addition(s1,s2);
   display(s3);
return 0;
}

/*
    Output:- 
       
        Enter binary number :- 1021

	It is not binary number

	Enter binary number :- 1011


	Enter binary number :- 0101

	Addition of binary number is :-  110000
*/
