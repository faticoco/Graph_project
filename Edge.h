#pragma once
#include <iostream>
#include <string>
#include "doubly_linked_list.h"
#include"Node.h"
using namespace std;

linked_list <EDGE*>  edges;

class EDGE
{
public:
	NODE* node_1;
	NODE *node_2;
	int dist;

	EDGE(NODE *node_1 , NODE *node_2 )
	{
		this->node_1 = node_1;
		this->node_2 = node_2;
		dist = 1;
		edges.insert(this);
	} 

	bool connection(NODE *n1 , NODE *n2)
	{
		bool same = (node_1 == n1 && node_2 == n2);
	    bool opposite = (node_1 == n2 && node_2 == n1);
		if (same || opposite)   //even if theres one way connection then the two nodes are friends
		{
			return true;
		}
		else
		{
			return false;
		}

	}

};
