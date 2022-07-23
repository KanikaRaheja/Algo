#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
 
class sort
{
   int n,count,sum,temp1,temp2,temp3;
   int  *a,*b,*c,*d;
   public:
   void get();
   void sorting();
   void print(int a[],int n);
  
   int bubbleSort(int a[],int n);
   int selectionSort(int a[],int n);
   int insertionSort(int a[],int n);
   void swap(int *a,int *b);
};
void sort::swap(int* a,int* b) 
{ 
    int tmp = *a; 
    *a = *b; 
    *b = tmp; 
} 
//bubble sort
int sort::bubbleSort(int a[],int n) 
{ 
    int cmp=0;
    bool again=true;
    for (long int i = 0; i < n - 1 && again; i++) { 
        for (long int j = n-1,again=false; j > i; j-- ) { 
        cmp++;
            if (a[j] < a[j - 1]) { 
                swap(&a[j], &a[j - 1]);
				again=true; 
            } 
        } 
    }
	 return cmp; 
} 
// Insertion sort 
int sort::insertionSort(int arr[],int n) 
{ 
    long int i, key, j,comp=0; 
    for (i = 1; i < n; i++) {
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key &&comp++) {
		 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    }
      return comp;
} 
// Selection sort 
int sort::selectionSort(int arr[],int n) 
{ 
    long int  midx,temp=0; 
  
    for (int i = 0; i < n - 1; i++) { 
  
        // Find the minimum element in unsorted array 
        midx = i; 
  
        for (int j = i + 1; j < n; j++ ) {
        	temp++;
            if (arr[j] < arr[midx]) 
                midx = j; 
            }
        if(midx!=i)
        {
        swap(&arr[midx], &arr[i]);
     	}
    }
	 return temp;
} 

//printing the sorted array
void sort::print(int a[],int n)
{
	  cout<<n<<"\t"<<temp1<<"\t\t"<<temp2<<"\t\t"<<temp3<<"\t\t"<<count<<endl;
}
void sort::get()
{
	n=(rand()%100)+10;
	a=new int[n];
	b=new int[n];
	c=new int[n];
	d=new int[n];
	for(int i=0;i<n;i++)
	{
	int no=rand()%n+1;
	a[i] = no; 
    b[i] = no; 
    c[i] = no;
	d[i] = no;
    }
}
void sort::sorting()
{
	int t=0;
	while(t++<15)
	{
		count=0;
	get();
  	
	 temp1=bubbleSort(a,n);
	 temp2=insertionSort(b,n);
	 temp3=selectionSort(c,n);
	print(a,n);
    }
}
int main()
{
	cout<<"size\tBubble sort\tinsertion sort\tselection sort"<<endl;
	cout<<endl;
    sort s;
    s.sorting();
	getch();
	return 0;
}
