#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
 
class sort
{
   int n,count,sum,temp1,temp2,temp3,cnt;
   int  *a,*b,*c,*d,*e,start,end;
   public:
   void get();
   void sorting();
   void print(int a[],int n);
   void mergesort(int a[],int l,int r);
   int merge(int a[],int l,int m ,int r );	
   int bubbleSort(int a[],int n);
   int selectionSort(int a[],int n);
   int insertionSort(int a[],int n);
   void swap(int *a,int *b);
   int position(int a[],int lb,int ub);
   void quicksort(int a[] ,int lb,int ub);
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
int sort::merge(int a[],int l,int m,int r  )
{
	  
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2];
	for(int i=0;i<n1;i++)
	L[i]=a[l+i];
	for(int j=0;j<n2;j++)
    R[j]=a[m+1+j];
	int i=0;
	int j=0;
	int k=l;
	while(i<n1 && j<n2  )
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
		}
		k++;
		count++;
	}
	//copying the remaining elements if left 
	while(i<n1)
	{
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=R[j];
		j++;
		k++;
	}
}

void sort::mergesort(int a[],int l,int r )
{
	if(l>=r)
	return;
	int m=(l+r-1)/2;
	mergesort(a,l,m );
	mergesort(a,m+1,r );
    merge(a,l,m,r );
    
}
void sort::quicksort(int a[],int lb,int ub)
{
	if(lb<ub)
	{
		int loc=position(a,lb,ub);
		quicksort(a,lb,loc-1);
		quicksort(a,loc+1,ub);
	}
}
int sort::position(int a[],int lb,int ub)
{
	 start=lb;
	 end=ub;
	int pivot=a[lb];
     while(start<end)
     {
		while(a[start]<=pivot && cnt++)
		{
		start++;
	    }
		while(a[end]>pivot && cnt++)
		{
		end--;
	    }
		if(start<end)
		swap(&a[start],&a[end]);
	}
	swap(&a[lb],&a[end]);
	return end;
}
void sort::print(int a[],int n)
{
	  cout<<n<<"\t"<<temp1<<"\t\t"<<temp2<<"\t\t"<<temp3<<"\t\t"<<count<<"\t\t"<<cnt<<endl; 
}
void sort::get()
{
	n=(rand()%100)+10;
	 
	a=new int[n];
	b=new int[n];
	c=new int[n];
	d=new int[n];
	e=new int[n];
	for(int i=0;i<n;i++)
	{
	int no=rand()%n+1;
	a[i] = no; 
    b[i] = no; 
    c[i] = no;
	d[i] = no;
	e[i] = no;
    }
}
void sort::sorting()
{
	int t=0;
	while(t++<15)
	{
		count=0;
		cnt=0;
	get();
  	mergesort(d,0,n-1);
	 temp1=bubbleSort(a,n);
	 temp2=insertionSort(b,n);
	 temp3=selectionSort(c,n);
	 quicksort(e,0,n-1);
	print(a,n);
    }
}
int main()
{
	cout<<"size\tBubble sort\tinsertion sort\tselection sort\tmergesort\tquick sort"<<endl;
	cout<<endl;
    sort s;
    s.sorting();
	getch();
	return 0;
}
