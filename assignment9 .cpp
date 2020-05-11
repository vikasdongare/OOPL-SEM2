/*Program for creating data file and storing information like telephone no 
and name then perform operation searching,modifying the data with both.*/
// Roll No:- 16
#include<iostream>
#include<fstream>
#include<string.h>
#define MAX 50
using namespace std;
int n;

class dictionary
{
	public:
	char name[30];
	long int telephone;
		dictionary()
		{
			for(int i=0;i<29;i++)
			{
				name[i]='\0';
			}
			telephone=0;
		}
		void read()
		{
			cout<<"\nEnter name:";
			cin>>name;
			cout<<"Enter telephone:";
			cin>>telephone;
		}
		void display()
		{
			cout<<"\nName:"<<name;
			cout<<"\nTelephone:"<<telephone;
		}
		long int num()
		{
			return telephone;
		}
};
void writedata()
{
	fstream fin;
	dictionary d[MAX];
	cout<<"\nEnter no of entries:";
	cin>>n;
	fin.open("dict.txt",ios::out|ios::binary|ios::app);
	for(int i=0;i<n;i++)
	{
		d[i].read();
		fin.write((char *)&d[i],sizeof(d[i]));
	}
	fin.close();
}
void readdata()
{
	fstream fin;
	int i=0;
	dictionary d[MAX];
	fin.open("dict.txt",ios::in|ios::binary);
	while(fin.read((char *)&d[i],sizeof(d[i])))
	{
		d[i].display();
		i++;
	}
	fin.close();
}
void search(long int no1)
{
	int i=0,n,flag=0;
	fstream fin;
	dictionary d[MAX];
	fin.open("dict.txt",ios::in);
	while(fin.read((char *)&d[i],sizeof(d[i])))
	{
		if(d[i].num()==no1)
		{
			cout<<"\nNumber Found";
			d[i].display();
			flag=1;
		}
		i++;
	}
	if(flag==0)
		cout<<"\nNot Found";
	fin.close();
}
void search(char name[30])
{
	int i=0,n,flag=0;
	fstream fin;
	dictionary d[MAX];
	fin.open("dict.txt",ios::in);
	while(fin.read((char *)&d[i],sizeof(d[i])))
	{
		if(strcmp(d[i].name,name)!=0)
			i++;
		else
		{
			cout<<"\nName Found";
			d[i].display();
			flag=1;
		}
	}
	if(flag==0)
		cout<<"\nNot Found";
	fin.close();
}
void modify(long int no2)
{
	int i=0,n,flag=0;
	fstream fin;
	dictionary d[MAX];
	fin.open("dict.txt",ios::in|ios::out);
	while(fin.read((char *)&d[i],sizeof(d[i])))
	{
		if(d[i].num()==no2)
		{
			cout<<"\nEnter new details:";
			d[i].read();
			int pos=-1*sizeof(d[i]);
			fin.seekp(pos,ios::cur);
			fin.write((char *)&d[i],sizeof(d[i]));
			d[i].display();
			flag=1;
			break;
		}
		i++;
	}
	if(flag==0)
		cout<<"\nNot Found";
	fin.close();
}
void modify(char name[30])
{
	int i=0,n,flag=0;
	fstream fin;
	dictionary d[MAX];
	fin.open("dict.txt",ios::in|ios::out);
	while(fin.read((char *)&d[i],sizeof(d[i])))
	{
		if(strcmp(d[i].name,name)!=0)
		{
			i++;
		}
		else
		{
			cout<<"\nEnter new details:";
			d[i].read();
			int pos=-1*sizeof(d[i]);
			fin.seekp(pos,ios::cur);
			fin.write((char *)&d[i],sizeof(d[i]));
			
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\nNot Found";
	fin.close();
}
int main()
{
	int ch;
	long int no;
	char name[30];
	do
	{
	cout<<"\n\t\t\t!!! Menu !!!";
	cout<<"\n\t1.Add to directory\t2.Display Directory\n\t3.Serach by number\t4.Search by name\n\t5.Modify by number\t6.Modify by name\n\t7.Exit\nEnter choice:";
	cin>>ch;
		cout<<"\n-----------------------------------------------------------------\n";
	switch(ch)
		{
		case 1:
			writedata();
			break;
		case 2:
			cout<<"\n!! Displaying Data !!";
			readdata();
			break;
		case 3:
			cout<<"\nEnter number:";
			cin>>no;
			cout<<"\n\t!!!! SEARCHING !!!!";
			search(no);
			break;
		case 4:
			cout<<"\nEnter name:";
			cin>>name;
			cout<<"\n\t!!!! SEARCHING !!!!";
			search(name);
			break;
		case 5:
			cout<<"\nEnter number:";
			cin>>no;
			cout<<"\n\t!!!! SEARCHING !!!!";
			modify(no);
			break;
		case 6:
			cout<<"\nEnter name:";
			cin>>name;
			cout<<"\n\t!!!! SEARCHING !!!!";
			modify(name);
			break;
		case 7:
			exit(0);
		default:
			cout<<"\n\t !!! Invalid choice !!!";
		}
		cout<<"\n-----------------------------------------------------------------\n";
	}while(ch<7);
}

/*
   Output:-
   	*****MENU*****

	1.Add content in Dictionary
	2.Display content of the Dictionary
	3.Search data by number
	4.Search data by name
	5.Modify data by searching number
	6.Modify data by searching name
	7.Exit

	Enter your choice:-  1

	How many entries you want to enter? 3

	Enter name:-Khushal


	Enter telephone number:-123456

	Enter name:-Akash


	Enter telephone number:-465789

	Enter name:-Vikas


	Enter telephone number:-987456


	*****MENU*****

	1.Add content in Dictionary
	2.Display content of the Dictionary
	3.Search data by number
	4.Search data by name
	5.Modify data by searching number
	6.Modify data by searching name
	7.Exit

	Enter your choice:-  2

	The availabel data is:-  
	Name:-Khushal

	Number:-123456

	Name:-Akash

	Number:-465789

	Name:-Vikas

	Number:-987456


	*****MENU*****

	1.Add content in Dictionary
	2.Display content of the Dictionary
	3.Search data by number
	4.Search data by name
	5.Modify data by searching number
	6.Modify data by searching name
	7.Exit

	Enter your choice:-  3

	Enter number to search:- 123456

	Number found...!!!
	Name:-Khushal

	Number:-123456


	*****MENU*****

	1.Add content in Dictionary
	2.Display content of the Dictionary
	3.Search data by number
	4.Search data by name
	5.Modify data by searching number
	6.Modify data by searching name
	7.Exit

	Enter your choice:-  4

	Enter name to search:- Vikas

	Name found...!!!
	Name:-Vikas

	Number:-987456


	*****MENU*****

	1.Add content in Dictionary
	2.Display content of the Dictionary
	3.Search data by number
	4.Search data by name
	5.Modify data by searching number
	6.Modify data by searching name
	7.Exit

	Enter your choice:-  5

	Enter number to modify:- 456789

	Number not found...!!!

	*****MENU*****

	1.Add content in Dictionary
	2.Display content of the Dictionary
	3.Search data by number
	4.Search data by name
	5.Modify data by searching number
	6.Modify data by searching name
	7.Exit

	Enter your choice:-  5

	Enter number to modify:- 123456

	Number found...!!!
	Enter new details
	Enter name:-Khushal


	Enter telephone number:-654321

	New Added data is...
	Name:-Khushal

	Number:-654321


	*****MENU*****

	1.Add content in Dictionary
	2.Display content of the Dictionary
	3.Search data by number
	4.Search data by name
	5.Modify data by searching number
	6.Modify data by searching name
	7.Exit

	Enter your choice:-  6

	Enter name to modify:- Akash

	Name found...!!!
	Enter new details
	Enter name:-Dhiraj


	Enter telephone number:-456789

	New added data is
	Name:-Dhiraj

	Number:-456789


	*****MENU*****

	1.Add content in Dictionary
	2.Display content of the Dictionary
	3.Search data by number
	4.Search data by name
	5.Modify data by searching number
	6.Modify data by searching name
	7.Exit

	Enter your choice:-  2

	The availabel data is:-  
	Name:-Khushal

	Number:-654321

	Name:-Dhiraj

	Number:-456789

	Name:-Vikas

	Number:-987456


	*****MENU*****

	1.Add content in Dictionary
	2.Display content of the Dictionary
	3.Search data by number
	4.Search data by name
	5.Modify data by searching number
	6.Modify data by searching name
	7.Exit

	Enter your choice:-  7

*/
