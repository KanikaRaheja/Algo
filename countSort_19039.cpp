#include<iostream>
#include<conio.h>
using namespace std;

class count
{
	int n,MAX,*a,Min;
	public:
		void get();
		int getmax(int[] ,int);
		int getmin(int[],int);
		void countsort(int[],int,int);
		void printarray(int[],int);
};

void count::get()
{
	cout<<"Enter the size of array:- ";
	cin>>n;
	a=new int[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int Max=getmax(a,n);
    int MIN=getmin(a,n);
	int k=Max-MIN;	
	 countsort(a,n,k);
}
 
int count::getmax(int a[],int n)
{
	MAX=0;
     for(int i=0;i<n;i++)
	 {
	 	if(a[i]>MAX)
	 	MAX=a[i];
		 }	
	return MAX;
}
int count::getmin(int a[],int n)
{
	Min=100000;
     for(int i=0;i<n;i++)
	 {
	 	if(a[i]<Min)
	 	Min=a[i];
		 }	
	return Min;
}
void count::countsort(int a[],int n,int k)
{
	int count[k+1]={0};
	int copy[n];
	//counting the number of occurence of each element
	for(int i=0;i<n;i++)
	count[a[i]]++;
	
	//updating the count array to get the corretc index
	for(int i=1;i<=k;i++)
	count[i]+=count[i-1];
	
	//putting the elements in their right index in copy array
	for(int i=n-1;i>=0;i--)
	{
		copy[count[a[i]]-1]=a[i];
		count[a[i]%10]--;
		
	}
	//copy the sorted array into original one
	for(int i=0;i<n;i++)
	a[i]=copy[i];
	
	printarray(a,n);
}
//printing the sorted array
void count::printarray(int a[],int n)
{
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}
int main()
{
	count c;
	c.get();
	getch();
	return 0;
}
