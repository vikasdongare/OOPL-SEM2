
//program for dequeue usin STL function
//Roll N0:-16
#include<iostream>
#include<deque>
using namespace std;
int main()
{
   deque<int> ob;
   deque<int>::iterator it;
   int element,ch;
   do
   {
   A:
   cout<<"\n\n\t***Select your choice***";
   cout<<"\n\n\t1.Insert element at back";
   cout<<"\n\t2.Insert element at front";
   cout<<"\n\t3.Delete element at back";
   cout<<"\n\t4.Delete element at front";
   cout<<"\n\t5.Get front element";
   cout<<"\n\t6.Get back element";
   cout<<"\n\t7.Size of dequeue";
   cout<<"\n\t8.Display element in dequeue";
   cout<<"\n\t9.exit";
   cout<<"\n\n\tEnter your choice:-  ";
   cin>>ch;
   
   switch(ch)
   {
    case 1:
           cout<<"\n\tEnter element to be inserted at back:-  ";
           cin>>element;
           ob.push_back(element);
           break;
    case 2:
           cout<<"\n\tEnter element to be inserted at front:-  ";
           cin>>element;
           ob.push_front(element);
           break;
    case 3:
           ob.pop_back();
           break;
    case 4:
           ob.pop_front();
           break;
    case 5:
           element=ob.front();
           cout<<"\n\tFront element is:-  "<<element;
           break;
    case 6:
           element=ob.back();
           cout<<"\n\tBack element is:-  "<<element;
           break;
     case 7:
            cout<<"\n\tSize of dequeue is:-  ";
            element=ob.size();
            cout<<element;
            break;
     case 8:
            cout<<"\n\tElement in dequeue is:-\n ";
            for(it=ob.begin();it!=ob.end();it++)
            {
               cout<<"\t"<<*it;
            }
            break;
      case 9:
              exit(0);
              break;
      default:
             cout<<"\n\tEnter valid choice....";
             goto A;
   }
   }while(ch!=10);
   return 0;
}


