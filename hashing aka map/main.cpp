#include <iostream>
#include <string>
#include <cstring>
using namespace std;
template<typename T>
class node
{
public:
    string key;
	T value;
	node<T>* next;
	
	node(string key,T val)
	{
		this->key=key;
		this->value=val;
		next=nullptr;		
		}
	~node()
	{
		if(next!=nullptr)
			delete next;
		}
	};
	
template<typename T>
class Hashtable
{
	node<T>** table;
	int current_size;
	int table_size;
	
	int hash_function(string  key)
	{
		int index=0;
		int p=1;
		for(int i=0;i<key.length();i++)
		{
			index+= (key[i]*p)%table_size;
			index=index%table_size;
			p=(p*27)%table_size;
			}
			return index;
		}
		
	void rehash()
	{
		node<T>**old_table=table;
		int old_table_size=table_size;
		table_size*=2;
		table=new node<T>*[table_size];//creating new table
		
		for(int i=0;i<table_size;i++)
			table[i]=nullptr;
		current_size=0;
		
		//coping old table element to new table
		for(int i=0;i<old_table_size;i++)
		{
			node<T>* temp=old_table[i];
			while(temp!=nullptr)
			{
				insert(temp->key,temp->value);
				temp=temp->next;
				}
			if(old_table[i]!=nullptr)
				delete old_table[i];
				
			}
		delete [] old_table;
		}
public:
	
	Hashtable(int ts=7)
	{
		table_size=ts;//update 
		current_size=0;
		table=new node<T>* [table_size];
	    for(int i=0;i<table_size;i++)
			table[i]=nullptr;
		}
		
		void insert(string key, T value)
		{
			int idx=hash_function(key);
			
			// creating an object which store key and value
			node<T>* n=new node<T>(key,value);
			
			// inserting to table at id=idx
			n->next=table[idx];
			table[idx]=n;
			
			current_size++;
			
			//rehashing
			float load_factor=(1.0*current_size)/(1.0*table_size);
			
			if(load_factor>0.7)
			{
				rehash();
				}
			}
			
		void print_table()
			{
				for(int i=0;i<table_size;i++)//update
				{
					cout<<"Bucket"<<" "<<i<<" : ";
					node<T>* temp=table[i];
					while(temp!=nullptr)
					{
						cout<<temp->key<<"->";
						temp=temp->next;
						}
					cout<<endl;
					} 
				}
			
		T* search(string key)
		{
            int idx=hash_function(key);
            node<T>* temp=table[idx];
            while(temp!=nullptr)
            {
                if(temp->key== key)
                {
                    return &temp->value;
                    }
                temp=temp->next;
                }
            return nullptr;
			}
            
        T& operator[] (string key)
        {
            T* f=search(key);
            if(f==nullptr)
            {
                T garbage;
                insert(key,garbage);
                f=search(key);
                }
            return *f;
            }
			
		void erase(string key)
		{
			int idx=hash_function(key);
             node<T>* head=table[idx];
              node<T>* q=nullptr;
              node<T>* p=nullptr;
              if(head->key==key)
              {
                  table[idx]=head->next;
                  delete head;
                  return ;
                  }
                else
                {
                    q=head;
                     p=head->next;
                     
                    while(p!=nullptr)
                    {
                        if(p->key== key)
                        {
                            q->next=p->next;
                            delete p;
                            return;
                            }
                        q=p;
                        p=p->next;
                        }
                    }
			}
	
	};
int main()
{
	Hashtable<int> price_menu;
    
    price_menu.insert("Burger",120);
    price_menu.insert("BurgerDuo",170);
    price_menu.insert("pepsi",30);    
    price_menu.insert("coke",20);
    price_menu.insert("pizza",150);
    price_menu.insert("Largepizza",280);
    price_menu["pizza"]=60;
    price_menu.print_table();
    cout<<price_menu["pizza"]<<endl;

	return 0;
	}
// intersecting of 2 array
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    map<int ,int > m;
    int n;
    cin>>n;
    int a[n]{0};
    int b[n]{0};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m[a[i]]++;
        }
    
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        }
    sort(b,b+n);
        cout<<"[";
        vector<int> v;
    for(int i=0;i<n;i++)
    {
        if(m.find(b[i])!=m.end() )
        {
            if(m[b[i]]>0)
            {
            m[b[i]]--;
            v.push_back(b[i]);
               }
            }
        }
    for(int i=0;i<v.size();i++)
    {
        if(i<v.size()-1)
        cout<<v[i]<<", ";
        else
            cout<<v[i];
        }
        cout<<"]"<<endl;
    
    return 0;
    }
