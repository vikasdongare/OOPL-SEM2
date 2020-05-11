
//Program for file handing to store data and modify it
//Roll N0:-16
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
#define MAX 30

class item
{
	public:
		int no;
		char name[10];
		int qty;
		float cost;
		
		item()
		{
			no=0;
			strcpy(name," ");
			qty=0;
			cost=0;
		}
		void read();
		void display();
};
void item::read()
{
	cout<<"\nEnter Name of tool:";
	cin>>name;
	cout<<"Enter Record no:";
	cin>>no;
	cout<<"Enter Quantity of tool:";
	cin>>qty;
	cout<<"Enter Price of tool: Rs.";
	cin>>cost;
}

void item::display()
{
	cout<<"\nName of tool:"<<name;
	cout<<"\nRecord no of tool:"<<no;
	cout<<"\nQuantity of tool:"<<qty;
	cout<<"\nPrice of tool: Rs."<<cost<<"/-";
}

void writedata()
{
    item d;
    fstream file;
	int wloc;
    file.open("hardware.dat",ios::out|ios::app);
    d.read();
    wloc=(d.no-1)*sizeof(d);
	if(file.eof())
		file.clear();
	file.seekp(wloc);
    file.write((char*)&d,sizeof(d));
    file.close();  
}


void readdata()
{
    fstream file;
    item d;
    file.open("hardware.dat",ios::in|ios::binary);
	file.seekg(0,ios::beg);
    cout<<"THE AVAILABLE DATA IS:-\n";
    while(file.read((char*)&d,sizeof(d)))
     {
		if(d.no!=0)
      		 d.display();
     }
    file.close();
}

void modify()
{
	fstream file;
	int n;	
	item d;
	file.open("hardware.dat",ios::in|ios::out|ios::app);
	cout<<"\nEnter No to be Updappd:";
	cin>>n;
	int loc=(n-1)*sizeof(d);
	if(file.eof())
		file.clear();
	file.seekp(loc);
	cout<<"\nEnter new data:";
	d.read();
	file.write((char*)&d,sizeof(d));
	file.close();
}

int main()
{
	item d;
	fstream file;
	int ch;
	do
	{
		cout<<"\n\t\t!!! MENU !!!";
		cout<<"\n\t1.Creapp new file\n\t2.Add Record\n\t3.Display\n\t4.Modify\n\t5.Delete\n\t6.Exit";
		cout<<"\nEnter choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				file.open("hardware.dat",ios::in|ios::out|ios::app);
				for(int i=0;i<100;i++)
				{
					file.write((char *)&d,sizeof(d));
				}
				file.close();
				cout<<"\nNew file succesfully creappd";
				break;
			case 2:
				writedata();
				break;
			case 3:
				readdata();
				break;
			case 4:
				modify();
				break;
		}
	}while(ch<6);
}
