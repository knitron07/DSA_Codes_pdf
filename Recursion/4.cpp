#include <iostream>

using namespace std;

void genrating_subsets(char* input,char*output,int i,int j)
{
    // base case
    if(input[i]=='\0')
    {
        output[j]='\0';
        cout<<output<<" ";
        
        return;
        }
        
        output[j]=input[i];
        genrating_subsets(input,output,i+1,j+1);
        genrating_subsets(input,output,i+1,j);
        
        return;
    }
    
void genrating_bracket(char*output,int n,int idx,int open,int close)
{
    //basecase
    if(idx==2*n)
    {
        output[idx]='\0';
        cout<<output<<endl;
        }
        
    if(open<n)
    {
        output[idx]='(';
        genrating_bracket(output, n, idx+1, open+1, close);
        }
    
    if(close<open)
    {
        output[idx]=')';
        genrating_bracket(output, n, idx+1, open, close+1);

        }
        
        return;
    }


int knapsack_0_1(int n,int cap,int *weight,int *profit)
{
    //basecase
    if(n==0 or cap==0)
    {
        return 0;
        }
        
    int include{0},exclude{0};
    int ans=0;
    
    if(cap>=weight[n-1])
    {
        include=profit[n-1]+knapsack_0_1(n-1,cap-weight[n-1],weight,profit);
        }
        
        
    exclude=knapsack_0_1(n-1,cap,weight,profit);
    
    ans=max(include,exclude);
    return ans;
    }
    
char keypad[][10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
void generate_names(char* input,char*output,int i,int j)
{
    if(input[i]=='\0')
    {
        output[j]='\0';
        cout<<output<<endl;
            
        return;
        }
    int digit=input[i]-'0';
    if(digit==1 or digit==0)
    {
        generate_names(input,output,i+1,j);
        }
    for(int k=0;keypad[digit][k]!='\0';k++)
    {
        output[j]=keypad[digit][k];
        //fill the remaining sapce by recursion
        generate_names(input,output,i+1,j+1);
        }    
    return;
    }
        
        
void generate_string(char* input,char* output,int i,int j)
{
    if(input[i]=='\0')
    {
        output[j]='\0';
        cout<<output<<endl;
        return;
        }
        
        
        // rec case
        // one digit at a time
        int digit=0;
       if(input[i]-'0'>0)
        {
            digit=input[i]-'0';
            char ch=digit+'A'-1;
            output[j]=ch;
            generate_string(input,output,i+1,j+1);  
               
            }
        
        if(input[i+1]!='\0')
        {
            int second_digit=input[i+1]-'0';
            int no=digit*10+second_digit;
            if(no<=26)
            {
                char ch=no+'A'-1;
                output[j]=ch;
                 generate_string(input,output,i+2,j+1);
                }
            }
            
        return;
    }
int main()
{
    char* input="123";
    char output[10000];
    
    generate_string(input,output,0,0);
    return 0;
    }
