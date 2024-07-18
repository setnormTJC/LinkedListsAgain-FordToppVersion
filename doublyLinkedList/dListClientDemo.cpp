#include <iostream>
#include <string>
#include <vector>
#include<fstream> 
#include<iomanip>
#include "DoublyLinkedList.h"

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



int main()
{
	dnode<string>* dNodeHeader = new dnode<string>; 
	//string first = "Run away";

	insertDNode(dNodeHeader, string("Run away"));

	insertDNode(dNodeHeader, string("But we're running"));

	insertDNode(dNodeHeader, string("in circles!"));

	writeDLinkedList(dNodeHeader, "\n");


	return 0; 
}