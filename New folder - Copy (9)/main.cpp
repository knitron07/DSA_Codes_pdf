#include<iostream>
#include<vector>
#include <stack>
using namespace std;

template<typename T>
class Stack{
    private:
    vector<T> v;
    public:
    void push(T data)
    {
        v.push_back(data);
    }

    bool empty(){
        if(v.size()==0)
            return true;

        return false;
    }
    void pop(){
        if(!empty())
            v.pop_back();
    }
    T top(){
        return v[v.size()-1];
    }
};

// reverse a stack using another stack
    void transfer(stack<int> &s1,stack<int> &s2,int n)
    {
        for(int i=0;i<n;i++)
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    void Reverse(stack<int> &s1){
        stack<int> s2;
        int n=s1.size();
        
        for(int i=0;i<n;i++)
        {
            // get top element;
            int x=s1.top();
            s1.pop();
            
            // transfer from s1 to s2
            transfer(s1,s2,n-1-i);
            
            // push x element to s1;
            s1.push(x);
            
            // transfer from s2 to s1
            transfer(s2,s1,n-1-i);
        }
        
        //return s1;
    }
// reverse stack using recursion
void insertInBottom(stack<int> &s1,int x)
{
    if(s1.empty())
        {
            s1.push(x);
            return;
        }
        
        int n=s1.top();
        s1.pop();
        
        insertInBottom(s1,x);
        
        s1.push(n);
        
        return;
    }
void solve(stack<int> &s1)
{
        if(s1.empty())
        return;
        
        int x=s1.top();
        s1.pop();
        
        solve(s1);
        
        insertInBottom(s1,x);
        
        return;
    }
    void ReverseRecu(stack<int> &s1){
       solve(s1);
        vector<int> ans;
        
        return s1;
    }


int main(){
    stack<int> s;
    for(int i=1;i<6;i++)
    s.push(i*i);
    Reverse(s);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}