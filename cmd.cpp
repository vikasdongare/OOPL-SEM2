#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class fstring
{
    char filename[30],oldstr[30],newstr[30];
    public:
         char str[20],cstr[20],rstr[20];
         void create();
         void display();
         void search();
         char *getfilename()
         {
             return filename;
         }
         char *getoldstr()
         {
             return oldstr;
         }
         char *getnewstr()
         {
             return newstr;
         }
         void set(char filename[],char oldstr[],char newstr[])
         {
             strcpy(this->filename,filename);
             strcpy(this->oldstr,oldstr);
             strcpy(this->newstr,newstr);
         }
};

void fstring::create()
{
    ofstream outfile;
    outfile.open(filename);
    cout<<"\nenter data:(write end to terminate)";
    while(1)
    {
        cin.getline(str,20);
        if(strcmp(str,"end")!=0)
            outfile<<str<<"\n";
        else
            break;
    }
    outfile.close();
}

void fstring::search()
{
    fstream file;
    file.open(filename,ios::in|ios::out);
    while(file>>str)
    {
        if(strcmp(str,oldstr)==0)
        {
            strcpy(cstr,oldstr);
            strcpy(rstr,newstr);
            int pos=-1*strlen(str);
            file.seekp(pos,ios::cur);
            file>>rstr;
            break;
        }
    }
    file.close();
}

void fstring::display()
{
    ifstream infile;
    infile.open(filename);
    while(infile.getline(str,20))
    {
        cout<<str<<"\n";
    }
    infile.close();
}

int main(int argc,char *argv[])
{
     fstring s1;
     int ch;

    cout<<"\nNumber of arguments:"<<argc;
    for(int i=0;i<argc;i++)
    {
        cout<<"\n"<<argv[i];
    }


    s1.set(argv[0],argv[1],argv[2]);

    cout<<"\nEnter choice:\n1.Create Display\n2.Search\n";
    cin>>ch;
    switch(ch)
    {
        case 1:
                s1.create();
                s1.display();
                break;
        case 2:
                s1.search();
                s1.display();
                break;
    }
    return 0;
}

