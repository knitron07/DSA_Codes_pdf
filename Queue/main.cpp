//queue with array
#include <iostream>

class Queue{
	int *arr;
	int f,r,cs,ms;
public:

    Queue(int ds=5)
	{
		arr=new int [ds];
		f=0;
		ms=ds;
		r=ms-1;
		cs=0;
		
		}
	bool full(){
		return cs==ms;
		}
    bool empty()
	{
		return cs==0;
		}
     void push(int data)	
	 {
		 if(!full())
		 {
			 r=(r+1)%ms;
			 arr[r]=data;
			 cs++;
			 }
		 
		 }
	
	void pop()
	{
		if(!empty())
		{
			f=(f+1)%ms;
			cs--;
			}
		}
	int front()
	{
		return arr[f];
		}
	
	~Queue()
	{
		if(arr !=nullptr)
		{
			delete [] arr;
			arr=nullptr;
			}
		}
	};

int main()
{
	Queue q; 
	return 0;
	}
//queue with linklist
#include <iostream>
#include <list>
using namespace std;
class Queue
{
	int cs;
	list <int> l;
public:
    Queue()
	{
		cs=0;
		}
    bool empty()
	{
		return cs==0;
		}
	void push(int data)
	{
		l.push_back(data);
		cs++;
		}
	void pop()
	{
		if(!empty())
		{
			l.pop_front();
			cs--;
			}
		}
	
	int front()
	{
		return l.front();
		}
	
	};
int main()
{
	Queue q;
	for(int i=1;i<=10;i++)
	{
		q.push(i);
		}
		while(!q.empty())
		{
			cout<<q.front()<<" ";
			q.pop();
			}
		cout<<endl;
	return 0;
	}
// stack with 2 queue
#include <iostream>
#include <queue>

using namespace std;

template<typename T>
class Stack
{
	queue<T> q1,q2;
public:
    void push(T data)
	{
		q1.push(data);
		}
	void pop()
	{
		if(q1.emplt())
			return ;
		while(q1.size()>1)
		{
			q2.push(q1.front());
			q1.pop();
			}
		q1.pop();
		
		swap(q1,q2);
		}
	T top()
	{
		if(q1.empty())
			return ;
		while(q1.size()>1)
		{
			q2.push(q1.front());
			q1.pop();
			}
		T x=q1.front();
		q1.pop();
		q2.push(x);
		swap(q1,q2);
		return x;
		}
	int size()
	{
		return q1.size() + q2.size();
		}
	bool empty()
	{
		return size()==0;
		}
	};

int main()
{
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	while(!s.empty())
	{
		cout<<s.top()<<endl;
	    s.pop();
	}
	return 0;
	}