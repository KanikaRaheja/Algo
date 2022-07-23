// C++ program for weighted job scheduling using Dynamic Programming.
#include <iostream>
#include <algorithm>
#include<conio.h>
using namespace std;
 
 
struct Job
{
    int start, finish, profit;
};
 
 
bool jobComparataor(Job s1, Job s2)
{
    return (s1.finish < s2.finish);
}
 
 
int latestNonConflict(Job arr[], int i)
{
    for (int j=i-1; j>=0; j--)
    {
        if (arr[j].finish <= arr[i].start)
            return j;
    }
    return -1;
}
 
 
int findMaxProfit(Job arr[], int n)
{
    
    sort(arr, arr+n, jobComparataor);
 
    
    int *table = new int[n];
    table[0] = arr[0].profit;
    
  
    for (int i=1; i<n; i++)
    {
         
        int inclProf = arr[i].profit;
        int l = latestNonConflict(arr, i);
        if (l != -1)
            inclProf += table[l];
 
         
        table[i] = max(inclProf, table[i-1]);
    }
 
    
    int result = table[n-1];
    delete[] table;
 
    return result;
}
 
 
int main()
{
    int n;
    cout<<"Enter the number of jobs:- ";
    cin>>n;
    Job *arr;
    arr=new Job[n];
    cout<<" start        finish          profit";
    cout<<endl;
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i].start;
    	cin>>arr[i].finish;
    	cin>>arr[i].profit;
	}
    cout << "The optimal profit is " << findMaxProfit(arr, n);
    getch();
    return 0;
}

/*
OUTPUT

Enter the number of jobs:- 4
 start        finish          profit
3               10              20
1               2               50
6               19              100
2               100             200
The optimal profit is 250

*/

 
