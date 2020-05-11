/*
    NAME: ROSHAN VILAS DESALE   CLASS: SE-A     ROLL_NO: 12
    ASSIGNMENT: 9
    PROBLEM STATEMENT: Command line Argument.
*/

#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main(int argc, char *argv[])
{
	fstream fio;
	string data,newdata;
	if(argc<4)
	{
		cout<<"\nInsufficient Arguments."<<endl;
		exit(1);
	}

	cout<<"\n----------Contents of file before modification---------"<<endl;
	fio.open(argv[1], ios::in);
	if(fio.eof())
	{
		cout<<"\nError opening file."<<endl;
	}
	else
	{
		while(!fio.eof())
		{
			getline(fio,data);
			cout<<data<<"\n";
		}
	}
	fio.close();
	cout<<"\nFrom file "<<argv[1]<<" word "<<argv[2]<<" will be replaced by word "<<argv[3]<<"\n"<<endl;
	fio.open(argv[1], ios::in);
	newdata=" ";
	if(fio.eof())
	{
		cout<<"\nError opening file."<<endl;
	}
	else
	{
		while(fio)
		{
			getline(fio,data);
			int a;
			a=(int)data.find(argv[2],0);
			while(a!=string::npos)
			{
				data.replace(a,strlen(argv[2]),argv[3]);
				a=(int)data.find(argv[2],(a+1));
			}
			newdata=newdata+data+"\n";
		}
	}
	fio.close();

	fio.open(argv[1], ios::out);
	if(fio.eof())
	{
		cout<<"\nError opening file."<<endl;
	}
	fio<<newdata;
	fio.close();
	cout<<"\n---------Replacement successful---------\n"<<endl;
	cout<<"\n---------Contents of file after modification---------"<<endl;
	fio.open(argv[1], ios::in);
	if(fio.eof())
	{
		cout<<"\nError opening file."<<endl;
	}
	else
	{
		while(fio)
		{
			getline(fio,data);
			cout<<data<<"\n";
		}
	}
	fio.close();
	return 0;
}

/*
OUTPUT:

----------Contents of file before modification---------
hello
hello hello
hello there
and again hello



From file command.txt word hello will be replaced by word hi


---------Replacement successful---------


---------Contents of file after modification---------
 hi
hi hi
hi there
and again hi

*/
