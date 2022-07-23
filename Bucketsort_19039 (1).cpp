#include<iostream>
#include<conio.h>

using namespace std;

struct Node
{
	float value;
	 Node* next;
	 
};



struct Bucket
{
	 Node *head;  
};

struct BucketList
{
	int V;
	 Bucket * array;
};

class BucketSort
{
	int size;
	float* a;
	float range;
	BucketList* mybucket;
	
	public:
		 BucketSort();
		void getdata();
		void bucketsort();
		void addnode(struct BucketList*,int bckt,float value);
		Node* newNode(float value);
		BucketList* createBucket();
		void displaybucket();
		void display();
};
BucketSort::BucketSort()
{
	size=0;
	a=new float[size];
	range=1;
}
void BucketSort::getdata()
{
 	
 
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>size;
	a=new float[size];
	
		for(int i = 0; i < size; i++)
			cin>>a[i];

		cout<<"\n\nOriginal array:-";
		display();
	
}

void BucketSort::bucketsort()
{
	
	    mybucket = createBucket();
 	
	range = range/size;
		for(int i = 0;i<size;++i)
				addnode(mybucket, (a[i]/range), a[i]);
	
	displaybucket();          
}
BucketList* BucketSort::createBucket()
{
	
	 BucketList* bl = new BucketList;
 
	bl->V = size;
	bl->array = new Bucket[size];   
 

	 
	for(int i=0; i<size; i++)
		bl->array[i].head = NULL;
 
	return bl;
}
 
 Node* BucketSort::newNode(float value)
{
	 Node* newnode = new Node;
	newnode->value = value;
	newnode->next = NULL;
	return newnode;
}
void BucketSort::addnode(struct BucketList* bl,int bckt,float value)
{
		 
	 Node *newnode = newNode(value);
	 Node *temp = new Node;
	
 
	if(bl->array[bckt].head != NULL)
	{
		temp = bl->array[bckt].head;
 
	 
		if(temp->value > newnode->value)
		{
			newnode->next = bl->array[bckt].head;
			bl->array[bckt].head = newnode;
		}
		else
		{
			 
			while(temp->next != NULL)
			{
				if((temp->next)->value > newnode->value)
					break;
 
				temp = temp->next;
			}
			newnode->next = temp->next;
			temp->next = newnode;
		}
	}
	else
	{
		 
		bl->array[bckt].head = newnode;
	}
}

void BucketSort::displaybucket()
{
	int j=0;	
	 Node* temp = new Node;
 	cout<<"\n\n";
	for(int v = 0; v<mybucket->V; v++)
	{
	
		 cout<<"\n\n bucket "<<v+1<<": ";
 		
		temp = mybucket->array[v].head;
		while (temp != NULL)
		{
			a[j++]=temp->value;       
			cout<<"->"<< temp->value;
			temp = temp->next;
		}
	}
}

void BucketSort::display()
{
	for(int i=0;i<size;++i)
		cout<<a[i]<<", ";
}


int main()
{
	BucketSort b1;
	b1.getdata();
	b1.bucketsort();
	cout<<"\n\nSorted Array:-";
	b1.display();
	
	getch();
	return 0;
}
 
 
