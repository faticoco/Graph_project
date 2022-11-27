#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include <string>
#include"Node.h"
using namespace std;

class EDGE
{
public:
	NODE* node_1;
	NODE *node_2;
	int dist;

	EDGE(NODE *n1 , NODE *n2 )
	{
		node_1 = n1;
		node_2 = n2;
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

#endif // !EDGE_H