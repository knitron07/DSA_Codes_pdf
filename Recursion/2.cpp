#include<iostream>

using namespace std;
// first occurance 
int linersearch(int a[],int n,int key)
{
	if(n==0)
		return -1;
	if(a[0]==key)
		return 0;
	int i=linersearch(a+1,n-1,key);
	
	if(i==-1)
		return -1;
	return i+1;
	}


// last occurance 
int lastocc(int a[],int n,int key)
{
	if(n==0)
		return -1;
	int last=lastocc(a+1,n-1,key);
	
	if(last==-1)
	{
		if(a[0]==key)
		    return 0;
		else
			return -1;
		}
		else
		return last+1;
	}


// all occurance 
void allocc(int a[],int n,int i,int key)
{
	if(i==n)
		return ;
	if(a[i]==key)
		cout<<i<<",";
	allocc(a,n,i+1,key);
	}


// multiply faster
int fast_power(int x,int n)
{
	//base case
	if(n==0)
		return 1;

	//rec case;
	int small_power=fast_power(x,n/2);
	small_power*=small_power;
	if(n%2==0)
	{
		return  small_power;
		}
	else
		return x*small_power;
	}


// bubble sort
void bubble_sort(int a[],int j,int n)
{
	if(n==1)
		return ;
	if(j==n-1)
		return bubble_sort(a,0,n-1);
	if(a[j]>a[j+1])
		swap(a[j],a[j+1]);
	return 	bubble_sort(a,j+1,n);
	}


// merge sort
void merge(int a[],int s,int e)
{
	int mid=(s+e)/2;
    int i=s;
	int j=mid+1;
	int k{s};
	int temp[100];
	while(i<=mid && j<=e)
	{
	     	if(a[i]<=a[j])
				temp[k++]=a[i++];
			else
				temp[k++]=a[j++];

		}
		while(i<=mid)
		{
			temp[k++]=a[i++];
			}
			
		while(j<=e)
		{
			temp[k++]=a[j++];
			}
			// copy element
		for(int x=s;x<=e;x++)
		{
			a[x]=temp[x];
			}
	}
void merge_sort(int a[],int s,int e)
{
	//base case
	if(s>=e)
		return;
	//dividing int 2 part
	int m=(s+e)/2;
	merge_sort(a,s,m);
	merge_sort(a,m+1,e);
	// merging 2 array
	
	merge(a,s,e);
	
	}


// inversion count
int merge(int *a,int s,int e)
{
	int mid=(s+e)/2;
	int i{s},j{mid+1},k{s};
	int temp[1000000];
	int count{0};
	while(i<=mid && j<=e)
	{
		if(a[i]<=a[j])
		{
			temp[k++]=a[i++];
			}
		else
		{
			temp[k++]=a[j++];
             count+=mid-i+1;
			}
		}
	while(i<=mid)
	{
		temp[k++]=a[i++];
		}
	
	while(j<=e)
	{
		temp[k++]=a[j++];
		}
	for(int x=s;x<=e;x++)
		{
			a[x]=temp[x];
			}
	return count;
	}
int inversion_count(int *a,int s,int e)

{
	//base case
	if(s>=e)
	{
		return 0 ;
		}
	
	//inversion 
	int mid=(s+e)/2;
	int x=inversion_count(a,s,mid);
	int y=inversion_count(a,mid+1,e);
	int z=merge(a,s,e);
	
	return x+z+y;
	}


// quick sort
int partition(int *a,int s,int e)
{
	int i=s-1;
	int j=s;
	for(;j<=e-1;j++)
	{
		if(a[j]<=a[e])
		{
			i++;
			swap(a[i],a[j]);
			}
		}
	swap(a[i+1],a[e]);
	return i+1;
	}
void quick_sort(int *a,int s,int e)
{
	//base case
	if(s>=e)
		return;
	// recursion call
	int p=partition (a,s,e);
	quick_sort(a,s,p-1);
	quick_sort(a,p+1,e);
	}
















































































































































































