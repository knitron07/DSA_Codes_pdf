#include <iostream>
#define ll long long int
using namespace std;
int main() {
   int t;
   cin>>t;
   while(t--)
   {
       ll n;
       cin>>n;
       ll a[n];
       ll sum=0;
       ll count=0;
       for(ll i=0;i<n;i++)
       {
           cin>>a[i];
           if(a[i]%2 ==0)
           {
           sum+=a[i];
           count++;

           }
       
       }
    if(count==0)
    {
        cout<<count<<endl;
        continue;
        }
       while(sum>1 and sum%2==0)
       {
           sum/=2;
           count++;
       }
cout<< count-1<<endl;;
   }
}
