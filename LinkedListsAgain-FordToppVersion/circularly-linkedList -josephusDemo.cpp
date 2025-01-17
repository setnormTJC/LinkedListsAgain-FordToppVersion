#include <iostream>
#include <string>
#include <vector>
#include<fstream> 
#include<iomanip>

#include"FordToppLinkedList.h"

//global using directives: 
using std::cout; 
using std::cin; 
using std::endl; 

using std::string;
using std::vector;

using std::ofstream;
using std::ifstream; 

using std::setw; 
using std::left; 


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

	/*assumes a circularly-linked list (else infinite loop)??*/
	void writeDLinkedList(dnode<T>* header, const string& separator)
	{
		dnode<T>* p = header->next; 

		while (p != header)
		{
			cout << p->nodeValue << separator; 
			p = p->next; 
		}
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

/*Calls the erase function defined above*/
template<typename T> 
void clearDList(dnode<T>* header)
{
	while (header->next != header)
	{
		erase(header->next);
	}
}


/*
* @param n -> number of contestants
* @param m -> number of times "clock hand" spins
*/
void josephus(int numberOfPeople, int numberOfClockSteps)
{
	dnode<int>* dList = new dnode<int>; 
	 
	for (int i = 1; i <= numberOfPeople; i++)
	{
		insertDNode(dList, i); 
	}

	dnode<int>* curr;
	curr = dList->next; 

	for (int i = 1; i < numberOfPeople; i++)
	{
		for (int j = 1; j <= numberOfClockSteps - 1; j++)
		{
			curr = curr->next; 
			if (curr == dList)
			{
				//cout << "curr was equal to dList (header node)!\n";
				curr = curr->next; 
			}
		}

		cout << "Delete person " << curr->nodeValue << endl; 
		//cout << "Delete person " << (char)(curr->nodeValue + 97) << endl;


		curr = curr->next; 
		eraseFromDList(curr->prev);

		if (curr == dList)
		{
			curr = curr->next;
		}
	}

	cout << curr->nodeValue << " won" << endl; 
	
	delete curr; 
	delete dList; 
}

int main()
{

	//dnode<int>* header = new dnode<int>; 

	//header->insert(header, 4); 
	//header->insert(header, 6);
	//header->insert(header, 5);
	//
	//header->writeDLinkedList(header, " "); // prints 4, 6, 5

	//cout << 3.14->link << endl; 

	josephus(6, 3); 

	return 0; 
}