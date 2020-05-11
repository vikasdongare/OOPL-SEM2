/*
 DEVELOP AN OBJECT ORIENTED PROGRAM IN C++ TO CREATE A DATABASE OF STUDENT INFORMATION SYSTEM CONTAINING THE FOLLOWING INFORMATION: NAME, ROLL NO, CLASS, DIVISION, DATE OF BIRTH, BLOOD GROUP, CONTACT ADDRESS, TELEPHONE NUMBER, DRIVING LICENCE NO. ETC. CONSTRUCT THE DATABASE WITH SUITABLE MEMBER FUNCTIONS FOR INITIALIZING AND DESTROYING THE DATA VIZ CONSTRUCTOR, DEFAULT CONSTRUCTOR, COPY CONSTRUCTOR, DESTRUCTOR, STATIC MEMBER FUNCTIONS, FRIEND CLASS, THIS POINTER, INLINE CODE AND DYNAMIC MEMORY ALLOCATIN OPERATORS-NEW AND DELETE

ROLL NO:-16
*/
#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
class student
{
   public:
   int rollno;
   char name[20];
   char dateofBirth[20];
   char telephone[10];
   char bloodGrp[10];
   static int count;
   static void counter()
   {
     cout<<"\nCOUNTER WORKING";
     cout<<"\nNo of objects created are"<<count;
   }
   void getdata();
   friend void display(student &obj);
   void display();
   
   //counter
   student()
   {
     rollno=count;
     count++;
     cout<<"constructor is executed";
   }
   //Destructor
   ~student()
   {
    cout<<"\nDestructor";
   }
   //Parameterized Constructor
   student(int rollno)
   {
     count++;
     this->rollno=rollno;
     cout<<"\nParameterized Constructor";
   }
   //Copy Constructor
   student(student &s)
   {
     count++;
     cout<<"\nCopy Contructor";
     rollno=s.rollno;
     strcpy(name,s.name);
     strcpy(dateofBirth,s.dateofBirth);
     strcpy(telephone,s.telephone);
     strcpy(bloodGrp,s.bloodGrp);
   }
};
int student::count=1;
void student::getdata()
{
 cout<<"\n"<<"Name:";
 cin>>name;
 cout<<"Date Of Birth:";
 cin>>dateofBirth;
 cout<<"Telephone:";
 cin>>telephone;
 cout<<"Blood Group:";
 cin>>bloodGrp;
}

void display(student &obj)
{
  cout<<"\n"<<setw(10)<<obj.rollno;
  cout<<setw(20)<<obj.name;
  cout<<setw(10)<<obj.dateofBirth;
  cout<<setw(20)<<obj.telephone;
  cout<<setw(15)<<obj.bloodGrp;
}

void student::display()
{
  cout<<"\n"<<setw(10)<<rollno;
  cout<<setw(20)<<name;
  cout<<setw(10)<<dateofBirth;
  cout<<setw(20)<<telephone;
  cout<<setw(15)<<bloodGrp;
}

int main()
{
  student s1,s2;
  cout<<"\n"<<"Enter the data of student 1";
  s1.getdata();
  cout<<"\n"<<"Enter the data of student 2";
  s2.getdata();
  student s3;
  cout<<"\n"<<"Enter the data of student 3";
  s3.getdata();
  student s4(s3);
  cout<<"\n"<<setw(10)<<"Roll No"<<setw(20)<<"Name"<<setw(10)<<"Date of Birth"<<setw(20)<<"Telephone"<<setw(15)<<"Blood Group";
  display(s1);
  display(s2);
  display(s3);
  cout<<"\nFor copy constructor s3 To s4";
  display(s4);
  //Creating array of pointers of student object
  student *s[50];
  int n,i;
  cout<<"\nEnter the no of students";
  cin>>n;
  for(i=0;i<n;i++)
  {
    s[i]=new student();
    s[i]->getdata();
  }
  cout<<"\n"<<setw(10)<<"Roll No"<<setw(20)<<"Name"<<setw(10)<<"Date of Birth"<<setw(20)<<"Telephone"<<setw(15)<<"Blood Group";
  for(i=0;i<n;i++)
  {
   s[i]->display();
  }
  student::counter();
  for(i=0;i<n;i++)
  {
    delete(s[i]);
  }
  return 0;
}

/*
OUTPUT:-

constructor is executed
constructor is executed
Enter the data of student 1
Name:Akash
Date Of Birth:6/10/1999
Telephone:9825647132
Blood Group:B-

Enter the data of student 2
Name:Mayur
Date Of Birth:26/04/2000
Telephone:8354692246
Blood Group:A-
constructor is executed
Enter the data of student 3
Name:Abhi
Date Of Birth:15/8/2000
Telephone:9945762314
Blood Group:O-

Copy Contructor
   Roll No                Name  Date of Birth      Telephone    Blood Group
         1               Akash  6/10/1999        9825647132             B-
         2               Mayur  26/04/2000       8354692246             A-
         3                Abhi  15/8/2000        9945762314             O-
For copy constructor s3 To s4
         3                Abhi  15/8/2000        9945762314             O-
Enter the no of students2
constructor is executed
Name:Vikas
Date Of Birth:13/08/2000
Telephone:9975093783
Blood Group:O+
constructor is executed
Name:DVG
Date Of Birth:27/04/2000
Telephone:8356794210
Blood Group:A-

   Roll No              Name   Date of Birth         Telephone      Blood Group
         5             Vikas    13/08/2000          9975093783             O+
         6              DVG    27/04/2000          8356794210             A-
COUNTER WORKING
No of objects created are7
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
*/
