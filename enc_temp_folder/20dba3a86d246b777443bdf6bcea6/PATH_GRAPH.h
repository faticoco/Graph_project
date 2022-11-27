#ifndef path_graph_h
#define path_graph_h

#include"Edge.h"

class path_graph {
public:

	void path_finding()
	{
		while (nodes.get_size() > 0)    //while all nodes finish
		{
			NODE* small = get_smallest_node(nodes);
			linked_list <NODE*>* adj_nodes = other_nodes(small);
			int counter = 0;
			while (counter < adj_nodes->get_size())
			{
				NODE* adj = adj_nodes->operator[](counter);

				//calculating path distance of the smallest adjacent node from start
				int path_distance = calculate_distance(small, adj) + small->dist_from_the_first_node;
				
				if (path_distance < adj->dist_from_the_first_node)
				{
					adj->dist_from_the_first_node = path_distance;
					adj->prev = small;
				}

				counter++;
			}
			adj_nodes->empty();   //the adjacent nodes has been passed
			delete adj_nodes;
		}
	}

	NODE* get_smallest_node(linked_list <NODE *> & n)
	{
		if (n.get_size() == 0)
		{
			return NULL; 
		} 
		int s_location = 0;
		NODE  *small = n.operator[](0);
		int counter = 1;

		while (counter < n.get_size())
		{
			NODE* node = n.operator[](counter);
			if (  small->dist_from_the_first_node > node->dist_from_the_first_node)  {	small = node;  s_location = counter; }
			counter++;
		}
		 
		for (int i = 0; i < s_location; i++)
		{
		    delete n.operator[](0);     //deleting starting nodes till current
		}
		return small;
	}


	linked_list <NODE*>* other_nodes(NODE *node)   //returns the other adjacent nodes
	{
		linked_list <NODE*>* adj_nodes = new linked_list<NODE *>;
		int counter = 0;
		while (counter < edges.get_size())
		{
			EDGE* e = edges.operator[](counter);
			NODE *adj = NULL;
			 
			if (e->node_1 == node)
			{
				adj = e->node_2;
			}
			else if (e->node_2 == node)
			{
				adj = e->node_1;
			}

			if (adj && composition(nodes, adj))
			{
				adj_nodes->insert(adj);
			}
			counter++;
		}
		return adj_nodes;
	}

	//if a particular node is present within all the nodes of a connected graph
	bool composition( linked_list <NODE *> & all_nodes, NODE *node_contained_or_not)
	{
		int counter = 0;
		while (counter < all_nodes.get_size())
		{
			if (node_contained_or_not == all_nodes.operator[](counter))
			{
				return true;
			}
			counter++;
		}
		return false;
	}

	//distance between two nodes  //calculate social distance 
	//returns -99 if no connection between two people
	int calculate_distance(NODE* N1, NODE* N2)
	{
		int counter = 0;
		while (counter < edges.get_size())
		{
			EDGE* e = edges.operator[](counter);
			if (e->connection(N1 , N2))
			{
				return e->dist;
			}
			counter++;
		}
		return -99;   //no distance  //no connection
	}

	//passes through the shortest route to a given node
	int calculate_shortest_path(NODE* shortest)
	{
		NODE* has_passed = shortest;
		cout << shortest->dist_from_the_first_node<<"\n";
		while (has_passed !=NULL)
		{
			has_passed = has_passed->prev;
		} 

		return shortest->dist_from_the_first_node;
	}

	//calculate social distance 
	void distance_between_two_nodes(NODE* N1, NODE* N2)
	{
		N1->dist_from_the_first_node = 0;

		path_finding();

		cout<<"\nSocial circle between two people is of "<<calculate_shortest_path(N2)<<" people apart "<<endl;
	}



};
#endif // !path_graph_h