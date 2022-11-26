#pragma once
#include <iostream>
#include <string>
#include "doubly_linked_list.h"
#include"graph.h"
using namespace std;
class NODE;
linked_list <NODE*>  nodes;

class NODE
{
public:
	int id;
	NODE* prev;
	int dist_from_the_first_node;

	NODE(int id ) : id(id) , prev(NULL) , dist_from_the_first_node(INT16_MAX) 
	{
		nodes.insert(this);
	}



};