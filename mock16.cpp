#include<iostream>
#include<stdlib.h>
using namespace std;

class cpparray
{
	public:
	int a[50],n;
	public:
		int size()
		{
			cout<<"\nEnter the no of elements : " ;
			cin>>n;
		}
		friend istream &operator >>(istream &in, cpparray &c);
		friend ostream &operator <<(ostream &out, cpparray &c);
		
		cpparray operator =(cpparray c)
		{
			for(int i=0;i<n;i++)
				{
					a[i]=c.a[i];
				}
			cout<<"\n\t!!! Array Copied !!!";
		}
		int &operator [](int lval);
		
};

istream &operator >> (istream &in, cpparray &c)
{	
			cout<<"\nEnter elements : \n";
			for(int i=0;i<c.n;i++)
			{
				cout<<"Element ("<<i+1<<") : ";
				in>>c.a[i];
			}
}


ostream &operator << (ostream &out, cpparray &c)
{	

			cout<<"\nThe elements are : ";
			for(int i=0;i<c.n;i++)
			{
				cout<<"\t";
				out<<c.a[i];
			}
}

int &cpparray:: operator [](int lval)
{
	int val;
			if(n<lval)
			{
				cout<<"\nLocation is out of range";
				return a[n-1];
			}
			else if(lval<=-1)
			{
				cout<<"\nLocation should not be negative";
				return a[0];
			}
			else
			{
				cout<<"\nEnter element : ";
				cin>>val;
				a[lval]=val;
				cout<<"\n\t!!! Element entered !!!";
				return a[lval];
			}
		}

int main()
{
	int ch,pos;
	cpparray c1,c2;
	c1.size();
	cin>>c1;
	cout<<"\n---------------------------------------\n";
	do
	{
	cout<<"\n\t--------<< MENU >>--------\n";	
	cout<<"\n\t1.Display Elements";
	cout<<"\n\t2.Copy to another array";
	cout<<"\n\t3.Range checking";
	cout<<"\n\t4.Exit";
	cout<<"\n\t--------------------------\n";
	cout<<"Enter choice : ";
	cin>>ch;
	
	cout<<"\n---------------------------------------\n";
	switch(ch)
	{
		case 1:
				cout<<c1;
				break;
		case 2:
				cout<<"\nDetails for 2nd array :";
				c2.size();
				c2=c1;
				break;
		case 3:
				cout<<"\nEnter position of element : ";
				cin>>pos;
				c1[pos];
				break;
		case 4:
				exit(0);
		default:
				cout<<"\n\t!!! Enter valid choice !!!";
	}
	
	cout<<"\n---------------------------------------\n";
	}while(ch<3);
}
