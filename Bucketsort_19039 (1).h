#include<iostream>
#include<conio.h>



using namespace std;


template<class T>
class List;
	
template<class T>
class node
{

	T ele;
	node<T>* next;
	
	
	friend class List<T>;
	
	
};


template<class T>
class List
{
	node<T>* head;
	public:
			
			List();
			~List();
			bool empty()const;
			const T& front()const;
			const T& tail()const;
			const T& getEle(const node<T>*);
			void addfront(const T&);
			void deletefront();
			void addtail(const T&);
			void deletetail();
			node<T>* getHead();
			node<T>* getNext(const node<T>*);

			
};

template<class T>
List<T>::List()
: head(NULL) {}

template<class T>
bool List<T>::empty()const
{
	return head==NULL;
}

template<class T>
List<T>::~List()
{
	while(!empty())
	deletefront();
}

template<class T>
const T& List<T>::front() const   	// throw(ListEmpty)
{
	return head->ele;			
}

template<class T>
node<T>* List<T>::getHead()
{
	return head;
}

template<class T>
const T& List<T>::getEle(const node<T>*temp)
{
	temp->ele;
}
template<class T>
node<T>* List<T>::getNext(const node<T>* temp)
{
	return temp->next;
}


template<class T>
void List<T>::addfront(const T& e)
{
	node<T>* temp=new node<T>;
	temp->ele=e;
	temp->next=head;
	head=temp;
}

template<class T>
void List<T>::deletefront()
{
	
		
			node<T>* temp=head;
			head=temp->next;
			delete temp;
	
	
}

template<class T>
void List<T>::addtail(const T& e)
{
	node<T>* n=new node<T>;
	n->ele=e;   
	n->next=NULL;
	if(head==NULL)
	{
		head=n;
	}
	else
	{
	node<T>* temp=head;
	while(temp->next!=NULL)
	temp=temp->next;
	temp->next=n;
   }
}

template<class T>
void List<T>::deletetail()
{
	
	
	node<T>* temp=head;

	if(temp->next==NULL)
		{
			delete temp;
			head=NULL;
		}
	else{
		node<T>* t;
		while(temp->next!=NULL)
			{
				t=temp;
				temp=temp->next;
			}

	t->next=NULL;
	delete temp;
}
}



template<class T>
const T& List<T>::tail()const 
{
	
	node<T>*temp=head;
	while(temp->next!=NULL)
	temp=temp->next;
	return temp->ele;
	
}





