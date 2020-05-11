//Program for selection sort and bubble sort using template
//Roll No :- 16

#include<iostream>
using namespace std;
template<class T>
class sort
{
  int i,j,imin,n;
  T array[20],temp;
  public:
   void read()
   {
       cout<<"\nEnter no of elements:";
       cin>>n;
       cout<<"\nEnter the array elements:\n";
       for(i=0;i<n;i++)
       {
          cin>>array[i];
       }
   }
   void display()
   {
      cout<<"\nThe array elements:\n";
       for(i=0;i<n;i++)
       {
          cout<<array[i]<<"\t";
       }
   }
   void assort()
   {
   for(i=0;i<n;i++)
       {
          imin=i;
          for(j=i+1;j<n;j++)
          {
             if(array[j]<array[imin])
             {
                   imin=j;
             }
          }
          if(imin!=i)
          {
             temp=array[i];
             array[i]=array[imin];
             array[imin]=temp;
          }
       }
   }
   void dssort()
   {
   for(i=0;i<n;i++)
       {
          imin=i;
          for(j=i+1;j<n;j++)
          {
             if(array[j]>array[imin])
             {
                   imin=j;
             }
          }
          if(imin!=i)
          {
             temp=array[i];
             array[i]=array[imin];
             array[imin]=temp;
          }
       }
   }
   void absort()
   {
     for(i=0;i<n;i++)
      {
         for(j=i;j<n;j++)
          {
             if(array[i]>array[j])
             {
                temp=array[j];
                array[j]=array[i];
                array[i]=temp;
            }
         }
      }
   }
   void dbsort()
   {
     for(i=0;i<n;i++)
      {
         for(j=i;j<n;j++)
          {
             if(array[i]<array[j])
             {
                temp=array[j];
                array[j]=array[i];
                array[i]=temp;
            }
         }
      }
   }
};
int main()
 {
    int ch,ch1;
    sort<int>a;
    sort<float>b;
    do
    {
       cout<<"\n1.Using selection sort\n2.Using bubble sort\n3.Exit\nEnter choice:";
       cin>>ch1;
       switch(ch1)
       {
          case 1:
     cout<<"\n--------------------------------------------------------------------------------\n";
    cout<<"\n1.Integer accending sorting\t2.Integer decending sorting\n3.Float acending sorting  \t4.Float decending sorting\n5.Exit\nEnter choice:"; 
      cin>>ch;
      cout<<"\n--------------------------------------------------------------------------------\n";
      switch(ch)
      {
         case 1:
            a.read();
            a.assort();
            a.display();
            break;
         case 2:
            a.read();
            a.dssort();
            a.display();
            break;
          case 3:
            b.read();
            b.assort();
            b.display();
            break;
          case 4:
            b.read();
            b.dssort();
            b.display();
            break;
          case 5:
             exit(0);
          default:
             cout<<"\n!! Enter valid choice !!";
        }
        break;
        
        case 2:
    cout<<"\n1.Integer accending sorting\t2.Integer decending sorting\n3.Float acending sorting  \t4.Float decending sorting\n5.Exit\nEnter choice:"; 
    cin>>ch;
      switch(ch)
      {
         case 1:
            a.read();
            a.absort();
            a.display();
            break;
         case 2:
            a.read();
            a.dbsort();
            a.display();
            break;
          case 3:
            b.read();
            b.absort();
            b.display();
            break;
          case 4:
            b.read();
            b.dbsort();
            b.display();
            break;
          case 5:
             exit(0);
          default:
             cout<<"\n!! Enter valid choice !!";
        }
        break;
        
        case 3:
            exit(0);
            
        default:
           cout<<"\n!! Enter valid choice !!";
      }
          cout<<"\n--------------------------------------------------------------------------------\n";
      }while(ch1<=2);
 }
 
 
 /* 
 OUTPUT :-
 
 1.Using selection sort
2.Using bubble sort
3.Exit
Enter choice:1

--------------------------------------------------------------------------------

1.Integer accending sorting	2.Integer decending sorting
3.Float acending sorting  	4.Float decending sorting
5.Exit
Enter choice:1

--------------------------------------------------------------------------------

Enter no of elements:3

Enter the array elements:
-1
0
1

The array elements:
-1	0	1	


1.Using selection sort
2.Using bubble sort
3.Exit
Enter choice:1

--------------------------------------------------------------------------------

1.Integer accending sorting	2.Integer decending sorting
3.Float acending sorting  	4.Float decending sorting
5.Exit
Enter choice:2

--------------------------------------------------------------------------------

Enter no of elements:3

Enter the array elements:
-1
0
1

The array elements:
1	0	-1	
--------------------------------------------------------------------------------

1.Using selection sort
2.Using bubble sort
3.Exit
Enter choice:1

--------------------------------------------------------------------------------

1.Integer accending sorting	2.Integer decending sorting
3.Float acending sorting  	4.Float decending sorting
5.Exit
Enter choice:3

--------------------------------------------------------------------------------

Enter no of elements:3

Enter the array elements:
-1.0
0
1.2

The array elements:
-1	0	1.2	
--------------------------------------------------------------------------------

1.Using selection sort
2.Using bubble sort
3.Exit
Enter choice:1

--------------------------------------------------------------------------------

1.Integer accending sorting	2.Integer decending sorting
3.Float acending sorting  	4.Float decending sorting
5.Exit
Enter choice:4

--------------------------------------------------------------------------------

Enter no of elements:3

Enter the array elements:
-1.2
0
1.2

The array elements:
1.2	0	-1.2	
--------------------------------------------------------------------------------


1.Using selection sort
2.Using bubble sort
3.Exit
Enter choice:2

1.Integer accending sorting	2.Integer decending sorting
3.Float acending sorting  	4.Float decending sorting
5.Exit
Enter choice:1

Enter no of elements:3

Enter the array elements:
-1
0
1

The array elements:
-1	0	1	
--------------------------------------------------------------------------------

1.Using selection sort
2.Using bubble sort
3.Exit
Enter choice:2

1.Integer accending sorting	2.Integer decending sorting
3.Float acending sorting  	4.Float decending sorting
5.Exit
Enter choice:2

Enter no of elements:3

Enter the array elements:
-1
0
1

The array elements:
1	0	-1	
--------------------------------------------------------------------------------

1.Using selection sort
2.Using bubble sort
3.Exit
Enter choice:2

1.Integer accending sorting	2.Integer decending sorting
3.Float acending sorting  	4.Float decending sorting
5.Exit
Enter choice:3

Enter no of elements:3

Enter the array elements:
-1.2

0
1.2

The array elements:
-1.2	0	1.2	
--------------------------------------------------------------------------------

1.Using selection sort
2.Using bubble sort
3.Exit
Enter choice:2

1.Integer accending sorting	2.Integer decending sorting
3.Float acending sorting  	4.Float decending sorting
5.Exit
Enter choice:4

Enter no of elements:3

Enter the array elements:
-1.2
0
1.2

The array elements:
1.2	0	-1.2	
--------------------------------------------------------------------------------

1.Using selection sort
2.Using bubble sort
3.Exit
Enter choice:3

