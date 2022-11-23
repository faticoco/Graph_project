#pragma once
#include"doubly_linked_list.h"
#include<iostream>
using namespace std;

class graph 
{
private:
	linked_list* list;
	int Vertices;
public:
	graph()
	{
		Vertices = 0;
		list = NULL;
	}
	graph(int vertices)
	{
		Vertices = vertices;
		list = new linked_list[vertices];
	}

	
	void add_edge(int i, int j)
	{
		list[i].insert(j);   //i is friend of j
		list[j].insert(i);  // j is friend of i 
	}
	
	void printGraph() 
	{

		int i = 0;
		int j = 0;
		for (i = 0; i < Vertices; i++)
		{
			for (j = 0; j = list->get_size(); ++j)
			{
				cout << list[i][j]; //overloaded
			}
			cout << endl;
		}
	}
};