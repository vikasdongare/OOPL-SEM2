
//Program using STL for sorting and searching with user-defined information.
//Roll N0:-16
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Item
{
 public:
        char name[30];
        int quantity,code;
        float cost;

        bool operator==(const Item &Item1)
        {
            return(code==Item1.code);
        }
        bool operator<(const Item &Item1)
        {
           return(code<Item1.code);
        }

        friend ostream& operator << (ostream &out, const Item &);

        friend istream& operator >> (istream &in, Item &k);
};

ostream & operator << (ostream &out, const Item &k)
{
        out<<"\n\t\t"<<k.code<<"\t\t"<<k.name<<"\t\t"<<k.quantity<<"\t\t"<<k.cost;
        return out;
}

istream & operator >> (istream &in , Item &k)
{
        cout<<"\nEnter Item Code : ";
        in>>k.code;
        cout<<"Enter Name : ";
        cin.ignore();
        in.getline(k.name,30);
        cout<<"Enter Quantity : ";
        in>>k.quantity;
        cout<<"Enter cost  : ";
        in>>k.cost;
        return in;
}

bool myfunc(const Item &k, const Item &i2)
{
        return(k.code<i2.code);
}

vector<Item> read()
{
      int n;
      Item k;
      vector<Item> j;
      cout<< "\nEnter total no. of Items : ";
      cin>>n;
      for(int i=0;i<n;i++)
          {
              if(i==0)
                cout<<"\nEnter data for 1st Item : ";
              else if(i==1)
                cout<<"\nEnter data for 2nd Item : ";
              else
                cout<<"\nEnter data for "<<(i+1)<<"th Item : ";

             cin>>k;
             j.push_back(k);
          }
    return j;
}

void printfunction(const Item &k)
{
     cout<<k;
}

void print( const vector<Item> &j)
{
     cout<<"\n\t\tCODE\t\tNAME\t\tQUANTITY\tCOST";
     for_each(j.begin(),j.end(),printfunction);
}

void insert(vector<Item> &j)
{
     Item k;
     cin>>k;
     j.push_back(k);
}

void delet(vector<Item>&j)
{
     Item k;
     cout<<"\nEnter Item Code To Delete : ";
     cin>>k.code;
     vector<Item>::iterator p;
     p=find(j.begin(),j.end(),k);
     if(p!=j.end())
      {
          j.erase(p);
          cout<<"\n\t!!! ITEM DELETED !!!";
      }
     else
        cout<<"\n\t!!! NOT FOUND !!!";
}

void search( vector<Item>&j )
{
    Item k;
    cout<<"\nEnter Item code To Search  : ";
    cin>>k.code;
    cout<<"\n\t\tCODE\t\tNAME\t\tQUANTITY\tCOST";
    vector<Item>::iterator p;
    p=find(j.begin(),j.end(),k);
    if(p!=j.end())
       cout<<*p;
    else
        cout<<"\n\t!!! NOT FOUND !!!";
}

void sort( vector<Item> &j)
{
     sort(j.begin(),j.end(),myfunc);
}

int main()
{
    vector<Item> j;
    int op;
    do
     {
            cout<<"\n\n\t-------<< MENU >>---------\n";
            cout<<"\n\t\t1.Create ";
            cout<<"\n\t\t2.Display ";
            cout<<"\n\t\t3.Insert  ";
            cout<<"\n\t\t4.Delete ";
            cout<<"\n\t\t5.Search ";
            cout<<"\n\t\t6.Sort";
            cout<<"\n\t\t7.Quit";
            cout<<"\n\n\t--------------------------";
            cout<<"\n\tEnter your choice : ";
            cin >> op;
            switch(op)
            {
             case 1:
                      j=read();
                      break;
             case 2:
                      print(j);
                      break;
             case 3:
                      insert(j);
                      break;
             case 4:
                      delet(j);
                      break;
             case 5:
                      search(j);
                      break;
             case 6:
                      sort(j);
                      print(j);
                      break;
            }
     }while(op!=7);
 }

/*

        -------<< MENU >>---------

                1.Create
                2.Display
                3.Insert
                4.Delete
                5.Search
                6.Sort
                7.Quit

        --------------------------
        Enter your choice : 1

Enter total no. of Items : 3

Enter data for 1st Item :
Enter Item Code : 3
Enter Name : ELECTRIC SANDER
Enter Quantity : 7
Enter cost  : 57

Enter data for 2nd Item :
Enter Item Code : 24
Enter Name : HAMMER
Enter Quantity : 76
Enter cost  : 11.99

Enter data for 3th Item :
Enter Item Code : 17
Enter Name : GIJ SAW
Enter Quantity : 21
Enter cost  : 11.00


        -------<< MENU >>---------

                1.Create
                2.Display
                3.Insert
                4.Delete
                5.Search
                6.Sort
                7.Quit

        --------------------------
        Enter your choice : 2

                CODE            NAME                    QUANTITY        COST
                3               ELECTRIC SANDER         7               57
                24              HAMMER                  76              11.99
                17              GIJ SAW                 21              11

        -------<< MENU >>---------

                1.Create
                2.Display
                3.Insert
                4.Delete
                5.Search
                6.Sort
                7.Quit

        --------------------------
        Enter your choice : 3

Enter Item Code : 39
Enter Name : LAWN MOVER
Enter Quantity : 3
Enter cost  : 79.50


        -------<< MENU >>---------

                1.Create
                2.Display
                3.Insert
                4.Delete
                5.Search
                6.Sort
                7.Quit

        --------------------------
        Enter your choice : 2

                CODE            NAME                    QUANTITY        COST
                3               ELECTRIC SANDER         7               57
                24              HAMMER                  76              11.99
                17              GIJ SAW                 21              11
                39              LAWN MOVER              3               79.5

        -------<< MENU >>---------

                1.Create
                2.Display
                3.Insert
                4.Delete
                5.Search
                6.Sort
                7.Quit

        --------------------------
        Enter your choice : 4

Enter Item Code To Delete : 3

        !!! ITEM DELETED !!!

        -------<< MENU >>---------

                1.Create
                2.Display
                3.Insert
                4.Delete
                5.Search
                6.Sort
                7.Quit

        --------------------------
        Enter your choice : 2

                CODE            NAME                    QUANTITY        COST
                24              HAMMER                  76              11.99
                17              GIJ SAW                 21              11
                39              LAWN MOVER              3               79.5

        -------<< MENU >>---------

                1.Create
                2.Display
                3.Insert
                4.Delete
                5.Search
                6.Sort
                7.Quit

        --------------------------
        Enter your choice : 5

Enter Item code To Search  : 3

                CODE            NAME            QUANTITY        COST
        !!! NOT FOUND !!!

        -------<< MENU >>---------

                1.Create
                2.Display
                3.Insert
                4.Delete
                5.Search
                6.Sort
                7.Quit

        --------------------------
        Enter your choice : 5

Enter Item code To Search  : 17

                CODE            NAME                    QUANTITY        COST
                17              GIJ SAW                 21              11

        -------<< MENU >>---------

                1.Create
                2.Display
                3.Insert
                4.Delete
                5.Search
                6.Sort
                7.Quit

        --------------------------
        Enter your choice : 6

                CODE            NAME                    QUANTITY        COST
                17              GIJ SAW                 21              11
                24              HAMMER                  76              11.99
                39              LAWN MOVER              3               79.5

        -------<< MENU >>---------

                1.Create
                2.Display
                3.Insert
                4.Delete
                5.Search
                6.Sort
                7.Quit

        --------------------------
        Enter your choice : 7

*/
