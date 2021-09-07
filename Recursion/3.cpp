#include <iostream>
using namespace std;
// string number to integer number
int string_to_number(char* s,int n)
{
	if(n==0)
	{
		return 0;
		}

	int digit =s[n-1]-'0';
	int small_ans=string_to_number(s,n-1);
	
	return small_ans*10+digit;

	}

//integer to string number
string words[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
void spelling(int n)
{
	if(n==0)
	{
		return;
		}
	int x=n%10;
	spelling(n/10);
	cout<<words[x]<<" ";
	return;
	}

// replace pie with 3.14
void replaece_pie(char a[],int i)
{
	if(a[i]=='\0' or a[i+1]=='\0')
		return ;
	if(a[i]=='p' or a[i+1]=='i')
	{
		int j=i+2;
		while(a[j]!='\0')
		{
			j++;
		    }
		while(j>=i+2)
		{
			a[j+2]=a[j];
			j--;
			}
		a[i]='3';
		a[i+1]='.';
		a[i+2]='1';
		a[i+3]='4';
		replaece_pie(a,i+4);
		}
	else
	{
		replaece_pie(a,i+1);
		}
	}

//tilling 
int tile(int n)
{
	if(n<4)
		return 1;
	int small_ans=tile(n-1)+tile(n-4);
	return small_ans;
	}

//ladder
int ladder(int n)
{
	if(n<0)
		return 0;
	if(n==0)
		return 1;
	int small_ans=ladder(n-1)+ladder(n-2)+ladder(n-3);
	return small_ans;
	}

//friend pairing
int ways(int n)
{
	//base case
	if(n<0)
		return 0;
	if(n==0 || n==1)
		return 1;
	//rec case
	
	int small_ans=ways(n-1)+((n-1)*(ways(n-2)));
	
	return small_ans;
	}

// tower of hanoi
void move(int n,char start,char helper,char final)
{
	if(n==0)
	return;

	//n-1 disk from start to helper
	move(n-1,start,final,helper);
	cout<<"Moving ring "<< n<<" from "<<start <<" to "<<final<<endl;
    move(n-1,helper,start,final);

	return ;

}