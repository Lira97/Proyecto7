#include <iostream>
using namespace std;
#ifndef LIST_H
#define LIST_H

class List 
{
	private:
		typedef struct node 
		{
			int dato;
			node *next;
		}* nodePtr;
		
		nodePtr primero;
		nodePtr curr;
		nodePtr temp;
	public:
		List();
		void insertarNodo(int T);
		void insertarFinal(int T);
		bool insertaDespues(int T, int ref);
		bool eliminaPrimero(int  &T);
		bool eliminaUltimo(int &T);
		bool eliminaNodo(int ref,int &T);
		void imprimirNodo();
	
};

List::List()
{
	primero = NULL;
	curr = NULL;
	temp = NULL;
}

void List::insertarNodo(int T)
{
	nodePtr n = new node;
	n->next = primero;
	n->dato = T;
	primero=n;
	
}
void List::insertarFinal(int T)
{
	nodePtr n = new node;
	nodePtr ultimo = new node;
	n->next = NULL;
	n->dato = T;
	if (primero)
	{
		ultimo=primero;
		while (ultimo->next)
		ultimo=ultimo->next;
		
		ultimo->next=n;
	}
	else 
	{
		primero = n;
	}
}
bool List::insertaDespues(int T, int ref)
{
	nodePtr n = new node;
	nodePtr q = new node;
	
	n->dato = T;
		if (primero)
		{
			q=primero;
			while ((q != NULL )&& (q->dato != ref))
			{
				q=q->next;
			}
			if (q != NULL)
			{
				
				n->dato = T;
				n->next = q->next;
				q->next = n;
				return true;
				
			}
			else 
			{
				return false;
			}
		}
		else 
		{
			return true;
		}
		
}
bool List::eliminaPrimero(int &T)
{
	nodePtr delPtr =NULL;
	if (primero)
	{
		delPtr = primero;
		primero = delPtr->next;
		delete delPtr;
		return true;
	}
	else 
	{
		return false;
	}
	
}
bool List::eliminaUltimo(int &T)
{
	nodePtr delPtr =NULL;
	nodePtr ant =NULL;
	if (primero)
	{
		if(!primero->next)
		{
			delete primero;
			primero=NULL;
		}
		else
		{
			delPtr = primero;
			while(delPtr->next)
			{
				ant=delPtr;
				delPtr=delPtr->next;
			}
			ant->next=NULL;
			delete delPtr;
		}
		return true;
	}
	else 
	{
		return false;
	}
	
}
bool List::eliminaNodo(int ref,int &T)
{
	nodePtr delPtr =NULL;
	temp =primero;
	curr=primero;
	while (curr != NULL && curr->dato != ref)
	{
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL)
	{
		delete delPtr;
		return false;
	}
	else 
	{
		delPtr = curr;
		curr = curr->next;
		temp->next=curr;
		if (delPtr == primero)
		{
			primero = primero->next;
			temp = NULL;
		}
		delete delPtr;
		return true;
	}
}
void List::imprimirNodo()
{
	curr = primero;
	while(curr != NULL)
	{
		cout<< curr->dato <<"\n";
		curr = curr->next ;
	}
}
#endif