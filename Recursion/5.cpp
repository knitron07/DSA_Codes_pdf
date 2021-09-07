#include <iostream>

using namespace std;

bool rat_in_a_maze(char a[][100],int n,int m,int i,int j)
{
    //base case
    if(i==n-1 and j==m-1)
    {
        a[i][j]='1';
        // printing all  the path 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<a[i][j]<<" ";
                }
            cout<<endl;
        }
        cout<<endl;
        
        return true;
        }
    // rat should b in maze
    if(i>=m or j>=n)
    {
        return false;
        }
    // if path is blocked
    if(a[i][j]=='X')
    {
        return false;
        }
    
    //assumint that path exist
    a[i][j]='1';
    bool right_path=rat_in_a_maze(a,n,m,i,j+1);
    bool down_path=rat_in_a_maze(a,n,m,i+1,j);
    
    // backtrack
    a[i][j]='0';
    
    if(right_path or down_path)
    {
        return true;
        }
    return false;
}
void permute(char*input,int i)
{
    if(input[i]=='\0')
    {
        cout<<input<<" ";
        return;
        }
        
    for(int j=i;input[j]!='\0';j++)
    {
        swap(input[i],input[j]);
        permute(input, i+1);
        // back track
        swap(input[i],input[j]);
        }
        
    return;
    }

bool is_safe(int board[][10],int n,int i,int j)
{
    //checking for column 
    for(int k=0;k<=i;k++)
    {
        if(board[k][j]==1)
            return false;
        }
        
    // checking for left diagonal
    int x=i;
    int y=j;
    while(x>=0 and y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
            }
        x--;
        y--;
        }
        
    // checking for right diagonal
    x=i;
    y=j;
    while(x>=0 and y<n)
    {
        if(board[x][y]==1)
        {
            return false;
            }
        x--;
        y++;
        }
    // now position is safe
    return true;
    }

bool solve_N_queen(int board[][10],int n,int i )
{
    if(i==n)
    {
        for(int k=0;k<n;k++)
        {
            for(int j=0;i<n;j++)
            {
                if(board[k][j]==1)
                    cout<<"Q"<<" ";
                else
                    cout<<"_"<<" ";
                }
            cout<<endl;
            }
        cout<<endl;
         return true;//----> will give only one answer
        //return false; // ------>will give all posible answer
        
        }
         
        //recursive case
        for(int j=0;j<n;j++)
        {
            
            if(is_safe(board,n,i,j))
            {
                board[i][j]=1;
                bool can_place_queen=solve_N_queen(board, n,i+1);
                if(can_place_queen)
                {
                     return true;
                    }
                board[i][j]=0;
            }
        }
        return false;
        
    }
int main()
{
    char a[100][100]={
                                "0000",
                                "00X0",
                                "000X",
                                "0X00"
        };
        
    if(rat_in_a_maze(a,4,4,0,0))
    {
        cout<<"path exist";
        }
    else
    {
        cout<<"path doesn't exit";
        }
    return 0;
    }