/*
  Output:-  
   
          	***Select your choice***

	1.Insert element at back
	2.Insert element at front
	3.Delete element at back
	4.Delete element at front
	5.Get front element
	6.Get back element
	7.Size of dequeue
	8.Display element in dequeue
	9.exit

	Enter your choice:-  1

	Enter element to be inserted at back:-  42


	***Select your choice***

	1.Insert element at back
	2.Insert element at front
	3.Delete element at back
	4.Delete element at front
	5.Get front element
	6.Get back element
	7.Size of dequeue
	8.Display element in dequeue
	9.exit

	Enter your choice:-  1

	Enter element to be inserted at back:-  32


	***Select your choice***

	1.Insert element at back
	2.Insert element at front
	3.Delete element at back
	4.Delete element at front
	5.Get front element
	6.Get back element
	7.Size of dequeue
	8.Display element in dequeue
	9.exit

	Enter your choice:-  2

	Enter element to be inserted at front:-  15


	***Select your choice***

	1.Insert element at back
	2.Insert element at front
	3.Delete element at back
	4.Delete element at front
	5.Get front element
	6.Get back element
	7.Size of dequeue
	8.Display element in dequeue
	9.exit

	Enter your choice:-  2

	Enter element to be inserted at front:-  46


	***Select your choice***

	1.Insert element at back
	2.Insert element at front
	3.Delete element at back
	4.Delete element at front
	5.Get front element
	6.Get back element
	7.Size of dequeue
	8.Display element in dequeue
	9.exit

	Enter your choice:-  1

	Enter element to be inserted at back:-  32


	***Select your choice***

	1.Insert element at back
	2.Insert element at front
	3.Delete element at back
	4.Delete element at front
	5.Get front element
	6.Get back element
	7.Size of dequeue
	8.Display element in dequeue
	9.exit

	Enter your choice:-  2

	Enter element to be inserted at front:-  51


	***Select your choice***

	1.Insert element at back
	2.Insert element at front
	3.Delete element at back
	4.Delete element at front
	5.Get front element
	6.Get back element
	7.Size of dequeue
	8.Display element in dequeue
	9.exit

	Enter your choice:-  8

	Element in dequeue is:-
 	51	46	15	42	32	32

	***Select your choice***

	1.Insert element at back
	2.Insert element at front
	3.Delete element at back
	4.Delete element at front
	5.Get front element
	6.Get back element
	7.Size of dequeue
	8.Display element in dequeue
	9.exit

	Enter your choice:-  3


	***Select your choice***

	1.Insert element at back
	2.Insert element at front
	3.Delete element at back
	4.Delete element at front
	5.Get front element
	6.Get back element
	7.Size of dequeue
	8.Display element in dequeue
	9.exit

	Enter your choice:-  8

	Element in dequeue is:-
 	51	46	15	42	32

	***Select your choice***

	1.Insert element at back
	2.Insert element at front
	3.Delete element at back
	4.Delete element at front
	5.Get front element
	6.Get back element
	7.Size of dequeue
	8.Display element in dequeue
	9.exit

	Enter your choice:-  4


	***Select your choice***

	1.Insert element at back
	2.Insert element at front
	3.Delete element at back
	4.Delete element at front
	5.Get front element
	6.Get back element
	7.Size of dequeue
	8.Display element in dequeue
	9.exit

	Enter your choice:-  8

	Element in dequeue is:-
 	46	15	42	32

	***Select your choice***

	1.Insert element at back
	2.Insert element at front
	3.Delete element at back
	4.Delete element at front
	5.Get front element
	6.Get back element
	7.Size of dequeue
	8.Display element in dequeue
	9.exit

	Enter your choice:-  5

	Front element is:-  46

	***Select your choice***

	1.Insert element at back
	2.Insert element at front
	3.Delete element at back
	4.Delete element at front
	5.Get front element
	6.Get back element
	7.Size of dequeue
	8.Display element in dequeue
	9.exit

	Enter your choice:-  6

	Back element is:-  32

	***Select your choice***

	1.Insert element at back
	2.Insert element at front
	3.Delete element at back
	4.Delete element at front
	5.Get front element
	6.Get back element
	7.Size of dequeue
	8.Display element in dequeue
	9.exit

	Enter your choice:-  7

	Size of dequeue is:-  4

	***Select your choice***

	1.Insert element at back
	2.Insert element at front
	3.Delete element at back
	4.Delete element at front
	5.Get front element
	6.Get back element
	7.Size of dequeue
	8.Display element in dequeue
	9.exit

	Enter your choice:-  1

	Enter element to be inserted at back:-  10


	***Select your choice***

	1.Insert element at back
	2.Insert element at front
	3.Delete element at back
	4.Delete element at front
	5.Get front element
	6.Get back element
	7.Size of dequeue
	8.Display element in dequeue
	9.exit

	Enter your choice:-  2

	Enter element to be inserted at front:-  30


	***Select your choice***

	1.Insert element at back
	2.Insert element at front
	3.Delete element at back
	4.Delete element at front
	5.Get front element
	6.Get back element
	7.Size of dequeue
	8.Display element in dequeue
	9.exit

	Enter your choice:-  8

	Element in dequeue is:-
 	30	46	15	42	32	10

	***Select your choice***

	1.Insert element at back
	2.Insert element at front
	3.Delete element at back
	4.Delete element at front
	5.Get front element
	6.Get back element
	7.Size of dequeue
	8.Display element in dequeue
	9.exit

	Enter your choice:-  10

	Enter valid choice....

	***Select your choice***

	1.Insert element at back
	2.Insert element at front
	3.Delete element at back
	4.Delete element at front
	5.Get front element
	6.Get back element
	7.Size of dequeue
	8.Display element in dequeue
	9.exit

	Enter your choice:-  9

*/
