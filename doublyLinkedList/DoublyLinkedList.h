#pragma once

#include<iostream>
#include<string> 


using std::cout;
using std::cin;
using std::endl;
using std::string; 

/*Defines a DOUBLY-linked list data structure
* Taken from Ford, Topp, 2002
*/
template<typename T>
class dnode
{
public:
	T nodeValue;
	dnode<T>* next;
	dnode<T>* prev;

	dnode()
	{
		next = this;
		prev = this;
	};

	dnode(const T& value)
		:nodeValue(value)
	{

	}
};

/*
* @param curr -> pointer to node after which to insert newNode
* @param item -> the value that the newNode holds
*/
template<typename T>
dnode<T>* insertDNode(dnode<T>* curr, const T& item)
{
	dnode<T>* newNode;
	newNode = new dnode<T>(item);

	dnode<T>* prevNode;
	prevNode = curr->prev;

	newNode->prev = prevNode;
	newNode->next = curr;

	prevNode->next = newNode;
	curr->prev = newNode;

	return newNode;
}

/*
@param curr -> a POINTER (perhaps iterator) to a dnode of type T
*/
template<typename T>
void eraseFromDList(dnode<T>* curr)
{
	if (curr->next == curr)
	{
		return;
	}

	dnode<T>* prevNode;
	prevNode = curr->prev;

	dnode<T>* succNode;
	succNode = curr->next;

	prevNode->next = succNode;
	succNode->prev = prevNode;

	delete curr;
}


/*assumes a circularly-linked list (else infinite loop)??*/
template<typename T> 
void writeDLinkedList(dnode<T>* header, const string& separator)
{
	dnode<T>* p = header->next;

	//while (p != header)
	while (p != nullptr) //infinite loop (for fun- "running in circles")
	{
		cout << p->nodeValue << separator;
		p = p->next;
	}
}

/*Calls the erase function defined above*/
template<typename T>
void clearDList(dnode<T>* header)
{
	while (header->next != header)
	{
		erase(header->next);
	}
}