// largest sequence
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int largest_sequence_2(int a[],int n)
{
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        int no=a[i];
        if(m.count(no-1)==0 and m.count(no+1)==0)
        {
            m[no]=1;
            }
        else if(m.count(no-1) and m.count(no+1)==0)
        {
            int len=m[no-1];
            m[no]=len+1;
            m[no-len]=len+1;
            }
        else if (m.count(no-1)==0 and m.count(no+1))
        {
            int len=m[no+1];
            m[no+len]=len+1;
            m[no]=len+1;
            }
        else if(m.count(no-1) and m.count(no+1))
        {
            int len1=m[no-1];
            int len2=m[no+1];
            
            int streak=len1+len2+1;
            m[no-len1]=streak;
            m[no+len2]=streak;
            }
        }
        int largest=0;
        for(auto x:m)
        {
            largest=max(largest,x.second);
            }
        
    return largest;
    }
    
int largest_sequence_3(int a[],int n)
{
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
        s.insert(a[i]);
        }
    int max_streak=1;
    
    for(int i=0;i<n;i++)
    {
        if(s.find(a[i]-1)==s.end())
        {
            int next_no=a[i]+1;
            int streak_len=1;
            while(s.find(next_no)!=s.end())
            {
                next_no+=1;
                streak_len+=1;
                }
            max_streak=max(max_streak,streak_len);
            }
        }
        
    return max_streak;
    }
int main()
{
    int a[]={1,4,8,6,2,5,7,9,12,10,3,14};
    int n=sizeof(a)/sizeof(a[0]);
    
    cout<<largest_sequence_3(a,n);
    return 0;
    }
// minimun window contain second string completely
#include <iostream>
#include <string>
using namespace std;

string min_window(string s,string pattern)
{
    
    if (s.length()<pattern.length())
        return "NONE";
    int s_freq[256]{0},pattern_freq[256]{0};
   int min_window{s.length()};
    for(int i=0;i<pattern.length();i++)
    {
         pattern_freq[pattern[i]]++;
        }
        int count{0};
        int start{0},start_idx{-1};
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        s_freq[ch]++;
        if(pattern_freq[ch]!=0 and pattern_freq[ch]>=s_freq[ch])
        {
            count++;
            }
            
        if(count== pattern.length())
        {
            char temp=s[start];
            while(pattern_freq[temp]==0 or s_freq[temp]>pattern_freq[temp] )
            {
                s_freq[temp]--;
                start++;
                temp=s[start];
                }
                
            int window_length=i-start; 
            if(window_length<min_window)
            {
                min_window=window_length+1;
                start_idx=start;
                }
            }
        }
        if(start_idx==-1)
        {
            return "NONE";
            }
        string ans=s.substr(start_idx,min_window);
        
        return ans;
    }

int main()
{
    
    cout<<min_window("samardeep","same")<<endl;
    return 0;
    
    }
// sub array sum =k
#include <iostream>
#include <unordered_map>

using namespace std;
int length_with_k_sum(int a[],int n,int k)
{
    
    int pre=0;
    int len=0;
    unordered_map<int,int>m;
    for(int i=0;i<n;i++)
    {
        pre+=a[i];
        if(pre==k)
        {
            len=max(len,i+1);
            }
        if(m.find(pre-k)!=m.end())
        {
            len=max(len,i-m[pre-k]);
            }
        else
        {
            m[pre]=i;
            }
            cout<<pre<<" ";
        }
        cout<<endl;
    return len;
    }
int main()
{
    int a[]={1,-1,5,-2,3};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<length_with_k_sum(a,n,3)<<endl;
    return 0;
    }
//sub array sum =0;
#include <iostream>
#include <unordered_map>

using namespace std;
int length_with_zero_sum(int a[],int n)
{
    
    int pre=0;
    int len=0;
    unordered_map<int,int>m;
    for(int i=0;i<n;i++)
    {
        pre+=a[i];
        if(pre==0)
        {
            len=max(len,i+1);
            }
        if(m.find(pre)!=m.end())
        {
            len=max(len,i-m[pre]);
            }
        else
        {
            m[pre]=i;
            }
            cout<<pre<<" ";
        }
        cout<<endl;
    return len;
    }
int main()
{
    int a[]={-2,1,-3,5,-6,4};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<length_with_zero_sum(a,n)<<endl;
    return 0;
    }
