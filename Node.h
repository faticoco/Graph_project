#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include"global.h"
using namespace std;



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
#endif // !NODE_H