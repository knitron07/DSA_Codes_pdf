#include <iostream>

using namespace std;

int coin_change_top_down(int n,int *dp,int *coin,int coin_size)
{
    if(n==0)
        return 0;
        
    //Looking int the dp
    if(dp[n]!=0)
        return dp[n];
        
    //Recursion
     int ans=INT_MAX;
    for(int i=0;i<coin_size;i++)
    {
        if(n-coin[i]>=0)
        {
        int sub_ans=coin_change_top_down(n-coin[i],dp,coin,coin_size);
        ans=min(ans,sub_ans+1);
            }
        }
    dp[n]=ans;
    return dp[n];
    }

int coin_change_bottom_up(int n,int *coin,int coin_size)
{
    int dp[1000]={0};
    
    for(int i=1;i<=n;i++)
    {
        dp[i]=INT_MAX;
        for(int k=0;k<coin_size;k++)
        {
            if(i-coin[k]>=0)
            {
                int ans=dp[i-coin[k]]+1;
                dp[i]=min(dp[i],ans);
                }
            }
        }
        
    return dp[n];
    }
int main()
{
    int dp[1000]={0};
    int coin[3]={1,7,10};
    int coin_size=sizeof(coin)/sizeof(coin[0]);
    int n;
    cin>>n;
    cout<<coin_change_bottom_up(n,coin,coin_size)<<endl;
    return 0;
    }
//---------------------------------------------------------------------------------------------------------------------------------------------------------------//
#include <iostream>

using namespace std;
int fibonacci_recurtion(int n,int *dp)
{
    if(n==0 or n==1)
        return n;
    if(dp[n]!=0)
    {
        return dp[n];
        }
    int x=fibonacci_recurtion(n-1,dp)+fibonacci_recurtion(n-2,dp);
    dp[n]=x;
    return x;
    }
int main()
{
    int dp[1000]={0};
    cout<<fibonacci_recurtion(500,dp)<<endl;
    
    return 0;
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------//
#include <iostream>

using namespace std;

int count_ways_top_down(int n,int k,int dp[])
{
    if(n==0)
        return 1;
        
    // lookup 
    if(dp[n]!=0)
        return dp[n];
        
    int ways=0;
    for(int i=1;i<=k;i++)
    {
        if(n-i>=0)
        {
            ways+=count_ways_top_down(n-i,k,dp);
            }
        }
        
    dp[n]=ways;
    return dp[n];
    
    }


 int  count_ways_bottom_up(int n,int k)
 {
     int dp[100]={0};
     
     dp[0]=1;
     
     for(int i=1;i<=n;i++)
     {
         dp[i]=0;
         for(int j=1;j<=k;j++)
         {
             if(i-j>=0)
                 dp[i]+=dp[i-j];
             }
         }
         
    return dp[n];
     }
     
 int  count_ways_bottom_up_optimized(int n,int k)
 {
     int dp[100]={0};
     
     dp[0]=dp[1]=1;
     
     for(int i=2;i<=k;i++)
     {
         dp[i]=2*dp[i-1];
         }
    for(int i=k+1;i<=n;i++)
         {
             
                 dp[i]= 2*dp[i-1]-dp[i-k-1];
             }
         
    return dp[n];
     }
int main()
{
    
    int dp[1000]={0};
    int n,k;
    cin>>n>>k;
    cout<<count_ways_bottom_up_optimized(n,k)<<endl;
    return 0;
    }
//------------------------------------------------------------------------------------------------------------------------------------------------//
#include <iostream>

using namespace std;

int Min_step_to_one_top_down(int n,int dp[])
{
    if(n==1)
    {
        return 0;
        }
    if(dp[n]!=0)
        return dp[n];
        
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;
    if(n%3==0)
        op1=Min_step_to_one_top_down(n/3,dp);
        
    if(n%2==0)
        op2=Min_step_to_one_top_down(n/2,dp);
        
    op3=Min_step_to_one_top_down(n-1,dp);
    
    int ans=min(op3,min(op1,op2))+1;
    dp[n]=ans;
    
    return dp[n];
    }
    
    
int Min_step_to_one_bottom_up(int n)
{
    int dp[10000]={0};
    for(int i=2;i<=n;i++)
    {
        int op1,op2,op3;
        op1=op2=op3=INT_MAX;
        
        if(i%3==0)
            op1=dp[i/3];
        if(i%2==0)
            op2=dp[i/2];
        op3=dp[i-1];
        
        dp[i]=min(op3,min(op1,op2))+1;
        
        }
        
    return dp[n];
    }
int main()
{
    int n;
    cin>>n;
    cout<<Min_step_to_one_bottom_up(n)<<endl;
    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#include <iostream>

using namespace std;

int max_profit_top_down(int cost[],int n,int *dp)
{
    if(n<=0)
        return 0;
        
    if(dp[n]!=0)
        return dp[n];
        
    
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int len=i+1;
        int curr_ans=cost[i]+max_profit_top_down(cost,n-len,dp);
        ans=max(ans,curr_ans);
        }
        
        return dp[n]=ans;
    }


int max_profit_bottom_up(int *cost,int length)
{
    int dp[length+1]={0};
    dp[0]=0;
    
    for(int n=1;n<=length;n++)
    {
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int cut=i+1;
            int curr_ans=cost[i]+dp[n-cut];
            ans=max(ans,curr_ans);
            }
        dp[n]=ans;
        }    
        
        
        return dp[length];
    }

int main()
{
    int cost[]={3,5,8,9,10,17,17,20};
    int dp[100]={0};
    cout<<max_profit_bottom_up(cost,8);
    return 0;
    }
    //---------------------------------------------------------------------------------------------------------------------------------------------//
#include <iostream>

using namespace std;

int wines_profit_top_down(int *wine,int i,int j,int y,int dp[][100])
{
    if(i>j)
        return 0;
        
    if(dp[i][j]!=0)
        return dp[i][j];
    
    
    int op1=wine[i]*y +wines_profit_top_down(wine,i+1,j,y+1,dp);
    int op2=wine[j]*y +wines_profit_top_down(wine,i,j-1,y+1,dp);
    
    return dp[i][j]=max(op1,op2);
    }

int main()
{
    int dp[100][100]={0};
    int wine[]={2,3,5,1,4};
    int n=sizeof(wine)/sizeof(wine[0]);
    cout<<wines_profit_top_down(wine,0,n-1,1,dp)<<endl;
    return 0;
    }