#pragma once
#include<fstream>
#include<string>
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

	void file_reading()
	{
		fstream myfile;
		myfile.open("friends.txt" , ios::in);
		string num;
		string first_node="";
		bool f_node=false;
		string other_nodes = "";
		while (getline(myfile, num))
		{
			for (int i = 0; i < num.size(); i++)
			{
				if (num[i] == ' ')
				{
					if (f_node = false && num[i] == ' ')   //first space that comes , the prev characters would be first node
					{
						for (int j = 0; num[j] !=':' ; j++)
						{
							first_node += num[j]; 
						}
						f_node = true;  //first node has passed
						cout << "first node " << first_node << ": ";
					}
					else
					{
						for (int j = 0; num[j] != ' '  ; j++)   //add into string until next space comes
						{
							other_nodes += num[j];
						}
						cout << "other node " << other_nodes<<endl;

						//now here add first and other node to the add edge function
						add_edge(stoi(first_node), stoi(other_nodes));

					}
				}
			}
		}
		myfile.close();
	}

};